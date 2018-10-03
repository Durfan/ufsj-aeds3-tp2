#include "main.h"

int** allocTable(size_t n, size_t m) {
    int i; 
    int **table = calloc(n,sizeof(int*));
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

int randint(int n) {
    if ((n - 1) == RAND_MAX) return rand();
    else {
        if (DEBUG) assert(n<=RAND_MAX);
        int end = RAND_MAX / n;
        if (DEBUG) assert(end > 0);
        end *= n;
        int r;
        while ((r = rand()) >= end);
        return r % n;
    }
}