#include "aleph.h"
#include <stdlib.h>
#include <string.h>
#include "sym_table.h"
int RETURN_STATE=0;
tData RETURN_VAL=NULL;
int tipoRaiz;
char* error="\0";

struct ast * newast(int nodeType, struct ast *izq, struct ast *der){
 struct ast* a = malloc(sizeof(struct ast));
    if(!a) {
    yyerror("out of space");
    exit(0);
    }
 a->nodeType = nodeType;
 a->izq = izq;
 a->der = der;
 return a;

}

struct ast * newElem(char* cad){
 tData a = malloc(sizeof(struct dataType));
if(!a) {
 yyerror("out of space");
 exit(0);
 }
 a->nodeType = T_ELEM;
 a->atom =strdup(cad);
 return (struct ast *)a;
}

struct ast * newInt(int val) {
    tData a = malloc(sizeof(struct dataType));
    if(!a) {
        yyerror("out of space");
        exit(0);
    }
    a->nodeType = T_INT;
    a->ivalor = val;
    return (struct ast *)a;
}

struct ast* newBool(int val) {
    tData a = malloc(sizeof(struct dataType));
    if(!a) {
        yyerror("out of space");
        exit(0);
    }
    a->nodeType = T_BOOL;
    a->bool= val;
    return (struct ast*)a;
}

struct ast* newref(char* sym){   //no le asigna un espacio en tabla de simbolos
    struct symref* a=malloc(sizeof(struct  symref));
    if(!a){
        yyerror("out ofspace");
        exit (0);
    }
    a->nodeType=ID_REF;
    a->nameref=sym;
    return (struct ast*)a;
} 

struct ast *newasgn(struct symbol *s, struct ast *v){
struct symasgn *a = malloc(sizeof(struct symasgn));
 if(!a) {
 yyerror("out of space");
 exit(0);
 }
 a->nodeType = T_ASIGN;
 a->s = s;
 a->v = v;
 return (struct ast *)a;
}

struct ast* newFlow(int nodeType, struct ast *cond, struct ast *body, struct ast *els){
struct flow *a = malloc(sizeof(struct flow));
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodeType = nodeType;
  a->cond = cond;
  a->body = body;
  a->els = els;
  return (struct ast *)a;
};

struct ast* newForeach(int nodeType,struct ast* var, struct ast* coleccion, struct ast* body){
struct foreach *a = malloc(sizeof(struct foreach));
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodeType = nodeType;
  a->var = var;
  a->body = body;
  a->coleccion = coleccion;
  return (struct ast *)a;  
}

/*struct ast*dodef(struct symbol *name, struct ast*params, struct ast *stmts){
    /*struct symref* a=malloc(sizeof(struct  symref)); 
    if(!a){
        yyerror("out ofspace");
        exit (0);
    }
    a->nodeType=ID_REF; // tambien existe T_FN revisar si sera necesario. 
    a->s=name;
    a->s->valor=0;
    name->syms = syms; //buscar de tener ya sea el ambito o que sea un ast a evaluar
    name->func_body= stmts; 
    return (struct ast*)a;
   if(name->syms) symlistfree(name->syms);
  if(name->func_body) treefree(name->func_body);
}*/
// Cambia la firma de la función para recibir un 'struct ast*' para los parámetros
struct ast* dodef(struct symbol *name, struct ast *params, struct ast *stmts){
    struct symref* a = malloc(sizeof(struct symref));
    if(!a){
        yyerror("out ofspace");
        exit (0);
    }
    a->nodeType=ID_REF;
    a->s=name;
    a->nameref=name->nom;
    a->s->valor=0;

    // Almacena el AST de la lista de parámetros directamente en el símbolo de la función
    name->param_list = params;
    name->func_body = stmts;
    return (struct ast*)a;
}


struct ast *newcall(char*s, struct ast *list_arg){
    struct ufncall *a = malloc(sizeof(struct ufncall));
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  
  a->nodeType =T_FNCALL;
  a->list_arg = list_arg;
  a->namechar = s;
  return (struct ast *)a;
} //crea una llamada;
tData eval_stmt(struct ast* izq ,struct ast* der);

/*tData eval_calluser(struct symbol *s ,tData actual_args){ //debo evaluar list_expr y pasarle a esta fn
//s tiene nombre y el cuerpo de la funcion;
tData result=NULL;
//iniciar nuevo scope
enter_scope();
printf("tabla dentro de eval_call");
print_symbol_tables();
 // Ahora iteramos sobre el AST de la lista de parámetros
    struct ast *param_node = s->param_list;
    tData current_arg = actual_args;

    while (param_node != NULL && current_arg != NULL) {
        // Obtenemos el símbolo (desde el ID_REF)
        struct symbol *formal_sym = ((struct symref*)param_node->izq)->s;
        
        printf(" cadena%s",formal_sym->nom);
        // Y creamos un nuevo símbolo local con su nombre
        struct symbol *local_sym = add_symbol_to_current_scope(formal_sym->nom);
       
        if (local_sym) {
            local_sym->valor = current_arg->data;
            local_sym->tipo = current_arg->data->nodeType;
        } else {
            yyerror("Error: No se pudo crear el símbolo local para el parámetro");
        }
        
        param_node = param_node->der;
        current_arg = current_arg->next;
    }
    
    if (s->func_body != NULL) {
        result = eval_stmt(s->func_body->izq, s->func_body->der);
    } else {
        result = newNodo(T_ELEM);
    }
    
    exit_scope();
 
    return result;
}*/
tData eval_calluser(char*sp, tData actual_args) {
    tData result = NULL;
    // 1. Entrar en un nuevo ámbito para la llamada a la función.
    enter_scope();
    struct symbol* s= find_symbol_in_scopes(sp);
    if(s!=NULL){
    // El puntero al inicio de la lista de nombres
    struct nomlist* formal_param_names = (struct nomlist*)s->param_list;
    tData current_arg = actual_args;
    // 2. Iterar sobre la lista de nombres de los parámetros formales
    // y asignarles los valores de los argumentos reales.
    while (formal_param_names != NULL && current_arg != NULL) {
        
        // Obtener el nombre del parámetro formal de la lista.
        char* param_name = formal_param_names->nom_sym;
        // Crear un nuevo símbolo con ese nombre en el ÁMBITO LOCAL actual.
        
        struct symbol *local_sym = add_symbol_to_current_scope(param_name);        
        if (local_sym) {
            // Asignar el valor del argumento real a la nueva variable local.
            local_sym->valor = current_arg->data;
            local_sym->tipo = current_arg->data->nodeType;
        } else {
            // Manejar error si la creación del símbolo falla.
            yyerror("Error: No se pudo crear el s├¡mbolo local para el par├ímetro");
        }
        
        // Moverse al siguiente parámetro formal y al siguiente argumento.
        formal_param_names = formal_param_names->next;
        current_arg = current_arg->next;
    }
    // 3. Evaluar el cuerpo de la función.
    if (s->func_body != NULL) {
        // La evaluación ahora usará las variables locales recién creadas.
        result = eval(s->func_body);
        if(RETURN_STATE==1){
            result=RETURN_VAL;
            s->valor=copyData(result);
        }else
            s->valor=newNodo(1);
    } else {
        result = newNodo(T_ELEM);
    }
    // 4. Salir del ámbito de la función.
    exit_scope();
    RETURN_STATE=0; 
    return ((tData)s->valor);
    }
    else return 0;   
}
   

struct symlist *newsymlist(int noteType,struct symbol *sym, struct symlist *next){
     struct symlist *sl = malloc(sizeof(struct symlist));
    if(!sl) {
    yyerror("out of space");
    exit(0);
     }
  sl->sym = sym;
  sl->next = next;
  return sl;
}
struct ast *newNOML(int nodeType,char *sym, struct nomlist *next){
     struct nomlist *noml = malloc(sizeof(struct nomlist));
    if(!noml) {
    yyerror("out of space");
    exit(0);
    }
    noml->nodeType=nodeType;
    noml->nom_sym = sym;
    noml->next = next;
  return (struct ast*)noml;
}

void printref(struct symref *ref){
    struct symbol*sp=find_symbol_in_scopes((ref)->nameref);
    if(sp!=NULL){
       if(sp->valor){
        printf("%s:",sp->nom);
         printData(sp->valor);
    }
    else{
        printf("variable vacia");
    } 
    }else yyerror("Error: Variable no encontrada en ningun ambito.");
}


void eval_asign(struct ast *s, struct ast *v){ //a,b=1,2/
    if(s && v){ 
        tData aux=eval(v->izq);
       
       // printf("cadena dentro eval asig: %s",((struct symbol*)aux)->nom);
        struct symbol* sp= lookupp(((struct nomlist*)s)->nom_sym);
        if(v->izq->nodeType==T_FNCALL){
             //struct symbol* auxsym= find_symbol_in_scopes(((struct symbol*)aux)->nom);
             //printf("cadena dentro eval asig: %s",((struct symbol*)aux)->nom );
            sp->valor=aux;
        }
        else{
            (sp)->valor=aux;
            (sp)->tipo=aux->nodeType;
        }
        if(s->der&&v->der)
            eval_asign((struct ast*)(((struct nomlist*)s)->next),v->der);
    }else{
        if(!(!s&&!v))//{
            yyerror("asignacion desvalanceada");
        //}else  printf("terminado");
    }

}

tData eval_stmt(struct ast *a, struct ast *b){
    tData nodo=NULL;
    // Primero, evaluamos el primer nodo de la lista de sentencias (el 'izq')
    if (a != NULL) {
        nodo = eval(a);
    } else {
        // Si el nodo es nulo, la lista está vacía, no hay nada que evaluar.
        return NULL;
    }

    // Luego, verificamos si hay más sentencias en la lista (el 'der')
    if (b != NULL) {
        // Si hay más, llamamos recursivamente a eval_stmt para el resto de la lista.
        // Asegúrate de que este llamado no intente acceder a un puntero nulo.
        return eval_stmt(b->izq, b->der);
    } else {
        // Si no hay más sentencias, devolvemos el resultado de la última evaluación.
        return nodo;
    }
}

/*tData eval_stmt(struct ast* izq ,struct ast* der){
    tData nodo=eval(izq);
    
    if(der){
        printf("otra rama de stmt");
        eval_stmt(der->izq,der->der);
    }
    return nodo;
}*/
int verificaTipo(struct ast*izq ){
    if(izq->nodeType==ID_REF && ((struct symref*)izq)->s->tipo==T_SET ){
        return 1;
    }else
    if(izq->nodeType==ID_REF && ((struct symref*)izq)->s->tipo==T_LIST)
        return 2;
    else if(izq->nodeType==T_SET)
        return 3;
    else if(izq->nodeType==T_LIST)
        return 4;
        else return -1;
    
    
    
}
int comparar(int tipo, struct ast* izq,struct ast* der){
        if(izq->nodeType==ID_REF && ((struct symref*)izq)->s->tipo==tipo){
                    if(der->nodeType==ID_REF && ((struct symref*)der)->s->tipo==tipo){  //ID_REF && ID_REF
                       return 1;


                    }else{     //ID_REF && tipo 
                        if(der->nodeType==tipo ){
                            return 2;
                        }else {
                            yyerror("tipo invalido para operar 1");
                            return 0;
                        }
                    }
                    
                }else {   
                    if(izq->nodeType==tipo){  
                        if(der->nodeType==tipo){   //tipo&&tipo
                            return 3;   
                        }else{   //tipo&&tipo
                            if(der->nodeType==ID_REF && ((struct symref*)der)->s->tipo==tipo){
                                return 4;
                            }else {
                                yyerror("tipo invalido para operar 2");
                                return 0;
                            }
                            
                        }
                    }else {
                        yyerror("tipo invalido para operar 3");
                        return 0;
                    }
                }
    }

tData eval( struct ast* a){
    tData nodo=malloc(sizeof(struct dataType));
    if(RETURN_STATE!=1){        
    tData aux2=inicializar();
    tData aux1=inicializar();
    if(!a){
        yyerror("memoria mal asignada");
        return 0;
    }
   nodo=inicializar();
   int r;
        switch (a->nodeType){
          
            case T_ELEM:
                nodo->nodeType=T_ELEM;
                nodo=(tData)a;
            break;
            case T_INT:
                nodo->nodeType=T_INT;
                nodo = (tData)a;
            break;
            case T_BOOL:
                nodo->nodeType=T_BOOL;
                nodo = (tData)a;
            break;
            case T_LIST:
                tipoRaiz=T_LIST;
                nodo->nodeType=tipoRaiz;
               if(a->izq==NULL && a->der==NULL){
                nodo->data=NULL;
                nodo->next=NULL;
                }
                else{
                nodo=eval(a->izq);
                }
            break;
            case T_SET:
                tipoRaiz =T_SET;
                nodo->nodeType=tipoRaiz;
                if(a->izq==NULL && a->der==NULL){
                nodo->data=NULL;
                nodo->next=NULL;
                }
                else{
                nodo=eval(a->izq);
                }
            break;
            case LIST_EXPR:  
                    nodo->nodeType=tipoRaiz; 
                    nodo->data= eval(a->izq);
                    if(a->der){
                    nodo->next= eval(a->der) ;  
                    }

                                  
            break;
            case T_ASIGN:
            eval_asign(a->izq,a->der);
            nodo=newNodo(T_ELEM);
            break;
            case T_UNION:
                    aux1=eval(a->izq);
                    aux2=eval(a->der);
                    if(aux1->nodeType==T_SET&&aux2->nodeType==T_SET){
                        nodo=UNION(aux1,aux2);
                    }
                    else {
                        error=strdup("operandos de distinto tipo");
                        nodo=newNodo(T_ELEM);
                    }
                break;
            case T_INTER:
                    aux1=eval(a->izq);
                    aux2=eval(a->der);
                    if(aux1->nodeType==T_SET&&aux2->nodeType==T_SET){
                        nodo=INTER(aux1,aux2);
                    }
                    else {
                        error=strdup("operandos de distinto tipo");
                        nodo=newNodo(T_ELEM);
                    }
                break;  
            case T_DIFF:
                aux1=eval(a->izq);
                aux2=eval(a->der);
                    if(aux1->nodeType==T_SET&&aux2->nodeType==T_SET){
                        nodo=DIFF(aux1,aux2);
                    }
                    else {
                        error=strdup("operandos de distinto tipo");
                        nodo=newNodo(1);
                    }
                break;  
            case T_FIRST:
                aux1=eval(a->izq);
                if(aux1->nodeType==T_SET|| aux1->nodeType==T_LIST){
                    nodo=FIRST(aux1);
                }else{
                        error=strdup("tipo de operando distinto de conj o lista ");
                        nodo=newNodo(T_ELEM);
                    }     
            break;
            case T_POP:
                     aux1=eval(a->izq);
                    if(aux1->nodeType==T_LIST){
                        nodo=POP(&aux1);
                    }
                    else {
                        error=strdup("operando de tipo invalido");
                        nodo=newNodo(T_ELEM);
                    }
            break; 
            case T_PUSH:
                    aux1=eval(a->izq); //elemto a agregar
                    aux2=eval(a->der);// lista
                    if(aux2->nodeType==T_LIST){
                        PUSH(aux2,aux1);
                        nodo=newNodo(T_ELEM);
                    }
                    else {
                        error=strdup("operando de tipo invalido");
                        nodo=newNodo(T_ELEM);
                    }
            break; 
            case T_ADD:
              aux1=eval(a->der);
              aux2=eval(a->izq);
                if(aux1->nodeType==T_SET|| aux1->nodeType==T_LIST){
                    nodo=ADD_INI(aux2,&aux1);
                    if((a->der)->nodeType==ID_REF){
                        struct symbol* s=find_symbol_in_scopes(((struct symref*)(a->der))->nameref);
                        s->valor=nodo;
                    }
                        
                }else{
                        error=strdup("tipo de operando distinto de conj o lista ");
                        nodo=newNodo(T_ELEM);
                    }
            break;
            case T_LAST:
              aux1=eval(a->izq);
                if(aux1->nodeType==T_SET|| aux1->nodeType==T_LIST){
                    nodo=LAST(aux1);
                }else{
                        error=strdup("tipo de operando distinto de conj o lista ");
                        nodo=newNodo(T_ELEM);
                    }
            break; 
            case T_GET:
                    aux1=eval(a->izq);
                    aux2=eval(a->der);
                if((aux1->nodeType==T_SET|| aux1->nodeType==T_LIST) && aux2->nodeType==T_INT){
                    nodo=returnElem(aux1,aux2->ivalor);
                }else{
                        error=strdup("tipo de operando distinto de conj o lista ");
                        nodo=newNodo(T_ELEM);
                    }
            break;
            case T_SIZE:{
                char aux[10];
                nodo=newNodo(T_INT);
                aux1=eval(a->izq);
                if(aux1->nodeType==T_SET){
                    nodo->ivalor= CARDINAL(aux1);
                }else{
                    if( aux1->nodeType==T_LIST){
                        nodo->ivalor= SIZEL(aux1);
                    }else{
                     error=strdup("tipo de operando distinto de conj o lista ");
                     
                    }
                }  
            break;
             }
             case '+':
             nodo->nodeType=T_INT;
             aux1=eval(a->izq);
             aux2=eval(a->der);
             if(aux1->nodeType==T_INT && aux2->nodeType==T_INT)
               nodo->ivalor=(aux1->ivalor + aux2->ivalor); break;
            
            case '-':
             nodo->nodeType=T_INT;
             aux1=eval(a->izq);
             aux2=eval(a->der);
             if(aux1->nodeType==T_INT && aux2->nodeType==T_INT)
               nodo->ivalor=(aux1->ivalor - aux2->ivalor); break;
            case '*':
             nodo->nodeType=T_INT;
             aux1=eval(a->izq);
             aux2=eval(a->der);
             if(aux1->nodeType==T_INT && aux2->nodeType==T_INT)
               nodo->ivalor=(aux1->ivalor * aux2->ivalor); break;
            case '/': 
            nodo->nodeType=T_INT;
            aux1=eval(a->izq);
             aux2=eval(a->der);
             if(aux1->nodeType==T_INT && aux2->nodeType==T_INT)
               nodo->ivalor=(aux1->ivalor / aux2->ivalor); 
            break;
            case T_AND:
            aux1 = eval(a->izq);
            aux2 = eval(a->der);
            if(aux1->nodeType==T_BOOL&&aux2->nodeType)
                nodo=(tData)newBool(aux1->bool&&aux2->bool);
            break;
            case T_OR:
            aux1 = eval(a->izq);
            aux2 = eval(a->der);
            if(aux1->nodeType==T_BOOL&&aux2->nodeType)
                nodo=(tData)newBool(aux1->bool||aux2->bool);
            break;
            case T_NOT:
            aux1 = eval(a->izq);
            if(aux1->nodeType==T_BOOL)
                nodo=(tData)newBool(!aux1->bool);
            break;
            case T_EQ:
            aux1 = eval(a->izq);
            aux2 = eval(a->der);
            nodo=(tData)newBool(isEqual(aux1,aux2));
            break;
            case T_NEQ:
            aux1 = eval(a->izq);
            aux2 = eval(a->der);
            nodo= ((tData)newBool(!isEqual(aux1,aux2)));
            break;
            case T_MY:
            aux1 = eval(a->izq);
            aux2 = eval(a->der);
                nodo=((tData)newBool(CMP(aux1,aux2)==1));
            break;
            case T_MN:
            aux1 = eval(a->izq);
            aux2 = eval(a->der);
                nodo=((tData)newBool(CMP(aux1,aux2)==-1));
            break;
            case T_MNEQ:
                aux1 = eval(a->izq);
                aux2 = eval(a->der);
                if(isEqual(aux1,aux2)|| CMP(aux1,aux2)==-1)
                    r=1;
                else r=0;
                nodo=((tData)newBool(r));
            break;
            case T_MYEQ:
                aux1 = eval(a->izq);
                aux2 = eval(a->der);
                int eq_result = isEqual(aux1, aux2);
                int cmp_result = CMP(aux1, aux2);
                int final_result = eq_result || (cmp_result == 1);
                nodo=(tData)newBool(final_result);
            break;
            case T_BE:
                aux1 = eval(a->izq);
                aux2 = eval(a->der);
                if(aux2->nodeType==T_SET /*||aux2->nodeType==T_LIST*/ ){
                    nodo=(tData)newBool(IN(aux2,aux1));
                }  
            break;
            case T_SUBSET:
                aux1 = eval(a->izq);
                aux2 = eval(a->der);
                if(aux2->nodeType==T_SET  /*||aux2->nodeType==T_LIST*/ ){
                    nodo=(tData)newBool(INCLUDE(aux2,aux1));
                }  
            break;
            case T_IF: {
                tData aux3=eval( ((struct flow *)a)->cond);
                    
                    if(aux3->nodeType==T_BOOL){
                        if( aux3->bool != 0) { //check the condition
                            if( ((struct flow *)a)->body) {             
                                nodo= eval( ((struct flow *)a)->body);
                            } else
                            nodo=newNodo(1);                /* a default value */
                        } else {
                        if( ((struct flow *)a)->els) {             
                        nodo = eval(((struct flow *)a)->els);
                        } else
                        nodo = newNodo(1);                /* a default value */
                        }
                    }
            break;
            }
            case T_WH:
            nodo=newNodo(1);
            tData aux4=eval(((struct flow *)a)->cond);            /* a default value */
            if( ((struct flow *)a)->body) {
                if(aux4->nodeType==T_BOOL)
                while( aux4->bool != 0){//evaluate the condition
                    nodo= eval(((struct flow *)a)->body);
                    aux4=eval(((struct flow *)a)->cond);
                }          
            }
            break;
            case T_FOREACH: {
            
            tData coleccion = eval(((struct foreach *)a)->coleccion); // Evalúa la colección
            if (coleccion->nodeType != T_LIST && coleccion->nodeType != T_SET) {
            yyerror("El 'foreach' solo puede iterar sobre listas o conjuntos.");
            return NULL;
            }
            tData copia_coleccion= copyData(coleccion);
            enter_scope();
            struct symbol* loop_var= add_symbol_to_current_scope(((struct symref *)((struct foreach *)a)->var)->nameref);
           // struct symref *loop_var =(struct symref *)newref(var->nom);     //((struct symref *)((struct foreach *)a)->var);
            if (((struct symref *)((struct foreach *)a)->var)->nodeType != ID_REF) {
             yyerror("La variable del bucle debe ser un identificador.");
                return NULL;
            }
            tData current_elem;
            // Itera sobre la colección
            while (copia_coleccion != NULL) {
            current_elem = copia_coleccion->data;
            // Asigna el valor del elemento actual a la variable
            loop_var->valor = current_elem; //en teoria tendria impacto global
            // Ejecuta el cuerpo del bucle
            nodo=eval(((struct foreach*)a)->body);
            // Pasa al siguiente elemento
            copia_coleccion = copia_coleccion->next;
            }
            exit_scope();
             // El foreach no retorna un valor
        } break;
            case ID_REF:{
                struct symbol*s =lookupp(((struct symref*)a)->nameref);
                nodo=s->valor;
            break;  
            case T_FN:
            nodo=newNodo(1);
            break;
            }
            case T_FNCALL: {
            tData aux5=eval(((struct ufncall*)a)->list_arg);
            nodo=(eval_calluser(((struct ufncall*)a)->namechar,aux5));
           
            break;
            }
            case EXPR:
                nodo=eval(a->izq); 
            break;
            case T_PRINT:
               
                printf("\n");
                if(a->izq->nodeType==ID_REF){
                    struct symbol*sp=find_symbol_in_scopes(((struct symref*)(a->izq))->nameref);//((struct symref*)(a->izq))->s->valor;
                    nodo=sp->valor;
                    if(strcmp(error,"\0")==0)
                        printref((struct symref*)(a->izq));
                    else
                        yyerror(error);
                }else if(a->izq->nodeType==T_INT){
                    nodo=eval(a->izq);
                    printf("%d",nodo->ivalor);
                }
                else{
                     nodo=eval(a->izq);
                    if(strcmp(error,"\0")==0){
                        printData(nodo);
                    }
                        
                    else
                        yyerror(error);                            
                }
                
            break;
            case LIST_STMT: 
            
                nodo=eval_stmt(a->izq,a->der);
            break;
            case T_RETURN:
                nodo=eval(a->izq);
                RETURN_VAL=nodo;
                RETURN_STATE=1;
                return nodo;
            break;
            default :
            yyerror("Tipo de nodo desconocido");
            return NULL;
            break;

        }
    return nodo;
    }
    return RETURN_VAL;
}



/*FUNCION QUE HACE HASHING
unsigned symhash(char *sym){
 unsigned int hash = 0;
 unsigned c;
 while(c = *sym++) hash = hash*9 ^ c;
 return hash;
}

struct symbol *lookupp(char* sym){
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

    
    







    
    





