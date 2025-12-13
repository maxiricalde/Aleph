%{
#include <stdio.h>
#include "aleph.h"
#include <string.h>
#include  "aleph.tab.h"
#include <stdlib.h> 
#include "sym_table.h"
//int yylineno = 1; // Declara la variable para el número de línea
%}

/*%option noyywrap*/
%%
"+" |
"-" |
"*" |
"/" { return yytext[0]; }
"=" {return ASSIGN;}
"return" {return RETURN;}
"/get" {return OP_GET;}
"/pop" {return OP_POP;}
"/push" {return OP_PUSH;}
"while" { return WHILE;}
"foreach" { return FOREACH;}
"def" {return DEF;}
"in" {return OP_IN;}
"if" { return IF;}
"else" { return ELSE;}
"&&" {return B_AND;}
"||" {return B_OR;}
"!" {return B_NOT;}
"==" {return EQ;}
"!=" {return NEQ;}
"<=" {return MNEQ;}
">=" {return MYEQ;}
">" {return MY;}
"<" {return MN;}
"true" { return BOOL_T;}
"false" { return BOOL_F;}
"/U" { return OP_UNION;}
"/u" { return OP_UNION;}
"/I" { return OP_INTER;}
"/i" { return OP_INTER;}
"/DIF" { return OP_DIFF;}
"/dif" { return OP_DIFF;}
"/FIRST" { return OP_FIRST;}
"/first" {return OP_FIRST;}
"/ADD" { return OP_ADD;}
"/add" {return OP_ADD;}
"/LAST" { return OP_LAST;}
"/last" {return OP_LAST;}
"/SIZE" { return OP_SIZE;}
"/size" {return OP_SIZE;}
"{" {return OPENLL;}
"}" {return CLOSELL;}
"(" {return OPENPAR;}
")" {return CLOSEPAR;}
"[" {return OPENCOR;}
"]" {return CLOSECOR;}
";" {return SEMI;}
"," {return COMMA;}
"/in" {return BELONG;}
"/include" {return SUBSET;}
"/print" {return PRINT;}
\"[^\"\n]*\" {yylval.c=strdup(yytext); return ELEM;} 
[a-zA-Z][a-zA-Z0-9_]* {yylval.c=strdup(yytext);return IDEN;} // yylval.c=strdup(yytext); return IDEN
[0-9]+ {yylval.i=atoi(yytext); return NUMBER;}
\n { yylineno++; }
[ \t]+    // Ignora espacios, tabulaciones y saltos de línea

<<EOF>> {return 0;}
%%
int yywrap() {
    return 1; // Indica a Flex que no hay más entradas que procesar
}
