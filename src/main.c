#include "main.h"

int main(void) {
    int clubs = 8;
    int **schedule = allocate(clubs,(2*clubs)-2);
    int **escala = allocate(clubs,clubs);
    
    system("clear");
    printf(" AEDS III/TP2: Traveling Tournament Problem\n\n");

    polygon(schedule,clubs);
    printSchedule(schedule,clubs);

    createEscala(escala,schedule,clubs);
    printEscala(escala,clubs);

    freeMEM(escala,clubs);
    freeMEM(schedule,clubs);

    return 0;
} 