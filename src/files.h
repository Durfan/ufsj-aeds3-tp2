typedef struct clubes {
    int sede;
    char nome[50];
    int desloc;
} clubes_t;

typedef struct cities {
    int idCTY;
    char nome[50];
} cities_t;

int getlines(const char* file);
int getCLUB(const char* file, clubes_t* clubes);
int getCITY(const char* file, cities_t* cities);
int getDIST(const char* file, int** travel);
void errFile(const char* file);