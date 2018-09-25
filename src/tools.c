#include "main.h"

int** allocTable(size_t n, size_t m) {
    int i, **table;
    table = calloc(n,sizeof(int*));
    if (table == NULL) exit(EXIT_FAILURE);
    for(i=0 ; i<n; i++)
        table[i] = calloc(m,sizeof(int));
    return table;
}

void freeMemory(size_t n, int** ptr) {
    int i;
    for(i=0 ; i<n ; i++)
        free(ptr[i]);
    free(ptr);
}

void shiftArray(size_t n, int* array) {
    int tmp = array[n-1];
    memmove(&array[1], &array[0], (n-1)*sizeof(int));
    array[0] = tmp;
}

int colBKG(int i, int j) {
    return (i+j)%2;
}