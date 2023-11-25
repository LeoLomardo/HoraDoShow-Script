%option yywrap

    #include <stdio.h>
    #include <string.h>
    #include "grammar.tab.h"

    /*
        Leo Land Bairos Lomardo-2020201
        Matheus Valejo Gomes Pereira - 2011536
    */

%%

[[:space:]]
RECEBA      { return RECEBA; }
DEVOLVA     { return DEVOLVA; }
FACA        { return FACA; }
ENQUANTO    { return ENQUANTO; }
AQUIACABOU  { return AQUIACABOU; }
FIMENQUANTO { return FIMENQUANTO; }
FIMSE       { return FIMSE; }
ZERO        { return ZERO; }
HORADOSHOW  { return HORADOSHOW; }
SE          { return SE; }
EXECUTE     { return EXECUTE; }
ENTAO       { return ENTAO; }
SENAO       { return SENAO; }
SOMA        { return SOMA;}
MULT        { return MULT;}
DIV         { return DIV;}
VETOR       { return VETOR;}
VALORVETOR  { return VALORVETOR;}
LSHIFT      { return LSHIFT;}
RSHIFT      { return RSHIFT;}
EQUAL       { return EQUAL;}
EQUALM      { return EQUALM;}
DIF         { return DIF;}
SUB         { return SUB;}
GT          { return GT; }
LT          { return LT; }
GE          { return GE; }
LE          { return LE; }
\(          { return ABRE; }
\)          { return FECHA; }
\=          { return IGUAL; }
\,          { return VIRG; }
[[:alnum:]]+    { yylval.content = strdup(yytext); return (ID); } /*Trata números como ID também*/
%%
