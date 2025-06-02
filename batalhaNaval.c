#include <stdio.h>

// --- Constantes para o jogo ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

/**
 * Desafio Batalha Naval - Nível Aventureiro
 *
 * Este programa inicializa um tabuleiro 10x10 e posiciona quatro
 * navios de tamanho 3: um horizontal, um vertical e dois diagonais,
 * um em cada tipo de diagonal (principal e secundária).
 */
int main() {
    // Declaração da matriz 10x10 para o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // --- 1. Inicialização do Tabuleiro com Água ---
    // Percorre toda a matriz, definindo cada célula como AGUA (0).
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- 2. Posicionamento dos Quatro Navios ---
    // As coordenadas foram escolhidas para não haver sobreposição.

    // Navio 1: HORIZONTAL (igual ao nível anterior)
    int linha_h = 1;
    int coluna_h = 1;
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_h][coluna_h + i] = NAVIO;
        }
    }

    // Navio 2: VERTICAL (igual ao nível anterior)
    int linha_v = 3;
    int coluna_v = 8;
    if (linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_v + i][coluna_v] = NAVIO;
        }
    }

    // Navio 3: DIAGONAL PRINCIPAL (linha e coluna aumentam juntas)
    int linha_d1 = 5;
    int coluna_d1 = 1;
    // Validação: garante que o navio cabe tanto na vertical quanto na horizontal
    if (linha_d1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna_d1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Incrementa a linha e a coluna a cada passo para formar a diagonal
            tabuleiro[linha_d1 + i][coluna_d1 + i] = NAVIO;
        }
    }

    // Navio 4: DIAGONAL SECUNDÁRIA (linha aumenta, coluna diminui)
    int linha_d2 = 0;
    int coluna_d2 = 8;
    // Validação: garante que o navio cabe na vertical e não sai pela esquerda
    if (linha_d2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna_d2 - (TAMANHO_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Incrementa a linha e DECREMENTA a coluna a cada passo
            tabuleiro[linha_d2 + i][coluna_d2 - i] = NAVIO;
        }
    }

    // --- 3. Exibição do Tabuleiro Completo ---
    printf("--- Tabuleiro da Batalha Naval com 4 Navios ---\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Pula para a próxima linha ao final de cada linha do tabuleiro
    }

    return 0;
}