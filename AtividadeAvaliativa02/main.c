#include <stdio.h>
#include <string.h>

char *arr[20] = {
    "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi",
    "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
};

int numTrocas = 0;
int numComparacoes = 0;

void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
    numTrocas++;
}


void bubbleSort(char **arr, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            numComparacoes++;
            if (strcmp(arr[j], arr[j+1]) > 0) {
                trocar(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    FILE *arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    fprintf(arquivo_saida, "Número de trocas: %d\n", numTrocas);
    fprintf(arquivo_saida, "Número de comparações: %d\n", numComparacoes);
    fprintf(arquivo_saida, "Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        fprintf(arquivo_saida, "%s\n", arr[i]);
    }

    fclose(arquivo_saida);

    // Calculando a mediana
    char *mediana = arr[n / 2];
    printf("Mediana: %s\n", mediana);

    return 0;
}
