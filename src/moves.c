#include "main.h"

void swapColumns(int n, int** tabela, int col1, int col2) {
    int i;
    int* temp = calloc(n,sizeof(int));

    for (i=0; i<n; i++) temp[i] = tabela[i][col1];
    for (i=0; i<n; i++) {
        tabela[i][col1] = tabela[i][col2];
        tabela[i][col2] = temp[i];
    }
    free(temp);
}

void swapEstadio(int n, int** tabela, int col, int club) {
    int i;
    tabela[club][col] = tabela[club][col]*(-1);
    tabela[abs(tabela[club][col])-1][col] = tabela[abs(tabela[club][col])-1][col]*(-1);
  
    for(i=n-1; i<(n-1)*2; i++) {
        if(tabela[club][i] == tabela[club][col]) {
            tabela[abs(tabela[club][i])-1][i] = tabela[abs(tabela[club][i])-1][i]*(-1);
            tabela[club][i] = tabela[club][i]*(-1);
        break;
    }
  }
}