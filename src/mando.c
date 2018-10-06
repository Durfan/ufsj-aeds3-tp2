#include "main.h"

void setmando(int n, int** tabela) { // DIE -1 ERROR FUCKING DIE!!!!!
    int i,j;
    int travel = 1;
    node_t* T1;
    node_t* T2;
    count();
    
    int** mando = allocTable(n,(2*n)-2);
    copyTable(n,mando,tabela);
    
    sorteia(n,mando,0);
    
    data_t booltable = {0};
    list_t* nt = create();
    for (i=0; i<n; i++) LLpsh(nt,booltable);

    for (j=0; j<n-2; j++) {

        for (i=0; i<n; i++) {
            T1 = atP(nt,abs(mando[i][j])-1);
            if (mando[i][j] < 0) T1->data.A =  travel;
            if (mando[i][j] > 0) T1->data.A = -travel;
        }

        for (i=0; i<n; i++) {
            T1 = atP(nt,i);
            T2 = atP(nt,abs(mando[i][j+1])-1);

            if (T2->data.value > T1->data.value) {
                if (T2->data.A > 0) {
                    T1->data.B = -travel;
                    T2->data.B =  travel;
                }
                if (T2->data.A < 0) {
                    T1->data.B =  travel;
                    T2->data.B = -travel;
                }
            }

            if (T2->data.value < T1->data.value) {
                if (T1->data.A > 0) {
                    T1->data.B =  travel;
                    T2->data.B = -travel;
                }
                if (T1->data.A < 0) {
                    T1->data.B = -travel;
                    T2->data.B =  travel;
                }
            }

            if (T2->data.value == T1->data.value) {
                if (T1->data.A > 0 && T2->data.A < 0) {
                    T1->data.B =  travel;
                    T2->data.B = -travel;
                }
                if (T1->data.A < 0 && T2->data.A > 0) {
                    T1->data.B = -travel;
                    T2->data.B =  travel;
                }
                else {
                    if (!randint(2)) {
                        T1->data.B =  travel;
                        T2->data.B = -travel;
                    }
                    else {
                        T1->data.B = -travel;
                        T2->data.B =  travel;
                    }
                }
            }
        }

        for (i=0; i<n; i++) {
            T1 = atP(nt,i);
            T2 = atP(nt,abs(mando[i][j+1])-1);
            mando[i][j+1] *= T2->data.B;
            if (mando[i][j]*mando[i][j+1] > 0) T1->data.value++;
        }
    }

    if (CSTMando(n,mando)) {
        freeMemory(n,mando);
        LLclr(nt);
        setmando(n,tabela);
    }
    else {
        //sorteia(n,tabela,1);
        copyTable(n,tabela,mando);
        espelha(n,tabela);
        freeMemory(n,mando);
        LLclr(nt);
    }
}

void sorteia(int n, int** tabela, int rodada) {
    int i;
    int mando[n];
    int travel = 1;

    memset(mando,0,sizeof(mando));
    for (i=0; i<n/2; i++) mando[i] = randint(2);

    for (i=n/2; i<n; i++) {
        if (mando[(n-1)-i]) mando[i] = 0;
        else mando[i] = 1;
    }

    if (!rodada) rodada = 0;
    else rodada = n-2;
    
    for (i=0; i<n; i++) {
        if (!mando[i]) tabela[i][rodada] *= -travel;
    }
}

int CSTMando(int n, int** tabela) {
    int i,j;
    int home = 0;
    int away = 0;
    int last = 0;

    for (i=0; i<n; i++) {
        for (j=0; j<n-2; j++) {
            if (tabela[i][j] > 0) home++;
            else home = 0;
            if (tabela[i][j] < 0) away++;
            else away = 0;
            if (home > 3 || away > 3) return 1;
        }
    }

    for (i=0; i<n; i++) {
        if (tabela[i][n-3] < 0) last++;
    }
    if (last < n/2) return 1;

    return 0;
}

void espelha(int n, int** tabela) {
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
        assert(n<=RAND_MAX);
        int end = RAND_MAX / n;
        assert(end > 0);
        end *= n;
        int r;
        while ((r = rand()) >= end);
        return r % n;
    }
}