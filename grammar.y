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
#define CODE_OPR_MULT 11
#define CODE_MAIOR 12
#define CODE_MAIOR_IGUAL 13
#define CODE_MENOR 14
#define CODE_MENOR_IGUAL 15
#define CODE_ID_NOVO 16
#define CODE_SPACE 17
#define CODE_OPR_SUB 18
#define CODE_OPR_DIV 19
#define CODE_END -1

char *buffer = NULL;
char *buffer2 = NULL;
extern int yylex();
extern FILE *yyin;
extern int yyparse();
FILE *cFile;
char *auxiliarGeral;
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
            case CODE_OPR_MULT: {
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

            /* CASE SUB(ID, ID2) ID = ID - ID2; */
            case CODE_OPR_SUB: {
                fprintf(cFile, "\t%s = %s - %s ;\n", llist->line.v1, llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE DIV(ID, ID2) ID = ID / ID2; */
            case CODE_OPR_DIV: {
                fprintf(cFile, "\t%s = %s / %s ;\n", llist->line.v1, llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE END ADD "}" TO END CONDITIONALS OR PROGRAM; */
            case CODE_END: {
                fprintf(cFile, "\n\t}\n");
                break;
            }

            /* CASE WHILE "WHILE(ID >0);" */
            case CODE_WHILE: {
                fprintf(cFile, "\twhile (%s != 0) {\n\n", llist->line.v1);
                break;
            }

            /* CASE FUNCTION OR ENTRY, START VARIABLES */
            case CODE_FUNCTION: {
                buffer2 =strdup(llist->line.v1);
                puts(llist->line.v1);
                char *v1 = strtok(llist->line.v1, ",");
                puts(llist->line.v1);
                
                while (v1 != NULL && *v1 != '.') {
                    fprintf(cFile, "\tint %s;\n", v1);
                    fprintf(cFile, "\tprintf(\"RECEBA [%s]: \");\n", v1);
                    fprintf(cFile, "\tscanf(\"%s\", &%s); \n", "%d", v1);
                    fprintf(cFile, " \n ");
                    v1 = strtok(NULL, ",");
                }

                v1 = strtok(NULL, ",");
                while (v1 != NULL ) {
                    fprintf(cFile, "\tint %s;\n", v1);
                    v1 = strtok(NULL, ",");
                }
                break;
            }

            /* CASE EXIT, RETURN VALUE OF SELECTED VARIABLE */
            case CODE_EXIT: {

                while(*(buffer2) !='.' ){
                    buffer2++;
                }
                buffer2++;
                char *v1 = strtok(buffer2, ",");

                while (v1 != NULL ) {
                    fprintf(cFile, "\n\tprintf(\"DEVOLVA [%s]: %%d\", %s);\n\n", v1,v1);
                    v1 = strtok(NULL, ",");
                }

                fprintf(cFile,"\treturn 0;\n}");
                break;
            }

            /* CASE CONDITIONAL SE */
            case CODE_IF: {
                fprintf(cFile,"\n\tif (%s != 0) {\n\n", llist->line.v1);
                break;
            }

            /* CASE CONDTIONAL SE NAO */
            case CODE_IF_NOT: {
                fprintf(cFile, "\n\t} else {\n\n");
                break;
            }

            /* CASE FOR */
            case CODE_REPEAT: {    
                fprintf(cFile, "\tfor (int i = 0; i < %s; i++) {\n\n", llist->line.v1 );   
                break;
            }

            /* CASE MAIOR IGUAL */
            case CODE_MAIOR_IGUAL: {
                fprintf(cFile, "\twhile(%s >= %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }

            /* CASE MAIOR QUE */
            case CODE_MAIOR: {
                fprintf(cFile, "\twhile(%s > %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }

            /* CASE MENOR_IGUAL */
            case CODE_MENOR_IGUAL: {
                fprintf(cFile, "\twhile(%s <= %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }

            /* CASE MENOR QUE */
            case CODE_MENOR: {
                fprintf(cFile, "\twhile(%s < %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }
            /* CASE ID IGUAL ID NOVO */
            case CODE_ID_NOVO: {
                fprintf(cFile, "\tint %s;\n\t%s = %s;\n", llist->line.v1, llist->line.v1, llist->line.v2);
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
%token SUB
%token <content> ID
%token SE
%token SENAO
%token MULT
%token FIMENQUANTO
%token VIRG
%token DIV
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
%type <llistvar> expr

%%

program :   RECEBA varlist DEVOLVA varlist HORADOSHOW cmds AQUIACABOU {
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
            if (buffer == NULL) {
                buffer = strdup($3);
            } else {
                size_t new_size = strlen(buffer) + strlen($3) + 2;  
                buffer = realloc(buffer, new_size);
                strcat(buffer, ",");
                strcat(buffer, $3);

            }
            $$ = buffer;
        }

        | ID {
            if (buffer == NULL) {
                buffer = strdup($1);
                $$ = $1;
            } else {
                size_t new_size = strlen(buffer) +  2;  
                buffer = realloc(buffer, new_size);
                strcat(buffer, ",.");
                size_t new_size2 = strlen(buffer) + strlen($1) + 2;  
                buffer = realloc(buffer, new_size2);
                strcat(buffer, ",");
                strcat(buffer, $1);
            }
            $$ = buffer;
        };


cmds :  cmds cmd { 
            addLLISTend($2, $1); $$ = $1; 
        }

        | cmd { $$ = $1;
        };

cmd :   ENQUANTO ID FACA cmds FIMENQUANTO {
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

        | ENQUANTO  expr  FACA cmds FIMENQUANTO {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");
            addLLISTend($2, llist); 
            addLLISTend($4, llist); 

            LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING END ENQUANTO");
            
            aux->line.cmd = CODE_END;
            addLLISTend(aux, llist);
            $$ = llist;
        }
        
        | ID IGUAL cmd {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IGUAL\n");

            LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING END ENQUANTO");
            
            llist->line.v1 = $1;
            aux->line.cmd = CODE_EQUAL;
            addLLISTend($3, llist);
            
            aux->line.v1 = $1;
            aux->line.v2 = auxiliarGeral;
            
            addLLISTend(aux, llist);
            
            $$ = llist;
        }
        
        | SOMA ABRE ID VIRG ID FECHA {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = $3;
            llist->line.v2 = $5;
            llist->line.cmd = CODE_OPR_ADD;

            auxiliarGeral = $3;
            $$ = llist;
        }

        | DIV ABRE ID VIRG ID FECHA {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = $3;
            llist->line.v2 = $5;
            llist->line.cmd = CODE_OPR_DIV;

            auxiliarGeral = $3;
            $$ = llist;
        }

        | SUB ABRE ID VIRG ID FECHA {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = $3;
            llist->line.v2 = $5;
            llist->line.cmd = CODE_OPR_SUB;

            auxiliarGeral = $3;
            $$ = llist;
        }

        | ID IGUAL ID {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IGUAL\n");
            llist->line.v1 = $1;
            llist->line.v2 = $3;
            char *auxVar = $1;
            int auxConta = 0;

            while(*auxVar != ',' && *auxVar != '\0'){
                auxVar++;
                auxConta++;
            }
            auxVar = (char*)malloc(auxConta+1);

            memcpy(auxVar, $1, auxConta);
            auxVar[auxConta] = '\0';
            puts(auxVar);
            if(existsInBuffer(auxVar) == 0){
                llist->line.cmd = CODE_ID_NOVO;  
            } else {
                
                llist->line.cmd = CODE_EQUAL;
                
            }
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

        | SE ID ENTAO cmds SENAO cmds FIMSE {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IF IF NOT");

            llist->line.v1 = $2;
            llist->line.cmd = CODE_IF;
            addLLISTend($4,llist);

            LLIST *aux = (LLIST*)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING IFNOT ");

            aux->line.cmd = CODE_IF_NOT;
            addLLISTend(aux,llist);
            addLLISTend($6,llist);

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
            llist->line.cmd = CODE_OPR_MULT;
            auxiliarGeral = $3;
            $$ = llist;
        }
    
        | NEWLINE{ 
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING NEWLINE");

            llist->line.cmd = CODE_SPACE;
        }

expr:   GT ABRE ID VIRG ID FECHA {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = $3;
            llist->line.v2 = $5;
            llist->line.cmd = CODE_MAIOR;
            $$ = llist;
        }

        | GE ABRE ID VIRG ID FECHA {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = $3;
            llist->line.v2 = $5;
            llist->line.cmd = CODE_MAIOR_IGUAL;
            $$ = llist;
        }

        | LT ABRE ID VIRG ID FECHA {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = $3;
            llist->line.v2 = $5;
            llist->line.cmd = CODE_MENOR;
            $$ = llist;
        }

        | LE ABRE ID VIRG ID FECHA {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = $3;
            llist->line.v2 = $5;
            llist->line.cmd = CODE_MENOR_IGUAL;
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