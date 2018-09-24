#include "main.h"

int **allocate(int n, int m) {
    int i, **array;
    array = calloc(n,sizeof(int*));
    if (array == NULL) exit(EXIT_FAILURE);
    for(i=0 ; i<n; i++)
        array[i] = calloc(m,sizeof(int));
    return array;
}

void freeMEM(int **ptr, int n) {
    int i;
    for(i=0 ; i<n ; i++)
        free(ptr[i]);
    free(ptr);
}

void rotateArray(int *array, int n) {
    int tmp = array[n-1];
    memmove(&array[1], &array[0], (n-1)*sizeof(int));
    array[0] = tmp;
}