#include "main.h"

int main(void) {
    int clubs = 6;
    int **schedule = allocate(clubs,(2*clubs)-2);

    system("clear");
    polygon(schedule,clubs);
    printSschedule(schedule,clubs);

    freeMEM(schedule,clubs);

    return 0;
} 