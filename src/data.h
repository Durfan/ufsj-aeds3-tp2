typedef struct clubes {
    int idCTY;
    char nome[50];
} clubes_t;

typedef struct cities {
    int idCTY;
    char nome[50];
} cities_t;

int getlines(const char* file);
void getCLUB(const char* file, clubes_t* clubes);
void getCITY(const char* file, cities_t* cities);
void getDIST(const char* file, int** travel);
void errFile(const char* file);