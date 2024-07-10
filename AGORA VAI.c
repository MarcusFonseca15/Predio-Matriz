
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void impressao(char matriz[5][5], int lin_bola, int col_bola, int andar, int passos, int x, int y, int lin_buraco, int col_buraco) {
// inicialização da matriz 5x5 VAZIA
    for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                matriz[j][k] = '-';
            }
    }    
    // Atualiza a matriz
    matriz[lin_buraco][col_buraco] = 'X';
    matriz[lin_bola][col_bola] = 'O';

    // Limpa a tela (só para sistemas Windows)
    //system("cls");

    // Imprime o estado atual
    for (int l = 0; l < x; l++) {
        for (int c = 0; c < y; c++) {
            printf("%c ", matriz[l][c]);
        }
        printf("\n");
    }
    printf("Andar: %d\n", andar);
    printf("%d passitos\n", passos);
    usleep(500000); //0.5 segundos
}

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
 //BURACO: X
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
int dist_atual = 0;

    do {                                            //enqt bola nao ta no buraco
        // Tentar mover a bola na direção do buraco
        int mov_lin = 0, mov_col = 0; //quantas casas a bola deve pular
        //int new_lin_bola = lin_bola;
        //int new_col_bola = col_bola;

    //Primeiro movimento: 1 passo pra cima
    lin_bola--;
    dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
        if (dist_atual > dist_ant){
            lin_bola++;
        } else {lin_bola--;}

    //Move pra direita
        if (lin_bola++) {
            col_bola++;
            dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
                if (dist_atual > dist_ant){
                col_bola--;
                } else {col_bola++;}
        }
    
    //Move pra baixo
        if (col_bola--){
            lin_bola++;
         dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
        if (dist_atual > dist_ant){
                lin_bola--;
                } else {lin_bola++;}
        }
    
    //Move pra esquerda
        if (lin_bola--){
            col_bola--;
             dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
             if (dist_atual > dist_ant){
                col_bola++;
                } else {col_bola--;}
        }
    
    system("cls");
    passos++;
    
    // Atualiza a posição da bola
        matriz[lin_bola][col_bola] = '-';
        lin_bola += mov_lin;
        col_bola += mov_col;
        matriz[lin_bola][col_bola] = 'O';
        
    impressao(matriz, lin_bola, col_bola, andar, x, y, lin_buraco, col_buraco);

        } while (lin_bola != lin_buraco || col_bola != col_buraco); //enqt bola nao ta no buraco

andar--;
repeat++;
int passostot += passos;
    } //enquanto repeat não é 10
int media = passos/10;
printf("\nPassos totais: %d", passostot);
printf("\nMedia: %d passos por andar", media);
    return 0;
} 