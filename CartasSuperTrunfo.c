#include <stdio.h>

// Desafio Super Trunfo - Países - Nível Aventureiro
// Aluno: Alex Batista Rodrigues
// Matrícula: 201907217894

// Definição da estrutura da carta
typedef struct {
    char estado;
    int cidade;
    char codigo[4];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

// Cálculos auxiliares
float calcularDensidadePopulacional(unsigned long int populacao, float area) {
    return populacao / area;
}

float calcularPibPerCapita(float pib, unsigned long int populacao) {
    return pib / populacao;
}

float calcularSuperPoder(Carta c) {
    return c.populacao + c.area + c.pib + c.pontosTuristicos +
           (1.0f / c.densidadePopulacional) + c.pibPerCapita;
}

// Registro da carta
void registrarCarta(Carta *carta) {
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o número da cidade (1-4): ");
    scanf("%d", &carta->cidade);

    sprintf(carta->codigo, "%c%02d", carta->estado, carta->cidade);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (milhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos derivados
    carta->densidadePopulacional = calcularDensidadePopulacional(carta->populacao, carta->area);
    carta->pibPerCapita = calcularPibPerCapita(carta->pib, carta->populacao);
    carta->superPoder = calcularSuperPoder(*carta);
}

// Exibição da carta
void exibirCarta(Carta c) {
    printf("\n--- CARTA %s ---\n", c.codigo);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f milhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder);
}

// Comparação dos atributos
void compararCartas(Carta c1, Carta c2) {
    printf("\n=== COMPARAÇÃO DAS CARTAS ===\n");
    printf("População: Carta 1 (%lu) vs Carta 2 (%lu) -> %d\n", c1.populacao, c2.populacao, c1.populacao > c2.populacao);
    printf("Área: Carta 1 (%.2f) vs Carta 2 (%.2f) -> %d\n", c1.area, c2.area, c1.area > c2.area);
    printf("PIB: Carta 1 (%.2f) vs Carta 2 (%.2f) -> %d\n", c1.pib, c2.pib, c1.pib > c2.pib);
    printf("Pontos turísticos: Carta 1 (%d) vs Carta 2 (%d) -> %d\n", c1.pontosTuristicos, c2.pontosTuristicos, c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 (%.2f) vs Carta 2 (%.2f) -> %d\n", c1.densidadePopulacional, c2.densidadePopulacional, c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per capita: Carta 1 (%.2f) vs Carta 2 (%.2f) -> %d\n", c1.pibPerCapita, c2.pibPerCapita, c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta 1 (%.2f) vs Carta 2 (%.2f) -> %d\n\n", c1.superPoder, c2.superPoder, c1.superPoder > c2.superPoder);
}

int main() {
    Carta carta1, carta2;

    printf("=== Cadastro da Carta 1 ===\n");
    registrarCarta(&carta1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    registrarCarta(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    compararCartas(carta1, carta2);

    return 0;
}
