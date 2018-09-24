typedef struct team {
    int idCTY;
    char nome[50];
} club_t;

typedef struct city {
    int idCTY;
    char nome[50];
} city_t;

int lines(char *file);
void getCITY(city_t *city, char *file);
void getDIST(int **travel, char *file);
void getCLUB(club_t *times, char *file);
void errFile(char *file);