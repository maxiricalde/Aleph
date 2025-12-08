#include "sym_table.h"
#include <string.h>
#include <stdlib.h>

// La variable global que será la cabeza de nuestra pila
ScopeNode* scope_stack_top = NULL;



unsigned symhash(const char *sym){
 unsigned int hash = 0;
 unsigned c;
 while(c = *sym++) hash = hash*9 ^ c;
 return hash;
}
struct symbol *lookupp(char* sym){
    struct symbol * var=find_symbol_in_scopes(sym);
    if(!var){
       var=add_symbol_to_current_scope(sym);
       
    }
    return var;
}
/*struct symbol *lookupp(char* sym){
 struct symbol *sp = &symtab[symhash(sym)%NHASH];
 int scount = NHASH; // how many have we looked at 
 while(--scount >= 0) {
 if(sp->nom && !strcmp(sp->nom, sym)) { return sp; }
 if(!sp->nom) { // new entry 
 sp->nom = strdup(sym);
sp->valor = 0;

 return sp;
 }
 if(++sp >= symtab+NHASH) sp = symtab; //try the next entry 
 }
 yyerror("symbol table overfloww\n");
 abort(); // tried them all, table is full 
}
*/

// Función para inicializar una nueva tabla de símbolos
static struct symtab* create_new_symbol_table() {
    struct symtab * new_table = (struct symtab*)calloc(NHASH, sizeof(struct symbol));
    if (!new_table) {
        yyerror("out of space");
        exit(1);
    }
    return new_table;
}

// Función para entrar en un nuevo ámbito (push)
void enter_scope() {
    ScopeNode* new_scope = (ScopeNode*)malloc(sizeof(ScopeNode));
    
    if (!new_scope) {
        yyerror("out of space");
        exit(1);
    }
    new_scope->ptr_table = create_new_symbol_table(); // Crea la nueva tabla para este ámbito
    new_scope->next = scope_stack_top;            // El nuevo nodo apunta al anterior
    scope_stack_top = new_scope;                  // El nuevo nodo es ahora la cima de la pila
}

// Función para salir de un ámbito (pop)
void exit_scope() {
    if (scope_stack_top == NULL) {
        yyerror("Error: Intentando salir del ambito global.");
        return;
    }
    ScopeNode* temp = scope_stack_top;             // Guarda el nodo actual
    scope_stack_top = scope_stack_top->next;       // Mueve la cima de la pila al siguiente nodo
    
    // Libera la memoria de la tabla de símbolos
    // NOTA: Si tus símbolos contienen campos que son punteros (como `nom`),
    // debes liberar esa memoria antes.
    free(temp->ptr_table);
    free(temp);
}

// Función para agregar un símbolo SOLO al ámbito actual (la tabla en la cima de la pila)
// Esta función reemplazará la funcionalidad de 'agregar' que tenía tu lookupp original.
struct symbol* add_symbol_to_current_scope(const char* name) {
    if (scope_stack_top == NULL) {
        yyerror("Error: No hay ambito actual para agregar simbolo.");
        return NULL;
    }
    struct symtab* current_table = scope_stack_top->ptr_table;
    unsigned int hash_val = symhash(name) % NHASH;
    int scount = NHASH;
    struct symbol *sp = &(current_table->table[hash_val]);

    // Busca si el símbolo ya existe en el ÁMBITO ACTUAL para evitar redeclaraciones
    while (--scount >= 0) {
        if (sp->nom && !strcmp(sp->nom, name)) {
            yyerror("Error: Redefinicion de variable en el mismo ambito.");
            return NULL;
        }
        if (!sp->nom) {
            // Se encontró un espacio vacío, lo agregamos.
            sp->nom = strdup(name);
            sp->valor=0;
            return sp;
        }
        // Hashing lineal para manejar colisiones
        hash_val = (hash_val + 1) % NHASH;
    }
   
    yyerror("Error: Tabla de simbolos llena.");
    return NULL;
}

// Función para buscar un símbolo en la pila de ámbitos (de arriba hacia abajo)
// Esta función reemplazará la funcionalidad de 'buscar' que tenía tu lookupp original.
struct symbol* find_symbol_in_scopes(const char* name) {
    ScopeNode* current_scope = scope_stack_top;
    while (current_scope != NULL) {
        unsigned int hash_val = symhash(name) % NHASH;
        int scount = NHASH;
        struct symbol *sp = &current_scope->ptr_table->table[hash_val];
        while (--scount >= 0) {
            if (sp->nom && !strcmp(sp->nom, name)) {
                return sp; // Encontrado en este ámbito
            }
            if (!sp->nom) {
                break; // No existe en este ámbito, pasamos al siguiente
            }
            hash_val = (hash_val + 1) % NHASH;
        }
        current_scope = current_scope->next;
    }
    return NULL; // Símbolo no encontrado en ningún ámbito
}


// Función principal para imprimir toda la pila de tablas de símbolos
void print_symbol_tables() {
    ScopeNode* current_scope = scope_stack_top;
    int scope_level = 0;
    
    printf("\n--- Pila de Tablas de Simbolos ---\n");
    
    while (current_scope != NULL) {
        printf("\nAmbito Nivel tope - %d:\n", scope_level);
        printf("---------------------\n");
        
        int found_symbols = 0;
        
        for (int i = 0; i < NHASH; i++) {
            struct symbol* sp = &current_scope->ptr_table->table[i];
            
            if (sp->nom != NULL) {
                printf("  - Simbolo: '%s'\n", sp->nom);
                printf("    Valor: ");
                
                // Si el símbolo tiene un valor (no es una función), imprímelo
                if (sp->tipo != T_FN && sp->valor != NULL) {
                    printData(sp->valor);
                } else if (sp->tipo == T_FN) {
                    printf("<FUNCTION>");
                } else {
                    printf("<sin valor>");
                }
                printf("\n");
                
                found_symbols = 1;
            }
        }
        
        if (!found_symbols) {
            printf("  (Vacio)\n");
        }
        
        current_scope = current_scope->next;
        scope_level++;
    }
    
    printf("\n----------------------------------\n");
}