#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *saida;
    char caractere;
    int dentroTag = 0;

    // Abre o arquivo de entrada
    entrada = fopen("arquivo.html", "r");
    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Abre o arquivo de saída
    saida = fopen("texto_sem_tags.txt", "w");
    if (saida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        fclose(entrada);
        return 1;
    }

    // Processa o arquivo de entrada caractere por caractere
    while ((caractere = fgetc(entrada)) != EOF) {
        if (caractere == '<') {
            dentroTag = 1; 
        } else if (caractere == '>') {
            dentroTag = 0; 
        } else if (!dentroTag) {
            fputc(caractere, saida);
        }
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Tags HTML removidas com sucesso. O texto sem tags foi salvo em texto_sem_tags.txt\n");

    return 0;
}