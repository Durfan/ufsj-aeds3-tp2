#include "main.h"

void polygon(int **schedule, int clubs) {
    int i,l;
    int travel=1;
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

void printSschedule(int **schedule, int clubs) {
    int i,j;

    printf(" \033[4m   \033[24m");
    for (i=0; i<(2*clubs)-2; i++) {
        printf("\033[4m %02d\033[24m", i+1);
    }
    printf("\n");
    for (i=0; i<clubs; i++) {
        printf(" %02d: ", i+1);
        for (j=0; j<(2*clubs)-2; j++) { // m_teams-1
            if (schedule[i][j]<0) printf(COLOR_YELL "%02d " COLOR_RESET, abs(schedule[i][j]));
            else printf("%02d ", abs(schedule[i][j]));
        }
        printf("\n");
    }
}