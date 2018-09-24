#include "main.h"

void printTabela(size_t n, int** tabela){
    int i,j;
    int rodadas = getRodadas(n);

    printf(" \033[4m   \033[24m");
    for (i=0; i<rodadas; i++) {
        printf("\033[4m %02d\033[24m", i+1);
    }
    printf("\n");
    for (i=0; i<n; i++) {
        printf(" %02d: ", i+1);
        for (j=0; j<rodadas; j++) { // m_teams-1
            if (tabela[i][j]<0) printf(COLOR_YELL "%02d " COLOR_RESET, abs(tabela[i][j]));
            else printf("%02d ", abs(tabela[i][j]));
        }
        printf("\n");
    }
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
}

void printTravel(size_t n, int** tabela, int** travel, clubes_t* clubes) {
    int i,j;
    int rodadas = getRodadas(n);
    int distance = 0;

    printf("\n");
    for (i=0; i<n; i++) {
        printf(" %02d %s", i+1, clubes[i].nome);
        for (j=0; j<rodadas; j++) { // m_teams-1
            distance += viagem(travel,clubes,i,tabela[i][j]);
        }
        printf("\t: %d km\n", distance);
    }
}

void printCLUB(size_t n, clubes_t* clubes) {
    int i;
    for (i=0; i<n; i++)
        printf("%d:%d \t%s\n", i, clubes[i].idCTY, clubes[i].nome);
}

void printCITY(size_t n, cities_t* cities) {
    int i;
    for (i=0; i<n; i++)
        printf("%d:%d \t%s\n", i, cities[i].idCTY, cities[i].nome);
}

void printDIST(size_t n, int** travel) {
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d\t", travel[i][j]);
        }
        printf("\n");
    }
}