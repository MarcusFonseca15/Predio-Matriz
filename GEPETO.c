#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Para utilizar a função sleep()

int main() {
    int x = 5, y = 5; // Tamanho da matriz
    char matriz[5][5];
    
    srand(time(NULL));

    // Posição aleatória da bola ('O')
    int lin_bola = rand() % x;
    int col_bola = rand() % y;

    // Posição aleatória do buraco ('X')
    int lin_buraco = rand() % x;
    int col_buraco = rand() % y;
    
    // Garantir que buraco e bola não ocupem a mesma posição inicial
    while (lin_bola == lin_buraco && col_bola == col_buraco) {
        lin_buraco = rand() % x;
        col_buraco = rand() % y;
    }

    // Inicialização da matriz vazia
    for (int j = 0; j < x; j++) {
        for (int k = 0; k < y; k++) {
            matriz[j][k] = '-';
        }
    }

    // Colocar buraco e bola na matriz
    matriz[lin_bola][col_bola] = 'O'; // Bola na matriz representa 'O'
    matriz[lin_buraco][col_buraco] = 'X'; // Buraco na matriz representa 'X'

    // Calcular distância inicial entre buraco e bola
    int dist_ant = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
    int dist_atual = 0;

    // Movimento da bola ('O') em direção ao buraco ('X')
    do {
        // Calcula a direção para mover a bola
        int mov_lin = 0, mov_col = 0;

        // Mover a bola na direção do buraco
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
        
        // Limpar a tela antes de imprimir a matriz atualizada
        system("cls");

        // Mover a bola na matriz
        matriz[lin_bola][col_bola] = '-'; // Apaga a posição anterior da bola
        lin_bola += mov_lin;
        col_bola += mov_col;
        matriz[lin_bola][col_bola] = 'O'; // Coloca a bola na nova posição

        // Imprimir matriz atual com animação
        for (int l = 0; l < x; l++) {
            for (int c = 0; c < y; c++) {
                printf("%c ", matriz[l][c]);
            }
            printf("\n");
        }

        // Pausar por um curto período de tempo para simular animação
        usleep(500000); // 500 milissegundos (0.5 segundos)

        // Atualizar distância atual (não é mais necessário para o movimento da bola)

    } while (lin_bola != lin_buraco || col_bola != col_buraco);

    // Imprimir mensagem de sucesso e sair do programa
    printf("\nBuraco alcançou a bola!\n");

    return 0;
}
