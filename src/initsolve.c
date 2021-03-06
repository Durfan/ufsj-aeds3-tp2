#include "main.h"

void initPolygon(int n, int** tabela) {
    int i,l;
    int topTeam = n;
    int polygon[n-1];
    
    for (i=0; i<n-1; i++) polygon[i] = i + 1;
    
    for (i=0; i<n-1; i++) {
        tabela[topTeam-1][i] = polygon[0];
        tabela[polygon[0]-1][i] = topTeam;
        tabela[topTeam-1][i+n-1] = polygon[0];
        tabela[polygon[0]-1][i+n-1] = topTeam;

        for (l=2; l<=n/2; l++) {
            tabela[polygon[l-1]-1][i] = polygon[n-l];
            tabela[polygon[n-l]-1][i] = polygon[l-1];
            tabela[polygon[l-1]-1][i+n-1] = polygon[n-l];
            tabela[polygon[n-l]-1][i+n-1] = polygon[l-1];
        }
        shiftArray(n-1,polygon);
    }
}

void associaClub(int n, clubes_t* clubes, int** travel, int** tabela) {
    int T1,T2,T2link;
    list_t* isreal = create();
    list_t* unreal = create();
    list_t* linked = create();
    buildCalvin(n,clubes,isreal,travel);
    buildHarold(n,unreal,tabela);
    buildLinked(n,linked);

    node_t* Rptr = isreal->head;
    node_t* Uptr = unreal->head;
    node_t* Lchg;

    while (!areClubs(linked)) {

        do {
            T1 = Rptr->data.T1; 
            T2 = Rptr->data.T2;           
            if (islinked(linked,T1)) {
                T1 = Rptr->data.T2;
                T2 = Rptr->data.T1;
            }
            if (islinked(linked,T1)) Rptr = Rptr->next;
            assert(Rptr != NULL);
        } while (islinked(linked,T1));
        
        Uptr = unreal->head;
        T2link = islinked(linked,T2);

        if (T2link) {
            while (!findBT1(Uptr,T2link)) Uptr = Uptr->next;
            associar(unreal,Uptr->data.B,T1);        
            Lchg = atP(linked,n-T1);
            Lchg->data.B = Uptr->data.B;
            Lchg->data.value = 1;
        }
        else {
            while (!findAT1(Uptr)) Uptr = Uptr->next;
            associar(unreal,Uptr->data.A,T1);
            Lchg = atP(linked,n-T1);
            Lchg->data.B = Uptr->data.A;
            Lchg->data.value = 1;
        }
    }
    changeClube(clubes,linked);

    LLclr(isreal);
    LLclr(unreal);
    LLclr(linked);
}

void changeClube(clubes_t* clubes, list_t* list) {
    int i;
    clubes_t change[list->size];
    node_t* swap;

    for (i=0; i<list->size; i++) {
        swap = atP(list,i);
        change[swap->data.B-1] = clubes[swap->data.A-1];
    }
    for (i=0; i<list->size; i++) clubes[i] = change[i];
}

void buildCalvin(int n, clubes_t* clubes, list_t* list, int** travel) {
    int i,j;
    int club1, club2;
    data_t distance = {0};

    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            club1 = clubes[i].sede -1;
            club2 = clubes[j].sede -1;
            distance.T1 = i+1;
            distance.T2 = j+1;
            distance.value = travel[club1][club2];
            LLpsh(list,distance);
        }
    }
    LLinc(list);
}

void buildHarold(int n, list_t* list, int** tabela) {
    int i,j;
    int clube1, clube2;
    int rodadas = getRodadas(n);
    int** harold = allocTable(n,n);
    data_t consecutive = {0};

    for (i=0; i<n; i++) {
        for (j=0; j<rodadas-1; j++) {
            clube1 = abs(tabela[i][j]) -1;
            clube2 = abs(tabela[i][j+1]) -1;
            harold[clube1][clube2]++;
            harold[clube2][clube1]++;
        }
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (i != j) {
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

void buildLinked(int n, list_t* list) {
    int i;
    data_t link = {0};
    for (i=0; i<n; i++) {
        link.A = i+1;
        LLpsh(list,link);
    }
}

int islinked(list_t* list, int T) {
    node_t* ptr = atP(list,list->size-T);
    if (ptr->data.value) return ptr->data.A;
    return 0;
}

void associar(list_t* list, int ab, int T1) {
    if (isEmpty(list)) return;
    node_t* ptr = list->head;
    while (ptr != NULL) {
        if (ptr->data.A == ab) ptr->data.T1 = T1;
        else if (ptr->data.B == ab) ptr->data.T2 = T1;
        ptr = ptr->next;
    }
}

bool areClubs(list_t* list) {
    node_t* ptr = list->head;
    while (ptr != NULL) {
        if (!ptr->data.value) return false;
        ptr = ptr->next;
    }
    return true;
}

bool findAT1(node_t* ptr) {
    assert(ptr != NULL);
    return (ptr->data.T1 == 0 && ptr->data.T2 == 0);
}

bool findBT1(node_t* ptr, int T2) {
    assert(ptr != NULL);
    return (ptr->data.T1 == T2 && ptr->data.T2 == 0);
}

bool findCTY(node_t* ptr, int T) { // Funçao Depreciada na versão de entrega
    assert(ptr != NULL);
    return (ptr->data.T1 == T || ptr->data.T2 == T);
}