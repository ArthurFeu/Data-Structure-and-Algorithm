#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila2.h"



static int incr(int i){
	return (i+1)%N;
}

FilaL2*fila_cria_l(){
	FilaL2*f = (FilaL2*) malloc(sizeof(FilaL2));
	f->ini = NULL;
	return f;
}

void fila_insere_ini_l(FilaL2 *fila, float v, char n[6]){
	// printf("entrou insere ini l\n");
	Lista *l=(Lista *)malloc(sizeof(Lista));
	l->id=v;
	for (int i = 0; i < 6; i++) l->senha[i]=n[i];
	l->prox=fila->ini;
	fila->ini=l;
	// printf("fim insere ini l\n");
	return;
}



int fila_vazia_l(FilaL2*f){
	return (f->ini == NULL);
}

void fila_imprime_l(FilaL2*f){
	Lista *q;

	for(q=f->ini; q!= NULL; q=q->prox){

				printf(" ID: %0.f \t",q->id);
				printf("\t\tsenha: %s \n",q->senha);
			

}
}


Lista* fila_busca_l(FilaL2*fila, float id){
	Lista *q;
	for(q=fila->ini; q!=NULL; q=q->prox){
		if(id == q->id){
			return q;
		}
	}
	return NULL;
}

Lista *lst_insere_ordenado(Lista *l, float v, char n[6]){
	Lista *novo;
	Lista *ant = NULL;
	Lista *p = l;
	// while (p!=NULL&&p->classe<i){
	// 	ant=p;
	// 	p=p->prox;
	// }
	novo = (Lista*) malloc(sizeof(Lista));
	novo->id=v;
	strcpy (novo->senha,n);
	novo->prox;
	if (ant==NULL){
		novo->prox=l;
		l=novo;
	}
	else {
		novo->prox=ant->prox;
		ant->prox=novo;
	}
	return l;
}
