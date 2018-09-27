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
 */

// void buildCalvin(size_t n, int** calvin, int** travel, clubes_t* clubes);
// void buildHarold(size_t n, int** harold, int** tabela);

// buildCalvin(Nclubes,calvin,travel,clubes);
// buildHarold(Nclubes,harold,tabela);

/* 
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

*/
