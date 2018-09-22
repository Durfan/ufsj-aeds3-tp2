typedef struct team {
    int idCTY;
    char nome[50];
} club_t;

typedef struct city {
    int idCTY;
    char nome[50];
} city_t;

void getDATA(city_t *city, int D[][10], club_t *club);
void getCITY(city_t *city);
void getDIST(int D[][10]);
void getCLUB(struct team *times);

void errFile();