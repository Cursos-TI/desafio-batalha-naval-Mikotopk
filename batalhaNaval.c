#include <stdio.h>

// --- Constantes para facilitar a leitura e manutenção do código ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

/**
 * Desafio Batalha Naval - Nível Novato
 *
 * Este programa inicializa um tabuleiro de Batalha Naval,
 * posiciona dois navios (um horizontal e um vertical) em
 * coordenadas fixas e exibe o estado final do tabuleiro.
 */
int main() {
    // Declaração da matriz que representará o nosso tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // --- 1. Inicialização do Tabuleiro ---
    // Usamos loops aninhados para percorrer cada célula da matriz
    // e preenchê-la com o valor de 'AGUA' (0).
    printf("Inicializando o tabuleiro com agua...\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {   // Loop para as linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) { // Loop para as colunas
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- 2. Posicionamento dos Navios ---
    // As coordenadas iniciais são definidas diretamente no código.

    // Posicionando o primeiro navio na HORIZONTAL
    // Coordenadas: linha 2, começando na coluna 3.
    int linha_navio_h = 2;
    int coluna_navio_h = 3;

    // Validação simples para garantir que o navio não saia do tabuleiro
    if (coluna_navio_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Usamos um loop para percorrer o tamanho do navio e posicioná-lo.
        // A linha permanece a mesma, e a coluna é incrementada.
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_navio_h][coluna_navio_h + i] = NAVIO;
        }
    }

    // Posicionando o segundo navio na VERTICAL
    // Coordenadas: coluna 7, começando na linha 5.
    int linha_navio_v = 5;
    int coluna_navio_v = 7;

    // Validação simples para garantir que o navio não saia do tabuleiro
    if (linha_navio_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // A coluna permanece a mesma, e a linha é incrementada.
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_navio_v + i][coluna_navio_v] = NAVIO;
        }
    }


    // --- 3. Exibição do Tabuleiro ---
    // Usamos novamente loops aninhados para imprimir cada célula da matriz.
    printf("--- Tabuleiro da Batalha Naval ---\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Imprime o valor da célula seguido de um espaço
            printf("%d ", tabuleiro[i][j]);
        }
        // Ao final de cada linha, imprime uma quebra de linha para formar o tabuleiro
        printf("\n");
    }

    return 0; // Indica que o programa terminou com sucesso
}