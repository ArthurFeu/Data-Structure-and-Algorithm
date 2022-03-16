#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main(){
    system("clear");
    Arv *tree=arv_criavazia();
    char resp,c;
    int valor = 1;

    printf("\n==Digite os Elementos==\n");
            printf("Insira (%do valor):\t", valor);
            scanf(" %c",&c);
            valor++;
            tree=arv_insere(tree,c);
            X:
            printf("\nDeseja inserir mais? (Sim == s/S || Não == qualquer tecla):\t");
            scanf(" %c",&resp);
                
                if (resp == 's' || resp == 'S'){
                    printf("Insira (%do valor):\t", valor);
                    scanf(" %c",&c);
                    tree=arv_insere(tree,c);
                    goto X;
            }
                else{
                    printf("\nÁrvore preenchida (simétrica):\n");
                    arv_imprime(tree);
                    printf("\n\n");
                } 
    return 0;
}