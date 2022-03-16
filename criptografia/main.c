#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila2.h"


void cripto(char *senha) {
    int i;
    for (i = 0; i < 6; i++) {
        char c = senha[i];
        if (c >= 'a' && c <= 'c')
            c += 26;
        c -= 3;
        senha[i] = c;
    }
}

void fila_imprime_cript(FilaL2 *f) {
    Lista *q;
    for (q = f->ini; q != NULL; q = q->prox) {
        char buffer[7];
        int i;
        for (i = 0; i < 7; i++)
            buffer[i] = q->senha[i];
        cripto(buffer);
        printf(" ID: %0.f \t",q->id);
	printf("\t\tsenha: %s \n",buffer);
    }
}
int main(){
	system("clear");
	FilaL2 *listasenhas=fila_cria_l();
	float id;
	int x;
	int tam_lst, quant=0;
	int latuais=0;
	char senha[6];

		printf("\n\t======== criptografia ========\n");
		printf("\n");
		printf("Digite o tamanho da lista: \n");
		scanf("%d", &tam_lst);

		MENU:
		latuais = tam_lst - quant;

		printf("\nTamanho restante da lista: %d \n", latuais);
		printf("\nOPÇÕES:\n\n");
		if (quant < tam_lst)
			printf("1) Inserir uma senha.\n");
		else
			printf("1) -- Impossível inserir! Lista Lotada --\n");
			printf("2) descriptografar senhas.\n");
			printf("3) Fechar Lista.\n\n");
			printf(">> ");
			scanf("%i",&x);
			printf("\n");

	switch(x){ //menu

//inserir elementos

		case 1:
			if (quant >= tam_lst) {
				system("clear");
				printf("OPÇÃO INVÁLIDA\n\n\n");
				printf("\nEstado da Lista:\n");
				fila_imprime_l(listasenhas);
				printf("\n");
				goto MENU;
				break;
			}
			
			printf("\nInforme a ID da senha que sera inserida:  ");
			scanf("%f",&id);
			printf("Informe a senha que sera inserida:  ");
			scanf("%s", senha);
			printf("%s\n", senha);


			listasenhas->ini=lst_insere_ordenado(listasenhas->ini, id, senha);
			quant++;
			system("clear");
			printf("Lista Atual:\n\n");
			fila_imprime_l(listasenhas);
			printf("\n");
			goto MENU;
			break;

//descriptografar uma senha

		case 2:
			if(fila_vazia_l(listasenhas)){
				system("clear");
				printf("\nVazia!\n");
				goto MENU;
			}
			printf("Senhas descriptografadas:\n");
            fila_imprime_cript(listasenhas); //erro na hora de imprimir as senhas descriptografadas
			printf("\n\n");
			goto MENU;
			break;

//fechar programa

		case 3:
			return 0;
			break;
			}
}		
