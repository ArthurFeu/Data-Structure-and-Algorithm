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

void fila_insere_ini_l(FilaL2 *fila, float v, int i){
	Lista *l=(Lista *)malloc(sizeof(Lista));
	l->placa=v;
	l->idade=i;
	l->prox=fila->ini;
	fila->ini=l;
}

Lista fila_retira_fim_l(FilaL2 *fila){
	Lista *t=fila->ini;
	Lista *ant;
	Lista retirado;
	if(fila_vazia_l(fila)){
		printf(" vazio!");
		exit(1);
	}
	if (t->prox == NULL)
	{
		return retirado;
	}
	while(t->prox!=NULL){
		ant=t;
		t=t->prox;
	}
	
	ant->prox=NULL;
	retirado.placa=t->placa;
	retirado.idade=t->idade;
	free(t);
	return retirado;
}

int fila_vazia_l(FilaL2*f){
	return (f->ini == NULL);
}

void fila_imprime_l(FilaL2*f){
	Lista *q;

	for(q=f->ini; q!= NULL; q=q->prox){
		int x=q->placa;
		if (x == NULL)
		{
			printf("Estacionamento Vazio\n");
		}else{
	 	printf(" Placa: %0.f \tIdade do Propietário: %d anos\n",q->placa, q->idade);
}
}
}

Lista* fila_busca_l(FilaL2*fila, float placa){
	Lista *q;
	for(q=fila->ini; q!=NULL; q=q->prox){
		if(placa == q->placa){
			return q;
		}
	}
	return NULL;
}

Lista *lst_insere_ordenado(Lista *l, float v, int i){
	Lista *novo;
	Lista *ant = NULL;
	Lista *p = l;
	while (p!=NULL&&p->idade<i){
		ant=p;
		p=p->prox;
	}
	novo = (Lista*) malloc(sizeof(Lista));
	novo->placa=v;
	novo->idade=i;
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