# HoraDoShow-Script
 analisador sint´atico para a linguagem HoraDoShow-Script


## Rodar
 bison -d grammar.y && flex lexic.l && gcc -c lex.yy.c grammar.tab.c && gcc -o compile lex.yy.o grammar.tab.o -lfl
