#include "main.h"

void printCITY(city_t *city) {
    int i;
    for (i=0;i<10;i++) {
        printf("%d:%d \t%s\n", i, city[i].idCTY, city[i].nome);
    }
}

void printDIST(int D[][10]) {
    int i,j;
    for (i=0;i<10;i++) {
        for (j=0;j<10;j++) {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
}

void printCLUB(club_t *club) {
    int i;
    for (i=0;i<20;i++) {
        printf("%d:%d \t%s\n", i, club[i].idCTY, club[i].nome);
    }
}