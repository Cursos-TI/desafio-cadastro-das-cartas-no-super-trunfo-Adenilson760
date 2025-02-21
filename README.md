#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;                // Estado (letra de A a H)
    char codigo[5];             // Código da carta (ex: A01, B03)
    char nomeCidade[100];       // Nome da cidade
    int populacao;              // População da cidade
    float area;                 // Área da cidade em km²
    float pib;                  // PIB da cidade em bilhões de reais
    int pontosTuristicos;       // Número de pontos turísticos
} Carta;

// Função para ler os dados de uma carta
void lerDados(Carta *carta) {
    // Leitura dos dados
    printf("Estado: ");
    scanf(" %c", &carta->estado); // O espaço antes de %c serve para consumir o caractere de nova linha

    printf("Código da Carta: ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    getchar();  // Limpar o buffer de entrada para capturar corretamente a string
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0; // Remover o '\n' do final da string

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB: ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir os dados de uma carta
void exibirDados(const Carta *carta, int numeroCarta) {
    printf("\nCarta %d:\n", numeroCarta);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->pontosTuristicos);
}

int main() {
    // Declaração das variáveis para as duas cartas
    Carta carta1, carta2;

    // Solicitar dados para a primeira carta
    printf("Informe os dados da Carta 1:\n");
    lerDados(&carta1);

    // Solicitar dados para a segunda carta
    printf("\nInforme os dados da Carta 2:\n");
    lerDados(&carta2);

    // Exibir os dados das cartas
    exibirDados(&carta1, 1);
    exibirDados(&carta2, 2);

    return 0;
}