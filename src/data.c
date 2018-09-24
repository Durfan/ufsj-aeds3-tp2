#include "main.h"

int lines(char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return 0;

    int count = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] != '\n') count++;
    }

    if (line) free(line);
    fclose(fp);
    return count;
}

void getCITY(city_t *city, char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        return;
    }

    int index=0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%d,%[^\t\n]", &city[index].idCTY, city[index].nome);
        index++;
    }
    if (line) free(line);
    fclose(fp);
}

void getDIST(int **travel, char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        return;
    }

    int row, col, dist;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] != '\n') {
        sscanf(line, "%d,%d,%d", &row, &col, &dist);
        travel[row-1][col-1] = dist;
        }
    }

    if (line) free(line);
    fclose(fp);
}

void getCLUB(club_t *club, char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        return;
    }

    int index=0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%d,%[^\t\n]", &club[index].idCTY, club[index].nome);
        index++;
    }

    if (line) free(line);
    fclose(fp);
}

void errFile(char *file) {
    printf(" Erro ao abrir '%s'\n", file);
}