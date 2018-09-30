#include "main.h"

list_t* create() {
    list_t* lista = (list_t*) malloc(sizeof(list_t));
    if (!lista) return NULL;
    lista->size = 0;
    lista->head = NULL;
    return lista;
}

node_t* atP(list_t* list, int index) {
    if (index >= 0 && index < list->size) {
        node_t* node = list->head;
        int i;
        for (i=0; i<index; i++) {
            node = node->next;
        }
        return node;
    }
    return NULL;
}

node_t* LLmin(list_t* list, int index) {
    node_t* p = atP(list,index);
    if (p != NULL) {
        node_t* minNode = p;
        while (p != NULL) {
            if (p->data.value < minNode->data.value)
                minNode = p;
            p = p->next;
        }
        return minNode;
    }
    return NULL;
}

node_t* LLmax(list_t* list, int index) {
    node_t* p = atP(list,index);
    if (p != NULL) {
        node_t* maxNode = p;
        while (p != NULL) {
            if (p->data.value > maxNode->data.value)
                maxNode = p;
            p = p->next;
        }
        return maxNode;
    }
    return NULL;
}

int LLidx(list_t* list, node_t* node) {
    if (node != NULL) {
        node_t* p = list->head;
        int index = 0;
        while (p != node && p != NULL) {
            p = p->next;
            index++;
        }
        if (p != NULL) return index;
    }
    return -1;
}

void LLpsh(list_t* list, data_t data) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    if (!node) return;
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void LLpop(list_t* list) {
    if (!isEmpty(list)) {
        node_t* p = list->head;
        list->head = p->next;
        free(p);
        list->size--;
    }
}

void LLdel(list_t* list, int index) {
    if (!index) LLpop(list);
    else {
        node_t* current = atP(list,index);
        if (current != NULL) {
            node_t* previous = atP(list,index-1);
            previous->next = current->next;
            free(current);
            list->size--;
        }
    }
}

void LLins(list_t* list, data_t data, int index) {
    if (!index) LLpsh(list,data);
    else {
        node_t* current = atP(list,index);
        if (current != NULL) {
            node_t* previous = atP(list,index-1);
            node_t* newNode = (node_t*) malloc(sizeof(node_t));
            newNode->data = data;
            previous->next = newNode;
            newNode->next = current;
            list->size++;
        }
    }
}

void LLchg(list_t* list, node_t* nodeA, node_t* nodeB) {
    if (nodeA == nodeB) return;
    int indexA = LLidx(list,nodeA);
    int indexB = LLidx(list,nodeB);

    if (indexA == -1 || indexB == -1) return;

    if (indexA > indexB) {
        nodeA = nodeB;
        nodeB = atP(list,indexA);
        indexA = indexB;
        indexB = LLidx(list,nodeB);
    }

    node_t* pb = atP(list,indexB-1);

    if (nodeA == list->head) list->head = nodeB;
    else {
        node_t* pa = atP(list,indexA-1);
        pa->next = nodeB;
    }

    pb->next = nodeA;
    node_t* p = nodeA->next;
    nodeA->next = nodeB->next;
    nodeB->next = p;
}

void LLdup(list_t* list) {
    if (isEmpty(list)) return;
    node_t* current = list->head;
    node_t* next2next;
    int T1a,T1b,T2a,T2b;

    while (current->next != NULL) {
        T1a = current->data.T1;
        T1b = current->next->data.T1;
        T2a = current->data.T2;
        T2b = current->next->data.T2;
        if (T1a == T1b && T2a == T2b) {
            next2next = current->next->next;
            free(current->next);
            current->next = next2next;
            list->size--;
        } 
        else current = current->next;
    }
}

void LLinc(list_t* list) {
    int i;
    for (i=0; i<list->size-1; i++) {
        LLchg(list,atP(list,i),LLmin(list,i));
    }
}

void LLdec(list_t* list) {
    int i;
    for (i=0; i<list->size-1; i++) {
        LLchg(list,atP(list,i),LLmax(list,i));
    }
}

void LLprt(list_t* list) {
    if (isEmpty(list)) return;
    node_t* ptr = list->head;
    while (ptr != NULL) {
        printf ("%d %d ", ptr->data.T1, ptr->data.T2);
        printf ("%d %d %d\n",ptr->data.A, ptr->data.B , ptr->data.value);
        ptr = ptr->next;
    }
}

void LLclr(list_t* list) {
    if (list->head == NULL) {
        free(list);
        return;
    }
    node_t* delNode;
    while (list->head != NULL) {
        delNode = list->head;
        list->head = list->head->next;
        free(delNode);
    }
    free(list);
}

int isEmpty(list_t* list) {
    return (list->head == NULL);
}