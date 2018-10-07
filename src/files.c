#include "main.h"

// Nota: As funcoes de leitura dos arquivos
// nao sao portaveis para o Windows.

// Retorna o numero de linhas do arquivo de
// clubes e por consequencia o numero de clubes
int getlines(const char* file) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        exit(1);
    }

    int k = 0;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] != '\n') k++;
    }

    if (line) free(line);
    fclose(fp);
    return k;
}

// Carrega a partir do arquivo de clubes, as sedes
// e nomes destes para uma struct array
int getCLUB(const char* file, clubes_t* clubes) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        return 1;
    }

    int index = 0;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%d,%[^\t\n]", &clubes[index].sede, clubes[index].nome);
        clubes[index].desloc = 0;
        index++;
    }

    if (line) free(line);
    fclose(fp);
    return 0;
}

// Carrega a partir do arquivo de cidades, os
// nomes destas para uma struct array
int getCITY(const char* file, cities_t* cities) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        return 1;
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
    return 0;
}

// Carrega a partir do arquivo de distancias, as
// distancias relativas das cidades para um 2Darray
int getDIST(const char* file, int** travel) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        errFile(file);
        return 1;
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
    return 0;
}

// Retorno de erro na abertura de arquivos
void errFile(const char* file) {
    printf(" Erro ao abrir '%s'\n", file);
}