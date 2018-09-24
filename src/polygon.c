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

void createEscala(int **escala, int **schedule, int clubs) {
    int i,j;
    int tupla1,tupla2;

    for (i=0; i<clubs; i++)
        for (j=0; j<clubs; j++) escala[i][j] = 0;

    for (i=0; i<clubs; i++) {
        for (j=0; j<(2*clubs)-3; j++) {
            tupla1 = abs(schedule[i][j])-1;
            tupla2 = abs(schedule[i][j+1])-1;
            escala[tupla1][tupla2]+=1;
            escala[tupla2][tupla1]+=1;
        }
    }
}