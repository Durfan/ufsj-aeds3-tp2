#include "main.h"

// Aloca dinamicamente uma matriz
int** allocTable(int n, int m) {
    int i; 
    int **table = calloc(n,sizeof(int*));
    if (table == NULL) exit(EXIT_FAILURE);
    for(i=0; i<n; i++)
        table[i] = calloc(m,sizeof(int));
    return table;
}

// Libera a memoria alocada da matriz
void freeMemory(int n, int** ptr) {
    int i;
    for (i=0 ; i<n ; i++) free(ptr[i]);
    free(ptr);
}

// ctrl+c ctrl+v rudimentar porem eficiente
void copyTable(int n, int** a, int** b) {
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<(2*n)-2; j++) {
            a[i][j] = b[i][j];
        }
    }
}

// Movimenta um array (shift)
// Ex.: 1234 -> 4123
void shiftArray(int n, int* array) {
    int tmp = array[n-1];
    memmove(&array[1], &array[0], (n-1)*sizeof(int));
    array[0] = tmp;
}

// Retorna a distancia de uma sede para outra sede
// de um clube a partir da matriz de distancias
int viagem(int** travel, clubes_t* clubes, int a, int b) {
    int from = clubes[a].sede-1;
    int to   = clubes[b].sede-1;
    assert(travel[from][to] >= 0);
    return travel[from][to];
}

// O custo total e o parcial de cada time e calculado
// por essa funcao. A funcao avalia os custos variados
// de deslocamento, sejam eles partindo de Casa->Fora,
// Fora->Casa e de Fora->Fora. Tambem avalia os custos
// do primeiro e ultimo oponente.
int custos(int n, int** tabela, int** travel, clubes_t* clubes) {
    int i,j;
    int Clubedesloc = 0;
    int deslocTotal = 0;
    int rodadas = getRodadas(n);
    int start,nemesis;

    for (i=0; i<n; i++) {
        
        nemesis = tabela[i][0]; // Home -> first opponent
        if (nemesis < 0) Clubedesloc += viagem(travel,clubes,i,abs(nemesis)-1);

        for (j=1; j<rodadas; j++) {
            start = tabela[i][j-1];
            nemesis = tabela[i][j];
            if (start < 0 && nemesis > 0) { // Away -> Home
                Clubedesloc += viagem(travel,clubes,abs(start)-1,i);
            } else if (start > 0 && nemesis < 0) { // Home -> Away
                Clubedesloc += viagem(travel,clubes,i,abs(nemesis)-1);
            } else if (start < 0 && nemesis < 0) { // Away -> Away
                Clubedesloc += viagem(travel,clubes,abs(start)-1,abs(nemesis)-1);
            }
        }

        nemesis = tabela[i][rodadas-1]; // Last opponent -> home
        if (nemesis < 0) Clubedesloc += viagem(travel,clubes,abs(nemesis)-1,i);
        
        clubes[i].desloc = Clubedesloc;
        deslocTotal += Clubedesloc;
        Clubedesloc = 0;
    }
    return deslocTotal;
}

// Retorno do numero de tentativas para
// gerar uma tabela com mandos validos
int count() {
    static int k = 0;
    return k++;
}

// Retorno dos tempos de execucao de
// um ponto ou funcao do codigo
void timeresult(clock_t start) {
    clock_t diff;
    int msec;
    diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf(COLOR_BLUE" %ds %dms\n\n"COLOR_RESET, msec/1000, msec%1000);
    wait(1);
}

// Funcao de Pausa por n segundos
void wait(unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

// Funcao de espera pelo usuario
void ask() {
    printf(COLOR_YELL"\n Aperte ENTER para ver os resultados...\n"COLOR_RESET);
    while (getchar() != '\n');
 }