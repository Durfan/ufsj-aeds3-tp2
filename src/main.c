#include "main.h"

int main(void) {
    int D[10][10];
    club_t club[20];
    city_t city[10];
    memset(D,0,sizeof(D));

    getDATA(city,D,club);

    printCITY(city);
    printDIST(D);
    printCLUB(club);

    return 0;
} 