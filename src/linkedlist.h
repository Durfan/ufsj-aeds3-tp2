typedef struct data {
    int T1;
    int T2;
    int value;
} data_t;

typedef struct node {
    data_t data;
    struct node *next;
} node_t;

typedef struct list {
    size_t size;
    node_t* head;
} list_t;

list_t* create();
node_t* atP(list_t* list, int index);
node_t* LLmin(list_t* list, int index);
node_t* LLmax(list_t* list, int index);
int LLidx(list_t* list, node_t* node);
void LLpsh(list_t* list, data_t data);
void LLpop(list_t* list);
void LLdel(list_t* list, int index);
void LLins(list_t* list, data_t data, int index);
void LLchg(list_t* list, node_t* nodeA, node_t* nodeB);
void LLinc(list_t* list);
void LLdec(list_t* list);
void LLprt(list_t* list);
void LLclr(list_t* list);
int isEmpty(list_t* list);