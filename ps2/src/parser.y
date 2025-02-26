%{
#include "vslc.h"

// State variables from the flex generated scanner
extern int yylineno;  // The line currently being read
extern char yytext[]; // The text of the last consumed lexeme

// The main flex driver function used by the parser
int yylex(void);

// The function called by the parser when errors occur
int yyerror(const char *error)
{
  fprintf(stderr, "%s on line %d\n", error, yylineno);
  exit(EXIT_FAILURE);
}

// Feel free to define #define macros if you want to
#define MKNODE0(type) node_create((type), 0)

#define MKNODE1(type, c1) node_create((type), 1, (c1))

#define MKNODE2(type, c1, c2) node_create((type), 2, (c1), (c2))

#define MKNODE3(type, c1, c2, c3) node_create((type), 3, (c1), (c2), (c3))

#define LIST_ADD(list, node) append_to_list_node(list, node)

%}

%token FUNC PRINT RETURN BREAK IF THEN ELSE WHILE DO VAR
%token NUMBER_TOKEN IDENTIFIER_TOKEN STRING_TOKEN

// Use operator precedence to ensure order of operations is correct
%left '=' '!'
%left '<' '>'
%left '+' '-'
%left '*' '/'
%right UNARY_OPERATORS

// Resolve the nested if-if-else ambiguity with precedence
%nonassoc IF THEN
%nonassoc ELSE

%%
program :
      global_list { root = $1; }
    ;
global_list :
      global { $$ = MKNODE1(LIST, $1); }
    | global_list global { $$ = LIST_ADD($1, $2); }
    ;
global :
      function { $$ = $1; }
    | global_declaration { $$ = $1; }
    ;
global_declaration :
      VAR global_variable_list { $$ = MKNODE1(GLOBAL_DECLARATION, $2); }
    ;
global_variable_list :
      global_variable { $$ = MKNODE1(LIST, $1); }
    | global_variable_list ',' global_variable { $$ = LIST_ADD($1, $3); }
    ;
global_variable :
      identifier { $$ = $1; }
    | array_indexing { $$ = $1; }
    ;
array_indexing :
      identifier '[' expression ']' { $$ = MKNODE2(ARRAY_INDEXING, $1, $3); }
    ;
variable_list :
      identifier { $$ = MKNODE1(LIST, $1); }
    | variable_list ',' identifier { $$ = LIST_ADD($1, $3); }
    ;
local_declaration :
      VAR variable_list { $$ = $2; }
    ;
local_declaration_list :
      local_declaration { $$ = MKNODE1(LIST, $1); }
    | local_declaration_list local_declaration { $$ = LIST_ADD($1, $2); }
    ;
parameter_list :
      variable_list { $$ = $1; }
    | { $$ = MKNODE0(LIST); } 
    ;
function :
      FUNC identifier '(' parameter_list ')' statement { $$ = MKNODE3(FUNCTION, $2, $4, $6); }
    ;
statement :
      assignment_statement { $$ = $1; } 
    | return_statement     { $$ = $1; }
    | print_statement      { $$ = $1; }
    | if_statement         { $$ = $1; }
    | while_statement      { $$ = $1; }
    | break_statement      { $$ = $1; }
    | function_call        { $$ = $1; }
    | block                { $$ = $1; }
    ;
block :
      '{' local_declaration_list statement_list '}' { $$ = MKNODE2(BLOCK, $2, $3); }
    | '{' statement_list '}' { $$ = MKNODE1(BLOCK, $2); }
    ;
statement_list :
      statement { $$ = MKNODE1(LIST, $1); }
    | statement_list statement { $$ = LIST_ADD($1, $2); }
    ;
assignment_statement :
      identifier '=' expression     { $$ = MKNODE2(ASSIGNMENT_STATEMENT, $1, $3); }
    | array_indexing '=' expression { $$ = MKNODE2(ASSIGNMENT_STATEMENT, $1, $3); }
    ;
return_statement :
      RETURN expression { $$ = MKNODE1(RETURN_STATEMENT, $2); }
    ;
print_statement :
      PRINT print_list { $$ = MKNODE1(PRINT_STATEMENT, $2); }
    ;
print_list :
      print_item { $$ = MKNODE1(LIST, $1); }
    | print_list ',' print_item { $$ = LIST_ADD($1, $3); }
    ;
print_item :
      expression { $$ = $1; }
    | string     { $$ = $1; }
    ;
break_statement :
      BREAK { $$ = MKNODE0(BREAK_STATEMENT); } 
    ;
if_statement :
      IF expression THEN statement { $$ = MKNODE2(IF_STATEMENT, $2, $4); } 
    | IF expression THEN statement ELSE statement { $$ = MKNODE3(IF_STATEMENT, $2, $4, $6); } 
    ;
while_statement :
      WHILE expression DO statement { $$ = MKNODE2(WHILE_STATEMENT, $2, $4); }
    ;
expression :
      expression '=' '=' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $4);
          $$->data.operator = "==";
        }
    | expression '!' '=' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $4);
          $$->data.operator = "!=";
        }
    | expression '<' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $3);
          $$->data.operator = "<";
        }
    | expression '<' '=' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $4);
          $$->data.operator = "<=";
        }
    | expression '>' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $3);
          $$->data.operator = ">";
        }
    | expression '>' '=' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $4);
          $$->data.operator = ">=";
        }
    | expression '+' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $3);
          $$->data.operator = "+";
        }
    | expression '-' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $3);
          $$->data.operator = "-";
        }
    | expression '*' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $3);
          $$->data.operator = "*";
        }
    | expression '/' expression
        {
          $$ = MKNODE2(OPERATOR, $1, $3);
          $$->data.operator = "/";
        }
    | '-' expression %prec UNARY_OPERATORS
        {
          $$ = MKNODE1(OPERATOR, $2);
          $$->data.operator = "-";
        }
    | '!' expression %prec UNARY_OPERATORS
        {
          $$ = MKNODE1(OPERATOR, $2);
          $$->data.operator = "!";
        }
    | '(' expression ')' 
        {
          $$ = $2;
        }
    | number
        {
          $$ = $1;
        }
    | identifier
        {
          $$ = $1;
        }
    | array_indexing
        {
          $$ = $1;
        }
    | function_call
        {
          $$ = $1;
        }
    ;
function_call :
      identifier '(' argument_list ')' { $$ = MKNODE2(FUNCTION_CALL, $1, $3); }
    ;
argument_list :
      expression_list { $$ = $1; }
    | { $$ = MKNODE0(LIST); } 
    ;
expression_list :
      expression { $$ = MKNODE1(LIST, $1); }
    | expression_list ',' expression { $$ = LIST_ADD($1, $3); } 
    ;
identifier :
      IDENTIFIER_TOKEN
        {
          $$ = MKNODE0(IDENTIFIER);
          // Allocate a copy of yytext to keep in the syntax tree as data
          $$->data.identifier = strdup(yytext);
        }
    ;
number :
      NUMBER_TOKEN
        {
          $$ = MKNODE0(NUMBER_LITERAL);
          $$->data.number_literal = strtol(yytext, NULL, 10);
        }
    ;
string :
      STRING_TOKEN
        {
          $$ = MKNODE0(STRING_LITERAL);
          $$->data.string_literal = strdup(yytext);
        }
    ;
%%

