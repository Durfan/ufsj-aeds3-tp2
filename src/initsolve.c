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

void associaClub(size_t n, clubes_t* clubes, int** travel, int** tabela) {
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
            if (DEBUG) assert(Rptr != NULL);
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
    changeClube(n,clubes,linked);
    housemaster(n,tabela);

    LLclr(isreal);
    LLclr(unreal);
    LLclr(linked);
}

void changeClube(size_t n, clubes_t* clubes, list_t* list) {
    int i;
    clubes_t change[list->size];
    node_t* swap;

    for (i=0; i<list->size; i++) {
        swap = atP(list,i);
        change[swap->data.B-1] = clubes[swap->data.A-1];
    }
    for (i=0; i<list->size; i++) clubes[i] = change[i];
}

void housemaster(size_t n, int** tabela) { // DIE -1 ERROR FUCKING DIE!!!!!
    int i,j,mando[n];
    int club1, club2;
    int out = -1;
    list_t* nt = create();
    data_t consecutive = {0};
    node_t* T1;
    node_t* T2;
    sorteia(n,mando);

    for (i=0; i<n; i++) LLpsh(nt,consecutive);
    
    for (i=0; i<n; i++) {
        if (!mando[i]) tabela[i][0] *= out;
    }

    for (i=1; i<n-3; i++) {
        getNT(n,nt,i,tabela);
        for (j=0; j<n; j++) {
            T1 = atP(nt,j);
            T2 = atP(nt,abs(tabela[j][i])-1);
            club1 = LLidx(nt,T1);
            club2 = LLidx(nt,T2);
            printf(" %d(%d) --> %d(%d)\n", club1, T1->data.A, club2, T2->data.A);
                
            if (T2->data.value == T1->data.value) {
                if (T1->data.A && !T2->data.A) tabela[j][i] = abs(tabela[j][i]);
                else tabela[j][i] *= out;
                if (!T1->data.A && T2->data.A) tabela[j][i] *= out;
            }
        }
    }

    LLprt(nt);
    LLclr(nt);
}

void getNT(size_t n, list_t* list, int rodada, int** tabela) {
    int i, T1;
    node_t* club;
    bool home = true;
    bool away = true;

    for (i=0; i<n; i++) {
        T1 = tabela[i][rodada-1];
        club = atP(list,abs(T1)-1);
        if (club->data.A && home) club->data.value++;
        if (club->data.B && away) club->data.value++;
        if (T1 > 0) {
            club->data.A = 1;
            club->data.B = 0;
        }
        if (T1 < 0) {
            club->data.A = 0;
            club->data.B = 1;
        }
    }    
}

void sorteia(size_t n, int* array) {
    int i;
    for (i=0; i<n/2; i++) {
        array[i] = 0;
        array[i] = randint(2);
    }
    for (i=n/2; i<n; i++) {
        if(array[(n-1)-i]) array[i] = 0;
        else array[i] = 1;
    }
}

void buildCalvin(size_t n, clubes_t* clubes, list_t* list, int** travel) {
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

void buildLinked(size_t n, list_t* list) {
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
    if (DEBUG) assert(ptr != NULL);
    return (ptr->data.T1 == 0 && ptr->data.T2 == 0);
}

bool findBT1(node_t* ptr, int T2) {
    if (DEBUG) assert(ptr != NULL);
    return (ptr->data.T1 == T2 && ptr->data.T2 == 0);
}

bool findCTY(node_t* ptr, int T) {
    if (DEBUG) assert(ptr != NULL);
    return (ptr->data.T1 == T || ptr->data.T2 == T);
}