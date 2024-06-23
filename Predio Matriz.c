#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Um prédio tem 5 andares e 9 quartos [3][3] por andar (45 quartos ao todo).
Procure um 1 em torno de vários 0.
Usuario vai colocar a coordenada como chute, e algoritmo diz a distancia entre o chute
e a posição (desconsidere a diagonal)
Dick: randomiza um numero 3 vezes([3][3][5]) para descobrir o valor 1*/
int main(){
    int x = 5, y = 3, z = 3;
    int matriz[5][3][3] = {0};
    int cX, cY, cZ, dif;
    
    srand(time(NULL));
    
    // Randomiza só o indice (posiçãoo)
    int randX = rand() % x;
    int randY = rand() % y;
    int randZ = rand() % z;
    
    // Colocando o 1 na posição gerada
    matriz[randX][randY][randZ] = 1;
/*
    //Pede ao usuario
    printf("Digite as coordenadas (x, y, z): ");
    scanf("%d %d %d", cX, cY, cZ);
    
        // Calcular a distancia
        int dif = abs(cX - randX) + abs(cY - randY) + abs(cZ - randZ);
        printf("Errou! Faltam %d passos\n", dif);*/
    
    int i, j, k, l, m, n;
    for (i=0; i<x; i++) {
        for (j=0; j<y; j++) {
            for (k=0; k<z; k++) {
                printf("%d ", matriz[i][j][k]);
                if (matriz[i][j][k] == 1){ //Grava a posição atual do 1
                	l = i;
                	m = j;
                	n = k;
				}
            }
            printf("\n");
        }
        printf("\n");
    }
    printf ("%d %d %d", l+1, m+1, n+1); //Mostrar coordenadas
    
    return 0;
}