#include "main.h"

void printTabela(size_t n, int** tabela) {
    int i,j;
    int rodadas = getRodadas(n);

    for (i=0; i<n; i++) {
        printf(" %02d", i+1);
        for (j=0; j<rodadas; j++) {
            printf(" %c", tabela[i][j]+64);
        }
        printf("\n");
    }
}

void printMatrix(size_t n, int** tabela) {
    int i,j;
    
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf(" %02d", tabela[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printCLUB(size_t n, clubes_t* clubes) {
    int i;
    printf(COLOR_BLUE " ID SD CLUBE\n" COLOR_RESET);
    for (i=0; i<n; i++) {
        printf(" %02d %02d %s\n", i, clubes[i].sede, clubes[i].nome);
    }
    printf("\n");
}

void printCITY(size_t n, cities_t* cities) {
    int i;
    printf(COLOR_BLUE " ID CT Cidade\n" COLOR_RESET);
    for (i=0; i<n; i++) {
        printf(" %02d %02d %s\n", i, cities[i].idCTY, cities[i].nome);
    }
    printf("\n");
}