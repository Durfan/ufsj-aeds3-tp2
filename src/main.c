#include "main.h"

int main(void) {
    system("clear");
    const char* fp_cities = "./data/dados_cidades.in";
    const char* fp_travel = "./data/dados_distancias.in";
    const char* fp_clubes = "./data/dados_times.in";

    size_t Nclubes = getlines(fp_clubes);
    size_t Ncities = getlines(fp_cities);
    size_t Nrodada = getRodadas(Nclubes);
    int** tabela = allocTable(Nclubes,Nrodada);
    int** escala = allocTable(Nclubes,Nclubes);
    int** travel = allocTable(Ncities,Ncities);
    cities_t cities[Ncities];
    clubes_t clubes[getlines(fp_clubes)];

    getDIST(fp_travel,travel);
    getCITY(fp_cities,cities);
    getCLUB(fp_clubes,clubes);
    
    printf(" AEDS III/TP2: Traveling Tournament Problem\n\n");

    initPolygon(Nclubes,tabela);
    buildEscala(Nclubes,escala,tabela);
    
    printTabela(Nclubes,tabela);

    if (DEBUG) {
        printDIST(Ncities,travel);
        printCITY(Ncities,cities);
        printCLUB(Nclubes,clubes);
        printTravel(Nclubes,tabela,travel,clubes);
        printEscala(Nclubes,escala);
    }

    freeMemory(Ncities,travel);
    freeMemory(Nclubes,escala);
    freeMemory(Nclubes,tabela);

    return 0;
} 