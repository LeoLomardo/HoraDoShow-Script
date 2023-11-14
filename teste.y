%{
#include <stdio.h>
#include <stdlib.h>
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
#define CODE_END -1

extern int yylex();
extern FILE *yyin;
extern int yyparse();
FILE *cFile;

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
    exit(errno);
}

void openFile() {
    cFile = fopen("cCode.c", "w+");

    if (cFile == NULL) {
        printf("Erro ao gerar arquivo");
        exit(-1);
    }
}

void cWriter(LLIST *llist);

%}

%token RECEBA DEVOLVA HORADOSHOW AQUIACABOU ZERO ABRE FECHA VEZES FIMEXE FIMSE VIRG
%token ENQUANTO FACA EXECUTE SOMA ID IGUAL MULT ENTAO SENAO
%token GE LE GT LT

%union {
    int var;
    char *content;
    struct llist *llistvar;
}

%type <var> program
%type <content> varlist
%type <llistvar> cmds
%type <llistvar> cmd

%%

program: RECEBA varlist DEVOLVA varlist HORADOSHOW cmds AQUIACABOU {
    // ... código original
    cWriter(llist);
};

varlist: varlist VIRG ID {
    // ... código original
}
       | ID {$$ = $1;}
       | /* vazio */ {$$ = NULL;}
       ;

cmds: cmds cmd { addLLISTend($2, $1); $$ = $1; }
    | cmd { $$ = $1; };

cmd: ENQUANTO ID FACA cmds FIMSE {
        // ... código original
    }
    | EXECUTE cmds VEZES ID FIMEXE {
        // ... código original
    }
    | ZERO ABRE ID FECHA {
        // ... código original
    }
    | MULT ABRE ID VIRG ID FECHA {
        // ... código original
    }
    | ID IGUAL ID {
        // ... código original
    }
    | /* outras regras */

%%

int main(int argc, char **argv) {
    FILE *hShowCode = fopen(argv[1], "r");
    openFile();
    yyin = hShowCode;
    yyparse();
    return 0;
}
