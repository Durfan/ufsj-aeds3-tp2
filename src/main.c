#include "main.h"

int main(void) {
    system("clear");
    char *fp_cities = "./data/dados_cidades.in";
    char *fp_travel = "./data/dados_distancias.in";
    char *fp_clubs = "./data/dados_times.in";

    size_t n_clubs = lines(fp_clubs);
    size_t n_cities = lines(fp_cities);
    size_t n_rounds = rounds(n_clubs);
    int **schedule = allocate(n_clubs,n_rounds);
    int **escala = allocate(n_clubs,n_clubs);
    int **travel = allocate(n_cities,n_cities);
    city_t city[n_cities];
    club_t club[lines(fp_clubs)];

    getDIST(travel,fp_travel);
    getCITY(city,fp_cities);
    getCLUB(club,fp_clubs);
    
    printf(" AEDS III/TP2: Traveling Tournament Problem\n\n");

    polygon(schedule,n_clubs);
    printSchedule(schedule,n_clubs);
    printTravel(schedule,travel,club,n_clubs);

    createEscala(escala,schedule,n_clubs);
    // printEscala(escala,n_clubs);

    freeMEM(travel,n_cities);
    freeMEM(escala,n_clubs);
    freeMEM(schedule,n_clubs);

    return 0;
} 