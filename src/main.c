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
    printf(" %s\n", fp_clubes);
    printf(" %s\n", fp_cities);
    printf(" %s\n", fp_travel);
    getCLUB(fp_clubes,clubes);
    getCITY(fp_cities,cities);
    getDIST(fp_travel,travel);
    timeresult(start);

    // factoring: Usa o metodo do Poligono
    // para gerar uma tabela valida.
    start = clock();
    printf(" Fatorando Poligon...\n");
    initPolygon(Nclubes,tabela);
    printEscala(Nclubes,tabela);
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
    printEscala(Nclubes,S0);
    currsol = custos(Nclubes,S0,travel,clubes);
    printf(" S000 -> %d :", currsol);
    timeresult(start);
    
    // Aplica a Solucao gerada pela fatoracao a um
    // numero de interacoes com o mando de campo
    // aleatorio afim de encontrar uma solucao melhor.
    start = clock();
    printf(" Refinando Solucao...\n");
    int iter = 0;
    int maxiter = 800;
    int** trysol = allocTable(Nclubes,Nrodada);
    int** bstsol = allocTable(Nclubes,Nrodada);
    copyTable(Nclubes,bstsol,S0);
    freeMemory(Nclubes,S0);

    while (iter < maxiter) {
        copyTable(Nclubes,trysol,tabela);
        setmando(Nclubes,trysol);

        solution = custos(Nclubes,trysol,travel,clubes);
        if (solution < currsol) {
            copyTable(Nclubes,bstsol,trysol);
            currsol = solution;
            printf(" S%03d -> %d\n", iter+1, currsol);
        }

        iter++;
    }

    freeMemory(Nclubes,trysol);
    freeMemory(Nclubes,tabela);
    timeresult(start);

    //ask(); // pausa para coferir os tempos de execucao

    // Exibe os resultados
    printTabela(Nclubes,clubes,bstsol);
    printTravel(Nclubes,clubes);

    deslocTotal = custos(Nclubes,bstsol,travel,clubes);
    printf(COLOR_YELL" Total -> %d Km\n"COLOR_RESET, deslocTotal);
    printf("\n Interacoes randomicas de Mando: %d\n", maxiter);
    printf(" Tentativas de geracao de Mando: %d\n", count());
    printf("\n TTP");

    freeMemory(Ncities,travel);
    freeMemory(Nclubes,bstsol);
    timeresult(execucao);

    return 0; // Chegou ate aqui? Nao? Save Me, Jebus!!
} 