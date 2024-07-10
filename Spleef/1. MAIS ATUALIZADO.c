#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void impressao(char matriz[5][5], int lin_bola, int col_bola, int andar, int x, int y, int passos_andar, int lin_buraco, int col_buraco) {
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
    system("cls");

    // Imprime o estado atual
    for (int l = 0; l < x; l++) {
        for (int c = 0; c < y; c++) {
            printf("%c ", matriz[l][c]);
        }
        printf("\n");
    }
    printf("Andar: %d\n", andar);
    printf("%d steps\n", passos_andar);
    usleep(500000); //0.5 segundos
}

int main() {
    // Estrutura de dados
    int x = 5, y = 5;
    char matriz[5][5];
    int andar = 10;
    int repeat = 0;
    int passos_tot = 0, passos_andar = 0;

    srand(time(NULL));

    // BOLA: O
    int lin_bola = rand() % x;
    int col_bola = rand() % y;

    while (repeat < 10) { // repetir 10 vezes
        passos_andar = 0;  
        printf("Andar: %d\n", andar);

        // BURACO: X
        int lin_buraco = rand() % x; // Linha
        int col_buraco = rand() % y; // Coluna

        // Inicialização da matriz 5x5 VAZIA
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

        // Andando
        do {
            // Escolhe direcao aleatória entre 0 (cima), 1 (direita), 2 (baixo), 3 (esquerda)
            int direction = rand() % 4;
            int new_lin_bola = lin_bola;
            int new_col_bola = col_bola;

            if (direction == 0 && matriz[lin_bola - 1][col_bola] != '9') { // cima
                new_lin_bola--;
            } else if (direction == 1 && matriz[lin_bola][col_bola + 1] != '9') { // direita
                new_col_bola++;
            } else if (direction == 2 && matriz[lin_bola + 1][col_bola] != '9') { // baixo
                new_lin_bola++;
            } else if (direction == 3 && matriz[lin_bola][col_bola - 1] != '9') { // esquerda
                new_col_bola--;
            }
 // Calcula a nova distância
            dist_atual = abs(lin_buraco - new_lin_bola) + abs(col_buraco - new_col_bola);

            impressao(matriz, new_lin_bola, new_col_bola, andar, x, y, passos_andar, lin_buraco, col_buraco);

            // Se a distância diminuiu ou se a posição é válida, move a bola
            if (dist_atual <= dist_ant) {
                lin_bola = new_lin_bola;
                col_bola = new_col_bola;
                dist_ant = dist_atual;
                impressao(matriz, new_lin_bola, new_col_bola, andar, x, y, passos_andar, lin_buraco, col_buraco);
            }

            // Incrementa os passos a cada tentativa de movimento
            passos_andar++;

        } while (lin_bola != lin_buraco || col_bola != col_buraco);

        // Atualiza a posição inicial da bola para o próximo andar
        andar--;
        repeat++;
        passos_tot += passos_andar;
    }

    // Calcula a média de passos por andar
    printf("Passos: %d passos totais\n", passos_tot);
    int media = passos_tot / 10;
    printf("\nMedia: %d passos por andar\n", media);

    return 0;
}