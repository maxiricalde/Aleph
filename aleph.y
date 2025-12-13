%{
#include <stdio.h>
#include "aleph.h"
#include "tData.h"
#include "sym_table.h"

extern int yylex();
extern void yyrestart();
extern FILE * yyin;
extern int yylex_destroy(void);
tData rta;

%}
%debug

%union{
        struct ast *t;
        char* c;
        int i;
        struct symbol* s;
       // struct symlist *sl;
        struct nomlist *nl;
}


%token DEF RETURN PRINT WHILE FOREACH IF ELSE OP_UNION OP_INTER OP_DIFF OP_GET OP_POP OP_PUSH OP_ADD OP_FIRST OP_LAST OP_SIZE   B_AND B_NOT B_OR EQ NEQ MYEQ MNEQ MY MN ASSIGN OP_IN  BELONG SUBSET OPENLL CLOSELL OPENPAR CLOSEPAR OPENCOR CLOSECOR SEMI  COMMA
%token <c>ELEM IDEN
%token <i>NUMBER BOOL_T BOOL_F

%token EOFF
%type <t>symlist program  body stmt lista_stmt lista_expr expr if while for_each set list expr_log  asig_mult  expr_relacionales



%left B_OR
%left B_AND
%nonassoc B_NOT
%nonassoc EQ NEQ MYEQ MNEQ MY MN BELONG SUBSET
%left OP_UNION OP_DIFF OP_INTER
%left OP_ADD OP_PUSH
%left OP_FIRST OP_LAST OP_SIZE OP_POP OP_GET
 %left '+' '-'
 %left '*' '/'
%start program
%%



       
program:  { 
           printf("\n>");
          } 
|body    {rta=eval($1); print_symbol_tables();
        freeast($1);
           if(rta){
                        printf("\n>>"); 
                      //  printData(rta);     
                }
                //printf("\n>");
                //treefree($2);
                //freeAST($2);
                dataFree(&rta);
        
                }

                ;
body: stmt eol body {$$=newast(LIST_STMT,$1,$3);}
    | stmt eol {$$=newast(LIST_STMT,$1,NULL);};
eol: SEMI;

//bloque: OPENLL body CLOSELL ;
stmt: expr
|RETURN expr                 {$$=newast(T_RETURN,$2,NULL);}
|PRINT OPENPAR expr CLOSEPAR {$$=newast(T_PRINT,$3,NULL);}
| asig_mult
| if
| while
|for_each
| DEF IDEN OPENPAR symlist CLOSEPAR OPENLL lista_stmt CLOSELL{$$=dodef(add_symbol_to_current_scope($2),$4,$7);
                                                                free($2);
                                                                printf("\nDefinida>");}
                                                                
    //| asig_let  
;


asig_mult: symlist ASSIGN lista_expr {$$=newast(T_ASIGN,$1,$3);} ;
//asig_let: LET IDEN ASSIGN OPENPAR list_var CLOSEPAR ;

if: IF OPENPAR expr CLOSEPAR OPENLL lista_stmt CLOSELL { $$ = newFlow(T_IF, $3, $6, NULL); }
| IF OPENPAR expr CLOSEPAR OPENLL lista_stmt CLOSELL ELSE OPENLL lista_stmt CLOSELL{ $$ = newFlow(T_IF, $3, $6,$10 ); }
;
while: WHILE OPENPAR expr CLOSEPAR  OPENLL lista_stmt CLOSELL { $$ = newFlow(T_WH, $3, $6, NULL); }
;
for_each:FOREACH IDEN OP_IN expr OPENLL lista_stmt CLOSELL {$$=newForeach(T_FOREACH,newref($2),$4,$6);}
;
lista_stmt:stmt  SEMI lista_stmt       {$$=newast(LIST_STMT,$1,$3);}
         | stmt  SEMI                      {$$=newast(LIST_STMT,$1,NULL);};

lista_expr:expr  COMMA lista_expr       {$$=newast(LIST_EXPR,$1,$3);}
         | expr                         {$$=newast(LIST_EXPR,$1,NULL);};
/*
list_var: IDEN COMMA list_var           {$$=newast(LIST_ID,(struct ast*)lookupp($1),$3);}
        |IDEN                           {$$=newast(LIST_ID,(struct ast*)lookupp($1),NULL);}*/

symlist: IDEN COMMA symlist             {$$=newNOML(LIST_ID,$1,(struct nomlist*)$3);}
        | IDEN                          {$$=newNOML(LIST_ID,$1,NULL);};

expr: ELEM              {$$=newElem($1);}  //no es este \"[a-zA-Z0-9]+\" {yylval.c=strdup(yytext); return ELEM;}
    | IDEN              {$$=newref($1);}
    | NUMBER            {$$=newInt($1);}
    |BOOL_F             {$$=newBool(0);}
    |BOOL_T             {$$=newBool(1);}
    |expr OP_UNION expr {$$=newast(T_UNION,$1,$3);}
    |expr OP_INTER expr {$$=newast(T_INTER,$1,$3);}
    |expr OP_DIFF expr  {$$=newast(T_DIFF,$1,$3);}
    |OPENPAR expr CLOSEPAR {$$=$2;}
    | OP_FIRST expr {$$=newast(T_FIRST,$2,NULL);}
    | OP_LAST expr {$$=newast(T_LAST,$2,NULL);}
    | expr OP_ADD expr {$$=newast(T_ADD,$1,$3);}
    |list
    |set
    | expr '+' expr          { $$ = newast('+', $1,$3); }
    | expr '-' expr          { $$ = newast('-', $1,$3);}
    | expr '*' expr          { $$ = newast('*', $1,$3); }
    | expr '/' expr          { $$ = newast('/', $1,$3); }
    |expr_relacionales {$$=$1;} 
    |expr_log {$$=$1;}      
    |OP_SIZE expr {$$=newast(T_SIZE,$2,NULL);} 
    |OP_GET expr OPENCOR expr CLOSECOR  {$$=newast(T_GET,$2,$4);} //agregado
    |OP_POP expr  {$$=newast(T_POP,$2,NULL);} 
    |expr OP_PUSH expr {$$=newast(T_PUSH,$1,$3);} 
    |IDEN OPENPAR lista_expr CLOSEPAR {$$=newcall($1,$3);}
    ;
expr_relacionales: expr EQ expr      {$$ = newast(T_EQ, $1, $3);}
                 | expr NEQ expr     {$$ = newast(T_NEQ, $1, $3);}
                 | expr MY expr      {$$ = newast(T_MY, $1, $3);}
                 | expr MN expr      {$$ = newast(T_MN, $1, $3);}
                 | expr MYEQ expr    {$$ = newast(T_MYEQ, $1, $3);}
                 | expr MNEQ expr    {$$ = newast(T_MNEQ, $1, $3);}
                 | expr BELONG expr  {$$ = newast(T_BE, $1, $3);} 
                 | expr SUBSET expr  {$$ = newast(T_SUBSET, $1, $3);} 
                 ;
expr_log: expr B_AND expr {$$ = newast(T_AND, $1, $3);}
        |B_NOT expr {$$ = newast(T_NOT,$2,NULL);}
        |expr B_OR expr {$$ = newast(T_OR, $1, $3);}
;

set: OPENLL lista_expr CLOSELL {$$=newast(T_SET,$2,NULL);}
| OPENLL CLOSELL {$$=newast(T_SET,NULL,NULL);}
;
list: OPENCOR lista_expr CLOSECOR {$$=newast(T_LIST,$2,NULL);}
 | OPENCOR CLOSECOR {$$=newast(T_LIST,NULL,NULL);}
;


/*
expr_logicas: factor_log 
        |expr_logicas OR factor_log;

factor_log:term_log 
        |factor_log AND term_log;
       

term_log: 
        |expr_log_fin
        |NOT term_log;
 */

%%

int main(int argc, char** argv) {
if(argc<2){ // leemos de stdin
        printf("aleph");
        
        yyparse();
        exit_scope();
        yylex_destroy();
        return 0; //corto aca
}
for(int i=1; i<argc;i++){
        FILE* f= fopen(argv[i],"r");
        if(!f){
                perror(argv[i]); //indica wue hubo un error al abrir el archivo
                return(1);
        }
        yyrestart(f);
        printf("aleph");
        printf(">");
        enter_scope();
        while(!feof(yyin)){
           yyparse();
        }
        exit_scope();
        fclose(f);    
}
yylex_destroy();
return 0;
}
extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "Error: %s en la linea %d\n ", s,yylineno);
}

int yylex(void);



