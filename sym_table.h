#ifndef SYM_TABLE_H
#define SYM_TABLE_H

#include "aleph.h"
#include <stdlib.h> 
#define NHASH 9997
typedef struct symtab {
    struct symbol table[NHASH];
} symtab;
// Definición de un Nodo de la Pila de Tablas de Símbolos
// Cada nodo contiene una tabla de símbolos para un ámbito
typedef struct ScopeNode {
    struct symtab *ptr_table;        // Puntero a la tabla de símbolos de este ámbito
    struct ScopeNode* next;      // Puntero al siguiente nodo en la pila (el ámbito anterior)
} ScopeNode;

// La cabeza de la pila, que actúa como el "top"
extern ScopeNode* scope_stack_top;

// Declaración de las funciones para manejar la pila
void enter_scope();
void exit_scope();

// Declaración de las funciones para manipular símbolos
struct symbol* add_symbol_to_current_scope(const char* name);
struct symbol* find_symbol_in_scopes(const char* name);
struct symbol *lookupp(char* sym);
void print_symbol_tables(void);

#endif // SYM_TABLE_H