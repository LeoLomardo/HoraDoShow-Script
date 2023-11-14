%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "llist.h"

#define CODE_FUNCTION 1
#define CODE_EXIT 2
#define CODE_OPR_ADD 3
#define CODE_OPR_ZERO 4
#define CODE_WHILE 5
#define CODE_EQUAL 6
#define CODE_REPEAT 7
#define CODE_IF 8
#define CODE_IF_NOT 9
#define CODE_MULT 11
#define CODE_MAIOR 12
#define CODE_MAIOR_IGUAL 13
#define CODE_MENOR 14
#define CODE_MENOR_IGUAL 15
#define CODE_ID_NOVO 16
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

    fprintf(cFile,"#include <stdio.h> \n \nint main(void) { \n");

    while(llist != NULL) {

        switch(llist->line.cmd){
            /* CASE ZERO(ID) ID = 0; */
            case CODE_OPR_ZERO: {
                fprintf(cFile, "\t%s = 0;\n", llist->line.v1);
                break;
            }
            /* CASE MULT(ID) ID = ID * ID; */
            case CODE_MULT: {
                fprintf(cFile, "\t%s = %s * %s;\n", llist->line.v1, llist->line.v1, llist->line.v2);
                break;
            }
            /* CASE EQUAL ID = ID; */
            case CODE_EQUAL: {
                fprintf(cFile, "\tint %s = %s;\n",llist->line.v1, llist->line.v2);
                break;
            }
            /* CASE SOMA(ID) ID = ID + ID; */
            case CODE_OPR_ADD: {
                fprintf(cFile, "\t%s = %s + %s ;\n", llist->line.v1, llist->line.v1, llist->line.v2);
                break;
            }
            /* CASE END ADD "}" TO END CONDITIONALS OR PROGRAM; */
            case CODE_END: {
                fprintf(cFile, "\t}\n");
                break;
            }
            /* CASE WHILE "WHILE(ID >0);" */
            case CODE_WHILE: {
                fprintf(cFile, "\twhile (%s > 0) {\n", llist->line.v1);
                break;
            }
            /* CASE FUNCTION OR ENTRY, START VARIABLES */
            case CODE_FUNCTION: {

                char *v1 = strtok(llist->line.v1, ",");
                
                while (v1 != NULL){

                    fprintf(cFile, "\tint %s;\n",v1);
                    fprintf(cFile, "\tprintf(\"RECEBA [%s]: \");\n", v1);
                    fprintf(cFile, "\tscanf(\"%s\",&%s); \n", "%d", v1);
                    fprintf(cFile, " \n ");
                    v1 = strtok(NULL, " ");
                }
                char *v2 = strtok(llist->line.v2, ",");
                fprintf(cFile, "\tint %s;\n",v2);
                fprintf(cFile, "\n");
                break;
            }
            /* CASE EXIT, RETURN VALUE OF SELECTED VARIABLE */
            case CODE_EXIT: {
                char *v1 = strtok(llist->line.v1, " ");

                while (v1 != NULL) {
                    fprintf(cFile, "\tprintf(\"DEVOLVA: [%s] = %s \\n\", %s);\n", v1, "%d", v1);
                    v1 = strtok(NULL, " ");
                }

                fprintf(cFile,"\treturn 0;\n}");
                break;
            }
            /* CASE CONDITIONAL SE */
            case CODE_IF: {
                fprintf(cFile,"\tif (%s != 0) {\n", llist->line.v1);
                break;
            }
            /* CASE CONDTIONAL SE NAO */
            case CODE_IF_NOT: {
                fprintf(cFile, "\t} else {\n");
                break;
            }
            /* CASE FOR */
            case CODE_REPEAT: {
                fprintf(cFile, "\tfor (int i = 0; i < %s; i++) {\n", llist->line.v1);
                break;
            }
            /* CASE MAIOR IGUAL */
            case CODE_MAIOR_IGUAL: {
                fprintf(cFile, "\twhile(%s => %s){\n", llist->line.v1,llist->line.v2);
                break;
            }
            /* CASE MAIOR QUE */
            case CODE_MAIOR: {
                fprintf(cFile, "\twhile(%s > %s){\n", llist->line.v1,llist->line.v2);
                break;
            }
            /* CASE MENOR_IGUAL */
            case CODE_MENOR_IGUAL: {
                fprintf(cFile, "\twhile(%s <= %s){\n", llist->line.v1,llist->line.v2);
                break;
            }
            /* CASE MENOR QUE */
            case CODE_MENOR: {
                fprintf(cFile, "\twhile(%s < %s){\n", llist->line.v1,llist->line.v2);
                break;
            }
            case CODE_ID_NOVO: {
                fprintf(cFile, "\t int %s;\n", llist->line.v1);
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
%token FIM
%token ENQUANTO
%token FACA
%token AQUIACABOU
%token HORADOSHOW
%token ZERO
%token ABRE
%token FIMSE
%token EXECUTE
%token FIMEXE
%token FECHA
%token IGUAL
%token GT
%token LT
%token GE
%token LE
%token ENTAO
%token SOMA
%token <content> ID
%token VEZES
%token SE
%token SENAO
%token MULT
%token FIMENQUANTO
%token VIRG
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

program : RECEBA varlist DEVOLVA varlist HORADOSHOW cmds AQUIACABOU {
    LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
    if (llist == NULL) printf("ERROR READING PROGRAM FUNCTION ENTRY\n");

    llist->line.v1 = $2;
    llist->line.v2 = $4;
    llist->line.cmd = CODE_FUNCTION;
    addLLISTstart(llist, $6);

    LLIST *aux = (LLIST *)malloc(sizeof(LLIST));
    if (aux == NULL) printf("ERROR READING PROGRAM EXIT ENTRY\n");

    aux->line.v1 = $4;
    aux->line.cmd = CODE_EXIT;
    addLLISTend(aux, llist);

    cWriter(llist);
};

varlist : varlist VIRG ID {
    char buffer[20];
    snprintf(buffer, 20, "%s,%s", $1,$3);
    $$ = buffer;
}
       | ID {$$ = $1;}
       | /* vazio */ {$$ = NULL;}
       ;


cmds    :   cmds    cmd { addLLISTend($2, $1); $$ = $1; }

        | cmd { $$ = $1;};

cmd     :   ENQUANTO ID FACA cmds FIMENQUANTO {

    LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
    if (llist == NULL) printf("ERROR READGING COMMAND ENTRY");

    llist->line.v1 = $2;
    llist->line.cmd = CODE_WHILE;
    addLLISTend($4, llist);

    LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
    if (aux == NULL) printf("ERROR READING END ENTRY");

    aux->line.cmd = CODE_END;
    addLLISTend(aux, llist);
    $$ = llist;
}
        | ENQUANTO LT ABRE ID VIRG ID FECHA FACA cmds FIMENQUANTO{
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND ENTRY");

        llist->line.v1 = $4;
        llist->line.v2 = $6;
        llist->line.cmd = CODE_MENOR;
        addLLISTend($9, llist);

        LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END ENTRY");

        aux->line.cmd = CODE_END;
        addLLISTend(aux, llist);
        $$ = llist;

    }
        | ENQUANTO LE ABRE ID VIRG ID FECHA FACA cmds FIMENQUANTO{
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND ENTRY");

        llist->line.v1 = $4;
        llist->line.v2 = $6;
        llist->line.cmd = CODE_MENOR_IGUAL;
        addLLISTend($9, llist);

        LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END ENTRY");

        aux->line.cmd = CODE_END;
        addLLISTend(aux, llist);
        $$ = llist;

    }
        | ENQUANTO GE ABRE ID VIRG ID FECHA FACA cmds FIMENQUANTO{
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND ENTRY");

        llist->line.v1 = $4;
        llist->line.v2 = $6;
        llist->line.cmd = CODE_MAIOR_IGUAL;
        addLLISTend($9, llist);

        LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END ENTRY");

        aux->line.cmd = CODE_END;
        addLLISTend(aux, llist);
        $$ = llist;

    }
        | ENQUANTO GT ABRE ID VIRG ID FECHA FACA cmds FIMENQUANTO{
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND ENTRY");

        llist->line.v1 = $4;
        llist->line.v2 = $6;
        llist->line.cmd = CODE_MAIOR;
        addLLISTend($9, llist);

        LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END ENTRY");

        aux->line.cmd = CODE_END;
        addLLISTend(aux, llist);
        $$ = llist;

    }
        
        | SOMA ABRE ID VIRG ID FECHA {
        LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
        if (llist == NULL) {
            printf("ERROR READING ADDITION\n");
            exit(EXIT_FAILURE);
        }

        llist->line.v1 = $3;
        llist->line.v2 = $5;  // Agora temos dois identificadores para a soma.
        llist->line.cmd = CODE_OPR_ADD;
        $$ = llist;
}

        
        | ID IGUAL ID {
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));

        if (llist == NULL) printf("ERROR READING ATTRIBUTION\n");
        llist->line.v1 = $1;
        llist->line.v2 = $3;
        
        if(existsInList(llist->line.v1,llist) == 0){    
            llist->line.cmd = CODE_ID_NOVO; 
        }
        
        llist->line.cmd = CODE_EQUAL;
        $$ = llist;
        
        
    }
        | EXECUTE cmds VEZES ID FIMEXE {

        LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READING LOOP");

        llist->line.v1 = $4;
        llist->line.cmd = CODE_REPEAT;
        addLLISTend($2,llist);

        LLIST *aux = (LLIST*)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END");

        aux->line.cmd = CODE_END;
        addLLISTend(aux,llist);
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

        aux->line.cmd = CODE_END;
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

        aux->line.cmd = CODE_END;
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

        | MULT ABRE ID VIRG ID FECHA {
        LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
        if (llist == NULL) {
            printf("ERROR READING MULTIPLICATION\n");
            exit(EXIT_FAILURE);
        }

        llist->line.v1 = $3;
        llist->line.v2 = $5;  
        llist->line.cmd = CODE_MULT;
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