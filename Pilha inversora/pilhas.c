#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

//Pilhas com vetor
Pilha *pilha_cria() {
	Pilha *p = (Pilha *) malloc(sizeof(Pilha));
	p->n = 0;

	return p;
}

void pilha_push(Pilha *p, int v) {
	if (p->n == N) {
		printf("A capacidade da pilha estorou.");
		exit(1);
	}

	p->vet[p->n++] = v;
}

int pilha_pop(Pilha *p) {
	if (pilha_vazia(p)) {
		printf("Pilha vazia.");
		exit(1);
	}

	return p->vet[--p->n];
}

int pilha_vazia(Pilha *p) {
	return (p->n == 0);
}

void pilha_libera(Pilha *p) {
	free(p);
}

void pilha_imprime(Pilha *p){
	int i;

	for(i=0;i<p->n;i++){
		printf(" %d\n", p->vet[i]);
	}
}

//Pilhas com listas
Pilha_lst *pilha_lst_cria(){
	Pilha_lst *p=(Pilha_lst *)malloc(sizeof(Pilha_lst));
	p->prim=NULL;
	return p;
}

void pilha_lst_push(Pilha_lst *p, int v){
	Lista *l=(Lista *)malloc(sizeof(Lista));
	l->info=v;
	l->prox=p->prim;
	p->prim=l;
}

int pilha_lst_pop(Pilha_lst *p){
	Lista *l;
	int c;
	if(pilha_lst_vazia(p)){
		printf("Pilha vazia\n");
		exit(1);
	}
	l=p->prim;
	c = l->info;
	p->prim = l->prox;
	free(l);
	return c;
}

int pilha_lst_vazia(Pilha_lst *p){
	return (p->prim==NULL);
}

void pilha_lst_libera(Pilha_lst *p){
	Lista *l=p->prim;
	while(l != NULL){
		Lista *t = l->prox;
		free(l);
		l=t;
	}
	free(p);
}

void pilha_lst_imprime(Pilha_lst *p){
	Lista *l;

	for(l=p->prim;l!=NULL;l=l->prox){
		printf("%d\n", l->info);
	}
}