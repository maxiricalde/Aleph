#include "tData.h"
#include "TAD_TCad.h"
/**cabeceras aux*/
void printData(tData d);
void mostrarListSet(tData d);
tData createDT_cadena(char* s);
tData createDT(tData dt);

void concatena(tData d, char ** cadi);
void str(tData d, char ** cadi);

/**Operaciones generales*/

tData inicializar(){
	tData nvo;
	nvo= (tData)malloc(sizeof(struct dataType));
	nvo->nodeType=0;
	nvo->atom=NULL;
	nvo->data=NULL;
	nvo->next=NULL;
	return nvo;
}
tData newNodo(int tipo){
	if(tipo == T_ELEM ||tipo==T_INT||tipo==T_BOOL ||tipo == T_SET || tipo ==T_LIST){
		tData nuevo;
		nuevo=inicializar();
		nuevo->nodeType=tipo;
		return nuevo;
	}else return NULL;
}
tData newData(char *s){ /**LISTO*/
	int r;
	tData nuevo;
	nuevo=inicializar();
	tData aux;
	aux= nuevo;
	do{
		printf("\nElegir el tipo de dato a ser cargado:\n[1]=Cadena\n[2]=Conjunto\n[3]=Lista\nRta: ");
		scanf("%d",&r);
	} while(r<1||r>3);
	if(r==1){
		if(s[0]=='\0'){
			nuevo=NULL;
		}
		else
		   nuevo=createDT_cadena(s);
	}else if(r==2){
		tVec vec;
		int tam=0;
		separa_CAD(s,vec,&tam);
		nuevo->nodeType = T_SET;
		for(int i=0;i<tam;i++){
			printf("\nEl dato a ser cargado es: %s",vec[i]);
			aux->data=newData(vec[i]);
			if(i<tam-1){
				aux->next=inicializar();
				aux->next->nodeType=T_SET;
				aux=aux->next;
			}
		}
	}else {
		tVec vec;
		int tam=0;
		separa_CAD(s,vec,&tam);
		nuevo->nodeType = T_LIST;
		for(int i=0;i<tam;i++){
			printf("\nEl dato a ser cargado es: %s",vec[i]);
			aux->data=newData(vec[i]);
			if(i<tam-1){
				aux->next=inicializar();
				aux->next->nodeType=T_LIST;
				aux=aux->next;
			}
		}
	}
	return nuevo;
}

void dataFree(tData* d){
	if(*d==NULL || d == NULL) return;
	tData actual= *d;
	tData sig;
	while (actual != NULL) {
		if (actual->nodeType == T_LIST || actual->nodeType == T_SET) {
            sig = actual->next; 
        } else {
            sig = NULL; // Los primitivos no tienen siguiente en esta estructura de union
        }
		switch(actual->nodeType){
			case T_ELEM:
				free(actual->atom);
			break;
			case T_LIST:
				dataFree(&actual->data);
			break;
			case T_SET:
				dataFree(&actual->data);
			break;
			
		}
		free(actual);
		actual = sig;
	}
	*d= NULL;
}

/*void dataFree(tData* d){ //revisarrr  
	if(d != NULL){
		if(((*d)->nodeType == T_ELEM)){
			free((*d)->data);
		}
    }else{
		struct dataType* actual;
		struct dataType* sig;
		actual = (*d)->data;
		sig = (*d)->next;
		while(actual != NULL){
			dataFree(&actual);
			actual= sig;
			sig = actual->next;
		}
	}
	free(*d);
	*d= NULL;
}*/

	

/*void printData(tData d){ 
	if(d!=NULL){
		if(d->nodeType==T_ELEM){
			printf("%s", d->atom);
		}
		else{
			if(d->nodeType==T_INT){
				printf("%d",d->ivalor);
			}
			if(d->nodeType==T_BOOL){
				if(d->bool==0){
					printf("false");
				}
				else{
					printf("true");
				}
			}
			if(d->nodeType==T_LIST){
				printf("[");
				mostrarListSet(d);
				printf("]");
			}
			if(d->nodeType==T_SET){
				printf("{");
				mostrarListSet(d);
				printf("}");
			}
		}
	}
}*/

void printData(tData d){
    if(d == NULL){
        return;
    }
    switch(d->nodeType){
        case T_ELEM:
            printf("%s", d->atom);
            break;
        case T_INT:
            printf("%d", d->ivalor);
            break;
        case T_BOOL:
            if(d->bool == 0){
                printf("false");
            } else {
                printf("true");
            }
            break;
        case T_LIST:
            printf("[");
            mostrarListSet(d);
            printf("]");
            break;
        case T_SET:
            printf("{");
            mostrarListSet(d);
            printf("}");
            break;
        default:
            // Opcional: Manejar un tipo de nodo desconocido
            printf("Tipo de nodo desconocido para imprimir");
            break;
    }
}
tData newNestedData(tData d, int t){ /**LISTO*/
	if(t==1){
		return NULL;
	}else if (t==2){
		tData nvo;
		nvo=inicializar();
		nvo->nodeType=T_SET;
		nvo->data=d;
		return nvo;
	}else if(t == 3){
		tData nvo;
		nvo=inicializar();
		nvo->nodeType=T_LIST;
		nvo->data=d;
		return nvo;
	}else return NULL;
	
}
int returnType(tData d){ // devuelve el tipo de dato del nodo (datatype) /**LISTO*/
	return d == NULL ? 0: d->nodeType; //si devuelve 0 esta vacio
}

char* toStr(tData d){
	if(d!=NULL){
		char* nvo;
		nvo=(char*)malloc(sizeof(char)*255);
		nvo[0]='\0';
		if(returnType(d) == T_ELEM){
			nvo = strdup(d->atom);
			return nvo;
		}
		else{
			if(returnType(d) == T_SET){
				concatena(d,&nvo);      
			}else{
				concatena(d, &nvo); 
			}	
		}
		return nvo;
	}else return NULL;
}
	

tData copyData(tData d){
	tData nvo;
	if(d!=NULL){
		if((isEmpty(d)!=1)){
			
		nvo = inicializar();
		int tipo;
		tipo=d->nodeType;
		nvo->nodeType=tipo;
		if(tipo==T_ELEM){
			nvo->atom = strdup(d->atom);
			//	if(d->next!=NULL){
			//	nvo->next = copyData(d->next);
			//}
		}else if (tipo==T_INT){
			nvo->ivalor=d->ivalor;
		}
		else{
			nvo->data= copyData(d->data);
			nvo->next= copyData(d->next);
		}
		return nvo;
		}
		else return nvo=newNodo(d->nodeType);
		
	}else return NULL;
}

/**Operaciones Lista*/

tData returnElem(tData d, int pos){
	if(d!=NULL){
		if(d->nodeType==T_LIST||d->nodeType==T_SET){
			tData nvo;
			nvo=inicializar();
			int i=0;
			while(d->next!=NULL && i<pos){
				d=d->next;
				i=i+1;
			}
			if(i==pos){
				nvo=copyData(d->data);
			//	nvo->next=NULL;
				return nvo;
			}
			else return NULL;
		}else return NULL;
	}return NULL;
}
	
int isEmpty(tData d){ 
	if(d!=NULL){
		if(d->data == NULL && d->next == NULL){
			return 1;
		}else {
			return 0;
		}
	}else return 1; //revisAR
}
		

int SIZEL(tData d){ /**LISTO*/
	if(d!=NULL){
		if(d->nodeType==T_LIST){
			int cant=0;
			if(d->data!=NULL){
				tData aux;
			aux=d;
			while(aux!=NULL){
				cant=cant+1;;
				aux=aux->next;
			}
			}
			
			return cant;
		}else return -1; //retorna -1 si no es lista
	}else return -1; //retorna -1 si es un tdata vacio

}
	
void PUSH(tData L, tData elem){ /*LISTO*/
	if(L != NULL){
		if((L)->nodeType==T_LIST){
		    if(isEmpty(L)!=1){
				tData aux = L;
		        while(aux->next!=NULL)
					aux=aux->next;
				aux->next=inicializar();
				aux->next->nodeType=T_LIST;
				aux->next->data=elem;

			}else {
				L->data=elem;
			}
		}
	}
}
tData POP(tData* L) {
    // 1. Manejar casos de lista vacía o inválida
    if (*L == NULL) {
        printf("Error: lista vacia\n");
        return NULL;
    }
    
    // 2. Comprobar que el tipo de nodo sea T_LIST
    if ((*L)->nodeType != T_LIST) {
        printf("Error: tipo de nodo invalido. No es una lista.\n");
        return NULL;
    }
    
    // 3. Manejar el caso de una lista con un solo elemento
    if ((*L)->next == NULL) {
        tData temp = (*L)->data;
		(*L)->data = NULL; // Establece la lista como vacía
        return temp;
    }
    
    // 4. Manejar el caso general (lista con más de un elemento)
    tData ant = *L;
    tData aux = (*L)->next;

    while (aux->next != NULL) {
        ant = aux;
        aux = aux->next;
    }
    
    ant->next = NULL; // El nuevo último elemento apunta a NULL
    return aux->data;
}
/*tData POP(tData* L){ 
	if(*L!=NULL){
		if((*L)->nodeType==T_LIST){
			tData aux = *L;
			tData ant=NULL;
			while(aux->next!=NULL){
				ant=aux;
				aux=aux->next;
			}
			ant->next=NULL;
			printf("valor del pop");
			printData(aux);
			return aux;
		}
	printf("lista invalida");	
	}return NULL;
}*/
/*int isEqual(tData d1, tData d2) {
    // Caso base: si ambos son nulos, son "iguales" en el sentido de que ambos están vacíos.
    // Aunque el retorno -1 no es ideal, mantengo la lógica original. Es mejor usar 1/0.
    if (d1 == NULL && d2 == NULL) {
        return 1;
    }
    // Si uno es nulo y el otro no, son diferentes.
    if (d1 == NULL || d2 == NULL) {
        return 0;
    }

    // Los tipos deben ser iguales para que los datos sean iguales.
    if (d1->nodeType != d2->nodeType) {
        return 0;
    }

    // Comparación según el tipo de nodo
    switch (d1->nodeType) {
        case T_ELEM:
            // Comparar cadenas. strcmp retorna 0 si son iguales.
            return (strcmp(d1->atom, d2->atom) == 0);

        case T_INT:
            // Comparar valores enteros.
            return (d1->ivalor == d2->ivalor);

        case T_LIST:
			tData elem1,elem2;
				elem1=d1->data;
				elem2=d2->data;
				while(d1!=NULL && elem1 != NULL && d2!=NULL && elem2 !=NULL){
					if(isEqual(elem1,elem2)==0){
						return 0;
					}
					d1=d1->next;
					d2=d2->next;
					if(isEmpty(d1)!=1){
						elem1=d1->data;
					}
					if(isEmpty(d2)!=1){
						elem2=d2->data;
					}
				}
				if((d1==NULL && d2!= NULL) || (d1!=NULL && d2==NULL)){
					return 0;
				}else{
					return 1;
				}
		case T_SET:
			tData aux;
			int igual;
				elem1=d1->data;
				igual=1;
				aux=d1;
				while(aux!=NULL && igual == 1){
					igual = IN(d2,elem1);
					aux=aux->next;
					if(aux!=NULL)
						elem1=aux->data;
				}
				elem1=d2->data;
				aux=d2;
				while(aux!=NULL && igual == 1){
					igual = IN(d1,elem1);
					aux=aux->next;
					if(aux!=NULL)
						elem1=aux->data;
				}
				if(igual==1){
					return igual;
				}else return 0;
			
		break;
        
        default:
            return 0; // Tipo no reconocido
    }
}
/*int isEqual(tData d1, tData d2){
	if(d1 != NULL && d2 != NULL && !isEmpty(d1)&&!isEmpty(d2)){
		int tipo1,tipo2;
		tipo1=d1->nodeType;
		tipo2=d2->nodeType;
		if(tipo1 == tipo2){ //pregunta si son iguales
			int igual=0;
			if(tipo1==T_ELEM){ //si son cadenas solo compara sus cadenas
				igual=strcmp(d1->atom,d2->atom);
				if(igual==0){
					return 1;
				}else return 0;
			}
			
			else if(tipo1==T_LIST){ //si son listas
				tData elem1,elem2;
				elem1=d1->data;
				elem2=d2->data;
				while(d1!=NULL && elem1 != NULL && d2!=NULL && elem2 !=NULL){
					if(isEqual(elem1,elem2)==0){
						return 0;
					}
					d1=d1->next;
					d2=d2->next;
					if(isEmpty(d1)!=1){
						elem1=d1->data;
					}
					if(isEmpty(d2)!=1){
						elem2=d2->data;
					}
				}
				if((d1==NULL && d2!= NULL) || (d1!=NULL && d2==NULL)){
					return 0;
				}else{
					return 1;
				}
				
			}else{ //deberia analizar igual para d2 
				tData elem1,aux;
				elem1=d1->data;
				igual=1;
				aux=d1;
				while(aux!=NULL && igual == 1){
					igual = IN(d2,elem1);
					aux=aux->next;
					if(aux!=NULL)
						elem1=aux->data;
				}
				elem1=d2->data;
				aux=d2;
				while(aux!=NULL && igual == 1){
					igual = IN(d1,elem1);
					aux=aux->next;
					if(aux!=NULL)
						elem1=aux->data;
				}
				if(igual==1){
					return igual;
				}else return 0;
			}
		}else return 0;
	}else if(d1 == NULL && d2 == NULL){
		return -1; //retorna -1 si son nulas
	}else return 0; 
}
*/
/**Operaciones Conjuntos*/
int CMP(tData d1, tData d2){
	/*Conj y lista: cual es mas largo
	Entero normal= d1 mayor que d2 retorna 1, si d2 retorna -1
	Cadena cmp*/
	if (d1 == NULL && d2 == NULL) {
        return 1;
    }
    // Si uno es nulo y el otro no, son diferentes.
    if (d1 == NULL || d2 == NULL) {
        return 0;
    }
    // Los tipos deben ser iguales para que los datos sean iguales.
    if (d1->nodeType != d2->nodeType) {
		printf("Adv:Los datos que se desean comparar son de distinto tipo");
        return 0;

    }
    // Comparación según el tipo de nodo
    switch (d1->nodeType) {
        case T_ELEM:
            // Comparar cadenas. strcmp retorna 0 si son iguales.
            return (strcmp(d1->atom, d2->atom)==1);
		break;
        case T_INT:
            // Comparar valores enteros.
			
            if(d1->ivalor > d2->ivalor)
				return 1;
			else if (d1->ivalor < d2->ivalor)
				return -1;
			else return 0;
		break;
        case T_LIST:
		if(SIZEL(d1)>SIZEL(d2))
			return 1;
		else if (SIZEL(d1)<SIZEL(d2))
				return -1;
		else return 0;
		break;	
		case T_SET:
			if(CARDINAL(d1)>CARDINAL(d2))
				return 1;
			else if (CARDINAL(d1)<CARDINAL(d2))
				return -1;
			else return 0;
		break;
        default:
            return 0; // Tipo no reconocido
	}
}

int isEqual(tData d1, tData d2) { //no tocar!!! esta bien
    // Si ambos son nulos, son "iguales" (ambos vacíos).
    if (d1 == NULL && d2 == NULL) {
        return 1;
    }
    // Si uno es nulo y el otro no, no son iguales.
    if (d1 == NULL || d2 == NULL) {
        return 0;
    }

    // Los tipos de los nodos deben ser iguales para que los datos sean iguales.
    if (d1->nodeType != d2->nodeType) {
        return 0;
    }

    // Comparación según el tipo de nodo
    switch (d1->nodeType) {
        case T_ELEM:
            // Compara cadenas. strcmp devuelve 0 si son iguales.
            return (strcmp(d1->atom, d2->atom) == 0);

        case T_INT:
            // Compara valores enteros.
            return (d1->ivalor == d2->ivalor);

        case T_LIST: {
            tData current1 = d1;
            tData current2 = d2;
            // Itera mientras ambas listas tengan elementos.
            while (current1 != NULL && current2 != NULL) {
                // Si algún elemento no es igual, las listas no son iguales.
                if (!isEqual(current1->data, current2->data)) {
                    return 0;
                }
                current1 = current1->next;
                current2 = current2->next;
            }
            // Si ambas listas terminaron al mismo tiempo, son iguales.
            // Si una terminó antes que la otra, tienen diferente longitud y no son iguales.
            return (current1 == NULL && current2 == NULL);
        }

        case T_SET: {
            // El cardinal de los conjuntos debe ser igual.
            // De lo contrario, no pueden ser iguales.
            if (CARDINAL(d1) != CARDINAL(d2)) {
                return 0;
            }
            // Verifica que cada elemento de d1 esté en d2.
            tData current = d1;
            while (current != NULL) {
                // Si un elemento de d1 no está en d2, los conjuntos no son iguales.
                if (!IN(d2, current->data)) {
                    return 0;
                }
                current = current->next;
            }
            // Si se llegó aquí, todos los elementos de d1 están en d2.
            // Como las cardinalidades son iguales, d2 también contiene todos los de d1.
            return 1;
        }

        default:
            // Tipo no reconocido
            return 0;
    }
    // No debería llegar aquí, pero se incluye para completar la función.
    return 0;
}

int CARDINAL(tData S){
	if(S->nodeType==T_SET){
		int cont=0;
		if(S->data==NULL){
			return cont;
		}else{
			while(S!=NULL){
			cont++;					
			S=S->next;
			}
		}
		return cont;
		
	}else return -1;
}
/*int IN(tData S, tData elem){ //listo _ controla si S es vacio
	
	if(S!=NULL && S->nodeType == T_SET && elem!=NULL){
		if(S->data==NULL){
			return 0;
		}
		else{
			int band = 1;
		if(elem->nodeType == T_ELEM|| elem->nodeType==T_INT){
			while(S!=NULL && band != 0){ 
				if(S->data->nodeType==T_ELEM && elem->nodeType == T_ELEM){
					band=strcmp(S->data->atom,elem->atom);
				}
				else if (S->data->nodeType==T_INT &&elem->nodeType==T_INT){
						if(S->data->ivalor==elem->ivalor)
							band=0;
				}
				S=S->next;
			}
			if(band==0){
				printf("band1");
				return 1;
			}else return 0;
			
		}else {
			band=0; //elem es tipo set 
			while(S!= NULL && band==0){
				if(S->nodeType != elem->nodeType){
					printf("\n no paso");
					S=S->next;
				}else{printf("paso por tipo set");
					band=isEqual(S,elem); //devolvera 1 si son iguales
					printData(S);
					S=S->next;
				}
			}
			if(band==1){
				return 1;
			}else return 0;
		}
		}
		
	}else return 0;
	
}*/
int IN(tData S, tData elem) {
    // Verificar que S no sea vacío y sea un conjunto, y que elem no sea NULL
   if(S!=NULL && S->nodeType == T_SET && elem!=NULL){
		if(S->data==NULL){
			return 0;
		}
		else{
			int band = 1;
			if(elem->nodeType == T_ELEM|| elem->nodeType==T_INT){
				while(S!=NULL && band != 0){ 
					if(S->data->nodeType==T_ELEM && elem->nodeType == T_ELEM){
					band=strcmp(S->data->atom,elem->atom);
					}
					else if (S->data->nodeType==T_INT &&elem->nodeType==T_INT){
						if(S->data->ivalor==elem->ivalor)
							band=0;
					}
				S=S->next;
				}
			if(band==0){
				return 1;
			}else return 0;
			}
        // Caso 2: elem es un conjunto (T_SET)
        	else if(elem->nodeType == T_SET || elem->nodeType==T_LIST) {
			tData current;
            current = S; // Reiniciamos al principio
            while(current != NULL) {
                if(current->data != NULL && current->data->nodeType == T_SET|| current->data->nodeType==T_LIST) {
                    // Comparar si los conjuntos son iguales
                    if(isEqual(current->data, elem)) {
                        return 1;
                    }
                }
                current = current->next;
            }
            return 0;
       		}
    	}
    return 0;
	}
}
/*int IN(tData S, tData elem){
    if (S == NULL || S->nodeType != T_SET ||S->nodeType != T_LIST || elem == NULL) {
        return 0;
    }

    tData current = S;
    int found = 0;
    while (current != NULL) {
        if (current->data != NULL) {
            switch (current->data->nodeType) {
                case T_ELEM:
                    if (elem->nodeType == T_ELEM && strcmp(current->data->atom, elem->atom) == 0) {
                        found = 1;
                    }
                    break;
                case T_INT:
                    if (elem->nodeType == T_INT && current->data->ivalor == elem->ivalor) {
                        found = 1;
                    }
                    break;
                case T_LIST:
                case T_SET:
                    // Asumiendo que isEqual maneja la comparación de colecciones
                    if (current->data->nodeType == elem->nodeType) {
                        if (isEqual(current->data, elem)) {
                            found = 1;
                        }
                    }
                    break;
                // Agrega otros tipos de datos aquí si es necesario
            }
        }
        current = current->next;
		 
    }
	if (found) {
        return 1;
    }
    return 0;
}	

int IN(tData S, tData elem) {
    // Return 0 immediately if the set or element is invalid,
    // or if the set is not of type T_SET.
    if (S == NULL || S->nodeType != T_SET || elem == NULL) {
        return 0;
    }

    // Handle an empty set.
    if (S->data == NULL) {
        return 0;
    }

    // Iterate through the set to find the element.
    tData current = S->data;
    while (current != NULL) {
        // Check for T_ELEM (strings) or T_INT (integers).
        if (elem->nodeType == T_ELEM || elem->nodeType == T_INT) {
            if (current->nodeType == elem->nodeType) {
                if (current->nodeType == T_ELEM) {
                    // Compare strings.
                    if (strcmp(current->atom, elem->atom) == 0) {
                        return 1;
                    }
                } else if (current->nodeType == T_INT) {
                    // Compare integers.
                    if (current->ivalor == elem->ivalor) {
                        return 1;
                    }
                }
            }
        } else {
            // Check for other types using the isEqual function.
            if (current->nodeType == elem->nodeType && isEqual(current, elem)) {
                return 1;
            }
        }
        current = current->next;
    }

    // If the loop finishes without finding the element, it's not in the set.
    return 0;
}*/
int INCLUDE(tData A, tData B){
	tData aux,elem;
	int igual;
		elem=A->data;
				igual=1;
				aux=A;
				while(aux!=NULL && igual == 1){
					igual = IN(B,elem);
					printf("%d",igual);
					aux=aux->next;
					if(aux!=NULL)
						elem=aux->data;
				}
}
tData UNION(tData A,tData B){
	tData nuevo;
	if((A!=NULL || B!=NULL) || (isEmpty(A) != 1 && isEmpty (B) != 1)){
		if(A!=NULL && B==NULL){
			if(isEmpty(A)==1){
				nuevo = newNodo(T_SET);
			}else {
				nuevo=copyData(A);
			}
			return nuevo;
		}else if(A==NULL && B!= NULL){
			if(isEmpty(B)==1){
				nuevo = newNodo(T_SET);
			}else {
				nuevo=copyData(B);
			}
			return nuevo;
		}else if(isEqual(A,B)==1){
			nuevo=copyData(B);
			return nuevo;
		}else {
			if(isEmpty(A)==1){
				nuevo = copyData(B);
				return nuevo;
			}else if(isEmpty(B)==1){
				nuevo = copyData(A);
				return nuevo;
			}else{
				nuevo=copyData(A);
				int esta;
				tData aux;
				while(B!=NULL){
					esta=0;
					esta=IN(nuevo,B->data);
					if(esta==0){
						aux=nuevo;
						while(aux->next!=NULL){
							aux=aux->next;
						}
						aux->next=inicializar();
						aux->next->nodeType=T_SET;
						aux->next->data=B->data;
					}
					B=B->next;
				}
			}
			return nuevo;
		}
	}return NULL;
}			

tData INTER(tData A,tData B){
	tData nuevo;
	if(A!=NULL && B != NULL){
		if(A==NULL||B==NULL){
			nuevo=newNodo(T_SET);
			return nuevo;
		}else{
			nuevo=newNodo(T_SET);
			tData aux;
			int esta=0;
			esta=IN(A,B->data);
			if(esta==1){
				nuevo->data=B->data;
			}
			B=B->next;
			while(B!=NULL){
				esta=0;
				esta=IN(A,B->data);
				if(esta==1){
					aux=nuevo;
					while(aux->next!=NULL){
						aux=aux->next;
					}
					aux->next=inicializar();
					aux->next->nodeType=T_SET;
					aux->next->data=B->data;
				}
				B=B->next;
			}
			return nuevo;
		}
	}return NULL;
}

	
tData DIFF(tData A,tData B){
	if((A!= NULL && B!=NULL) || (isEmpty(A)!=1 && isEmpty(B)!=1)){
		tData nvo;
		if(A!=NULL && (B==NULL || isEmpty(B)==1)){
			nvo=copyData(A);
			return nvo;
		}else if((A==NULL || isEmpty(A)==1) && B!=NULL){
			nvo=copyData(B);
			return nvo;
		}else if(isEqual(A,B)==1){
			nvo = newNodo(2);
			return nvo;
		}else{
			if(isEmpty(A)==1){
				nvo = newNodo(2);
				return nvo;
			}else{
				int esta;
				tData aux;
				esta=0;
				aux=A;
				int b=0;
				while(aux!=NULL && b==0){
					esta=IN(B,aux->data);
					if(esta==0){
						nvo=newNodo(2);
						nvo->data=aux->data;
						b=1;
					}
					aux=aux->next;
				}
				if(b==1){
					tData aux2;
					aux2=nvo;
					while(aux!=NULL){
						esta=IN(B,aux->data);
						if(esta==0){
							while(aux2->next!=NULL){
								aux2=aux2->next;
							}
							aux2->next=newNodo(T_SET);
							aux2->next->data=aux->data;
						}
						aux=aux->next;
					}
				}else{
					nvo=inicializar(T_SET);
				}
				return nvo;
			}
		}
	}else if(A!= NULL && B!=NULL){
		return NULL;
	}else if(isEmpty(A)==1){
		tData nvo;
		nvo=copyData(B);
		return nvo;
	}else {
		tData nvo;
		nvo=copyData(A);
		return nvo;
	}
}			
/**desarrollo modulos auxiliares*/
void mostrarListSet(tData d){
	if(d!=NULL){
		if(d->nodeType==T_LIST){
			printData(d->data);
			if(d->next!=NULL){
				printf(",");
				mostrarListSet(d->next);
			}
		}
		if(d->nodeType==T_SET){
			printData(d->data);
			if(d->next!=NULL){
				printf(",");
				mostrarListSet(d->next);
			}
		}
	}
}

tData createDT_cadena(char* s){
	tData nuevo= (tData)malloc(sizeof(struct dataType));
	nuevo->nodeType = T_ELEM;
	nuevo->atom = strdup(s);
	return nuevo;
}
tData createDT(tData dt) {
	tData newDT= (tData)malloc(sizeof(struct dataType));

	newDT->nodeType = (dt->nodeType == T_ELEM) ? T_ELEM : dt->nodeType;
	newDT->data = dt;
	newDT->next = NULL;
	return newDT;
}	

void concatena(tData d, char** cad){
	if(d!=NULL){
		if(d->nodeType==T_ELEM){
			(*cad)=strcat(*cad,d->atom);
		}
		else{
			if(d->nodeType==T_LIST){
				(*cad)=strcat(*cad,"[");
				str(d,cad);
				(*cad)=strcat(*cad,"]");
			}
			if(d->nodeType==T_SET){
				(*cad)=strcat(*cad,"{");
				str(d,cad);
				(*cad)=strcat(*cad,"}");
			}
		}
	}
}
	
void str(tData d, char**cad){
	if(d!=NULL){
		if(d->nodeType==T_LIST){
			concatena(d->data,cad);
			if(d->next!=NULL){
				(*cad)=strcat(*cad,",");
				str(d->next,cad);
			}
		}
		if(d->nodeType==T_SET){
			concatena(d->data,cad);
			if(d->next!=NULL){
				(*cad)=strcat(*cad,",");
				str(d->next,cad);
			}
		}
	}
}		


/// @brief retorna una copia del primer elemento de un set/list
/// @param tData collection 
/// @return 
tData FIRST(tData d){
	tData aux=newNodo(1);
    if(d!=NULL){
        if(d->nodeType==T_LIST || d->nodeType==T_SET){
            aux=copyData(d->data);
        }
    }return aux;
}

tData LAST(tData d){
	tData aux=newNodo(1);
    if(d!=NULL){
        if(d->next!=NULL){
            return LAST(d->next);
        }else{
            return copyData(d->data);
        }
    }return aux;
}

tData ADD_INI(tData elem, tData *coleccion) {
    tData new_node = newNodo(returnType(*coleccion));
    new_node->data = copyData(elem);
	new_node->next = *coleccion;
	if((*coleccion)->data==NULL)
		new_node->next=NULL;
    coleccion = &new_node;
	return new_node;
}

tData ADD_FIN(tData elem, tData coleccion) {
	printData(elem);
	printData(coleccion);
    // Crear un nuevo nodo para el elemento a agregar.
    tData new_node = newNodo(returnType(elem));
    new_node->data = copyData(elem); // Asumimos que elem es un nodo y accedemos a su data.
    new_node->next = NULL;

    // Si la colección está vacía, el nuevo nodo es el primer y único elemento.
    if (coleccion == NULL) {
        return new_node;
    }

    // Si la colección no está vacía, recorremos hasta el final
    // para agregar el nuevo nodo.
    tData current = coleccion;
    while (current->next != NULL) {
        current = current->next;
    }

    // Enlazamos el último nodo de la colección con el nuevo nodo.
    current->next = new_node;

    // La colección original (la cabeza de la lista) se mantiene sin cambios.
    return coleccion;
}
/*tData ADD(tData elem, tData coleccion){ 
	tData aux=inicializar();
	tData aux2=inicializar();
	printData(elem);
	printData(coleccion);
    if(coleccion!=NULL){								
	
		tData aux2;
		//aux=newNestedData(coleccion->data,returnType(coleccion)); //set original
		//aux->next=coleccion->next;
		//coleccion->data=copyData(elem);
		//coleccion->next=aux;
		
		aux2=coleccion;
		aux=newNodo(returnType(coleccion));
		aux->data=elem; // modificar copydata para que entienda {}
		aux->next=copyData(coleccion);
		
		
    }else{
        aux=copyData(elem);
        dataFree(&elem);
    }

	printData(aux2);
	return aux2;
}*/