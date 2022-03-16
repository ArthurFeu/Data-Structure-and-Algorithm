#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhas.h"
int top = -1;
void pop( TIPO_STACK *elemento )
{
          if( top == -1 ) // pilha vazia
                   printf("\npilha vazia\n");
   
          else {
                    *elemento = stack[top];
                    top--;
          }
   
} // fim funcao

void push( TIPO_STACK elemento )
{
          if( top == MAX ) // pilha cheia
                    printf("\npilha cheia\n");
   
          else {
      top++;   
                    stack[top] = elemento; 
          }
} // fim funcao

// //Pilhas com vetor
// Pilha *pilha_cria() {
// 	Pilha *p = (Pilha *) malloc(sizeof(Pilha));
// 	p->n = 0;

// 	return p;
// }

// void pilha_push(Pilha *p, char v) {
// 	if (p->n == N) {
// 		printf("A capacidade da pilha estorou.");
// 		exit(1);
// 	}

// 	p->vet[p->n++] = v;
// }

// char pilha_pop(Pilha *p) {
// 	if (pilha_vazia(p)) {
// 		printf("Pilha vazia.");
// 		exit(1);
// 	}

// 	return p->vet[--p->n];
// }

// int pilha_vazia(Pilha *p) {
// 	return (p->n == 0);
// }

// void pilha_libera(Pilha *p) {
// 	free(p);
// }

// void pilha_imprime(Pilha *p){
// 	int i;

// 	for(i=p->n-1;i>=0;i--){
// 		printf("%c\n", p->vet[i]);
// 	}
// }


// void pilha_lst_push(Pilha_lst *p, char v){
// 	Lista *l=(Lista *)malloc(sizeof(Lista));
// 	l->info=v;
// 	l->prox=p->prim;
// 	p->prim=l;
// }

// char pilha_lst_pop(Pilha_lst *p){
// 	Lista *l;
// 	char c;
// 	if(pilha_lst_vazia(p)){
// 		printf("Pilha vazia\n");
// 		exit(1);
// 	}
// 	l=p->prim;
// 	c = l->info;
// 	p->prim = l->prox;
// 	free(l);
// 	return c;
// }

// int pilha_lst_vazia(Pilha_lst *p){
// 	return (p->prim==NULL);
// }

// void pilha_lst_libera(Pilha_lst *p){
// 	Lista *l=p->prim;
// 	while(l != NULL){
// 		Lista *t = l->prox;
// 		free(l);
// 		l=t;
// 	}
// 	free(p);
// }

// void pilha_lst_imprime(Pilha_lst *p){
// 	Lista *l;

// 	for(l=p->prim;l!=NULL;l=l->prox){
// 		printf("%c\n", l->info);
// 	}
// }