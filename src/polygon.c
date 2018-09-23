#include "main.h"

void initsolve(int m_teams) {
    int solution[m_teams][40];

    int i,j,l;
    int sign=1;
    int topTeam = m_teams;
    int polygon[m_teams-1];
    
    for (i=0; i<m_teams-1; i++) polygon[i] = i + 1;
    
    for (i=0; i<m_teams-1; i++) {
        solution[topTeam-1][i] = sign*polygon[0];
        solution[polygon[0]-1][i] = -sign*topTeam;

        solution[topTeam-1][i+m_teams-1] = -sign*polygon[0];
        solution[polygon[0]-1][i+m_teams-1] = sign*topTeam;

        for (l=2; l<=m_teams/2; l++) {
            solution[polygon[l-1]-1][i] = sign*polygon[m_teams-l];
            solution[polygon[m_teams-l]-1][i] = -sign*polygon[l-1];
            solution[polygon[l-1]-1][i+m_teams-1] = -sign*polygon[m_teams-l];
            solution[polygon[m_teams-l]-1][i+m_teams-1] = sign*polygon[l-1];
        }

        sign *= -1;
        rotate(polygon,m_teams-1);
    }
    for (i=0; i<m_teams; i++) {
        for (j=0; j<19; j++) {
            printf("%+d ", solution[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i=0; i<m_teams; i++) {
        for (j=19; j<38; j++) {
            printf("%+d ", solution[i][j]);
        }
        printf("\n");
    }
}

void polygon(int num_teams) {
    int i,j, turno;
    int n2 = num_teams/2;
    int S0[num_teams+1][num_teams-1];
    int clubs[num_teams+1];
    int club1, club2;

    for (i=0; i<num_teams; i++) clubs[i]=i+1;
    for (turno=0; turno<num_teams-1; turno++) {
        for (i=0; i<n2; i++) {
            club1 = clubs[n2-i];
            club2 = clubs[n2+i+1];
            S0[n2-i][turno] = club2;
            S0[n2+i+1][turno] = club1;
        }
        rotate(clubs,num_teams);
    }

    for (i=1; i<=num_teams; i++) {
        for (j=0; j<num_teams-1; j++) {
            printf("%d ", S0[i][j]);
        }
        printf("\n");
    }
}

void rotate(int *array, size_t n) {
    int tmp = array[n-1];
    memmove(&array[1], &array[0], (n-1)*sizeof(int));
    array[0] = tmp;
}