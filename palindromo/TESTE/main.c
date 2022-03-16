#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhas.h"


int main()
{ 

char fraseOriginal[MAX], fraseInvertida[MAX];
         int i, tamanho;
      
         printf("\n=== Checar existencia de palindromo ===\n\n    Entre com a frase a ser checada \n(sem caracteres especiais e sem espacos) \n\nFrase: ");
         scanf("%s", fraseOriginal);

         //// coloca frase na pilha ////
   
         tamanho = strlen( fraseOriginal );

         for( i = 0; i < tamanho; i++ )
                   push( fraseOriginal[i] );
   
   
          //// tira frase da pilha, agora invertida ////
   
          for( i = 0; i < tamanho; i++ )
                    pop( &fraseInvertida[i] );   
   
      
          // fraseInvertida[tamanho] = '{FONTE}'; // finaliza string invertida

          //// mostra frase invertida ////
          printf("Frase Invertida: %s", fraseInvertida);
   
          //// checa se as duas strings sao iguais ////
          if( !strcmp( fraseOriginal, fraseInvertida) )
                     printf("\nResultado: Confere, palindromo existente\n\n");
   
          else
                     printf("\nResultado: Nao confere\n\n");

  return 0;
}