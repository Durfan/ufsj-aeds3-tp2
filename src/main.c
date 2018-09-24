#include "main.h"

int main(void) {
    system("clear");
    const char* fp_cities = "./data/dados_cidades.in";
    const char* fp_travel = "./data/dados_distancias.in";
    const char* fp_clubes = "./data/dados_times.in";

    size_t Nclubes = getlines(fp_clubes);
    size_t Ncities = getlines(fp_cities);
    size_t Nrodada = getRodadas(Nclubes);
    int** tabela = allocate(Nclubes,Nrodada);
    int** escala = allocate(Nclubes,Nclubes);
    int** travel = allocate(Ncities,Ncities);
    cities_t cities[Ncities];
    clubes_t clubes[getlines(fp_clubes)];

    getDIST(fp_travel,travel);
    getCITY(fp_cities,cities);
    getCLUB(fp_clubes,clubes);
    
    printf(" AEDS III/TP2: Traveling Tournament Problem\n\n");

    initPolygon(Nclubes,tabela);
    printTabela(Nclubes,tabela);
    printTravel(Nclubes,tabela,travel,clubes);

    buildEscala(Nclubes,escala,tabela);
    printEscala(Nclubes,escala);

    freeMEM(Ncities,travel);
    freeMEM(Nclubes,escala);
    freeMEM(Nclubes,tabela);

    return 0;
} 