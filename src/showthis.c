#include "main.h"

void printTabela(size_t n, int** tabela) {
    int i,j;
    int rodadas = getRodadas(n);

    printf(" \033[4m  \033[24m");
    for (i=0; i<rodadas && i<n-1; i++) {
        printf("\033[4m  %02d\033[24m", i+1);
    }
    printf("\n");
    for (i=0; i<n; i++) {
        printf(" %02d ", i+1);
        for (j=0; j<rodadas && j<n-1; j++) {
            if (tabela[i][j]<0) printf(COLOR_YELL " %02d " COLOR_RESET, abs(tabela[i][j]));
            else printf(" %02d ", abs(tabela[i][j]));
        }
        printf("\n");
    }
    if (n>=16) {
        printf("\n Imprimir Returno... [Enter]");
        while (getchar() !='\n');
        printf("\n \033[4m  \033[24m");
        for (i=n-1; i<rodadas; i++) {
            printf("\033[4m  %02d\033[24m", i+1);
        }
        printf("\n");
        for (i=0; i<n; i++) {
            printf(" %02d ", i+1);
            for (j=n-1; j<rodadas; j++) {
                if (tabela[i][j]<0) printf(COLOR_YELL " %02d " COLOR_RESET, abs(tabela[i][j]));
                else printf(" %02d ", abs(tabela[i][j]));
            }
            printf("\n");
        }
    }
    printf("\n");
}

void printEscala(size_t n, int** escala) {
    int i,j;
    
    printf("\n  ");
    for (i=0; i<n; i++) printf(COLOR_BLUE " %c:" COLOR_RESET, i+65);
    printf("\n");
    for (i=0; i<n; i++) {
        printf(COLOR_BLUE " %c" COLOR_RESET, i+65);
        for (j=0; j<n; j++) {
            if (!escala[i][j]) printf(COLOR_BLUE " --" COLOR_RESET);
            else printf(" %02d", escala[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printTravel(size_t n, int** tabela, int** travel, clubes_t* clubes) {
    int i,j;
    int rodadas = getRodadas(n);
    int distance = 0;

    for (i=0; i<n; i++) {
        for (j=0; j<rodadas; j++) { // m_teams-1
            distance += viagem(travel,clubes,i,tabela[i][j]);
        }
        printf(" %06d km", distance);
        printf(" => %s\n", clubes[i].nome);
    }
    printf("\n");
}

void printCLUB(size_t n, clubes_t* clubes) {
    int i;
    for (i=0; i<n; i++) {
        printf(" %02d:%02d %s\n", i, clubes[i].sede, clubes[i].nome);
    }
    printf("\n");
}

void printCITY(size_t n, cities_t* cities) {
    int i;
    for (i=0; i<n; i++) {
        printf(" %02d:%02d %s\n", i, cities[i].idCTY, cities[i].nome);
    }
    printf("\n");
}

void printDIST(size_t n, int** travel) {
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf(" %d\t", travel[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}