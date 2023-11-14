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
#define CODE_HSHOW 17
#define CODE_SPACE 18
#define CODE_END -1
char *buffer = NULL;
extern int yylex();
extern FILE *yyin;
extern int yyparse();
FILE *cFile;
char *nomeAquivo = "exemplo1.c";
void yyerror(const char *s){
    fprintf(stderr, "%s\n", s);
    exit(errno);
}

void openFile(){
    cFile = fopen(nomeAquivo,"w+");

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
            /* CASE SPACE; */
            case CODE_SPACE: {
                fprintf(cFile, "\t\n");
                break;
            }
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
                fprintf(cFile, "\t%s = %s;\n",llist->line.v1, llist->line.v2);
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
                
                while (v1 != NULL) {
                    fprintf(cFile, "\tunsigned int %s;\n", v1);
                    fprintf(cFile, "\tprintf(\"RECEBA [%s]: \");\n", v1);
                    fprintf(cFile, "\tscanf(\"%s\", &%s); \n", "%d", v1);
                    fprintf(cFile, " \n ");
                    v1 = strtok(NULL, ",");
                }

                char *v2 = strtok(llist->line.v2, ",");
                fprintf(cFile, "\tunsigned int %s;\n", v2);
                fprintf(cFile, "\n");

                break;
            }
             case CODE_HSHOW: {
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
                fprintf(cFile, "\tfor (int i = 0; i < %s; i++) {\n", llist->line.v1 );
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
                fprintf(cFile, "\tunsigned int %s;\n\t%s = %s;\n", llist->line.v1, llist->line.v1, llist->line.v2);
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
%token ENQUANTO
%token FACA
%token AQUIACABOU
%token HORADOSHOW
%token ZERO
%token ABRE
%token FIMSE
%token EXECUTE
%token FECHA
%token IGUAL
%token GT
%token LT
%token GE
%token LE
%token ENTAO
%token SOMA
%token <content> ID
%token SE
%token SENAO
%token MULT
%token FIMENQUANTO
%token VIRG
%token NEWLINE
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
    
    LLIST *aux1 = (LLIST *)malloc(sizeof(LLIST));
    if (aux1 == NULL) printf("ERROR READING PROGRAM EXIT ENTRY\n");
    aux1->line.cmd  = CODE_HSHOW;
    addLLISTend(aux1, llist);

    LLIST *aux2 = (LLIST *)malloc(sizeof(LLIST));
    if (aux2 == NULL) printf("ERROR READING PROGRAM EXIT ENTRY\n");

    aux2->line.v1 = $4;
    aux2->line.cmd = CODE_EXIT;
    addLLISTend(aux2, llist);

    cWriter(llist);
};

varlist : varlist VIRG ID {
    // Aloca ou realoca memória para o buffer e concatena o novo ID
    if (buffer == NULL) {
        buffer = strdup($3);
    } else {
        size_t new_size = strlen(buffer) + strlen($3) + 2;  // +2 para a vírgula e o caractere nulo
        buffer = realloc(buffer, new_size);
        strcat(buffer, ",");
        strcat(buffer, $3);
    }
    $$ = buffer;
}
| ID {
    // Inicializa o buffer com o primeiro ID
    buffer = strdup($1);
    $$ = buffer;
};


cmds    :   cmds    cmd { addLLISTend($2, $1); $$ = $1; }

        | cmd { $$ = $1;};

cmd     :   ENQUANTO ID FACA cmds FIMENQUANTO {

        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND ENQUANTO");

        llist->line.v1 = $2;
        llist->line.cmd = CODE_WHILE;
        addLLISTend($4, llist);

        LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END ENQUANTO");

        aux->line.cmd = CODE_END;
        addLLISTend(aux, llist);
        $$ = llist;
    }
        | ENQUANTO LT ABRE ID VIRG ID FECHA FACA cmds FIMENQUANTO{
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND ENQUANTO");

        llist->line.v1 = $4;
        llist->line.v2 = $6;
        llist->line.cmd = CODE_MENOR;
        addLLISTend($9, llist);

        LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END ENQUANTO");

        aux->line.cmd = CODE_END;
        addLLISTend(aux, llist);
        $$ = llist;

    }
        | ENQUANTO LE ABRE ID VIRG ID FECHA FACA cmds FIMENQUANTO{
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND ENQUANTO");

        llist->line.v1 = $4;
        llist->line.v2 = $6;
        llist->line.cmd = CODE_MENOR_IGUAL;
        addLLISTend($9, llist);

        LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END ENQUANTO");

        aux->line.cmd = CODE_END;
        addLLISTend(aux, llist);
        $$ = llist;

    }
        | ENQUANTO GE ABRE ID VIRG ID FECHA FACA cmds FIMENQUANTO{
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND ENQUANTO");

        llist->line.v1 = $4;
        llist->line.v2 = $6;
        llist->line.cmd = CODE_MAIOR_IGUAL;
        addLLISTend($9, llist);

        LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END ENQUANTO");

        aux->line.cmd = CODE_END;
        addLLISTend(aux, llist);
        $$ = llist;

    }
        | ENQUANTO GT ABRE ID VIRG ID FECHA FACA cmds FIMENQUANTO{
        LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND ENQUANTO");

        llist->line.v1 = $4;
        llist->line.v2 = $6;
        llist->line.cmd = CODE_MAIOR;
        addLLISTend($9, llist);

        LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING END ENQUANTO");

        aux->line.cmd = CODE_END;
        addLLISTend(aux, llist);
        $$ = llist;

    }
        
        | SOMA ABRE ID VIRG ID FECHA {
        LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READGING COMMAND SOMA");


        llist->line.v1 = $3;
        llist->line.v2 = $5;
        llist->line.cmd = CODE_OPR_ADD;
        $$ = llist;
}

        
        | ID IGUAL ID {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IGUAL\n");

            if(existsInBuffer(buffer, $1) == 0){
            llist->line.v1 = $1;
            llist->line.v2 = $3;
            llist->line.cmd = CODE_ID_NOVO; 
        } else {
            // A variável já existe na lista
            llist->line.v1 = $1;
            llist->line.v2 = $3;
            llist->line.cmd = CODE_EQUAL;
        }

            // Adiciona o nó à lista
            $$ = llist;
        }
        | EXECUTE ABRE ID VIRG cmds FECHA {

        LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READING LOOP");

        llist->line.v1 = $3;
        llist->line.cmd = CODE_REPEAT;
        addLLISTend($5,llist);

        LLIST *aux = (LLIST*)malloc(sizeof(LLIST));
        if (aux == NULL) printf("ERROR READING LOOP");

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
        if (aux == NULL) printf("ERROR READING IF");

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
        if (llist == NULL) printf("ERROR READING MULT");

        llist->line.v1 = $3;
        llist->line.v2 = $5;  
        llist->line.cmd = CODE_MULT;
        $$ = llist;
    }
    
        | NEWLINE{ 
        LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
        if (llist == NULL) printf("ERROR READING NEWLINE");
        llist->line.cmd = CODE_SPACE;
        }

%%

int main(int argc, char **argv){
    FILE *hShowCode = fopen(argv[1], "r");
    openFile();
    yyin = hShowCode;
    yyparse();
    return 0;
}