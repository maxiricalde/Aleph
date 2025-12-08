#ifndef TAD_AF_H
#define TAD_AF_H
#include "tData.h"
typedef struct {
	tData estados; //lista que contenga conjuntos [q0,q1,q2...]
	tData alfabeto;// [b,a]
	tData trans; //[[q0,a,{q1}],[q0,b,{q2}...]
	tData ini; //{q0}
	tData fin; //{q2};
}tAutomata;

tAutomata cargarAutomata();
void inicia(tAutomata*);
void mostrarAutomata(tAutomata);
tData transicion(tData deltaL, tData qSet, char alf);
int analizaCad(tAutomata AF,tData qSet, char* cad);
int lleno(tAutomata);
void vaciar(tAutomata*);
int comoEs(tAutomata);
tAutomata transformarAFND(tAutomata);
#endif
