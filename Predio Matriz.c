#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x = 5, y = 3, z = 3;
    int matriz[5][3][3] = {0};
    int cX, cY, cZ, dif = 0;
    
    srand(time(NULL));
    int randX = rand() % x;
    int randY = rand() % y;
    int randZ = rand() % z;
    
    matriz[randX][randY][randZ] = 1;

    printf("Digite as coordenadas (x, y, z): ");
    scanf("%d %d %d", &cX, &cY, &cZ);
    
    //distancia
    int difX = (cX - randX), difY = (cY - randY), difZ = (cZ - randZ);
    if(difX < 0){
        difX = randX - cX;
    }
    if(difY < 0){
        difY = randY - cY;
    }
    if(difZ < 0){
        difZ = randZ - cZ;
    }
    //dif = abs(cX - randX) + abs(cY - randY) + abs(cZ - randZ);
    printf("Errou! Faltam %d passos\n", dif);
    
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
    int difsoma = difX+difY+difZ;
    //int ababa = abs(cX-l)+abs(cY-m)+abs(cZ-n);
    printf ("%d %d %d", l+1, m+1, n+1); //Mostrar coordenadas
    //printf ("\n%d passos", ababa);
    printf("FALTAM %d", difsoma);
    return 0;
}