#include <stdio.h>
#include <string.h>

// Definindo uma estrutura para armazenar as informações de uma carta
typedef struct {
    char estado;
    char codigo[4];
    char cidade[50];
    unsigned long int populacao; // Usando unsigned long int para permitir números grandes
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcularDados(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib * 1000000000 / c->populacao; // PIB em bilhões e população em unidades
    c->superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + (1 / c->densidadePopulacional) + c->pibPerCapita;
}

// Função para comparar dois valores e retornar o maior, ou o menor para a densidade populacional
int comparar(float valor1, float valor2, int tipo) {
    if (tipo == 0) { // Para atributos normais (maior valor vence)
        return valor1 > valor2;
    } else { // Para densidade populacional (menor valor vence)
        return valor1 < valor2;
    }
}

void exibirCarta(Carta c) {
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.cidade);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder);
}

int main() {
    Carta carta1, carta2;

    // Entrada dos dados da carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf(" %c", &carta1.estado);
    printf("Código: ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", carta1.cidade); // Ler string com espaços
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Calcular os dados para carta 1
    calcularDados(&carta1);

    // Entrada dos dados da carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf(" %c", &carta2.estado);
    printf("Código: ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", carta2.cidade); // Ler string com espaços
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Calcular os dados para carta 2
    calcularDados(&carta2);

    // Exibir as informações de ambas as cartas
    printf("\nCarta 1:\n");
    exibirCarta(carta1);
    
    printf("\nCarta 2:\n");
    exibirCarta(carta2);

    // Comparar as cartas com base em um atributo
    int atributoEscolhido;
    printf("\nEscolha o atributo para comparar (1-População, 2-Área, 3-PIB, 4-Pontos Turísticos, 5-Densidade Populacional, 6-PIB per Capita, 7-Super Poder): ");
    scanf("%d", &atributoEscolhido);

    int resultado;
    switch(atributoEscolhido) {
        case 1: // População
            resultado = comparar(carta1.populacao, carta2.populacao, 0);
            break;
        case 2: // Área
            resultado = comparar(carta1.area, carta2.area, 0);
            break;
        case 3: // PIB
            resultado = comparar(carta1.pib, carta2.pib, 0);
            break;
        case 4: // Pontos Turísticos
            resultado = comparar(carta1.pontosTuristicos, carta2.pontosTuristicos, 0);
            break;
        case 5: // Densidade Populacional
            resultado = comparar(carta1.densidadePopulacional, carta2.densidadePopulacional, 1);
            break;
        case 6: // PIB per Capita
            resultado = comparar(carta1.pibPerCapita, carta2.pibPerCapita, 0);
            break;
        case 7: // Super Poder
            resultado = comparar(carta1.superPoder, carta2.superPoder, 0);
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Exibir o resultado da comparação
    if (resultado) {
        printf("\nCarta 1 venceu!\n");
    } else if (resultado == 0) {
        printf("\nCarta 2 venceu!\n");
    }

    return 0;
}
