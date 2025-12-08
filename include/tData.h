#ifndef TDATA_H
#define TDATA_H

#define T_ELEM 1
#define T_SET 2
#define T_LIST 3
#define T_BOOL 4
#define T_INT 19



typedef enum {
	false=0,
	true=1 
}BOOLEAN;



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TAD_TCad.h"

struct dataType{
	int nodeType;
	union{
		char* atom;
		int ivalor;
		BOOLEAN bool;
		struct{
			struct dataType* data;
			struct dataType* next; 
		};
	};
};
typedef struct dataType* tData;





/*operaciones generales*/


//a partir de una cadena dada por el usuario, crea un nuevo dato (ATM, T_SET o T_LIST)
tData newData(char *s);        
//a partir de un tData crea uno nuevo anidando (nest) el tData recibido como hijo derecho
tData newNestedData(tData d, int t);
//elimina un dataSL
void dataFree(tData* d);
//imprime un dato por pantalla
void printData(tData d); 
//retorna tipo de dato
int returnType(tData d); 
//convierte tData a cadena
char* toStr(tData d); 
//copia un tData en otro tData
tData copyData(tData d);

/*operaciones agregadas */
tData newNodo(int tipo);
tData inicializar(); //tipo de dato esta en 0

/*operaciones T_LIST* y T_SET*/
tData FIRST(tData d);
//Es vac�o
int isEmpty(tData d); 
//Son iguales
int isEqual(tData d1, tData d2); 
int INCLUDE(tData A,tData B);
int CMP(tData d1, tData d2);

/*operaciones con T_LIST*/
//agrega un elemento a la lista por el final 
void PUSH(tData L, tData elem);  
//elimina el �ltimo elemento de la lista y lo devuelve como salida
tData POP(tData* L);
//retorna el tama�o de la lista
int SIZEL(tData L);  
/*Retorna elemento en posici�n pos dentro del SLData*/
tData returnElem(tData d, int pos); 


/*operaciones con T_SET*/
//calcula la cantidad de elementos de un conjunto
int CARDINAL(tData S); 
//determina si un elemento pertenece a un conjunto
int IN(tData S, tData elem); 
//genera un nuevo conjunto que resulta de la uni�n de dos conjuntos
tData UNION(tData A,tData B); 
//genera un nuevo conjunto que resulta de la intersecci�n de dos conjuntos
tData INTER(tData A,tData B);
//genera un nuevo conjunto que resulta de la diferencia de dos conjuntos
tData DIFF(tData A,tData B);


tData FIRST(tData d);
tData LAST(tData d);
tData ADD_INI(tData d, tData* og);

#endif
