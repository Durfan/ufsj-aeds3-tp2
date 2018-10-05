int** allocTable(int n, int m);
void freeMemory(int n, int** ptr);
void shiftArray(int n, int* array);

int viagem(int** travel, clubes_t* clubes, int a, int b);
int custos(int n, int** tabela, int** travel, clubes_t* clubes);