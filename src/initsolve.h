void initPolygon(int n, int** tabela);
void associaClub(int n, clubes_t* clubes, int** travel, int** tabela);
void changeClube(clubes_t* clubes, list_t* list);
void buildCalvin(int n, clubes_t* clubes, list_t* list, int** travel);
void buildHarold(int n, list_t* list, int** tabela);
void buildLinked(int n, list_t* list);

int islinked(list_t* list, int T);
void associar(list_t* list, int ab, int T1);
bool areClubs(list_t* list);

bool findAT1(node_t* ptr);
bool findBT1(node_t* ptr, int T2);
bool findCTY(node_t* ptr, int T);