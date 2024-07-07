
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

    //BOLA: O
        int lin_bola = (rand() % z);
        int col_bola = (rand() % w);
        
while (repeat!=10){ //repetir 10 vezes/
    printf("Andar: %d", andar);
    srand(time(NULL));
    //DEFINE BURACO: X
        int lin_buraco = (rand() % x); // Linha
        int col_buraco = (rand() % y); // Coluna

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
    int dist_atual;
    int mov_lin, mov_col;
    //ANDANDO
    do {
    //Anda só pra cima
        mov_col += 1;
        passos++;
        if (col_bola += 1){
        dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
        }
        //Se dist aumenta, volta, senão, continua
        if (dist_atual > dist_ant){
            mov_col -= 1;
            passos++;
        } else {
            mov_col += 1;
            passos++;
        } 
        if (col_bola -= 1){
            mov_lin += 1;
            passos++;
            dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
        }
        if (dist_atual > dist_ant){
            mov_lin -= 1;
            passos++;
        } else {
            mov_lin += 1;
            passos++;
        }
        //BARREIRA 1vetor a mais ao redor do 5x5 para bolinha não escapar
        system("cls");

        // Atualiza a posição da bola. Aux checa se alterou o
        //valor de linbola e colbola
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
} while (lin_bola != lin_buraco || col_bola != col_buraco);

    //DISTANCIA ATUAL
    //    dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
    //passos += dif; //acumula passos a cada andar que passa
andar--;
repeat++;
    } while (andar>0); //while (repeat!=10){ //repetir 10 vezes/
int media = passos/10;
printf("\nMedia: %d passos por andar", media);
    return 0;
}