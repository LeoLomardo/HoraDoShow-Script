%option yywrap

    #include <stdio.h>
    #include "grammar.tab.h"

%%

[[:space:]]
RECEBA      { return RECEBA; }
DEVOLVA     { return DEVOLVA; }
FACA        { return FACA; }
ENQUANTO    { return ENQUANTO; }
FIM         { return FIM; }
FIMEXE         { return FIMEXE; }
AQUIACABOU         { return AQUIACABOU; }
FIMENQUANTO         { return FIMENQUANTO; }
FIMSE         { return FIMSE; }
ZERO        { return ZERO; }
HORADOSHOW        { return HORADOSHOW; }
SE          { return SE; }
EXECUTE     { return EXECUTE; }
VEZES       { return VEZES; }
ENTAO       { return ENTAO; }
SENAO       { return SENAO; }
SOMA        { return SOMA;}
MULT        { return MULT;}
GT           { return GT; }
KT           { return LT; }
GE         { return GE; }
LE         { return LE; }
\(          { return ABRE; }
\)          { return FECHA; }
=           { return IGUAL; }
,           { return VIRG; }
[a-zA-Z]    {yylval.content = strdup(yytext); return (ID);}
