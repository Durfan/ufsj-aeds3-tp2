void initPolygon(size_t n, int** tabela);
void associaClub(size_t n, clubes_t* clubes, int** travel, int** tabela);
void changeClube(size_t n, clubes_t* clubes, list_t* list);
void buildCalvin(size_t n, clubes_t* clubes, list_t* list, int** travel);
void buildHarold(size_t n, list_t* list, int** tabela);
void buildLinked(size_t n, list_t* list);

int islinked(list_t* list, int T);
void associar(list_t* list, int ab, int T1);
bool areClubs(list_t* list);

bool findAT1(node_t* ptr);
bool findBT1(node_t* ptr, int T2);
bool findCTY(node_t* ptr, int T);