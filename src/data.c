#define _GNU_SOURCE

#include "main.h"

void getDATA(city_t *city, int D[][10], club_t *club) {
    getCITY(city);
    getDIST(D);
    getCLUB(club);
}

void getCITY(city_t *city) {
    FILE *fp = fopen("./data/dados_cidades.in", "r");
    if (fp == NULL) errFile();
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int index=0;
    while ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%d,%[^\t\n]", &city[index].idCTY, city[index].nome);
        index++;
    }
    if (line)
        free(line);
    fclose(fp);
}

void getDIST(int D[][10]) {
    FILE *fp = fopen("./data/dados_distancias.in", "r");
    if (fp == NULL) errFile();
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int row, col, dist;
    while ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%d,%d,%d", &row, &col, &dist);
        D[row-1][col-1] = dist;
    }
    if (line)
        free(line);
    fclose(fp);
}

void getCLUB(club_t *club) {
    FILE *fp = fopen("./data/dados_times.in", "r");
    if (fp == NULL) errFile();
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int index=0;
    while ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%d,%[^\t\n]", &club[index].idCTY, club[index].nome);
        index++;
    }
    if (line)
        free(line);
    fclose(fp);
}

void errFile() {
    printf(" Erro ao abrir arquivo!\n");
    exit(EXIT_FAILURE);
}