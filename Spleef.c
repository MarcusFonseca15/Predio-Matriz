
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(){

// estrutura de dados
int x=5, y=5, w=5, z=5, l, c;
char matriz[5][5];
int passos = 0, andar=10;
int repeat=0;

while (repeat!=10){ //repetir 10 vezes/
printf("Andar: %d", andar);
 srand(time(NULL));
 //BURACO: X
    int lin_buraco = (rand() % x); // Linha
    int col_buraco = (rand() % y); // Coluna
//BOLA: O
    int lin_bola = (rand() % z);
    int col_bola = (rand() % w);
    
    // Garantir que buraco e bola não spawne no msm lugar
    while (lin_bola == lin_buraco && col_bola == col_buraco) {
        lin_buraco = rand() % x;
        col_buraco = rand() % y;
    }

// inicialização da matriz 5x5 VAZIA
    for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                matriz[j][k] = '-';
            }
    }
//BOTA O BURACO E A BOLA NO ESPAÇO
matriz[lin_bola][col_bola] = 'O';
matriz[lin_buraco][col_buraco] = 'X';

// distancia entre buraco e bola, se a diferença entre a
//bola e o buraco diminuir continua andando na mesma direção,
//se aumentar, checa outra direção aleatoria
int dist_ant = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola); //distancia bola pro buraco
int dist_atual = 0;
//printf("%d passos\n", dist); //Debug Log.
//ANDANDO
    do {
        // Tentar mover a bola na direção do buraco
        int mov_lin = 0, mov_col = 0;
        
        if (lin_bola < lin_buraco) {
            mov_lin = 1;
        } else if (lin_bola > lin_buraco) {
            mov_lin = -1;
        } else {
            if (col_bola < col_buraco) {
                mov_col = 1;
            } else if (col_bola > col_buraco) {
                mov_col = -1;
            } 
        }
        
        system("cls");
        passos++;

        // Atualiza a posição da bola
        matriz[lin_bola][col_bola] = '-';
        lin_bola += mov_lin;
        col_bola += mov_col;
        matriz[lin_bola][col_bola] = 'O';

// Imprime o estado atual
    for(l = 0; l < 5; l ++){
        for(c = 0; c < 5; c ++){
            printf("%c ", matriz[l][c]);
        }
        printf("\n");
    }
    printf("Andar: %d\n", andar);
	printf("Passos: %d passos totais\n", passos);
    usleep(5000000);

    //DISTANCIA ATUAL
    //    dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
    
    } while (lin_bola != lin_buraco || col_bola != col_buraco);
    //passos += dif; //acumula passos a cada andar que passa
andar--;
repeat++;
} while (andar>0);
int media = passos/10;
printf("Passos: %d passos totais", passos);
printf("Média: %d passos por andar", media);
    return 0;
}