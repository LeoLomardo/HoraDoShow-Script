%option yywrap

    #include <stdio.h>
    #include "grammar.tab.h"

%%

[[:space:]]
RECEBA     { return RECEBA; }
DEVOLVA       { return DEVOLVA; }
FACA        { return FACA; }
ENQUANTO    { return ENQUANTO; }
FIM         { return FIM; }
ZERO        { return ZERO; }
SE          { return SE; }
VEZES       { return VEZES; }
ENTAO       { return ENTAO; }
SENAO       { return SENAO; }
FIMSE       { return FIMSE; }
FIMWHILE     { return FIMWHILE; }
\(           { return ABRE; }
\)           { return FECHA; }
=           { return IGUAL; }
[a-zA-Z]    {yylval.content = strdup(yytext); return (ID);}
