#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand ( time(NULL) );
    int predio[3][3][5], comprimento, largura, altura, comprimento_usuario, largura_usuario, altura_usuario, distancia_total;
    memset(predio, 0, sizeof(int) * 3 * 3 * 5);
    
   comprimento = rand() % 3;
   largura = rand() % 3;
   altura = rand() % 5;
   
   predio[comprimento][largura][altura] = 1;
   
   while (1) {
       printf("\nInsira o comprimento: ");
       scanf("%d", &comprimento_usuario);
       printf("Insira a largura: ");
       scanf("%d", &largura_usuario);
       printf("Insira a altura: ");
       scanf("%d", &altura_usuario);
       
       if (comprimento_usuario >= 0 && comprimento_usuario <= 3 && altura_usuario >= 0 
       && altura_usuario <= 5 && largura_usuario >= 0 && largura_usuario <= 3) {
       
           if (comprimento_usuario == comprimento && largura_usuario == largura && altura_usuario == altura) {
               printf("Voce acertou! Parabens!");
               break;
           } 
           
           distancia_total = abs(comprimento_usuario - comprimento) + abs(largura_usuario - largura) + abs(altura_usuario - altura);
           printf("Distancia total: %d", distancia_total);
       } else {
           printf("\nVoce inseriu o valor errado. Tente novamente!");
       }
   }
   
   printf("\n%d %d %d", comprimento, largura, altura);

    return 0;
}