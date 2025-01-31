#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void impressao(char matriz[5][5], int lin_bola, int col_bola, int andar, int passos, int x, int y, int passos_andar, int dist_ant, int dist_atual) {
    // Atualiza a matriz
    matriz[lin_bola][col_bola] = 'O';

    // Limpa a tela :D
    system("cls");

    // Imprime o estado atual
    for (int l = 0; l < x; l++) {
        for (int c = 0; c < y; c++) {
            printf("%c ", matriz[l][c]);
        }
        printf("\n");
    }
    
    printf("Andar: %d\n", andar);
    printf("Passos no andar: %d\n", passos_andar);
    
    usleep(500000);
}

int main() {
    int x = 5, y = 5;
    char matriz[5][5];
    int andar = 10;
    int repeat = 0;
    int passos = 0, passos_andar = 0;

    srand(time(NULL));

    // BOLA: O
    int lin_bola = rand() % x;
    int col_bola = rand() % y;

    while (repeat < 10) { // Repetir 10 vezes
        passos_andar = 0; //Zera os passos por andar
        printf("Andar: %d\n", andar);

        // BURACO: X
        int lin_buraco = rand() % x; // Linha
        int col_buraco = rand() % y; // Coluna

        // Inicialização da matriz 5x5 vazia
        for (int j = 0; j < x; j++) {
            for (int k = 0; k < y; k++) {
                matriz[j][k] = '-';
            }
        }

        // Coloca o buraco e a bola no espaço
        matriz[lin_bola][col_bola] = 'O';
        matriz[lin_buraco][col_buraco] = 'X';

        // Distância entre buraco e bola
        int dist_ant = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
        int dist_atual;
        int mov_lin = -1, mov_col = 0; // Variavel de movimento
    //Andando
        do {
            // Verifica a direção atual da bola ja que ela andou 1 p cima
            int new_lin_bola = lin_bola + mov_lin;
            int new_col_bola = col_bola + mov_col;

            // Verifica se é possível se mover :D na nova posição
            if (new_lin_bola >= 0 && new_lin_bola < x && new_col_bola >= 0 && new_col_bola < y) {
                dist_atual = abs(lin_buraco - new_lin_bola) + abs(col_buraco - new_col_bola);
                
                    impressao(matriz, new_lin_bola, new_col_bola, andar, passos, x, y, passos_andar, dist_ant, dist_atual);

                // Se a distância diminuiu, continua na mesma direção
                if (dist_atual < dist_ant) {
                    lin_bola = new_lin_bola;
                    col_bola = new_col_bola;
                    dist_ant = dist_atual;
                    
                } else { // Se não diminuiu, muda a direção de movimento
                    if (mov_lin == -1 && mov_col == 0) {
                        mov_lin = 0;  // Muda para tentar mover para a direita
                        mov_col = 1;
                    	
                    } else if (mov_lin == 0 && mov_col == 1) {
                        mov_lin = 1;  // Muda para tentar mover para baixo
                        mov_col = 0;
                        
                    } else if (mov_lin == 1 && mov_col == 0) {
                        mov_lin = 0;  // Muda para tentar mover para a esquerda
                        mov_col = -1;
                        
                    } else if (mov_lin == 0 && mov_col == -1) {
                        mov_lin = -1; // Muda para tentar mover para cima
                        mov_col = 0;
                        
                    }
                     passos++;
            		 passos_andar++;
                }
            } else {// Se não é possível mover na direção atual, retorna para a próxima direção
                if (mov_lin == -1 && mov_col == 0) {
                    mov_lin = 0;  // Retorna para tentar mover para a direita
                    mov_col = 1;
                } else if (mov_lin == 0 && mov_col == 1) {
                    mov_lin = 1;  // Retorna para tentar mover para baixo
                    mov_col = 0;
                } else if (mov_lin == 1 && mov_col == 0) {
                    mov_lin = 0;  // Retorna para tentar mover para a esquerda
                    mov_col = -1;
                } else if (mov_lin == 0 && mov_col == -1) {
                    mov_lin = -1; // Retorna para tentar mover para cima
                    mov_col = 0;
                }
            } //Se chegar na borda

            passos++;
            passos_andar++;

        } while (lin_bola != lin_buraco || col_bola != col_buraco);

        // Atualiza a posição inicial da bola para o próximo andar
        andar--;
        repeat++;
    }

    // Calcula a média de passos por andar
    printf("Passos: %d passos totais\n", passos);
    int media = passos / 10;
    printf("\nMedia: %d passos por andar\n", media);

    return 0;
}