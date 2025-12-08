#include "TAD_TCad.h"

void unirCompuestos1(tVec vecCad);

	
void cargarCadena(tElem cad){
	
	fflush(stdin);
	//fgets(cad, TAM, stdin);
	leeCad(cad,TAM);
	fflush(stdin);
}
void eliminarPrimerUltimoCaracter(char* cadena){
	int len = strlen(cadena);
	if (len > 0){
		cadena[len - 1] = '\0';
	}
	if(cadena[0] != '\0'){
		memmove (cadena, cadena + 1, strlen(cadena));
	}
}
	char* clean(char* s){
		int i=1;
		char* aux;
		aux=(char*) malloc(sizeof(char)*255); 
		while (s[i]!='\0'){
			aux[i-1]=s[i];
			i++;
		}
		aux[i-2]='\0';
		return aux;
	}

void separa_cad(tElem cad, tVec vec){ // version disque arreglada por Agus//
	eliminarPrimerUltimoCaracter(cad);
	int i=0;
	vec[i]= strtok(i==0? cad:NULL ,",");
	while(vec[i]!=NULL){
		i++;
		vec[i]= strtok(i==0? cad:NULL ,",");
	}
	unirCompuestos1(vec);
}
void unirCompuestos1(tVec vecCad){
	int i=0;
	while(vecCad[i]!=NULL&&(*vecCad)[i]!='{'){
		i++;
	}
	if((*vecCad)[i]=='{'){
		int j=i+1;
		while((vecCad)[j]!= NULL&&(*vecCad)[j]!='}'){
			j++;
		}
		for(int t=i; t<=j;t++){
			strcat(vecCad[i],vecCad[t]);
			printf("concatenada: %s", vecCad[i]);
		}
	}
}
	

void getElemt(tElem* cad, tElem* extraido){// me separa de la cadena el primer elemento
	char*  s_aux;
	s_aux= (char*)malloc(sizeof(char)*255);
	int i=0,b,j=0, cont_a1=0, cont_c1=0, cont_a2=0,cont_c2=0, cont_a3=0,cont_c3=0;
		
	if ((*cad)[0]!='{' && (*cad)[0]!='['&&(*cad)[0]!='(') {
		while ((*cad)[i]!='\0' && (*cad)[i]!=',') {
			(*extraido)[i]=(*cad)[i];
			i++;
		}
		(*extraido)[i]='\0';
	}
	else{
		b=0;
		while((*cad)[i]!='\0'&&!b){
		(*extraido)[i]=(*cad)[i];
		switch((*cad)[i]){
		    case '{':
				cont_a1++;
				break;
			case '(':
				cont_a2++;
				break;
			case '[':
				cont_a3++;
				break;
			case '}':
				cont_c1++;
				break;
			case')':
				cont_c2++;
				break;
			case']':
				cont_c3++;
				break;
		}
		if(cont_a1-cont_c1==0&&cont_a2-cont_c2==0&&cont_a3-cont_c3==0){
		b=1;
		}
		i++;
	}
	(*extraido)[i]='\0';
	}
	i++;
	if (i<strlen(*cad)) {
		j=0;
		while ((*cad)[i]!='\0'){
		    s_aux[j]=(*cad)[i];
			j++;
			i++;
		}
		s_aux[j]='\0';
		(*cad)=s_aux;
	} else (*cad)=NULL;
}
void separa_CAD(tElem cad, tVec vec,int* t){
	int i=0;
	char* aux;
	
	eliminarPrimerUltimoCaracter((cad));
	while(cad!=NULL){
		aux=malloc(sizeof(char)*255);
		getElemt(&cad,&aux);
		vec[i]=aux;
			i++;
		}
		*t=i;
}

	
	void leeCad(char *cadena, int tam){
		int j, m;
		/*obtener el primer caracter del stdin*/
		m=getchar();
		/*ANALIZAR EL PRIMER CARACTER LE�DO*/
		if (m!=EOF) { /*si el primer caracter no es fin de archivo*/
			
			/*inicializacion del �ndice que maneja el vector de char*/
			j=0;
			/*si el primer caracter leido no es un enter, se lo guarda en la cadena*/
			if (m!='\n'){ 
				cadena[j]=m; 
				j++;
			}
			/*LEER DEL SEGUNDO CARACTER EN ADELANTE*/
			/*leer el resto de los caractaeres y ponerlos en el vector de char*/
			m=getchar();
			while (j<tam-1 && m!=EOF && m!='\n') {
				cadena[j]=m;
				m=getchar();
				j++;
			}
			/*agregar marca de fin de cadena*/
			cadena[j]='\0';
			
			/*vaciar la pila*/
			while(m!=EOF && m!='\n')
				m=getchar();
			
		} else {
			/*si se lee el fin del archivo en el primer caracter, no hay cadena*/
			/*solo poner la marca de fin de cadena*/
			cadena[0]='\0';
		}
	}
		
