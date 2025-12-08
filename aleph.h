
#ifndef ALEPH_H
#define ALEPH_H


#include "include/tData.h"


#define T_ELEM 1
#define T_SET 2
#define T_LIST 3
#define T_BOOL 4

#define LIST_EXPR 5
#define EXPR 6
#define T_UNION 7
#define T_INTER 8
#define T_DIFF 9
#define ID_REF 10
#define T_ASIGN 11
#define LIST_ID 12
#define T_FIRST 13
#define T_ADD 14
#define T_LAST 15
#define T_SIZE 16
#define LIST_STMT 17
#define T_PRINT 18
#define T_INT 19
#define T_EQ 20
#define T_NEQ 21
#define T_MY 22
#define T_MN 23
#define T_MYEQ 24
#define T_MNEQ 25
#define T_BE 26
#define T_SUBSET 27
#define T_IF 28
#define T_WH 29
#define T_FOREACH 30
#define T_FNCALL 31
#define T_FN 32
#define T_RETURN 33
#define T_GET 34
#define T_POP 35
#define T_PUSH 36
#define T_AND 37
#define T_OR 38
#define T_NOT 39
extern int yylineno; 
void yyerror(const char *s); 

struct symbol{
    char* nom;
    tData valor;
    int tipo;
    struct ast *func_body;     /* stmt for the function */
    //struct symlist *syms; /* list of dummy args */
   // struct nomlist *noml;
   struct ast* param_list;
    
};

struct symlist {
  struct symbol *sym;
  struct symlist *next;
 };

struct nomlist {
  int nodeType;
  char* nom_sym;
  struct nomlist *next;
 }; 
struct ufncall {                /* user function */
  int nodeType;                 /* type T_FN */
  struct ast *list_arg;                /* list of arguments */
  struct symbol *nom;
  char* namechar;
 };
 
struct ast{ //estructura de arbol sintactico abstracto, que te dice el tipo de dato nodo y te apunta a su rama izq y der
    int nodeType;
    struct ast *izq;
    struct ast *der;
};
 /* registro */



struct symref {
 int nodeType; /*tipo ID_REF*/
 struct symbol *s;
 char* nameref;
};


struct symasgn {
 int nodeType; /* tipo ASIGN */
 struct symbol *s; /*puntero al registro en tablasim*/
 struct ast *v; /* value */
};

struct flow { 
  int nodeType;                 /* type IF or While */
  struct ast *cond;             /* condition */
  struct ast *body;               /* then branch or do list */
  struct ast *els;               /* optional else branch */
 };
 
struct foreach { 
  int nodeType;                 /* type IF or While */
  struct ast *var;             /* condition */
  struct ast *body;               /* then branch or do list */
  struct ast *coleccion;               /* optional else branch */
 };

struct ast *newasgn(struct symbol* s, struct ast * v);
struct ast *newref(char*);
struct ast *newast(int nodeType, struct ast *izq, struct ast *der);
struct ast* newFlow(int nodeType, struct ast *cond, struct ast *body, struct ast *els);
struct ast* newForeach(int nodeType,struct ast* var, struct ast* coleccion, struct ast* body);
struct ast *newElem(char* cad);
struct ast *newInt(int ent);
struct ast* newBool(int val);

struct symlist *newsymlist(int nodeType,struct symbol *sym, struct symlist *next);
struct ast *newNOML(int nodeType,char *sym, struct nomlist *next);
struct ast* dodef(struct symbol *name, struct ast *params, struct ast *stmts);
struct ast *newcall(char *s, struct ast *l); //crea una llamada;
tData eval( struct ast* a);
struct symbol* lookupp(char* );

void printref(struct symref *s);

#endif