#include "main.h"

int viagem(int** travel, clubes_t* clubes, int da_casa, int nemesis) {
    int from = clubes[da_casa].sede-1;
    int to   = clubes[nemesis-1].sede;
    return travel[from][to];
    return -1;
}

void initPolygon(size_t n, int** tabela) {
    int i,l;
    int topTeam = n;
    int polygon[n-1];
    
    for (i=0; i<n-1; i++) polygon[i] = i + 1;
    
    for (i=0; i<n-1; i++) {
        tabela[topTeam-1][i]    = polygon[0];
        tabela[polygon[0]-1][i] = topTeam;

        tabela[topTeam-1][i+n-1]    = polygon[0]; // Mirror
        tabela[polygon[0]-1][i+n-1] = topTeam;    // rorriM

        for (l=2; l<=n/2; l++) {
            tabela[polygon[l-1]-1][i] = polygon[n-l];
            tabela[polygon[n-l]-1][i] = polygon[l-1];

            tabela[polygon[l-1]-1][i+n-1] = polygon[n-l]; // Mirror
            tabela[polygon[n-l]-1][i+n-1] = polygon[l-1]; // rorriM
        }
        shiftArray(n-1,polygon);
    }
}

void associaClub(size_t n, clubes_t* clubes, int** travel, int** tabela) {
    int T1, T2;
    int associado = 0;
    list_t* real = create();
    list_t* unreal = create();
    buildCalvin(n,real,clubes,travel);
    buildHarold(n,unreal,tabela);

    LLprt(real);

    node_t* NXTlink = real->head;
    node_t* closeT1 = real->head;
    while (associado < n) {
        T1 = NXTlink->data.T1;
        T2 = closeT1->data.T2;
        associado++;
    }

    LLclr(real);
    LLclr(unreal);
}

void buildCalvin(size_t n, list_t* list, clubes_t* clubes, int** travel) {
    int i,j;
    int clube1, clube2;
    data_t distancia;

    for (i=0; i<n; i++) {
        clube1 = clubes[i].sede;
        for (j=0; j<n; j++) {
            clube2 = clubes[j].sede;
            if (i < j) {
                distancia.T1 = i+1;
                distancia.T2 = j+1;
                distancia.value = travel[clube1-1][clube2-1];
                LLpsh(list,distancia);
            }
        }
    }
    LLinc(list);  
}

void buildHarold(size_t n, list_t* list, int** tabela) {
    int i,j;
    int clube1, clube2;
    int rodadas = getRodadas(n);
    int** harold = allocTable(n,n);
    data_t consecutive;

    for (i=0; i<n; i++) {
        for (j=0; j<rodadas-1; j++) {
            clube1 = tabela[i][j] -1;
            clube2 = tabela[i][j+1] -1;
            harold[clube1][clube2] += 1;
            harold[clube2][clube1] += 1;
        }
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (harold[i][j]) {
                consecutive.T1 = i+1;
                consecutive.T2 = j+1;
                consecutive.value = harold[i][j];
                LLpsh(list,consecutive);
            }
        }
    }

    LLdec(list);
    freeMemory(n,harold);
}