#include "main.h"

int main(void) {
    system("clear");
    setlocale(LC_ALL, "Portuguese");
    
    const char* fp_cities = "./data/dados_cidades.in";
    const char* fp_travel = "./data/dados_distancias.in";
    const char* fp_clubes = "./data/dados_times.in";

    size_t Nclubes = getlines(fp_clubes);
    size_t Ncities = getlines(fp_cities);
    size_t Nrodada = getRodadas(Nclubes);
    int** tabela = allocTable(Nclubes,Nrodada);
    int** travel = allocTable(Ncities,Ncities);
    cities_t cities[Ncities];
    clubes_t clubes[Nclubes];

    assert(!(Nclubes%2));

    getDIST(fp_travel,travel);
    getCITY(fp_cities,cities);
    getCLUB(fp_clubes,clubes);
    
    printf(" AEDS III/TP2: Traveling Tournament Problem\n\n");

    printf(" 1: Fatoracao \"Metodo do Poligono\":\n\n");
    initPolygon(Nclubes,tabela);
    printTabela(Nclubes,clubes,tabela);

    printf("\n 2: Associacao por jogos consecutivos:\n\n");

    associaClub(Nclubes,clubes,travel,tabela);
    printTabela(Nclubes,clubes,tabela);

/* 
    if (DEBUG) {
        printDIST(Ncities,travel);
        printCITY(Ncities,cities);
        printCLUB(Nclubes,clubes);
        printTravel(Nclubes,tabela,travel,clubes);
    }
 */

    freeMemory(Ncities,travel);
    freeMemory(Nclubes,tabela);

    return 0;
} 