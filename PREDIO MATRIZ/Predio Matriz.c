#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // notas pessoais**
    // abs retorna o valor absoluto de uma diferença, por exemplo 1-5 = -4
    // abs retornará somente o 4.

    // randomização da posição do 1
    int x = 5, y = 3, z = 3;
    int matriz[5][3][3] = {0};
    int cX, cY, cZ, dif = 0;

    srand(time(NULL));
    int randX = (rand() % x) + 1; // altura
    int randY = (rand() % y) + 1; // linha     //adiciona +1 para que o valor randomizado inclua 0
    int randZ = (rand() % z) + 1; // coluna
    
    matriz[randX - 1][randY - 1][randZ - 1] = 1;   //adicona -1 para que as coordenadas sejam 
                                                   //ajustadas aos indices da matriz pq a matriz começa em 0

    while (1) {
        printf("Digite as coordenadas (x, y, z): ");
        scanf("%d %d %d", &cX, &cY, &cZ);

        // calculo distancia
        dif = abs(cX - randX) + abs(cY - randY) + abs(cZ - randZ);

        if (dif == 0) {
            printf("Parabens! Voce acertou!!\n");
            break;
        } else {
            printf("Errou! Faltam %d passos\n", dif);
        }
    }

    // imprime a matriz
    int i, j, k;
    for (i = 4; i >= 0; i--) { // Invertido pra imprimir direito
        for (j = 0; j < y; j++) {
            for (k = 0; k < z; k++) {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("Coordernada Real: %d, %d, %d\n", randX, randY, randZ); // Mostrar coordenadas reais
    return 0;
}