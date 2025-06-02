#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs() (valor absoluto)

// --- Constantes Globais ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 7 // Usaremos 7x7 para habilidades mais visíveis
#define AGUA 0
#define NAVIO 3
#define EFEITO_HABILIDADE 5
#define AFETADO 1
#define NAO_AFETADO 0

/**
 * Desafio Batalha Naval - Nível Mestre
 *
 * Este programa demonstra a criação de áreas de efeito para habilidades
 * especiais (Cone, Cruz, Octaedro) e as sobrepõe a um tabuleiro de
 * Batalha Naval existente. A geração das formas e a sobreposição
 * utilizam laços aninhados e lógica condicional.
 */
int main() {
    // --- 1. Definição dos Tabuleiros e Matrizes ---
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // --- 2. Inicialização do Tabuleiro Principal e Posicionamento de Navios ---
    // (Reutilizando a lógica dos níveis anteriores para ter um cenário base)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    // Posiciona alguns navios para referência visual
    tabuleiro[1][1] = NAVIO; tabuleiro[1][2] = NAVIO; tabuleiro[1][3] = NAVIO; // Horizontal
    tabuleiro[5][8] = NAVIO; tabuleiro[6][8] = NAVIO; tabuleiro[7][8] = NAVIO; // Vertical

    // --- 3. Geração Dinâmica das Matrizes de Habilidade ---
    int centro = TAMANHO_HABILIDADE / 2; // Ponto central da matriz de habilidade (ex: 3 para 7x7)

    printf("Gerando matrizes de habilidade 7x7...\n\n");

    // Laços aninhados para percorrer cada matriz de habilidade
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Habilidade CONE (origem no topo, expande para baixo)
            // A área afetada se alarga a cada linha, centrada na coluna do meio.
            if (i >= abs(j - centro)) {
                habilidade_cone[i][j] = AFETADO;
            } else {
                habilidade_cone[i][j] = NAO_AFETADO;
            }

            // Habilidade CRUZ (uma linha e uma coluna a partir do centro)
            if (i == centro || j == centro) {
                habilidade_cruz[i][j] = AFETADO;
            } else {
                habilidade_cruz[i][j] = NAO_AFETADO;
            }

            // Habilidade OCTAEDRO/LOSANGO (distância de Manhattan do centro)
            // abs(i-centro) + abs(j-centro) calcula a "distância em blocos" do centro.
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade_octaedro[i][j] = AFETADO;
            } else {
                habilidade_octaedro[i][j] = NAO_AFETADO;
            }
        }
    }

    // --- 4. Sobreposição de UMA Habilidade no Tabuleiro ---
    // Para um exemplo claro, vamos sobrepor apenas a habilidade OCTAEDRO.
    printf("Sobrepondo a habilidade 'Octaedro' no tabuleiro...\n");
    int origem_linha = 4;  // Ponto no tabuleiro principal onde o centro
    int origem_coluna = 4; // da habilidade será posicionado.

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Verifica se a posição na matriz de habilidade deve afetar o tabuleiro
            if (habilidade_octaedro[i][j] == AFETADO) {
                // Calcula a coordenada correspondente no tabuleiro principal.
                // Subtrai 'centro' para alinhar a habilidade pelo seu centro.
                int alvo_linha = origem_linha + (i - centro);
                int alvo_coluna = origem_coluna + (j - centro);

                // Validação de Limites: garante que não vamos escrever fora do tabuleiro.
                if (alvo_linha >= 0 && alvo_linha < TAMANHO_TABULEIRO &&
                    alvo_coluna >= 0 && alvo_coluna < TAMANHO_TABULEIRO) {
                    
                    // Marca a posição no tabuleiro principal com o efeito da habilidade.
                    // Apenas marca se for água, para não apagar navios na visualização.
                    if(tabuleiro[alvo_linha][alvo_coluna] == AGUA) {
                        tabuleiro[alvo_linha][alvo_coluna] = EFEITO_HABILIDADE;
                    }
                }
            }
        }
    }


    // --- 5. Exibição do Tabuleiro Final ---
    printf("\n--- Tabuleiro Final com Area de Efeito ---\n");
    printf(" . = Agua | N = Navio | * = Efeito da Habilidade\n\n");
    // Imprime cabeçalho das colunas para melhor visualização
    printf("  ");
    for(int k = 0; k < TAMANHO_TABULEIRO; k++) printf("%d ", k);
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime cabeçalho da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case AGUA:              printf(". "); break;
                case NAVIO:             printf("N "); break;
                case EFEITO_HABILIDADE: printf("* "); break;
                default:                printf("? "); break;
            }
        }
        printf("\n");
    }

    return 0;
}