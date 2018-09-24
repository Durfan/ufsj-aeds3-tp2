#include "main.h"

int viagem(int **travel, club_t *club, int da_casa, int nemesis) {
    int from = club[da_casa].idCTY-1;
    int to   = club[abs(nemesis)-1].idCTY;
    if (nemesis > 0) return 0;
    if (nemesis < 0) return travel[from][to];
    return -1;
}

void polygon(int **schedule, int clubs) {
    int i,l;
    int travel = 1;
    int topTeam = clubs;
    int polygon[clubs-1];
    
    for (i=0; i<clubs-1; i++) polygon[i] = i + 1;
    
    for (i=0; i<clubs-1; i++) {
        schedule[topTeam-1][i] = travel*polygon[0];
        schedule[polygon[0]-1][i] = -travel*topTeam;

        schedule[topTeam-1][i+clubs-1] = -travel*polygon[0];
        schedule[polygon[0]-1][i+clubs-1] = travel*topTeam;

        for (l=2; l<=clubs/2; l++) {
            schedule[polygon[l-1]-1][i] = travel*polygon[clubs-l];
            schedule[polygon[clubs-l]-1][i] = -travel*polygon[l-1];
            schedule[polygon[l-1]-1][i+clubs-1] = -travel*polygon[clubs-l];
            schedule[polygon[clubs-l]-1][i+clubs-1] = travel*polygon[l-1];
        }

        travel *= -1;
        rotateArray(polygon,clubs-1);
    }
}

void createEscala(int **escala, int **schedule, int clubs) {
    int i,j;
    int club1,club2;

    for (i=0; i<clubs; i++) {
        for (j=0; j<(2*clubs)-3; j++) {
            club1 = abs(schedule[i][j]) -1;
            club2 = abs(schedule[i][j+1]) -1;
            escala[club1][club2] += 1;
            escala[club2][club1] += 1;
        }
    }
}