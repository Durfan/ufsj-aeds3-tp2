#include "main.h"

int **initsolve(int m_teams) {
    int i,l;
    int travel=1;
    int topTeam = m_teams;
    int polygon[m_teams-1];
    int **solution = createTable(m_teams,(2*m_teams)-2);
    
    for (i=0; i<m_teams-1; i++) polygon[i] = i + 1;
    
    for (i=0; i<m_teams-1; i++) {
        solution[topTeam-1][i] = travel*polygon[0];
        solution[polygon[0]-1][i] = -travel*topTeam;

        solution[topTeam-1][i+m_teams-1] = -travel*polygon[0];
        solution[polygon[0]-1][i+m_teams-1] = travel*topTeam;

        for (l=2; l<=m_teams/2; l++) {
            solution[polygon[l-1]-1][i] = travel*polygon[m_teams-l];
            solution[polygon[m_teams-l]-1][i] = -travel*polygon[l-1];
            solution[polygon[l-1]-1][i+m_teams-1] = -travel*polygon[m_teams-l];
            solution[polygon[m_teams-l]-1][i+m_teams-1] = travel*polygon[l-1];
        }

        travel *= -1;
        rotate(polygon,m_teams-1);
    }
    printTable(solution,m_teams);
    return solution;
}

int **createTable(int m, int n) {
    int i;
    int* values = calloc(m*n, sizeof(int));
    int** rows = malloc(n*sizeof(int*));
    for (i=0; i<n; ++i) rows[i] = values + i*m;
    return rows;
}

void printTable(int **table, size_t n) {
    int i,j;

    printf(" \033[4m   \033[24m");
    for (i=0; i<(2*n)-2; i++) {
        printf("\033[4m %02d\033[24m", i+1);
    }
    printf("\n");
    for (i=0; i<n; i++) {
        printf(" %02d: ", i+1);
        for (j=0; j<(2*n)-2; j++) { // m_teams-1
            if (table[i][j]<0) printf(COLOR_YELL "%02d " COLOR_RESET, abs(table[i][j]));
            else printf("%02d ", abs(table[i][j]));
        }
        printf("\n");
    }
}

void rotate(int *array, size_t n) {
    int tmp = array[n-1];
    memmove(&array[1], &array[0], (n-1)*sizeof(int));
    array[0] = tmp;
}