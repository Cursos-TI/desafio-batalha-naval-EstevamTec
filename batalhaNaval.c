#include <stdio.h>

// --- Definições de Constantes ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// --- Protótipo da Função ---
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

int main() {
    // 1. Representar e Inicializar o Tabuleiro
    
    // Declaração de uma matriz 10x10 (array bidimensional)
    // Todas as posições são inicializadas com 0 (AGUA)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // --- Posições Fixas dos Navios ---
    // (As coordenadas iniciais são definidas diretamente no código)

    // Navio Horizontal
    int linha_h = 2; // Começa na linha 2 (índice 2)
    int coluna_h = 1; // Começa na coluna 1 (índice 1)
    
    // Navio Vertical
    int linha_v = 5; // Começa na linha 5 (índice 5)
    int coluna_v = 6; // Começa na coluna 6 (índice 6)

    // Os vetores de navios para cópia (simplificação: apenas o valor 3)
    // int navio_modelo[TAMANHO_NAVIO] = {3, 3, 3}; // Não é estritamente necessário, mas ilustra a ideia.

    // --- 2. Posicionar os Navios e Validação Simplificada ---

    // A validação de limites é simplificada, pois as coordenadas foram escolhidas
    // para garantir que os navios de tamanho 3 cabem no tabuleiro 10x10.
    // Navio Horizontal: Coluna inicial (1) + Tamanho (3) = 4. 4 < 10. OK.
    // Navio Vertical: Linha inicial (5) + Tamanho (3) = 8. 8 < 10. OK.

    // 2.1. Posicionar Navio Horizontal
    printf("Posicionando Navio Horizontal em: Linha %d, Coluna %d\n", linha_h, coluna_h);
    // Loop para preencher as colunas a partir da coluna inicial
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Validação de sobreposição simplificada: Checa se a posição é água (0)
            if (tabuleiro[linha_h][coluna_h + i] == AGUA) {
                tabuleiro[linha_h][coluna_h + i] = NAVIO; // Marca com 3 (NAVIO)
            } else {
                printf("ERRO: Sobreposição detectada no Navio Horizontal!\n");
                // Em um jogo real, você voltaria ou pediria novas coordenadas.
            }
        }
    } else {
        printf("ERRO: Navio Horizontal fora dos limites do tabuleiro!\n");
    }

    // 2.2. Posicionar Navio Vertical
    printf("Posicionando Navio Vertical em: Linha %d, Coluna %d\n\n", linha_v, coluna_v);
    // Loop para preencher as linhas a partir da linha inicial
    if (linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Validação de sobreposição simplificada: Checa se a posição é água (0)
            if (tabuleiro[linha_v + i][coluna_v] == AGUA) {
                tabuleiro[linha_v + i][coluna_v] = NAVIO; // Marca com 3 (NAVIO)
            } else {
                printf("ERRO: Sobreposição detectada no Navio Vertical!\n");
                // Em um jogo real, você voltaria ou pediria novas coordenadas.
            }
        }
    } else {
        printf("ERRO: Navio Vertical fora dos limites do tabuleiro!\n");
    }

    // 3. Exibir o Tabuleiro
    printf("--- Tabuleiro Batalha Naval (10x10) ---\n");
    printf("(0 = Água | 3 = Navio)\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

/**
 * @brief Exibe o tabuleiro de Batalha Naval no console.
 * * Utiliza loops aninhados para percorrer e imprimir todos os elementos da matriz.
 * @param tabuleiro A matriz 10x10 que representa o tabuleiro.
 */
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprime o cabeçalho das colunas (0 a 9)
    printf("    "); // Espaço para alinhar com as linhas
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%d ", col);
    }
    printf("\n");
    
    // Imprime uma linha separadora
    printf("  --");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("--");
    }
    printf("\n");

    // Loops aninhados para percorrer a matriz
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        // Imprime o índice da linha
        printf("%d | ", linha); 
        
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            // Imprime o valor da posição e um espaço para separação
            printf("%d ", tabuleiro[linha][coluna]); 
        }
        printf("\n"); // Nova linha após o fim de cada linha do tabuleiro
    }
    printf("\n----------------------------------------\n");
}