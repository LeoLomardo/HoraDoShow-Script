#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct line{
    short cmd;
    char *v1;
    char *v2;
}LINE;

typedef struct llist{
    struct llist *ant;
    struct llist *prox;
    LINE line;
}LLIST;

void addLLISTend(LLIST *newC, LLIST *llist){

    LLIST *temp = llist;

    while (temp->prox != NULL){
        temp = temp->prox;
    }

    temp->prox = newC;
    newC->ant = temp;
}

void addLLISTstart(LLIST *newC, LLIST *llist){

    llist->ant = newC;
    newC->prox = llist;
}

int existsInBuffer(char *buffer, char *var) {
    if (strstr(buffer, var) != NULL) {
        return 1; 
    }

    return 0 ;
}