#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *buffer;

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

int existsInBuffer( char *var) {
    char *bufferCopy = strdup(buffer);
    if (bufferCopy == NULL) {
        printf("Buffer vazio.\n");
        return 0;
    }

    char *result = strstr(bufferCopy, var);


    if (result != NULL) {
        printf("Substring encontrada: %s\n", result);
        free(bufferCopy);
        return 1;
    } else {
        printf("Substring nao encontrada.\n");
        free(bufferCopy);
        return 0;
    }
}

