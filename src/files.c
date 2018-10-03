#include "main.h"

int getlines(const char* file) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) return 0;

    int count = 0;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] != '\n') count++;
    }

    if (line) free(line);
    fclose(fp);
    return count;
}

void getCLUB(const char* file, clubes_t* clubes) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        return;
    }

    int index = 0;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%d,%[^\t\n]", &clubes[index].sede, clubes[index].nome);
        index++;
    }

    if (line) free(line);
    fclose(fp);
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
        sscanf(line, "%d,%[^\t\n]", &cities[i].idCTY, cities[i].nome);
        i++;
    }
    if (line) free(line);
    fclose(fp);
}

void getDIST(const char* file, int** travel) {
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

void errFile(const char* file) {
    printf(" Erro ao abrir '%s'\n", file);
}