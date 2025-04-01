#include "vslc.h"

// This header defines a bunch of macros we can use to emit assembly to stdout
#include "emit.h"

// In the System V calling convention, the first 6 integer parameters are passed in registers
#define NUM_REGISTER_PARAMS 6
static const char* REGISTER_PARAMS[6] = {RDI, RSI, RDX, RCX, R8, R9};

// Takes in a symbol of type SYMBOL_FUNCTION, and returns how many parameters the function takes
#define FUNC_PARAM_COUNT(func) ((func)->node->children[1]->n_children)

static void generate_stringtable(void);
static void generate_global_variables(void);
static void generate_function(symbol_t* function);
static void generate_expression(node_t* expression);
static void generate_statement(node_t* node);
static void generate_main(symbol_t* first);

// Entry point for code generation
void generate_program(void)
{
  generate_stringtable();
  generate_global_variables();

  // This directive announces that the following assembly belongs to the .text section,
  // which is the section where all executable assembly lives
  DIRECTIVE(".text");

  // TODO: (Part of 2.3)
  // For each function in global_symbols, generate it using generate_function ()

  // TODO: (Also part of 2.3)
  // In VSL, the topmost function in a program is its entry point.
  // We want to be able to take parameters from the command line,
  // and have them be sent into the entry point function.
  //
  // Due to the fact that parameters are all passed as strings,
  // and passed as the (argc, argv)-pair, we need to make a wrapper for our entry function.
  // This wrapper handles string -> int64_t conversion, and is already implemented.
  // call generate_main ( <entry point function symbol> );
}

// Prints one .asciz entry for each string in the global string_list
static void generate_stringtable(void)
{
  // This section is where read-only string data is stored
  // It is called .rodata on Linux, and "__TEXT, __cstring" on macOS
  DIRECTIVE(".section %s", ASM_STRING_SECTION);

  // These strings are used by printf
  DIRECTIVE("intout: .asciz \"%s\"", "%ld");
  DIRECTIVE("strout: .asciz \"%s\"", "%s");
  // This string is used by the entry point-wrapper
  DIRECTIVE("errout: .asciz \"%s\"", "Wrong number of arguments");

  // TODO 2.1: Print all strings in the program here, with labels you can refer to later
  // You have access to the global variables string_list and string_list_len from symbols.c
  for (size_t i = 0; i < string_list_len; i++)
  {
    DIRECTIVE("string%ld: \t.asciz %s", i, string_list[i]); 
  }
}

// Prints .zero entries in the .bss section to allocate room for global variables and arrays
static void generate_global_variables(void)
{
  // This section is where zero-initialized global variables lives
  // It is called .bss on linux, and "__DATA, __bss" on macOS
  DIRECTIVE(".section %s", ASM_BSS_SECTION);
  DIRECTIVE(".align 8");

  // TODO 2.2: Fill this section with all global variables and global arrays
  // Give each a label you can find later, and the appropriate size.
  // Regular variables are 8 bytes, while arrays are 8 bytes per element.
  // Remember to mangle the name in some way, to avoid collisions with labels
  // (for example, put a '.' in front of the symbol name)
  for (size_t i = 0; i < global_symbols->n_symbols; i++)
  {
    symbol_t* symbol = global_symbols->symbols[i];
    if (symbol->type == SYMBOL_GLOBAL_VAR)
    {
      DIRECTIVE(".%s: \t.zero 8", symbol->name);
    }
    else if (symbol->type == SYMBOL_GLOBAL_ARRAY)
    {
      if (symbol->node->children[1]->type != NUMBER_LITERAL)
      {
        fprintf(stderr, "error: length of array '%s' is not compile time known", symbol->name);
        exit(EXIT_FAILURE);
      }
      int64_t length = symbol->node->children[1]->data.number_literal;
      DIRECTIVE(".%s: \t.zero %ld", symbol->name, length * 8);
    }
  }

  // As an example, to set aside 16 bytes and label it .myBytes, write:
  // DIRECTIVE(".myBytes: .zero 16")
}

// Global variable used to make the functon currently being generated accessible from anywhere
static symbol_t* current_function;

// Prints the entry point. preamble, statements and epilouge of the given function
static void generate_function(symbol_t* function)
{
  // TODO: 2.3

  // TODO: 2.3.1 Do the prologue, including call frame building and parameter pushing
  // Tip: use the definitions REGISTER_PARAMS and NUM_REGISTER_PARAMS at the top of this file
  LABEL(".%s", function->name);
  current_function = function;

  PUSHQ(RBP);
  MOVQ(RSP, RBP);

  // Up to 6 parmans from registers pushed to the stack
  for (size_t i = 0; i < FUNC_PARAM_COUNT(function) && i < NUM_REGISTER_PARAMS; i++) 
  {
    PUSHQ(REGISTER_PARAMS[i]);
  }

  // Then, for each local variable, push 8-byte 0 values to the stack
  for (size_t i = 0; i < function->function_symtable->n_symbols; i++) 
  {
    if (function->function_symtable->symbols[i]->type == SYMBOL_LOCAL_VAR) { PUSHQ("$0"); }
  }

  // TODO: 2.4 the function body can be sent to generate_statement()
  generate_statement(function->node->children[2]);

  // TODO: 2.3.2
  LABEL(".%s.epilogue", function->name);
  MOVQ(RBP, RSP);
  POPQ(RBP);
  RET;
}

// Generates code for a function call, which can either be a statement or an expression
static void generate_function_call(node_t* call)
{
  // TODO 2.4.3
  symbol_t* symbol = call->children[0]->symbol;
  if (symbol->type != SYMBOL_FUNCTION)
  {
    fprintf(stderr, "error: '%s' is not a function\n", symbol->name);
    exit(EXIT_FAILURE);
  }

  node_t* argument_list = call->children[1];

  size_t parameter_count = FUNC_PARAM_COUNT(symbol);
  if (parameter_count != argument_list->n_children)
  {
    fprintf(
        stderr,
        "error: function '%s' expects '%zu' arguments, but '%zu' were given\n",
        symbol->name,
        parameter_count,
        argument_list->n_children);
    exit(EXIT_FAILURE);
  }

  // We evaluate all parameters from right to left, pushing them to the stack
  for (int i = parameter_count - 1; i >= 0; i--)
  {
    generate_expression(argument_list->children[i]);
    PUSHQ(RAX);
  }

  // Up to 6 parameters should be passed through registers instead. Pop them off the stack
  for (size_t i = 0; i < parameter_count && i < NUM_REGISTER_PARAMS; i++)
  {
    POPQ(REGISTER_PARAMS[i]);
  }

  EMIT("call .%s", symbol->name);

  // Now pop away any stack passed parameters still left on the stack, by moving %rsp upwards
  if (parameter_count > NUM_REGISTER_PARAMS)
  {
    EMIT("addq $%zu, %s", (parameter_count - NUM_REGISTER_PARAMS) * 8, RSP);
  }
}

// Generates code to evaluate the expression, and place the result in %rax
static void generate_expression(node_t* expression)
{
  // TODO: 2.4.1 Generate code for evaluating the given expression.
  // (The candidates are NUMBER_LITERAL, IDENTIFIER, ARRAY_INDEXING, OPERATOR and FUNCTION_CALL)
  switch (expression->type)
  {
  case NUMBER_LITERAL:
    // Simply place the number into %rax
    EMIT("movq $%ld, %s", expression->data.number_literal, RAX);
    break;
  case IDENTIFIER:
    // Load the variable, and put the result in RAX
    MOVQ(generate_variable_access(expression), RAX);
    break;
  case ARRAY_INDEXING:
    // Load the value pointed to by array[idx], and put the result in RAX
    MOVQ(generate_array_access(expression), RAX);
    break;
  case OPERATOR:
  {
    const char* op = expression->data.operator;
    if (strcmp(op, "+") == 0)
    {
      generate_expression(expression->children[0]);
      PUSHQ(RAX);
      generate_expression(expression->children[1]);
      POPQ(RCX);
      ADDQ(RCX, RAX);
    }
    else if (strcmp(op, "-") == 0)
    {
      if (expression->n_children == 1)
      {
        // Unary minus
        generate_expression(expression->children[0]);
        NEGQ(RAX);
      }
      else
      {
        // Binary minus. Evaluate RHS first, to get the result in RAX easier
        generate_expression(expression->children[1]);
        PUSHQ(RAX);
        generate_expression(expression->children[0]);
        POPQ(RCX);
        SUBQ(RCX, RAX);
      }
    }
    else if (strcmp(op, "*") == 0)
    {
      // Multiplication does not need to do sign extend
      generate_expression(expression->children[0]);
      PUSHQ(RAX);
      generate_expression(expression->children[1]);
      POPQ(RCX);
      IMULQ(RCX, RAX);
    }
    else if (strcmp(op, "/") == 0)
    {
      generate_expression(expression->children[1]);
      PUSHQ(RAX);
      generate_expression(expression->children[0]);
      CQO; // Sign extend RAX -> RDX:RAX
      POPQ(RCX);
      IDIVQ(RCX); // Didivde RDX:RAX by RCX, placing the result in RAX
    }
    else if (strcmp(op, "==") == 0)
    {
      generate_expression(expression->children[0]);
      PUSHQ(RAX);
      generate_expression(expression->children[1]);
      POPQ(RCX);
      CMPQ(RAX, RCX);
      SETE(AL);        // Store lhs == rhs into %al
      MOVZBQ(AL, RAX); // Zero extend to all of %rax
    }
    else if (strcmp(op, "!=") == 0)
    {
      generate_expression(expression->children[0]);
      PUSHQ(RAX);
      generate_expression(expression->children[1]);
      POPQ(RCX);
      CMPQ(RAX, RCX);
      SETNE(AL);       // Store lhs != rhs into %al
      MOVZBQ(AL, RAX); // Zero extend to all of %rax
    }
    else if (strcmp(op, "<") == 0)
    {
      generate_expression(expression->children[0]);
      PUSHQ(RAX);
      generate_expression(expression->children[1]);
      POPQ(RCX);
      CMPQ(RAX, RCX);
      SETL(AL);        // Store lhs < rhs into %al
      MOVZBQ(AL, RAX); // Zero extend to all of %rax
    }
    else if (strcmp(op, "<=") == 0)
    {
      generate_expression(expression->children[0]);
      PUSHQ(RAX);
      generate_expression(expression->children[1]);
      POPQ(RCX);
      CMPQ(RAX, RCX);
      SETLE(AL);       // Store lhs <= rhs into %al
      MOVZBQ(AL, RAX); // Zero extend to all of %rax
    }
    else if (strcmp(op, ">") == 0)
    {
      generate_expression(expression->children[0]);
      PUSHQ(RAX);
      generate_expression(expression->children[1]);
      POPQ(RCX);
      CMPQ(RAX, RCX);
      SETG(AL);        // Store lhs > rhs into %al
      MOVZBQ(AL, RAX); // Zero extend to all of %rax
    }
    else if (strcmp(op, ">=") == 0)
    {
      generate_expression(expression->children[0]);
      PUSHQ(RAX);
      generate_expression(expression->children[1]);
      POPQ(RCX);
      CMPQ(RAX, RCX);
      SETGE(AL);       // Store lhs >= rhs into %al
      MOVZBQ(AL, RAX); // Zero extend to all of %rax
    }
    else if (strcmp(op, "!") == 0)
    {
      generate_expression(expression->children[0]);
      CMPQ("$0", RAX);
      SETE(AL);        // Store %rax == 0 into %al
      MOVZBQ(AL, RAX); // Zero extend to all of %rax
    }
    else
      assert(false && "Unknown expression operation");
    break;
  }
  case FUNCTION_CALL:
    generate_function_call(expression);
    break;
  default:
    assert(false && "Unknown expression type");
  }
}

static void generate_assignment_statement(node_t* statement)
{
  // TODO: 2.4.2
  // You can assign to both local variables, global variables and function parameters.
  // Use the IDENTIFIER's symbol to find out what kind of symbol you are assigning to.
  // The left hand side of an assignment statement may also be an ARRAY_INDEXING node.
  // In that case, you must also emit code for evaluating the index being stored to
  node_t* dest = statement->children[0];
  node_t* expression = statement->children[1];

  // First the right hand side of the assignment is evaluated
  generate_expression(expression);

  if (dest->type == IDENTIFIER) {
    // Store rax into the memory location corresponding to the variable
    MOVQ(RAX, generate_variable_access(dest));
  }
  else
  {
    assert(dest->type == ARRAY_INDEXING);
    // Store rax until the final address of the array element is found,
    // since array index calculation can potentially modify all registers
    PUSHQ(RAX);
    const char* dest_mem = generate_array_access(dest);
    POPQ(RAX);
    MOVQ(RAX, dest_mem);
  }
}

static void generate_print_statement(node_t* statement)
{
  // TODO: 2.4.4
  // Remember to call safe_printf instead of printf
  node_t* print_items = statement->children[0];
  for (size_t i = 0; i < print_items->n_children; i++)
  {
    node_t* item = print_items->children[i];
    if (item->type == STRING_LIST_REFERENCE)
    {
      EMIT("leaq strout(%s), %s", RIP, RDI);
      EMIT("leaq string%zu(%s), %s", (size_t)item->data.string_list_index, RIP, RSI);
    }
    else
    {
      generate_expression(item);
      MOVQ(RAX, RSI);
      EMIT("leaq intout(%s), %s", RIP, RDI);
    }
    EMIT("call safe_printf");
  }

  MOVQ("$'\\n'", RDI);
  EMIT("call safe_putchar");
}

static void generate_return_statement(node_t* statement)
{
  // TODO: 2.4.5 Evaluate the return value, store it in %rax and jump to the function epilogue
  generate_expression(statement->children[0]);
  EMIT("jmp .%s.epilogue", current_function->name);
}

// Recursively generate the given statement node, and all sub-statements.
static void generate_statement(node_t* node)
{
  if (node == NULL)
    return;

  // TODO: 2.4 Generate instructions for statements.
  // The candidates are BLOCK, ASSIGNMENT_STATEMENT, PRINT_STATEMENT, RETURN_STATEMENT,
  // FUNCTION_CALL
  switch (node->type)
  {
  case BLOCK:
  {
    // All handling of pushing and popping scopes has already been done
    // Just generate the statements that make up the statement body, one by one
    node_t* statement_list = node->children[node->n_children - 1];
    for (size_t i = 0; i < statement_list->n_children; i++)
      generate_statement(statement_list->children[i]);
    break;
  }
  case ASSIGNMENT_STATEMENT:
    generate_assignment_statement(node);
    break;
  case PRINT_STATEMENT:
    generate_print_statement(node);
    break;
  case RETURN_STATEMENT:
    generate_return_statement(node);
    break;
  case FUNCTION_CALL:
    generate_function_call(node);
    break;
  case IF_STATEMENT:
    generate_if_statement(node);
    break;
  case WHILE_STATEMENT:
    generate_while_statement(node);
    break;
  case BREAK_STATEMENT:
    generate_break_statement();
    break;
  default:
    assert(false && "Unknown statement type");
  }
}

static void generate_safe_printf(void)
{
  LABEL("safe_printf");

  PUSHQ(RBP);
  MOVQ(RSP, RBP);
  // This is a bitmask that abuses how negative numbers work, to clear the last 4 bits
  // A stack pointer that is not 16-byte aligned, will be moved down to a 16-byte boundary
  ANDQ("$-16", RSP);
  EMIT("call printf");
  // Cleanup the stack back to how it was
  MOVQ(RBP, RSP);
  POPQ(RBP);
  RET;
}

// Generates the scaffolding for parsing integers from the command line, and passing them to the
// entry point of the VSL program. The VSL entry function is specified using the parameter "first".
static void generate_main(symbol_t* first)
{
  // Make the globally available main function
  LABEL("main");

  // Save old base pointer, and set new base pointer
  PUSHQ(RBP);
  MOVQ(RSP, RBP);

  // Which registers argc and argv are passed in
  const char* argc = RDI;
  const char* argv = RSI;

  const size_t expected_args = FUNC_PARAM_COUNT(first);

  SUBQ("$1", argc); // argc counts the name of the binary, so subtract that
  EMIT("cmpq $%ld, %s", expected_args, argc);
  JNE("ABORT"); // If the provdied number of arguments is not equal, go to the abort label

  if (expected_args == 0)
    goto skip_args; // No need to parse argv

  // Now we emit a loop to parse all parameters, and push them to the stack,
  // in right-to-left order

  // First move the argv pointer to the vert rightmost parameter
  EMIT("addq $%ld, %s", expected_args * 8, argv);

  // We use rcx as a counter, starting at the number of arguments
  MOVQ(argc, RCX);
  LABEL("PARSE_ARGV"); // A loop to parse all parameters
  PUSHQ(argv);         // push registers to caller save them
  PUSHQ(RCX);

  // Now call strtol to parse the argument
  EMIT("movq (%s), %s", argv, RDI); // 1st argument, the char *
  MOVQ("$0", RSI);                  // 2nd argument, a null pointer
  MOVQ("$10", RDX);                 // 3rd argument, we want base 10
  EMIT("call strtol");

  // Restore caller saved registers
  POPQ(RCX);
  POPQ(argv);
  PUSHQ(RAX); // Store the parsed argument on the stack

  SUBQ("$8", argv);        // Point to the previous char*
  EMIT("loop PARSE_ARGV"); // Loop uses RCX as a counter automatically

  // Now, pop up to 6 arguments into registers instead of stack
  for (size_t i = 0; i < expected_args && i < NUM_REGISTER_PARAMS; i++)
    POPQ(REGISTER_PARAMS[i]);

skip_args:

  EMIT("call .%s", first->name);
  MOVQ(RAX, RDI);    // Move the return value of the function into RDI
  EMIT("call exit"); // Exit with the return value as exit code

  LABEL("ABORT"); // In case of incorrect number of arguments
  EMIT("leaq errout(%s), %s", RIP, RDI);
  EMIT("call puts"); // print the errout string
  MOVQ("$1", RDI);
  EMIT("call exit"); // Exit with return code 1

  generate_safe_printf();

  // Declares global symbols we use or emit, such as main, printf and putchar
  DIRECTIVE("%s", ASM_DECLARE_SYMBOLS);
}
