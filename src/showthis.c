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

void printCalvin(size_t n, int** calvin) {
    int i,j;
    
    printf(" (Tabela: 'Calvin')\n");
    for (i=0; i<n; i++) printf(COLOR_BLUE " %02d:" COLOR_RESET, i+1);
    printf("\n");
    for (i=0; i<n; i++) {
        // printf(COLOR_BLUE " %02d" COLOR_RESET, i+1);
        for (j=0; j<n; j++) {
            if (!calvin[i][j]) printf(COLOR_BLUE " %03d" COLOR_RESET, calvin[i][j]);
            else printf(" %01.1f", (float)calvin[i][j]/1000);
        }
        printf("\n");
    }
    printf("\n");
}

void printHarold(size_t n, int** harold) {
    int i,j;
    
    for (i=0; i<n; i++) {
        printf(" %c", i+65);
        for (j=0; j<n; j++) {
            printf(" %02d", harold[i][j]);
        }
        printf("\n");
    }
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

void printDIST(size_t n, int** travel) {
    int i,j;
    printf(" (Tabela: Distancias Relativas)\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (!travel[i][j]) printf(COLOR_BLUE " %04d" COLOR_RESET, travel[i][j]);
            else printf(" %04d", travel[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}