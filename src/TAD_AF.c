#include "TAD_AF.h"
tData creaTrans(tData partidaS, tData sim, tData llegadaS);
tData transicion(tData deltaL, tData qSet, char alf);
int analizaCad(tAutomata AF,tData qSet, char* cad);


void inicia(tAutomata* AF){
	AF->estados=inicializar();
	AF->alfabeto=inicializar();
	AF->trans=inicializar();
	AF->ini=inicializar();
	AF->fin=inicializar();
}
int lleno(tAutomata af){
	if(isEmpty(af.estados)==1 || isEmpty(af.alfabeto)==1 || isEmpty(af.trans)==1 || isEmpty(af.ini)==1 || isEmpty(af.fin)==1){
		return 0;
	}else return 1;
}
void vaciar(tAutomata* af){
	dataFree(&af->estados);
	dataFree(&af->alfabeto);
	dataFree(&af->trans);
	dataFree(&af->ini);
	dataFree(&af->fin);
}
tAutomata cargarAutomata(){
	tAutomata nvo;
	char* cad=(char*)malloc(sizeof(char)*255);
	
	printf("\nIngresar estados: {q0,q1,...qn} \n");
	cargarCadena(cad);
	nvo.estados=newData(cad);
	
	printf("\nIngresar alfabeto: {0,1,...,m} \n");
	cargarCadena(cad);
	nvo.alfabeto=newData(cad);
	
	printf("\nIngresar transiciones: [{q0,0,{q1}},{q0,1,{q1}},....,{qn,m,qnm}] \n");
	cargarCadena(cad);
	nvo.trans=newData(cad);
	
	printf("\nIngresar estado inicial: {q0} \n");
	cargarCadena(cad);
	nvo.ini=newData(cad);
	
	printf("\nIngresar estados de aceptaci�n: {q0,q1,...qn} \n");
	cargarCadena(cad);
	nvo.fin=newData(cad);
	
	return nvo;
}
void mostrarAutomata(tAutomata a){
	printf("\nAUTOMATA\n");
	printf("Estados: ");printData(a.estados);
	printf("\nAlfabeto: ");printData(a.alfabeto);
	printf("\nTransiciones: ");printData(a.trans);
	printf("\nInicial: ");printData(a.ini);
	printf("\nAceptaci�n: ");printData(a.fin);
}

int comoEs(tAutomata a){ //0 si es AFD 1 si es AFND
	if(isEmpty(a.trans)!=1){
		int j=0,b=0,tam;
		tam=(SIZEL(a.trans));
		while( j < tam && b==0){
			tData aux;
			aux=returnElem(a.trans,j);
			int card;
			tData elemento;
			elemento=returnElem(aux,2);
			if(isEmpty(elemento)==1){
				b=1;
			}else{
				card=CARDINAL(elemento);
				if(card > 1){
					b=1;
				}
			}
			
			j++;
		}
		return b;
	}return -1;
}
	
int analizaCad(tAutomata AF,tData qSet, char* cad){
	char* ptro;
	ptro = cad;
	// qSet conjunto que contiene estado inicial
   tData nvo;
	nvo=qSet;
		
	do{
		nvo=transicion(AF.trans,nvo,*ptro);
		ptro=ptro+1;
	} while(strcmp(ptro,"\0")!=0);
		
	return (!isEmpty(INTER(nvo,AF.fin))) ? 1:0 ;
}

tData transicion(tData deltaL, tData qSet, char alf){
	tData destino,upla,actualE,sim,dest;
	destino=newNodo(2);
	char* aux;
	char* Q;
	int b;
	T_list partida;
	
	Q=toStr(qSet);
	separa_CAD(Q,partida.VecCad,&partida.tam);
	for(int j=0; j<partida.tam; j++){
		int i=0;b=0;
		while(returnElem(deltaL,i)!=NULL&&b!=1){
			upla=returnElem(deltaL,i);
			actualE=returnElem(upla,0);
			aux=toStr(actualE);
			if(strcmp(aux,partida.VecCad[j])==0){
				sim=returnElem(upla,1);
				aux=toStr(sim);
				if(aux[0]==alf){
					b=1;
					dest=returnElem(upla,2);
					destino=UNION(destino,dest);
				}
			}
			i=i+1;
		}
	}
	if(b==1){
		return destino;
	}else
		return NULL;
}	

tAutomata transformarAFND(tAutomata AFND){
	tAutomata AF;
	tData aux;
	tData upla;
	int b=0;
	AF.alfabeto = copyData(AFND.alfabeto); // alfabeto: tipo lista
	AF.estados =newNodo(3);// AF.estados es lista de conjuntos
	PUSH(AF.estados,AFND.ini);// agregamos a la lista el estado inicial de AFND que es un conjunto
	AF.ini=copyData(newNestedData(AFND.ini,2));// es un conjunto 	que contiene un conjunto)
	
	AF.trans=newNodo(3);// es una lista de 3-uplas (cargadas como listas)
	AF.fin=newNodo(2);
	
	int i = 0;
	
	while(i < SIZEL(AF.estados)){// la lista AF.estados va a ir cambiando a medida que se agregan nuevos estados
		for(int j=0; j<SIZEL(AF.alfabeto);j++){
			tData cadena;
			cadena=returnElem(AF.alfabeto,j);
			char* cad = toStr(cadena);
			aux= transicion(AFND.trans,returnElem(AF.estados,i),*cad);
			int t=0;b=0;
			upla=creaTrans(returnElem(AF.estados,i),returnElem(AF.alfabeto,j),aux);
			PUSH(AF.trans,upla);
			b=isEmpty(aux);
			while( t <=SIZEL (AF.estados)&&b==0){
				if(isEqual(returnElem(AF.estados,t),aux)==1){
					b=1;
				}
				t++;
			}
			if(b==0){
				PUSH(AF.estados,aux);
				if(!isEmpty(INTER(aux,AFND.fin))){
					AF.fin=UNION(AF.fin,newNestedData(aux,2));
				}
			}
		}
		i++;
	}
	
	return AF;
}

tData creaTrans(tData partidaS, tData sim, tData llegadaS){
	tData upla=newNodo(3);

	PUSH(upla,partidaS);
	PUSH(upla,sim);
	PUSH(upla,llegadaS);
	return upla;
}
