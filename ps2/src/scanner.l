%{
#include "vslc.h"

// The tokens defined in parser.y
#include "parser.h"

// parser.h contains some unused functions, ignore that
#pragma GCC diagnostic ignored "-Wunused-function"
%}

%option noyywrap
%option array
%option yylineno

WHITESPACE [ \t\n\r\v]
COMMENT \/\/[^\n]+
QUOTED \"([^\"\n]|\\\")*\"
NUMBER [0-9]+
IDENTIFIER [A-Za-z_][A-Za-z0-9_]*

%%
{WHITESPACE}+           { /* Eliminate whitespace */ }
{COMMENT}               { /* Eliminate comments */ }
{QUOTED}                { return STRING_TOKEN; }

func                    { return FUNC; }
var                     { return VAR; }
return                  { return RETURN; }
print                   { return PRINT; }
if                      { return IF; }
then                    { return THEN; }
else                    { return ELSE; }
while                   { return WHILE; }
do                      { return DO; }
break                   { return BREAK; }

{NUMBER}                { return NUMBER_TOKEN; }
{IDENTIFIER}            { return IDENTIFIER_TOKEN; }

  /* All other chars get returned as single char tokens */
.                       { return yytext[0]; }
%%
