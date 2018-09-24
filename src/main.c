#include "main.h"

int main(void) {
    char *fp_cities = "./data/dados_cidades.in";
    char *fp_travel = "./data/dados_distancias.in";
    char *fp_clubs = "./data/dados_times.in";

    int clubs = 6;
    int cities = lines(fp_cities);
    int rounds = rounds(clubs);
    int **schedule = allocate(clubs,rounds);
    int **escala = allocate(clubs,clubs);
    int **travel = allocate(cities,cities);
    city_t city[cities];
    club_t club[lines(fp_clubs)];

    getDIST(travel,fp_travel);
    getCITY(city,fp_cities);
    getCLUB(club,fp_clubs);
    
    system("clear");
    printf(" AEDS III/TP2: Traveling Tournament Problem\n\n");

    polygon(schedule,clubs);
    printSchedule(schedule,clubs);

    createEscala(escala,schedule,clubs);
    printEscala(escala,clubs);

    freeMEM(travel,cities);
    freeMEM(escala,clubs);
    freeMEM(schedule,clubs);

    return 0;
} 