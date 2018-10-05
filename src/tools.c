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

int viagem(int** travel, clubes_t* clubes, int from, int to) {
    int a = clubes[from].sede-1;
    int b   = clubes[to].sede-1;
    return travel[a][b];
    return -1;
}

void ask() {
    printf("\n Aperte ENTER para continuar...");
    while( getchar() != '\n' );
}