#include "main.h"

int viagem(int** travel, clubes_t* clubes, int da_casa, int nemesis) {
    int from = clubes[da_casa].sede-1;
    int to   = clubes[abs(nemesis)-1].sede;
    if (nemesis > 0) return 0;
    if (nemesis < 0) return travel[from][to];
    return -1;
}

void initPolygon(size_t n, int** tabela) {
    int i,l;
    int travel = 1;
    int topTeam = n;
    int polygon[n-1];
    
    for (i=0; i<n-1; i++) polygon[i] = i + 1;
    
    for (i=0; i<n-1; i++) {
        tabela[topTeam-1][i]    =  travel*polygon[0];
        tabela[polygon[0]-1][i] = -travel*topTeam;

        tabela[topTeam-1][i+n-1]    = -travel*polygon[0];
        tabela[polygon[0]-1][i+n-1] =  travel*topTeam;

        for (l=2; l<=n/2; l++) {
            tabela[polygon[l-1]-1][i] =  travel*polygon[n-l];
            tabela[polygon[n-l]-1][i] = -travel*polygon[l-1];
            tabela[polygon[l-1]-1][i+n-1] = -travel*polygon[n-l];
            tabela[polygon[n-l]-1][i+n-1] =  travel*polygon[l-1];
        }

        travel *= -1;
        shiftArray(n-1,polygon);
    }
}

void buildEscala(size_t n, int** escala, int** tabela) {
    int i,j;
    int clube1,clube2;

    for (i=0; i<n; i++) {
        for (j=0; j<(2*n)-3; j++) {
            clube1 = abs(tabela[i][j]) -1;
            clube2 = abs(tabela[i][j+1]) -1;
            escala[clube1][clube2] += 1;
            escala[clube2][clube1] += 1;
        }
    }
}