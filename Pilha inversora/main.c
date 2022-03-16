#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"
//teste de edição :P
//teste de edição :D
int main(){	
	Pilha *p1 = pilha_cria(), *p2 = pilha_cria();
	int tam;
	system("clear");
	printf("Digite o tamanho: ");
	scanf("%d", &tam);
	printf("\n");
	//lê os valores:
	for (int i = 0; i < tam; i++) {
		int num;
		printf("Digite o valor n° %d: ", i + 1);
		scanf("%d", &num);
		pilha_push(p1, num);
	}

	//imprime pilha:
	printf("\nPilha normal:\n");
	pilha_imprime(p1);
	//inverte a pilha:
	while (!pilha_vazia(p1)) {
		pilha_push(p2, pilha_pop(p1));
	}
	//imprime pilha inversa:
	printf("\nPilha inversa:\n");
	pilha_imprime(p2);

	//free
	pilha_libera(p1);
	pilha_libera(p2);
	return 0;
}
