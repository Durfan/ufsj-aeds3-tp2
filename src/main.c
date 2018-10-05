#include "main.h"

int main(void) {
    system("clear");
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    
    const char* fp_cities = "./data/dados_cidades.in";
    const char* fp_travel = "./data/dados_distancias.in";
    const char* fp_clubes = "./data/dados_times.in";

    int Nclubes = getlines(fp_clubes);
    int Ncities = getlines(fp_cities);
    int Nrodada = getRodadas(Nclubes);
    int** tabela = allocTable(Nclubes,Nrodada);
    int** travel = allocTable(Ncities,Ncities);
    cities_t cities[Ncities];
    clubes_t clubes[Nclubes];
    int deslocTotal;

    assert(!(Nclubes%2));

    getDIST(fp_travel,travel);
    getCITY(fp_cities,cities);
    getCLUB(fp_clubes,clubes);
    
    initPolygon(Nclubes,tabela);
    associaClub(Nclubes,clubes,travel,tabela);
    deslocTotal = custos(Nclubes,tabela,travel,clubes);

    printTabela(Nclubes,clubes,tabela);
    printTravel(Nclubes,clubes);

    printf(COLOR_YELL" Total -> %d Km\n"COLOR_RESET, deslocTotal);

    freeMemory(Ncities,travel);
    freeMemory(Nclubes,tabela);

    return 0;
} 