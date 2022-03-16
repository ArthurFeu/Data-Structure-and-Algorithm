#include <stdio.h>
#include <stdlib.h>
#include "arv.h"


//criar uma arvore vazia
Arv *arv_criavazia(){
	return NULL; //retorna dado=esq=dir como NULL
}

//criar uma arvore com uma raiz/no
Arv *arv_cria(char c, Arv *sae, Arv *sad){
	Arv *p = (Arv*) malloc (sizeof(Arv));
	p->dado = c;
	p->esq = sae;
	p->dir = sad;
	return p; //retorna a arvore criada
}

//faz com que a árvore fique vazia
int arv_vazia(Arv *a){
	return a == NULL;
}

//funçao para imprimir recursivamente os elementos da arvore, de forma simetrica (esq->root->dir)
void arv_imprime (Arv *a){
int i=arv_altura(a);
	if (!arv_vazia(a)){
		arv_imprime(a->esq);
		if (a->esq!=NULL && a->dir!=NULL)// && arv_altura(a)==-1)
			printf("r(%c) ",a->dado); //imprime o root destacado
		else
			printf("%c ",a->dado);
		arv_imprime(a->dir);
	}
	//
}

//funçao para imprimr de uma forma visualmente agradavel
/*ex:
root=b, esq=a, 
dir=c
impressao
	b
a		c*/
void arv_imprimeO (Arv *a){

}

//funçao para liberar recursivamente os elementos da arvore
Arv *arv_libera (Arv *a){
	if (!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free (a);
	}
	return NULL;
}

//funçao para encontrar se um elemento c pertence a arvore a
int arv_pertence (Arv *a, char c){
	if (arv_vazia(a))
		return 0;
	else
		return a->dado==c || arv_pertence(a->esq,c) || arv_pertence(a->dir,c);
}

//se a>b, retorna a, se nao retorna b
static int max2(int a, int b){
	return (a>b) ? a : b;
}

//funçao para dar a altura da arvore
int arv_altura (Arv *a){
	if (arv_vazia(a))
		return -1; //por definiçao
	else
		return 1 + max2(arv_altura(a->esq), arv_altura(a->dir));
}

//função para inserir elementos em uma arvore binaria, sendo que o elemento menor que a raiz vai pra esquerda e maior vai pra direita
Arv *arv_insere(Arv *a, char c){
	if (a==NULL){
		a=(Arv*) malloc(sizeof(Arv));
		a->dado=c;
		a->esq=a->dir=NULL;
	}
	else if (c<a->dado)
		a->esq=arv_insere(a->esq,c);
	else
		a->dir=arv_insere(a->dir,c);	
}

// FUNÇÕES PARA ARVORES COM NUMEROS VARIAVEIS DE FILHOS

Arvv *arvv_cria (char c){
	Arvv *a = (Arvv*) malloc (sizeof(Arvv));
	a->dado = c;
	a->prim = NULL;
	a->prox = NULL;
	return a;
}

void arvv_insere (Arvv *a, Arvv *sa){
	sa->prox=a->prim;
	a->prim=sa;
}

void arvv_imprime (Arvv *a){
	Arvv *p;
	printf("%c\n",a->dado);
	for (p=a->prim;p!=NULL;p=p->prox)
		arvv_imprime(p);
}

int arvv_pertence (Arvv *a, char c){
	Arvv *p;
	if (a->dado==c)
		return 1; //achou
	else{
		for (p=a->prim;p!=NULL;p=p->prox){
			if (arvv_pertence(p, c))
				return 1; //achou
		}
		return 0;
	}
}

void arvv_libera (Arvv *a){
	Arvv *p=a->prim;
	while (p!=NULL){
		Arvv *t=p->prox;
		arvv_libera(p);
		p=t;
	}
	free(a);
}

int arvv_altura (Arvv *a){
	int hmax=-1; //tratar caso de zero filhos
	Arvv *p;
	for (p=a->prim;p!=NULL;p=p->prox){
		int h = arvv_altura(p);
		if (h>hmax)
			hmax=h;
	}
	return hmax+1;
}
