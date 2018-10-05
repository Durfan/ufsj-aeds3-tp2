#include "main.h"

void printTabela(int n, clubes_t* clubes, int** tabela) {
    int i,j;
    int rodadas = getRodadas(n);
    bool rodada = true;

    for (i=0; i<n; i++) {
        if (rodada) {
            printf(COLOR_BLUE"   Clube\\Rodada\t");
            for (j=0; j<rodadas/2; j++) {
                printf(" %02d", j+1);
            }
            printf(COLOR_RESET"\n");
        }
        printf(" %02d %.11s\t", i+1, clubes[i].nome);
        for (j=0; j<rodadas/2; j++) {
            if (tabela[i][j] > 0) printf("\u2502%02d", tabela[i][j]);
            else printf("\u2502"COLOR_YELL"%02d"COLOR_RESET, abs(tabela[i][j]));
        }
        rodada = false;
        printf("\n");
    }
    printf("\n");

    rodada = true;
    for (i=0; i<n; i++) {
        if (rodada) {
            printf(COLOR_BLUE"   Clube\\Rodada\t");
            for (j=rodadas/2; j<rodadas; j++) {
                printf(" %02d", j+1);
            }
            printf(COLOR_RESET"\n");
        }
        printf(" %02d %.11s\t", i+1, clubes[i].nome);
        for (j=rodadas/2; j<rodadas; j++) {
            if (tabela[i][j] > 0) printf("\u2502%02d", tabela[i][j]);
            else printf("\u2502"COLOR_YELL"%02d"COLOR_RESET, abs(tabela[i][j]));
        }
        rodada = false;
        printf("\n");
    }
    printf("\n");
}

void printTravel(int n, clubes_t* clubes) {
    int i;

    for (i=0; i<n; i++) {
        printf(" %d Km : %s\n", clubes[i].desloc, clubes[i].nome);
    }
}

void printMatrix(int n, int** tabela) {
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf(" %02d", tabela[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printCLUB(int n, clubes_t* clubes) {
    int i;
    for (i=0; i<n; i++) {
        printf(" %02d %d ", clubes[i].sede, clubes[i].desloc);
        printf("%s\n", clubes[i].nome);
    }
    printf("\n");
}

void printCITY(int n, cities_t* cities) {
    int i;
    printf(COLOR_BLUE " ID CT Cidade\n" COLOR_RESET);
    for (i=0; i<n; i++) {
        printf(" %02d %02d %s\n", i, cities[i].idCTY, cities[i].nome);
    }
    printf("\n");
}