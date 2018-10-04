#include "main.h"

void mando(size_t n, int** tabela) { // DIE -1 ERROR FUCKING DIE!!!!!
    int i,j;
    int travel = 1;
    node_t* T1;
    node_t* T2;
    
    sorteiaRDN(n,tabela,0);
    
    data_t booltable = {0};
    list_t* nt = create();
    for (i=0; i<n; i++) LLpsh(nt,booltable);

    for (i=0; i<n-3; i++) {

        for (j=0; j<n; j++) {
            T1 = atP(nt,abs(tabela[j][i])-1);
            if (tabela[j][i] < 0) T1->data.A =  travel;
            if (tabela[j][i] > 0) T1->data.A = -travel;
        }

        for (j=0; j<n; j++) {
            T1 = atP(nt,j);
            T2 = atP(nt,abs(tabela[j][i+1])-1);

            if (T2->data.value > T1->data.value) {
                if (T2->data.A > 0) {
                    T1->data.B = -travel;
                    T2->data.B =  travel; }
                if (T2->data.A < 0) {
                    T1->data.B =  travel;
                    T2->data.B = -travel; }

            }

            if (T2->data.value < T1->data.value) {
                if (T1->data.A > 0) {
                    T1->data.B =  travel;
                    T2->data.B = -travel; }
                if (T1->data.A < 0) {
                    T1->data.B = -travel;
                    T2->data.B =  travel; }
                
            }

            if (T2->data.value == T1->data.value) {
                if (T1->data.A > 0 && T2->data.A < 0) {
                    T1->data.B =  travel;
                    T2->data.B = -travel; }
                if (T1->data.A < 0 && T2->data.A > 0) {
                    T1->data.B = -travel;
                    T2->data.B =  travel; }
                else {
                    if (!randint(2)) {
                        T1->data.B =  travel;
                        T2->data.B = -travel; }
                    else {
                        T1->data.B = -travel;
                        T2->data.B =  travel; }
                }
            }
        }

        for (j=0; j<n; j++) {
            T1 = atP(nt,j);
            T2 = atP(nt,abs(tabela[j][i+1])-1);
            tabela[j][i+1] *= T2->data.B;
            if (tabela[j][i]*tabela[j][i+1] > 0) T1->data.value++;
        }
    }

    sorteiaRDN(n,tabela,1);
    espelha(n,tabela);

    LLclr(nt);
}

void sorteiaRDN(size_t n, int** tabela, int rodada) {
    int i;
    int mando[n];
    int travel = 1;

    memset(mando,0,sizeof(mando));
    for (i=0; i<n/2; i++) mando[i] = randint(2);

    for (i=n/2; i<n; i++) {
        if(mando[(n-1)-i]) mando[i] = 0;
        else mando[i] = 1;
    }

    if (!rodada) rodada = 0;
    else rodada = n-2;
    
    for (i=0; i<n; i++) {
        if (!mando[i]) tabela[i][rodada] *= -travel;
    }
}

void espelha(size_t n, int** tabela) {
    int i,j,k;
    int rodadas = getRodadas(n);

    for (i=0; i<n; i++) {
        k = rodadas/2;
        for (j=0; j<rodadas/2; j++) {
            if (tabela[i][j] > 0) tabela[i][k] *= -1;
            k++;
        }
    }

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