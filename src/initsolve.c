#include "main.h"

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

bool islinked(list_t* list, int T) {
    node_t* ptr = atP(list,list->size-T);
    if (ptr->data.B) return true;
    return false;
}

void associar(list_t* list, int ab, int T1, int associa) {
    if (isEmpty(list)) return;
    node_t* ptr = list->head;
    while (ptr != NULL) {
        if (ptr->data.A == ab && !associa) ptr->data.T1 = T1;
        if (ptr->data.B == ab && !associa) ptr->data.T2 = T1;
        if (ptr->data.A == ab &&  associa) ptr->data.T1 = T1;
        if (ptr->data.B == ab &&  associa) ptr->data.T2 = T1;
        ptr = ptr->next;
    }
}

bool areClubs(list_t* list) {
    node_t* ptr = list->head;
    while (ptr != NULL) {
        if (!ptr->data.B) return false;
        ptr = ptr->next;
    }
    return true;
}

int closeCity(list_t* list, int T) {
    node_t* ptr = list->head;
    int min;
    int close;
    while (ptr != NULL) {
        if (ptr->data.T1 == T || ptr->data.T2 == T) {
            min = ptr->data.value;
        }
        ptr = ptr->next;
    }
    ptr = list->head;
    while (ptr != NULL) {
        if (ptr->data.T1 == T) {
            if (ptr->data.value < min) {
                min = ptr->data.value;
                close = ptr->data.T2;
            }
        }
        if (ptr->data.T2 == T) {
            if (ptr->data.value < min) {
                min = ptr->data.value;
                close = ptr->data.T1;
            }
        }
        ptr = ptr->next;
    }
    return close;
}

bool bt1(node_t* ptr, int T2) {
    if (ptr->data.T1 == T2 && ptr->data.T2 == 0) return true;
    assert(ptr != NULL);
    return false;
}

bool abt(node_t* ptr) {
    if (ptr->data.T1 == 0 && ptr->data.T2 == 0) return true;
    assert(ptr != NULL);
    return false;
}

void associaClub(size_t n, clubes_t* clubes, int** travel, int** tabela) {
    int i,T1,T2;
    list_t* isreal = create();
    list_t* unreal = create();
    list_t* linked = create();
    buildCalvin(n,isreal,clubes,travel);
    buildHarold(n,unreal,tabela);
    data_t link = {0};

    node_t* Rptr = isreal->head;
    node_t* Uptr = unreal->head;
    node_t* Lchg;

    for (i=0; i<n; i++) {
        link.A = i+1;
        LLpsh(linked,link);
    }
    
    while (!areClubs(linked)) {

        do {
            T1 = Rptr->data.T1;
            if (islinked(linked,T1)) T1 = Rptr->data.T2;
            if (islinked(linked,T1)) Rptr = Rptr->next;
        } while (islinked(linked,T1));
        
        T2 = closeCity(isreal,T1);   
        Uptr = unreal->head;

        if (islinked(linked,T2)) {
            while (!bt1(Uptr,T2)) Uptr = Uptr->next;
            associar(unreal,Uptr->data.B,T1,1);
            Lchg = atP(linked,n-T1);
            Lchg->data.B = Uptr->data.B;
        }
        else {
            while (!abt(Uptr)) Uptr = Uptr->next;
            associar(unreal,Uptr->data.A,T1,0);
            Lchg = atP(linked,n-T1);
            Lchg->data.B = Uptr->data.A;
        }
    }

    LLprt(linked);
    
    LLclr(isreal);
    LLclr(unreal);
    LLclr(linked);
}

void buildCalvin(size_t n, list_t* list, clubes_t* clubes, int** travel) {
    int i,j;
    int club1, club2;
    data_t distance = {0};

    for (i=0; i<n; i++) {
        club1 = clubes[i].sede -1;
        for (j=i+1; j<n; j++) {
            club2 = clubes[j].sede -1;
            distance.T1 = i+1;
            distance.T2 = j+1;
            distance.value = travel[club1][club2];
            LLpsh(list,distance);
        }
    }
    LLinc(list);
}

void buildHarold(size_t n, list_t* list, int** tabela) {
    int i,j;
    int clube1, clube2;
    int rodadas = getRodadas(n);
    int** harold = allocTable(n,n);
    data_t consecutive = {0};

    for (i=0; i<n; i++) {
        for (j=0; j<rodadas-1; j++) {
            clube1 = tabela[i][j] -1;
            clube2 = tabela[i][j+1] -1;
            harold[clube1][clube2]++;
            harold[clube2][clube1]++;
        }
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (harold[i][j]) {
                consecutive.A = i+1;
                consecutive.B = j+1;
                consecutive.value = harold[i][j];
                LLpsh(list,consecutive);
            }
        }
    }
    LLdec(list);
    freeMemory(n,harold);
}