#include "main.h"

int main(void) {
    clock_t start, execucao = clock();

    system("clear");
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    
    printf(COLOR_BLUE"\n AEDS III/TP2: Traveling Tournament Problem\n\n"COLOR_RESET);

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

    assert(!(Nclubes%2));

    // load: Carrega os arquivos em ./data
    start = clock();
    printf(" Carregando Dados....\n");
    getDIST(fp_travel,travel);
    getCITY(fp_cities,cities);
    getCLUB(fp_clubes,clubes);
    timeresult(start);

    // factoring: Usa o metodo do Poligono
    // para gerar uma tabela valida.
    start = clock();
    printf(" Fatorando Poligon...\n");
    initPolygon(Nclubes,tabela);
    timeresult(start);
    
    
    // links: Associa os Times com mais jogos
    // consecutivos com os clubes com sedes proximas. 
    start = clock();
    printf(" Associando Clubes...\n");
    associaClub(Nclubes,clubes,travel,tabela);
    timeresult(start);

    // Gera o mando de Campo a partir de uma primeira
    // rodada com mando aleatorio. Define os custos da
    // solucao inicial.
    start = clock();
    printf(" Solucao S0 Gulosa...\n");
    int** S0 = allocTable(Nclubes,Nrodada);
    copyTable(Nclubes,S0,tabela);
    setmando(Nclubes,S0);
    currsol = custos(Nclubes,S0,travel,clubes);
    freeMemory(Nclubes,S0);
    timeresult(start);
    
    start = clock();
    printf(" Refinando Solucao...\n");
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

    timeresult(start);

    ask();
    printTabela(Nclubes,clubes,tabela);
    printTravel(Nclubes,clubes);

    printf(COLOR_YELL" Total -> %d Km\n"COLOR_RESET, deslocTotal);
    printf("\n Tentativas para gerar o Mando de Campo: %d\n", count());

    freeMemory(Ncities,travel);
    freeMemory(Nclubes,tabela);
    printf(" TTP");
    timeresult(execucao);

    return 0;
} 