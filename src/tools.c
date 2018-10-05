#include "main.h"

int** allocTable(int n, int m) {
    int i; 
    int **table = calloc(n,sizeof(int*));
    if (table == NULL) exit(EXIT_FAILURE);
    for(i=0 ; i<n; i++)
        table[i] = calloc(m,sizeof(int));
    return table;
}

void freeMemory(int n, int** ptr) {
    int i;
    for(i=0 ; i<n ; i++)
        free(ptr[i]);
    free(ptr);
}

void shiftArray(int n, int* array) {
    int tmp = array[n-1];
    memmove(&array[1], &array[0], (n-1)*sizeof(int));
    array[0] = tmp;
}

int viagem(int** travel, clubes_t* clubes, int a, int b) {
    int from = clubes[a].sede-1;
    int to   = clubes[b].sede-1;
    assert(travel[from][to] >= 0);
    return travel[from][to];
}

int custos(int n, int** tabela, int** travel, clubes_t* clubes) {
    int i,j;
    int Clubedesloc = 0;
    int deslocTotal = 0;
    int rodadas = getRodadas(n);
    int start,nemesis;

    for (i=0; i<n; i++) {
        
        nemesis = tabela[i][0]; //Home -> first opponent
        if (nemesis < 0) Clubedesloc += viagem(travel,clubes,i,abs(nemesis)-1);

        for (j=1; j<rodadas; j++) {
            start = tabela[i][j-1];
            nemesis = tabela[i][j];
            if (start < 0 && nemesis > 0) { //Away -> Home
                Clubedesloc += viagem(travel,clubes,abs(start)-1,i);
            } else if (start > 0 && nemesis < 0) { //Home -> Away
                Clubedesloc += viagem(travel,clubes,i,abs(nemesis)-1);
            } else if (start < 0 && nemesis < 0) { //Away -> Away
                Clubedesloc += viagem(travel,clubes,abs(start)-1,abs(nemesis)-1);
            }
        }

        nemesis = tabela[i][rodadas-1]; //Last opponent -> home
        if (nemesis < 0) Clubedesloc += viagem(travel,clubes,abs(nemesis)-1,i);
        
        clubes[i].desloc = Clubedesloc;
        deslocTotal += Clubedesloc;
        Clubedesloc = 0;
    }
    return deslocTotal;
}