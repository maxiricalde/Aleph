#ifndef TAD_TCAD_H
#define TAD_TCAD_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_V 100
#define TAM 100

typedef char* tElem;
typedef tElem tVec[SIZE_V];
typedef struct  {
	tVec VecCad;
	int tam;
}T_list;



typedef char cad[TAM];
void leeCad(char* a,int tam);
void cargarCadena(tElem );
void separa_CAD(tElem cad,tVec vec,int *t); 
void getElemt(tElem* cad, tElem* extraido);


#endif
