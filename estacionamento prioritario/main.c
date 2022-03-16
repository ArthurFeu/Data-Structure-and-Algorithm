#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

void retira(FilaL2 *estacionamento, float placa){

	if (!fila_busca_l(estacionamento, placa)) {
		return;
	}
	while (1) {
		Lista elemento = fila_retira_fim_l(estacionamento);
		if (elemento.placa == placa) {
			printf("Carro retirado com sucesso!\n");
			return;
		}
		fila_insere_ini_l(estacionamento,elemento.placa,elemento.idade);
	}
}

int main(){
	system("clear");
	FilaL2 *estacionamento=fila_cria_l();
	float placa;
	int x;
	int tam_est, quant=0;
	int vatuais=0;
	int idade;


		printf("Digite o tamanho (número de vagas) do estacionamento:  ");
		scanf("%d", &tam_est);
		printf("\n");


		MENU:
		vatuais = tam_est - quant;

		printf("\nNúmero de vagas disponíveis: %d \n", vatuais);
		printf("\nOPÇÕES:\n\n");
		if (quant < tam_est)
			printf("1) Estacionar um carro.\n");
		else
			printf("1) -- Impossível inserir! Estacionamento Lotado --\n");
			printf("2) Retirar um carro.\n");
			printf("3) Fechar estacionamento.\n\n");
			printf(">> ");
			scanf("%i",&x);
			printf("\n");

	switch(x){ //menu

//inserir elementos

		case 1:
			if (quant >= tam_est) {
				system("clear");
				printf("OPÇÃO INVÁLIDA\n\n\n");
				printf("\nEstado do estacionamento:\n");
				fila_imprime_l(estacionamento);
				printf("\n");
				goto MENU;
				break;
			}
			
			printf("\nInforme a placa do carro que será estacionado:  ");
			scanf("%f",&placa);
			printf("Informe a idade do proprietário do carro:  ");
			scanf("%d", &idade);
			printf("\n");
			estacionamento->ini=lst_insere_ordenado(estacionamento->ini, placa, idade);
			quant++;
			system("clear");
			printf("Estado atual do estacionamento:\n\n");
			fila_imprime_l(estacionamento);
			printf("\n");
			goto MENU;
			break;

//retirar elementos

		case 2:
			if(fila_vazia_l(estacionamento)){
			system("clear");
			printf("\nVazio!\n");
			goto MENU;
			}

			printf("Informe a placa do carro que será retirado:  ");
			scanf("%f",&placa);
			retira(estacionamento,placa);
			system("clear");
			printf("Estado atual do estacionamento:\n\n");
			fila_imprime_l(estacionamento);
			printf("\n");
			quant = quant-1;
			goto MENU;
			break;

//fechar programa

		case 3:
			return 0;
			break;
			}
}		