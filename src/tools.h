int** allocTable(int n, int m);
void freeMemory(int n, int** ptr);
void copyTable(int n, int** a, int** b);
void shiftArray(int n, int* array);

int viagem(int** travel, clubes_t* clubes, int a, int b);
int custos(int n, int** tabela, int** travel, clubes_t* clubes);

int count();
void timeresult(clock_t start);
void wait(unsigned int secs);
void ask();