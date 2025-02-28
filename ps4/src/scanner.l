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

WHITESPACE [ \t\v\r\n]
COMMENT \/\/[^\n]+
QUOTED \"([^\"\n]|\\\")*\"

%%
{WHITESPACE}+           { /* Eliminate whitespace */ }
{COMMENT}               { /* Eliminate comments */ }
func                    { return FUNC; }
print                   { return PRINT; }
return                  { return RETURN; }
break                   { return BREAK; }
if                      { return IF; }
then                    { return THEN; }
else                    { return ELSE; }
while                   { return WHILE; }
do                      { return DO; }
var                     { return VAR; }
[0-9]+                  { return NUMBER_TOKEN; }
[A-Za-z_][0-9A-Za-z_]*  { return IDENTIFIER_TOKEN; }
{QUOTED}                { return STRING_TOKEN; }
  /* Unknown chars get returned as single char tokens */
.                       { return yytext[0]; }
%%
