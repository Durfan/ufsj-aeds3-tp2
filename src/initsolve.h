void initPolygon(size_t n, int** tabela);
void associaClub(size_t n, clubes_t* clubes, int** travel, int** tabela);
void buildCalvin(size_t n, list_t* list, clubes_t* clubes, int** travel);
void buildHarold(size_t n, list_t* list, int** tabela);

bool islinked(list_t* list, int T);
void associar(list_t* list, int ab, int T1, int associa);
bool areClubs(list_t* list);
int closeCity(list_t* list, int T);
bool bt1(node_t* ptr, int T2);
bool abt(node_t* ptr);