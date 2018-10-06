#include "main.h"

int main(void) {
    clock_t start, diff, Exec = clock();

    system("clear");
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    
    printf(COLOR_BLUE" AEDS III/TP2: Traveling Tournament Problem\n\n"COLOR_RESET);
    printf(" Gerando Tabela:\n");

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
    int currsol;
    int solution;
    int deslocTotal;
    int msec;

    assert(!(Nclubes%2));

    start = clock();
    printf(" Carregando Dados....");
    getDIST(fp_travel,travel);
    getCITY(fp_cities,cities);
    getCLUB(fp_clubes,clubes);
    diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf(" %ds %dms\n", msec/1000, msec%1000);
    
    start = clock();
    printf(" Fatorando Poligon...");
    initPolygon(Nclubes,tabela);
    diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf(" %ds %dms\n", msec/1000, msec%1000);
    
    start = clock();
    printf(" Associando Clubes...");
    associaClub(Nclubes,clubes,travel,tabela);
    diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf(" %ds %dms\n", msec/1000, msec%1000);

    start = clock();
    printf(" Solucao S0 Gulosa...");
    int** S0 = allocTable(Nclubes,Nrodada);
    copyTable(Nclubes,S0,tabela);
    setmando(Nclubes,S0);
    currsol = custos(Nclubes,S0,travel,clubes);
    freeMemory(Nclubes,S0);
    diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf(" %ds %dms\n", msec/1000, msec%1000);
    
    start = clock();
    printf(" Refinando Solucao...");
    int iter = 0;
    int** trysol = allocTable(Nclubes,Nrodada);
    int** bstsol = allocTable(Nclubes,Nrodada);

    while (iter < 350) {
        copyTable(Nclubes,trysol,tabela);
        setmando(Nclubes,trysol);

        solution = custos(Nclubes,trysol,travel,clubes);
        if (solution < currsol) {
            copyTable(Nclubes,bstsol,trysol);
            currsol = solution;
        }

        iter++;
    }

    copyTable(Nclubes,tabela,bstsol);
    deslocTotal = custos(Nclubes,tabela,travel,clubes);
    freeMemory(Nclubes,trysol);
    freeMemory(Nclubes,bstsol);

    diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf(" %ds %dms\n\n", msec/1000, msec%1000);

    printTabela(Nclubes,clubes,tabela);
    printTravel(Nclubes,clubes);

    printf(COLOR_YELL" Total -> %d Km\n"COLOR_RESET, deslocTotal);
    printf("\n Tentativas para gerar o Mando de Campo: %d\n", count());

    freeMemory(Ncities,travel);
    freeMemory(Nclubes,tabela);

    diff = clock() - Exec;
    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf(" Tempo de Execucao: %ds %dms\n", msec/1000, msec%1000);

    return 0;
} 