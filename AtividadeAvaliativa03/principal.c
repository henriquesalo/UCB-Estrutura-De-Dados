#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    FILE* arquivo;
    arquivo = fopen("vertices.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int n;
    fscanf(arquivo, "%d", &n);

    Ponto* vertices = (Ponto*)malloc(n * sizeof(Ponto));

    if (vertices == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(arquivo);
        return 1;
    }

    int i;
    for (i = 0; i < n; i++) {
        float x, y;
        fscanf(arquivo, "%f %f", &x, &y);
        vertices[i] = criarPonto(x, y);
    }

    fclose(arquivo);

    float area = calcularArea(vertices, n);

    printf("A area do poligono e: %.2f\n", area);

    free(vertices);

    return 0;
}