/*
void polygon(int num_teams) {
    int i,j, turno;
    int n2 = num_teams/2;
    int S0[num_teams+1][num_teams-1];
    int clubs[num_teams+1];
    int club1, club2;

    for (i=0; i<num_teams; i++) clubs[i]=i+1;
    for (turno=0; turno<num_teams-1; turno++) {
        for (i=0; i<n2; i++) {
            club1 = clubs[n2-i];
            club2 = clubs[n2+i+1];
            S0[n2-i][turno] = club2;
            S0[n2+i+1][turno] = club1;
        }
        rotate(clubs,num_teams);
    }

    for (i=1; i<=num_teams; i++) {
        for (j=0; j<num_teams-1; j++) {
            printf("%d ", S0[i][j]);
        }
        printf("\n");
    }
}

void getCITY(const char* file, cities_t* cities) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        return;
    }

    int i = 0;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%d,%[^\t\n]", &i, cities[i].nome);
        i++;
    }
    if (line) free(line);
    fclose(fp);
}

void getCITY2(const char* file, char* cities) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        return;
    }

    int i = 0;
    char* line = NULL;
    char* last;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\n")] = 0;
        last = strrchr(line, ',');
        if (last != NULL) {
            cities[i] = malloc(sizeof(last));
            strcpy(cities[i],last+1);
        }
        i++;
    }

    if (line) free(line);
    fclose(fp);
}

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (calvin[i][j]) {
                k = 0;
                while (k<4) {
                    Rclubs[i][k] = i;
                    Rclubs[i][k] = j;
                    Rclubs[i][k] = calvin[i][j];
                    k++;
                }
            }
        }
    }

    for (i=0; i<n; i++) {
        for (j=0; j<4; j++) {
            if (calvin[i][j]) {
                printf("%02dx%02d => %d\n", i+1, j+1, Rclubs[i][j]);
            }
        }
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (harold[i][j]) printf("%cx%c => %d\n", i+65, j+65, harold[i][j]);
        }
    }
*/

/* 
void buildCalvin(size_t n, int** calvin, int** travel, clubes_t* clubes) {
    int i,j;
    int clube1,clube2;

    for (i=0; i<n; i++) {
        clube1 = clubes[i].sede -1;

        for (j=0; j<n; j++) {
            clube2 = clubes[j].sede -1;
            calvin[i][j] = travel[clube1][clube2];
        }
    }
}

void buildHarold(size_t n, int** harold, int** tabela) {
    int i,j;
    int clube1,clube2;
    int rodadas = getRodadas(n);

    for (i=0; i<n; i++) {
        for (j=0; j<rodadas-1; j++) {
            clube1 = abs(tabela[i][j]) -1;
            clube2 = abs(tabela[i][j+1]) -1;
            harold[clube1][clube2] += 1;
            harold[clube2][clube1] += 1;
        }
    }
}

void housemaster(size_t n, clubes_t* clubes, int** tabela, int** travel) {
    int i,j;
    int club1, club2;
    int rodadas = getRodadas(n);
    int out = -1;

    for (i=0; i<n; i++) {
        club1 = clubes[i].sede;
        printf("%d ", club1);
        for (j=0; j<rodadas/2; j++) {
            club2 = clubes[tabela[i][j] -1].sede;
            printf("%d ", club2);
            if (travel[club1-1][club2-1]>0) tabela[i][j]*=out;
        }
        printf("\n");
    }

    printCLUB(n,clubes);

    void getNT(size_t n, list_t* list, int rodada, int** tabela) {
    int i, T1;
    node_t* club;
    bool home, away;

    for (i=0; i<n; i++) {
        T1 = tabela[i][rodada-1];
        club = atP(list,abs(T1)-1);
        home = club->data.T2*club->data.A;
        away = club->data.T1*club->data.B;
        if (home) club->data.value++;
        if (away) club->data.value++;
        if (T1 > 0) {
            club->data.A = 1;
            club->data.T2 = 1;
        }
        else {
            club->data.B = 1;
            club->data.T1 = 1;
        }

    }    
}
}

            T1 = tabela[j][i-1];
            T2 = tabela[j][i-1];
            club1 = atP(nt,abs(T1)-1);
            club2 = atP(nt,abs(T2)-1);
            printf("Clube 1: %d\n", club1->data.A);
            printf("Clube 2: %d\n", club2->data.A);

 */

// void buildCalvin(size_t n, int** calvin, int** travel, clubes_t* clubes);
// void buildHarold(size_t n, int** harold, int** tabela);

// buildCalvin(Nclubes,calvin,travel,clubes);
// buildHarold(Nclubes,harold,tabela);

/* 
printf(" 01: (a,b)=%02d,%02d : (T1,T2)=%02d,%02d \n", Uptr->data.A, Uptr->data.B, T1, T2);
printf("%d -> Condicao T2: (a,b)=%d,%d : (T1,T2)=%d,%d \n", i+1, Uptr->data.A, Uptr->data.B, T1, T2);

void initPolygon(size_t n, int** tabela) {
    int i,l;
    int travel = 1;
    int topTeam = n;
    int polygon[n-1];
    
    for (i=0; i<n-1; i++) polygon[i] = i + 1;
    
    for (i=0; i<n-1; i++) {
        tabela[topTeam-1][i]    =  travel*polygon[0];
        tabela[polygon[0]-1][i] = -travel*topTeam;

        tabela[topTeam-1][i+n-1]    = -travel*polygon[0];
        tabela[polygon[0]-1][i+n-1] =  travel*topTeam;

        for (l=2; l<=n/2; l++) {
            tabela[polygon[l-1]-1][i] =  travel*polygon[n-l];
            tabela[polygon[n-l]-1][i] = -travel*polygon[l-1];
            tabela[polygon[l-1]-1][i+n-1] = -travel*polygon[n-l];
            tabela[polygon[n-l]-1][i+n-1] =  travel*polygon[l-1];
        }

        travel *= -1;
        shiftArray(n-1,polygon);
    }
}

memcpy(tabela2,tabela,Nclubes*sizeof(*tabela));

    for (i=0; i<n; i++) {
        clube1 = clubes[i].sede -1;
        for (j=0; j<n; j++) {
            clube2 = clubes[j].sede -1;
            calvin[i][j] = travel[clube1][clube2];
        }
    }

void housemaster(size_t n, int** tabela) { // DIE -1 ERROR FUCKING DIE!!!!!
    int i,j,random,mando[n];
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

    for (i=1; i<2; i++) {
        getNT(n,nt,i,tabela);
        for (j=0; j<n; j++) {
            T1 = atP(nt,j);
            T2 = atP(nt,abs(tabela[j][i])-1);
            club1 = LLidx(nt,T1)+1;
            club2 = LLidx(nt,T2)+1;
            printf(" %d(%d) --> %d(%d)\n", club1, T1->data.A, club2, T2->data.A);
                
            if (T2->data.value == T1->data.value) {
                if (T1->data.A && !T2->data.A) findClub(n,i,club1,tabela);
                if (!T1->data.A && T2->data.A) tabela[j][i] = abs(tabela[j][i]);
                else {
                    random = randint(2);
                    if (random) findClub(n,i,club1,tabela);
                    else tabela[j][i] = abs(tabela[j][i]);
                }
            }
        }
    }

    LLprt(nt);
    LLclr(nt);
}

void findClub(size_t n, int j, int club, int** tabela) {
    int i = 0;
    while (i<n) {
        if (abs(tabela[i][j]) == club) tabela[i][j] *= -1;
        i++;
    }
}

void getNT(size_t n, list_t* list, int rodada, int** tabela) {
    int i, T1;
    node_t* club;
    bool home = 0;
    bool away = 1;

    for (i=0; i<n; i++) {
        T1 = tabela[i][rodada-1];
        club = atP(list,abs(T1)-1);
        if (club->data.A && !home) club->data.value++;
        if (club->data.A && away) club->data.value++;
        if (T1 < 0) club->data.A = 0;
        if (T1 > 0) club->data.A = 1;
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


*/
