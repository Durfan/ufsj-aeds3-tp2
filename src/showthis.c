#include "main.h"

void printEscala(int **escala, int clubs) {
    int i,j;
    
    printf("\n  ");
    for (i=0; i<clubs; i++) printf(COLOR_BLUE " %c:" COLOR_RESET, i+65);
    printf("\n");
    for (i=0; i<clubs; i++) {
        printf(COLOR_BLUE " %c" COLOR_RESET, i+65);
        for (j=0; j<clubs; j++) {
            if (!escala[i][j]) printf(COLOR_BLUE " --" COLOR_RESET);
            else printf(" %02d", escala[i][j]);
        }
        printf("\n");
    }
}

void printSchedule(int **schedule, int clubs) {
    int i,j;
    int rounds = rounds(clubs);

    printf(" \033[4m   \033[24m");
    for (i=0; i<rounds; i++) {
        printf("\033[4m %02d\033[24m", i+1);
    }
    printf("\n");
    for (i=0; i<clubs; i++) {
        printf(" %02d: ", i+1);
        for (j=0; j<rounds; j++) { // m_teams-1
            if (schedule[i][j]<0) printf(COLOR_YELL "%02d " COLOR_RESET, abs(schedule[i][j]));
            else printf("%02d ", abs(schedule[i][j]));
        }
        printf("\n");
    }
}

void printTravel(int **schedule, int **travel, club_t *club, int clubs) {
    int i,j;
    int rounds = rounds(clubs);
    int distance = 0;

    printf("\n");
    for (i=0; i<clubs; i++) {
        printf(" %02d %s", i+1, club[i].nome);
        for (j=0; j<rounds; j++) { // m_teams-1
            distance += viagem(travel,club,i,schedule[i][j]);
        }
        printf("\t: %d km\n", distance);
    }
}

void printCITY(city_t *city) {
    int i;
    for (i=0;i<10;i++) {
        printf("%d:%d \t%s\n", i, city[i].idCTY, city[i].nome);
    }
}

void printDIST(int **travel) {
    int i,j;
    for (i=0;i<10;i++) {
        for (j=0;j<10;j++) {
            printf("%d\t", travel[i][j]);
        }
        printf("\n");
    }
}

void printCLUB(club_t *club, int clubs) {
    int i;
    for (i=0;i<clubs;i++) {
        printf("%d:%d \t%s\n", i, club[i].idCTY, club[i].nome);
    }
}