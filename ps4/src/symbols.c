#include <vslc.h>

// Declaration of global symbol table
symbol_table_t* global_symbols;

// Declarations of helper functions defined further down in this file
static void find_globals(void);
static void bind_names(symbol_table_t* local_symbols, node_t* root);
static void print_symbol_table(symbol_table_t* table, int nesting);
static void destroy_symbol_tables(void);

static size_t add_string(char* string);
static void print_string_list(void);
static void destroy_string_list(void);

/* External interface */

// Creates a global symbol table, and local symbol tables for each function.
// All usages of symbols are bound to their symbol table entries.
// All strings are entered into the string_list
void create_tables(void)
{
  // DONE
  // TODO:
  // First use find_globals() to create the global symbol table.
  // As global symbols are added, function symbols get their own local symbol tables as well.
  //
  // Once all global symbols are added, go through all functions bodies and bind references.
  //
  // Binding should performed by bind_names(function symbol table, function body AST node).
  // IDENTIFIERs that reference declarations should point to the symbol_t they reference.
  // It handles pushing and popping scopes, and adding variables to the local symbol table.
  // A final task performed by bind_names(...), is adding strings to the global string list.
  find_globals();

  for (size_t i = 0; i < global_symbols->n_symbols; i++)
  {
    symbol_t* symbol = global_symbols->symbols[i];
    if (symbol->type != SYMBOL_FUNCTION) { continue; }
    
    bind_names(symbol->function_symtable, symbol->node);
  }
}

// Prints the global symbol table, and the local symbol tables for each function.
// Also prints the global string list.
// Finally prints out the AST again, with bound symbols.
void print_tables(void)
{
  print_symbol_table(global_symbols, 0);
  printf("\n == STRING LIST == \n");
  print_string_list();
  printf("\n == BOUND SYNTAX TREE == \n");
  print_syntax_tree();
}

// Cleans up all memory owned by symbol tables and the global string list
void destroy_tables(void)
{
  destroy_symbol_tables();
  destroy_string_list();
}

/* Internal matters */

// Goes through all global declarations, adding them to the global symbol table.
// When adding functions, a local symbol table with symbols for its parameters are created.
static void find_globals(void)
{
  // DONE
  // TODO: Create symbols for all global defintions (global variables, arrays and functions),
  // and add them to the global symbol table. See the symtype_t enum in "symbols.h"

  // When creating a symbol for a function, also create a local symbol_table_t for it.
  // Store this local symbol table in the function symbol's function_symtable field.
  // Any parameters the function may have should be added to this local symbol table.

  // TIP: create symbols using malloc(sizeof(symbol_t)), and assigning the relevant fields.
  // Use symbol_table_insert() (from "symbol_table.h") to insert new symbols into tables.

  // If a symbol already exists with the same name, the insertion will return INSERT_COLLISION.
  // Feel free to print an error message and abort using exit(EXIT_FAILURE),
  // but we will not be testing your compiler on invalid VSL.
  global_symbols = symbol_table_init();

  for (size_t i = 0; i < root->n_children; i++)
  {
    node_t* node = root->children[i];

    if (node->type == GLOBAL_DECLARATION)
    {
      // Since declarations in VSL are lists, we iterate over the children
      node_t* list = node->children[0];
      for (size_t j = 0; j < list->n_children; j++)
      {
        node_t* child = list->children[j];
        symbol_t global_symbol = (symbol_t) {
          .node = child,
          .function_symtable = NULL,
        };

        if (child->type == IDENTIFIER)
        {
          global_symbol.type = SYMBOL_GLOBAL_VAR;
          global_symbol.name = child->data.identifier;
        }
        else if (child->type == ARRAY_INDEXING)
        {
          global_symbol.type = SYMBOL_GLOBAL_ARRAY;
          global_symbol.name = child->children[0]->data.identifier;
        }
        
        symbol_t* global_sym = malloc(sizeof(symbol_t));
        *global_sym = global_symbol;
        insert_result_t insert_result = symbol_table_insert(global_symbols, global_sym);
        if (insert_result == INSERT_COLLISION) { exit(EXIT_FAILURE); }
      }
    }
    else if (node->type == FUNCTION)
    {
      // Create local symbol table for the function
      symbol_table_t* local_table = symbol_table_init();
      local_table->hashmap->backup = global_symbols->hashmap;

      // Create symbol for the function and add it to the global table
      symbol_t* function_symbol = malloc(sizeof(symbol_t));
      *function_symbol = (symbol_t) {
				.name = node->children[0]->data.identifier,
				.type = SYMBOL_FUNCTION,
				.node = node,
				.function_symtable = local_table,
			};
      insert_result_t insert_result = symbol_table_insert(global_symbols, function_symbol);
      if (insert_result == INSERT_COLLISION) { exit(EXIT_FAILURE); }

      // Iterate over the function paramters and add them to the local table
      node_t* param_list = node->children[1];
      for (size_t j = 0; j < param_list->n_children; j++)
      {
        node_t* param = param_list->children[j];
        symbol_t* param_symbol = malloc(sizeof(symbol_t));
        *param_symbol = (symbol_t) {
          .name = param->data.identifier,
          .type = SYMBOL_PARAMETER,
          .node = param,
          .function_symtable = NULL,
        };
        insert_result = symbol_table_insert(local_table, param_symbol);
        if (insert_result == INSERT_COLLISION) { exit(EXIT_FAILURE); }
      }
    }
  }
}

// A recursive function that traverses the body of a function, and:
//  - Adds variable declarations to the function's local symbol table.
//  - Pushes and pops local variable scopes when entering and leaving blocks.
//  - Binds all IDENTIFIER nodes that are not declarations, to the symbol it references.
//  - Moves STRING_LITERAL nodes' data into the global string list,
//    and replaces the node with a STRING_LIST_REFERENCE node.
//    Overwrites the node's data.string_list_index field with with string list index
static void bind_names(symbol_table_t* local_symbols, node_t* node)
{
  if (node == NULL) { return; }

  symbol_hashmap_t* prev_hashmap;
  
  switch (node->type)
  {
    case FUNCTION:
      // Avoid binding the parameters
      bind_names(local_symbols, node->children[2]);
      break;
    case BLOCK:
      // Init new hashmap for the scope of the block
      prev_hashmap = local_symbols->hashmap;
      local_symbols->hashmap = symbol_hashmap_init();
      local_symbols->hashmap->backup = prev_hashmap;

      // If the block is of the form '{' local_declaration_list statement_list '}'
      // i.e. n_children is >= 2, we iterate over the local variable symbols and
      // add them to the blocks local table 
      if (node->n_children >= 2)
      {
        node_t* locals_list = node->children[0];
        for (size_t i = 0; i < locals_list->n_children; i++)
        {
          node_t* locals = locals_list->children[i];
          for (size_t j = 0; j < locals->n_children; j++)
          {
            node_t* local = locals->children[j];
            symbol_t* local_symbol = malloc(sizeof(symbol_t));
            *local_symbol = (symbol_t) {
              .name = local->data.identifier,
              .type = SYMBOL_LOCAL_VAR,
              .node = local,
              .function_symtable = NULL,
            };
            insert_result_t insert_result = symbol_table_insert(local_symbols, local_symbol);
            if (insert_result == INSERT_COLLISION) { exit(EXIT_FAILURE); }
          }
        }
      }

      bind_names(local_symbols, node->children[(node->n_children - 1)]);

      // Restore the hashmap
      symbol_hashmap_destroy(local_symbols->hashmap);
      local_symbols->hashmap = prev_hashmap;
      break;
    case IDENTIFIER:
      node->symbol = symbol_hashmap_lookup(local_symbols->hashmap, node->data.identifier);
      break;
    case STRING_LITERAL:
      node->data.string_list_index = add_string(node->data.string_literal);
      node->type = STRING_LIST_REFERENCE;
      break;
    default:
      for (size_t i = 0; i < node->n_children; i++)
      {
        bind_names(local_symbols, node->children[i]);
      }
      break;
  }
  // DONE
  // TODO: Implement bind_names, doing all the things described above
  // Tip: See symbol_hashmap_init() in symbol_table.h, to make new hashmaps for new scopes.
  // Remember the symbol_hashmap_t's backup pointer, forming a linked list of backup hashmaps.
  // Can you use this linked list to implement a stack of hash maps?

  // Tip: Local variables can only be defined in BLOCK nodes.
  // Not all BLOCK nodes define local variables, some only contain a single LIST of statements.
  // Any IDENTIFIER that is not a local variable declaration, must be a symbol usage.

  // Tip: Strings can be added to the string list using add_string(). It returns its index.

  // Note: If an IDENTIFIER has a name that does not correspond to any symbol in the current scope,
  // a parent scope, or in the global symbol table, that is an error.
  // Feel free to print a nice error message and abort.
  // We will not test your compiler on incorrect VSL.
}

// Prints the given symbol table, with sequence number, symbol names and types.
// When printing function symbols, its local symbol table is recursively printed, with indentation.
static void print_symbol_table(symbol_table_t* table, int nesting)
{
  for (size_t i = 0; i < table->n_symbols; i++)
  {
    symbol_t* symbol = table->symbols[i];

    printf(
        "%*s%ld: %s(%s)\n",
        nesting * 4,
        "",
        symbol->sequence_number,
        SYMBOL_TYPE_NAMES[symbol->type],
        symbol->name);

    // If the symbol is a function, print its local symbol table as well
    if (symbol->type == SYMBOL_FUNCTION)
      print_symbol_table(symbol->function_symtable, nesting + 1);
  }
}

// Frees up the memory used by the global symbol table, all local symbol tables, and their symbols
static void destroy_symbol_tables(void)
{
  for (size_t i = 0; i < global_symbols->n_symbols; i++) 
  {
		symbol_t *symbol = global_symbols->symbols[i];
		if (symbol->function_symtable) 
    {
			symbol_table_destroy(symbol->function_symtable);
		}
	}
	symbol_table_destroy(global_symbols);
  // DONE
  // TODO: Implement cleanup. All symbols in the program are owned by exactly one symbol table.

  // TIP: Using symbol_table_destroy() goes a long way, but it only cleans up the given table.
  // Try cleaning up all local symbol tables before cleaning up the global one.
}

// Declaration of global string list
char** string_list;
size_t string_list_len;
static size_t string_list_capacity;

// Adds the given string to the global string list, resizing if needed.
// Takes ownership of the string, and returns its position in the string list.
static size_t add_string(char* string)
{
  size_t index = string_list_len;

	if (!string_list) 
  {
		string_list_capacity = 16;
		string_list = malloc(sizeof(char*) * string_list_capacity);
	}

	// Resize the list when out of capacity
	if (index >= string_list_capacity) 
  {
		string_list_capacity *= 2;
		string_list = realloc(string_list, string_list_capacity);
	}

	// Set the element and update the index
	string_list[index] = string;
	string_list_len++;

  return index;
  // DONE
  // TODO: Write a helper function you can use during bind_names(),
  // to easily add a string into the dynamically growing string_list.

  // The length of the string list should be stored in string_list_len.

  // The variable string_list_capacity should contain the maximum number of char*
  // that can fit in the current string_list before we need to allocate a larger array.
  // If length is about to surpass capacity, create a larger allocation first.
  // Tip: See the realloc function from the standard library

  // Return the position the added string gets in the list.
}

// Prints all strings added to the global string list
static void print_string_list(void)
{
  for (size_t i = 0; i < string_list_len; i++)
    printf("%ld: %s\n", i, string_list[i]);
}

// Frees all strings in the global string list, and the string list itself
static void destroy_string_list(void)
{
  // DONE
  // TODO: Called during cleanup, free strings, and the memory used by the string list itself
	for (size_t i = 0; i < string_list_len; i++) 
  {
		free(string_list[i]);
	}
	free(string_list);
	string_list = NULL;
	string_list_len = 0;
	string_list_capacity = 0;
}
