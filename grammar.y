%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "list.h"

#define CODE_FUNCTION 1
#define CODE_EXIT 2
#define CODE_OPR_ZERO 4
#define CODE_WHILE 5
#define CODE_EQUAL 6
#define CODE_REPEAT 7
#define CODE_IF 8
#define CODE_IF_NOT 9
#define CODE_END_IF 10
#define CODE_END_WHILE 11
#define CODE_END -1

extern int yylex();
extern FILE *yyin;
extern int yyparse();
FILE *cFile;

void yyerror(const char *s){
    fprintf(stderr, "%s\n", s);
    exit(errno);
}

void openFile(){
    cFile = fopen("cCode.c","w+");

    if (cFile == NULL){
        printf("Erro ao gerar arquivo");
        exit(-1);
    }
}

void cWriter(LLIST *llist){
    openFile();

    fprintf(cFile,"#include <stdio.h>\nint main(void) {\n");

    while(llist != NULL) {

        switch(llist->line.cmd){
            /* CASE ZERO(ID) ID = 0; */
            case CODE_OPR_ZERO: {
                fprintf(cFile, "%s = 0;\n", llist->line.v1);
                break;
            }
            
            /* CASE EQUAL ID = ID; */
            case CODE_EQUAL: {
                fprintf(cFile, "%s = %s;\n",llist->line.v1, llist->line.v2);
                break;
            }
            /* CASE END ADD "}" TO END CONDITIONALS OR PROGRAM; */
            case CODE_END: {
                fprintf(cFile, "}\n");
                break;
            }
            /* CASE END IF "}"*/
            case CODE_END_IF: {
                fprintf(cFile, "}\n");
                break;
            }
            /* CASE WHILE "WHILE(ID >0);" */
            case CODE_WHILE: {
                fprintf(cFile, "while (%s > 0) {\n", llist->line.v1);
                break;
            }
            /* CASE END WHILE "}"*/
            case CODE_END_WHILE: {
                fprintf(cFile, "}\n");
                break;
            }
            /* CASE FUNCTION OR ENTRY, START VARIABLES */
            case CODE_FUNCTION: {

                char *v1 = strtok(llist->line.v1, " ");

                while (v1 != NULL){

                    fprintf(cFile, "int %s;\n",v1);
                    fprintf(cFile, "printf(\"RECEBA [%s]: \");\n", v1);
                    fprintf(cFile, "scanf(\"%s\",&%s);\n", "%d", v1);

                    v1 = strtok(NULL, " ");
                }
                break;
            }
            /* CASE EXIT, RETURN VALUE OF SELECTED VARIABLE */
            case CODE_EXIT: {
                char *v1 = strtok(llist->line.v1, " ");

                while (v1 != NULL) {
                    fprintf(cFile, "printf(\"DEVOLVA: [%s] = %s \\n\", %s);\n", v1, "%d", v1);
                    v1 = strtok(NULL, " ");
                }

                fprintf(cFile,"return 0;\n}");
                break;
            }
            /* CASE CONDITIONAL SE */
            case CODE_IF: {
                fprintf(cFile,"if (%s != 0) {\n", llist->line.v1);
                break;
            }
            /* CASE CONDTIONAL SE NAO */
            case CODE_IF_NOT: {
                fprintf(cFile, "} else {\n");
                break;
            }
            /* CASE FOR */
            case CODE_REPEAT: {
                fprintf(cFile, "for (int i = 0; i < %s; i++) {\n", llist->line.v1);
                break;
            }

        }
        llist = llist->prox;
    }
    fclose(cFile);
}

%}

%token RECEBA
%token DEVOLVA
%token AQUIACABOU
%token ENQUANTO
%token FACA
%token ZERO
%token ABRE
%token FECHA
%token IGUAL
%token ENTAO
%token <content> ID
%token VEZES
%token SE
%token SENAO
%token FIMSE
%token FIMWHILE
%token FIM

%union{
    int var;
    char *content;
    struct llist *llistvar;
}

%type <var> program
%type <content> varlist
%type <llistvar> cmds
%type <llistvar> cmd

%%

program : RECEBA varlist DEVOLVA varlist cmds AQUIACABOU {
    LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
    if (llist == NULL) printf("ERROR READING PROGRAM FUNCTION ENTRY\n");

    llist->line.v1 = $2;
    llist->line.v2 = $4;
    llist->line.cmd = CODE_FUNCTION;
    addLLISTstart(llist, $5);

    LLIST *aux = (LLIST *)malloc(sizeof(LLIST));
    if (aux == NULL) printf("ERROR READING PROGRAM EXIT ENTRY\n");

    aux->line.v1 = $4;
    aux->line.cmd = CODE_END;
    addLLISTend(aux, llist);

    cWriter(llist);
};

varlist :   varlist ID {
    char buffer[10];

    snprintf(buffer, 10, "%s %s", $1, $2);
    $$ = buffer;

    }

        | ID    {$$ = $1;};

cmds    :   cmds    cmd { addLLISTend($2, $1); $$ = $1; }

        | cmd { $$ = $1;};

cmd     :   ENQUANTO ID FACA cmds FIMWHILE {

    LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
    if (llist == NULL) printf("ERROR READGING COMMAND ENTRY");

    llist->line.v1 = $2;
    llist->line.cmd = CODE_WHILE;
    addLLISTend($4, llist);

    LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
    if (aux == NULL) printf("ERROR READING END ENTRY");

    aux->line.cmd = CODE_END_WHILE;
    addLLISTend(aux, llist);
    $$ = llist;
}


        | ID IGUAL ID {
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));

        if (llist == NULL) printf("ERROR READING ATTRIBUTION\n");

        llist->line.v1 = $1;
        llist->line.v2 = $3;
        llist->line.cmd = CODE_EQUAL;
        $$ = llist;
    }


        | SE ID ENTAO cmds FIMSE {

        LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READING IF");

        llist->line.v1 = $2;
        llist->line.cmd = CODE_IF;
        addLLISTend($4,llist);

        LLIST *aux = (LLIST*)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END");

        aux->line.cmd = CODE_END_IF;
        addLLISTend(aux,llist);
        $$ = llist;

    }

        | SE ID ENTAO cmds SENAO ENTAO cmds FIMSE {
        
        LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READING IF IF NOT");

        llist->line.v1 = $2;
        llist->line.cmd = CODE_IF;
        addLLISTend($4,llist);

        LLIST *aux = (LLIST*)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING IFNOT ");

        aux->line.cmd = CODE_IF_NOT;
        addLLISTend(aux,llist);
        addLLISTend($7,llist);

        aux->line.cmd = CODE_END_IF;
        addLLISTend(aux,llist);

        $$ = llist;
    }

        | ZERO ABRE ID FECHA {
        LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READING ZERO");

        llist->line.v1 = $3;
        llist->line.cmd = CODE_OPR_ZERO;
        $$ = llist;
    }

%%

int main(int argc, char **argv){
    FILE *hShowCode = fopen(argv[1], "r");
    openFile();
    yyin = hShowCode;
    yyparse();
    return 0;
}