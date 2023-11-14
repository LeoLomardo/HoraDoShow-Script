/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    RECEBA = 258,                  /* RECEBA  */
    DEVOLVA = 259,                 /* DEVOLVA  */
    FIM = 260,                     /* FIM  */
    ENQUANTO = 261,                /* ENQUANTO  */
    FACA = 262,                    /* FACA  */
    AQUIACABOU = 263,              /* AQUIACABOU  */
    HORADOSHOW = 264,              /* HORADOSHOW  */
    ZERO = 265,                    /* ZERO  */
    ABRE = 266,                    /* ABRE  */
    FIMSE = 267,                   /* FIMSE  */
    EXECUTE = 268,                 /* EXECUTE  */
    FIMEXE = 269,                  /* FIMEXE  */
    FECHA = 270,                   /* FECHA  */
    IGUAL = 271,                   /* IGUAL  */
    GT = 272,                      /* GT  */
    LT = 273,                      /* LT  */
    GE = 274,                      /* GE  */
    LE = 275,                      /* LE  */
    ENTAO = 276,                   /* ENTAO  */
    SOMA = 277,                    /* SOMA  */
    ID = 278,                      /* ID  */
    VEZES = 279,                   /* VEZES  */
    SE = 280,                      /* SE  */
    SENAO = 281,                   /* SENAO  */
    MULT = 282,                    /* MULT  */
    FIMENQUANTO = 283,             /* FIMENQUANTO  */
    VIRG = 284                     /* VIRG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 187 "grammar.y"

    int var;
    char *content;
    struct llist *llistvar;

#line 99 "grammar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
