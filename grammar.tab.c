/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "llist.h"

    /*
        Leo Land Bairos Lomardo-2020201
        Matheus Valejo Gomes Pereira - 2011536
    */
    
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
#define CODE_IF_GL 20
#define CODE_WHILE_GL 21
#define CODE_RSHIFT 22
#define CODE_LSHIFT 23
#define CODE_ABSOLUTE_EQUAL 24
#define CODE_ABSOLUTE_DIF 25
#define CODE_INIT_VETOR 26
#define CODE_VETOR_VALOR 27
#define CODE_EQUAL_MATRIZ 28
#define CODE_END -1


char *buffer = NULL;
char *buffer2 = NULL;
extern int yylex();
extern FILE *yyin;
extern int yyparse();
FILE *cFile;
char *auxiliarGeral;
char *nomeAquivo = "exemplo1.c";
char contFor[2] = "a";

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
                fprintf(cFile, "\n");
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

            /* CASE INIT VETOR(ID,LINHA, COLUNA) int ID[linha][coluna]; */
            case CODE_INIT_VETOR: {
                if (strcmp(llist->line.v3, "0") == 0){
                    fprintf(cFile, "\tint %s[%s];\n", llist->line.v1, llist->line.v2);
                }else if(strcmp(llist->line.v2, "0") == 0 && strcmp(llist->line.v3, "0") != 0) {
                    printf("Erro de sintaxe!\n");
                }else{
                    fprintf(cFile, "\tint %s[%s][%s];\n", llist->line.v1, llist->line.v2, llist->line.v3);
                }
                break;
            }

            /* CASE VETOR VALOR(ID,LINHA, COLUNA, VALOR) ID[linha][coluna] = VALOR; */
            case CODE_VETOR_VALOR: {
                if (strcmp(llist->line.v3, "0") == 0){
                    fprintf(cFile, "\t%s[%s] = %s;\n", llist->line.v1, llist->line.v2, llist->line.v4);
                }else if(strcmp(llist->line.v2, "0") == 0 && strcmp(llist->line.v3, "0") != 0) {
                    printf("Erro de sintaxe!\n");
                }else{
                    fprintf(cFile, "\t%s[%s][%s] = %s;\n", llist->line.v1, llist->line.v2, llist->line.v3, llist->line.v4);
                }
                break;

                
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
                fprintf(cFile, "\t}\n");
                break;
            }

            /* CASE WHILE "WHILE(ID >0);" */
            case CODE_WHILE: {
                fprintf(cFile, "\n\twhile (%s != 0) {\n\n", llist->line.v1);
                break;
            }

            /* CASE WHILE "WHILE(expr);" */
            case CODE_WHILE_GL: {
                fprintf(cFile, "\n\twhile");
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
                    fprintf(cFile, "\tscanf(\"%s\", &%s); \n", "%i", v1);
                    fprintf(cFile, " \n ");
                    v1 = strtok(NULL, ",");
                }

                v1 = strtok(NULL, ",");
                while (v1 != NULL ) {
                    fprintf(cFile, "\tint %s;\n", v1);
                    v1 = strtok(NULL, ",");
                }
                fprintf(cFile, " \n ");
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
                    fprintf(cFile, "\n\tprintf(\"DEVOLVA [%s]: %%d\", %s);\n\n", v1, v1);
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

             /* CASE CONDITIONAL SE_GL */
            case CODE_IF_GL: {
                fprintf(cFile,"\n\tif");
                break;
            }

            /* CASE CONDTIONAL SE NAO */
            case CODE_IF_NOT: {
                fprintf(cFile, "\n\t} else {\n\n");
                break;
            }

            /* CASE FOR */
            case CODE_REPEAT: {
                fprintf(cFile, "\n\tfor (int %s = 0; %s < %s; %s++) {\n\n", contFor, contFor, llist->line.v1, contFor);
                contFor[0]++;
                break;
            }

            /* CASE MAIOR IGUAL */
            case CODE_MAIOR_IGUAL: {
                fprintf(cFile, "\(%s >= %s){\n\n", llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE MAIOR QUE */
            case CODE_MAIOR: {
                fprintf(cFile, "\t(%s > %s){\n\n", llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE MENOR_IGUAL */
            case CODE_MENOR_IGUAL: {
                fprintf(cFile, "\(%s <= %s){\n\n", llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE MENOR QUE */
            case CODE_MENOR: {
                fprintf(cFile, "\t(%s < %s){\n\n", llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE ABSOLUTE EQUAL */
            case CODE_ABSOLUTE_EQUAL: {
                fprintf(cFile, "\t(%s == %s){\n\n", llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE ABSOLUTE DIF */
            case CODE_ABSOLUTE_DIF: {
                fprintf(cFile, "\t(%s != %s){\n\n", llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE ID IGUAL ID NOVO */
            case CODE_ID_NOVO: {
                fprintf(cFile, "\tint %s;\n\t%s = %s;\n", llist->line.v1, llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE ID IGUAL ID MATRIZ */
            case CODE_EQUAL_MATRIZ: {
                if (strcmp(llist->line.v4, "0") == 0){
                    fprintf(cFile, "\t %s=%s[%s];\n", llist->line.v1, llist->line.v2, llist->line.v4);

                }else if(strcmp(llist->line.v3, "0") == 0 && strcmp(llist->line.v4, "0") != 0) {
                    printf("Erro de sintaxe!\n");

                }else{
                    fprintf(cFile, "\t%s=%s[%s][%s];\n", llist->line.v1, llist->line.v2, llist->line.v3, llist->line.v4);
                }
                break;
            }

            /* CASE SHIFT BIT ESQUERDA */
            case CODE_LSHIFT: {
                fprintf(cFile, "\t%s = %s << %s ;\n", llist->line.v1, llist->line.v1, llist->line.v2);
                break;
            }

            /* CASE SHIFT BIT DIREITA */
            case CODE_RSHIFT: {
                fprintf(cFile, "\t%s = %s >> %s ;\n", llist->line.v1, llist->line.v1, llist->line.v2);
                break;
            }
        }
        llist = llist->prox;
    }
    fclose(cFile);
}


#line 374 "grammar.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RECEBA = 3,                     /* RECEBA  */
  YYSYMBOL_DEVOLVA = 4,                    /* DEVOLVA  */
  YYSYMBOL_ENQUANTO = 5,                   /* ENQUANTO  */
  YYSYMBOL_FACA = 6,                       /* FACA  */
  YYSYMBOL_AQUIACABOU = 7,                 /* AQUIACABOU  */
  YYSYMBOL_HORADOSHOW = 8,                 /* HORADOSHOW  */
  YYSYMBOL_ZERO = 9,                       /* ZERO  */
  YYSYMBOL_ABRE = 10,                      /* ABRE  */
  YYSYMBOL_FIMSE = 11,                     /* FIMSE  */
  YYSYMBOL_EXECUTE = 12,                   /* EXECUTE  */
  YYSYMBOL_FECHA = 13,                     /* FECHA  */
  YYSYMBOL_IGUAL = 14,                     /* IGUAL  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_LSHIFT = 16,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 17,                    /* RSHIFT  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_ENTAO = 21,                     /* ENTAO  */
  YYSYMBOL_SOMA = 22,                      /* SOMA  */
  YYSYMBOL_VETOR = 23,                     /* VETOR  */
  YYSYMBOL_VALORVETOR = 24,                /* VALORVETOR  */
  YYSYMBOL_SUB = 25,                       /* SUB  */
  YYSYMBOL_ID = 26,                        /* ID  */
  YYSYMBOL_SE = 27,                        /* SE  */
  YYSYMBOL_SENAO = 28,                     /* SENAO  */
  YYSYMBOL_MULT = 29,                      /* MULT  */
  YYSYMBOL_FIMENQUANTO = 30,               /* FIMENQUANTO  */
  YYSYMBOL_EQUALM = 31,                    /* EQUALM  */
  YYSYMBOL_VIRG = 32,                      /* VIRG  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_DIF = 34,                       /* DIF  */
  YYSYMBOL_EQUAL = 35,                     /* EQUAL  */
  YYSYMBOL_NEWLINE = 36,                   /* NEWLINE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_varlist = 39,                   /* varlist  */
  YYSYMBOL_cmds = 40,                      /* cmds  */
  YYSYMBOL_cmd = 41,                       /* cmd  */
  YYSYMBOL_expr = 42                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   312

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  32
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   353,   353,   372,   385,   402,   406,   409,   424,   439,
     457,   471,   486,   498,   509,   520,   532,   544,   570,   585,
     601,   617,   632,   657,   681,   690,   701,   708,   717,   726,
     736,   745,   754
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RECEBA", "DEVOLVA",
  "ENQUANTO", "FACA", "AQUIACABOU", "HORADOSHOW", "ZERO", "ABRE", "FIMSE",
  "EXECUTE", "FECHA", "IGUAL", "GT", "LSHIFT", "RSHIFT", "LT", "GE", "LE",
  "ENTAO", "SOMA", "VETOR", "VALORVETOR", "SUB", "ID", "SE", "SENAO",
  "MULT", "FIMENQUANTO", "EQUALM", "VIRG", "DIV", "DIF", "EQUAL",
  "NEWLINE", "$accept", "program", "varlist", "cmds", "cmd", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -21,    11,   -56,    -1,   -56,   -21,   -14,     2,   -56,
     235,    17,     7,    28,    29,    30,    31,    32,    34,    35,
      13,   277,    36,    37,    38,   -56,    91,   -56,    39,    40,
      44,    45,    52,    50,    51,    56,    42,    46,    47,    53,
      62,    64,    66,    67,   258,    43,    55,    69,    71,    73,
     -56,   -56,    75,    76,    78,    83,   235,    84,    85,   235,
      99,    89,    93,    96,    97,   100,   101,   102,    13,   -56,
     235,   235,   103,   116,   119,   120,   123,   124,   125,   114,
     126,   133,   137,   -56,   235,   143,   146,   148,   150,   151,
     154,    -3,    58,   155,   158,   159,   160,   161,   170,   177,
     -56,   178,   181,   -56,   166,   195,   196,   197,   187,   194,
     214,   -56,   235,   -56,   235,   217,   199,   219,   220,   229,
     233,   236,   237,   240,   -56,   -56,   -56,   -56,   228,   230,
     -56,   189,   212,   -56,   239,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   242,   241,   -56,   -56,   244,   -56,   243,   246,
     264,   265,   -56,   -56
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,    20,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    14,    13,    12,     0,     0,
      16,     0,     0,    25,     0,    15,    27,    30,    29,    32,
      31,    28,     0,     0,    22,    23,     0,    10,     0,     0,
       0,     0,    11,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,    65,   -55,   -26,   267
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     4,    26,    27,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    79,    11,     6,    82,     3,    12,     1,   111,    13,
      10,     5,     9,    14,    15,    91,    92,    36,    69,    16,
      17,    18,    19,    20,    21,   112,    22,    44,    23,   104,
      24,     7,    28,    25,     7,    29,    30,    31,    37,    38,
      39,    40,    41,    32,    42,    43,    47,    48,    49,    52,
      53,    33,    34,    51,    54,    55,    51,   131,    56,   132,
      57,    58,    59,    11,    70,    51,    51,    12,    60,   113,
      13,     8,    61,    62,    14,    15,    71,     0,    51,    63,
      16,    17,    18,    19,    20,    21,   114,    22,    64,    23,
      65,    24,    66,    67,    25,    72,    11,    73,    50,    74,
      12,    75,    76,    13,    77,    51,    51,    14,    15,    78,
      80,    81,    83,    16,    17,    18,    19,    20,    21,    11,
      22,    84,    23,    12,    24,    85,    13,    25,    86,    87,
      14,    15,    88,    89,    90,    93,    16,    17,    18,    19,
      20,    21,    11,    22,   100,    23,    12,    24,    94,    13,
      25,    95,    96,    14,    15,    97,    98,    99,   101,    16,
      17,    18,    19,    20,    21,   102,    22,   103,    23,   105,
      24,    11,   106,    25,   107,    12,   108,   109,    13,   124,
     110,   115,    14,    15,   116,   117,   118,   119,    16,    17,
      18,    19,    20,    21,    11,    22,   120,    23,    12,    24,
     144,    13,    25,   121,   122,    14,    15,   123,   125,   126,
     127,    16,    17,    18,    19,    20,    21,    11,    22,   128,
      23,    12,    24,   145,    13,    25,   129,   130,    14,    15,
     133,   134,   135,   136,    16,    17,    18,    19,    20,    21,
      11,    22,   137,    23,    12,    24,   138,    13,    25,   139,
     140,    14,    15,   141,   142,   147,   143,    16,    17,    18,
      19,    20,    21,    11,    22,   146,    23,    12,    24,   150,
      13,    25,   151,   148,    14,    15,   149,   152,   153,     0,
      16,    17,    18,    19,    68,    21,     0,    22,    46,    23,
       0,    24,    28,     0,    25,    29,    30,    31,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    33,    34
};

static const yytype_int16 yycheck[] =
{
      26,    56,     5,     4,    59,    26,     9,     3,    11,    12,
       8,     0,    26,    16,    17,    70,    71,    10,    44,    22,
      23,    24,    25,    26,    27,    28,    29,    14,    31,    84,
      33,    32,    15,    36,    32,    18,    19,    20,    10,    10,
      10,    10,    10,    26,    10,    10,    10,    10,    10,    10,
      10,    34,    35,    79,    10,    10,    82,   112,     6,   114,
      10,    10,     6,     5,    21,    91,    92,     9,    26,    11,
      12,     6,    26,    26,    16,    17,    21,    -1,   104,    26,
      22,    23,    24,    25,    26,    27,    28,    29,    26,    31,
      26,    33,    26,    26,    36,    26,     5,    26,     7,    26,
       9,    26,    26,    12,    26,   131,   132,    16,    17,    26,
      26,    26,    13,    22,    23,    24,    25,    26,    27,     5,
      29,    32,    31,     9,    33,    32,    12,    36,    32,    32,
      16,    17,    32,    32,    32,    32,    22,    23,    24,    25,
      26,    27,     5,    29,    30,    31,     9,    33,    32,    12,
      36,    32,    32,    16,    17,    32,    32,    32,    32,    22,
      23,    24,    25,    26,    27,    32,    29,    30,    31,    26,
      33,     5,    26,    36,    26,     9,    26,    26,    12,    13,
      26,    26,    16,    17,    26,    26,    26,    26,    22,    23,
      24,    25,    26,    27,     5,    29,    26,    31,     9,    33,
      11,    12,    36,    26,    26,    16,    17,    26,    13,    13,
      13,    22,    23,    24,    25,    26,    27,     5,    29,    32,
      31,     9,    33,    11,    12,    36,    32,    13,    16,    17,
      13,    32,    13,    13,    22,    23,    24,    25,    26,    27,
       5,    29,    13,    31,     9,    33,    13,    12,    36,    13,
      13,    16,    17,    13,    26,    13,    26,    22,    23,    24,
      25,    26,    27,     5,    29,    26,    31,     9,    33,    26,
      12,    36,    26,    32,    16,    17,    32,    13,    13,    -1,
      22,    23,    24,    25,    26,    27,    -1,    29,    21,    31,
      -1,    33,    15,    -1,    36,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    38,    26,    39,     0,     4,    32,    39,    26,
       8,     5,     9,    12,    16,    17,    22,    23,    24,    25,
      26,    27,    29,    31,    33,    36,    40,    41,    15,    18,
      19,    20,    26,    34,    35,    42,    10,    10,    10,    10,
      10,    10,    10,    10,    14,    26,    42,    10,    10,    10,
       7,    41,    10,    10,    10,    10,     6,    10,    10,     6,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    41,
      21,    21,    26,    26,    26,    26,    26,    26,    26,    40,
      26,    26,    40,    13,    32,    32,    32,    32,    32,    32,
      32,    40,    40,    32,    32,    32,    32,    32,    32,    32,
      30,    32,    32,    30,    40,    26,    26,    26,    26,    26,
      26,    11,    28,    11,    28,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    13,    13,    13,    13,    32,    32,
      13,    40,    40,    13,    32,    13,    13,    13,    13,    13,
      13,    13,    26,    26,    11,    11,    26,    13,    32,    32,
      26,    26,    13,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    42,    42,    42,
      42,    42,    42
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     3,     1,     2,     1,     5,     5,     3,
       8,    10,     6,     6,     6,     6,     6,     3,    10,     6,
       5,     5,     7,     7,     4,     6,     1,     6,     6,     6,
       6,     6,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: RECEBA varlist DEVOLVA varlist HORADOSHOW cmds AQUIACABOU  */
#line 353 "grammar.y"
                                                                      {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING PROGRAM FUNCTION ENTRY\n");

            llist->line.v1 = (yyvsp[-5].content);
            llist->line.v2 = (yyvsp[-3].content);
            llist->line.cmd = CODE_FUNCTION;
            addLLISTstart(llist, (yyvsp[-1].llistvar));

            LLIST *aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING PROGRAM EXIT ENTRY\n");

            aux->line.v1 = (yyvsp[-3].content);
            aux->line.cmd = CODE_EXIT;
            addLLISTend(aux, llist);

            cWriter(llist);
        }
#line 1530 "grammar.tab.c"
    break;

  case 3: /* varlist: varlist VIRG ID  */
#line 372 "grammar.y"
                          {
            if (buffer == NULL) {
                buffer = strdup((yyvsp[0].content));
            } else {
                size_t new_size = strlen(buffer) + strlen((yyvsp[0].content)) + 2;  
                buffer = realloc(buffer, new_size);
                strcat(buffer, ",");
                strcat(buffer, (yyvsp[0].content));

            }
            (yyval.content) = buffer;
        }
#line 1547 "grammar.tab.c"
    break;

  case 4: /* varlist: ID  */
#line 385 "grammar.y"
             {
            if (buffer == NULL) {
                buffer = strdup((yyvsp[0].content));
                (yyval.content) = (yyvsp[0].content);
            } else {
                size_t new_size = strlen(buffer) +  2;  
                buffer = realloc(buffer, new_size);
                strcat(buffer, ",.");
                size_t new_size2 = strlen(buffer) + strlen((yyvsp[0].content)) + 2;  
                buffer = realloc(buffer, new_size2);
                strcat(buffer, ",");
                strcat(buffer, (yyvsp[0].content));
            }
            (yyval.content) = buffer;
        }
#line 1567 "grammar.tab.c"
    break;

  case 5: /* cmds: cmds cmd  */
#line 402 "grammar.y"
                 { 
            addLLISTend((yyvsp[0].llistvar), (yyvsp[-1].llistvar)); (yyval.llistvar) = (yyvsp[-1].llistvar); 
        }
#line 1575 "grammar.tab.c"
    break;

  case 6: /* cmds: cmd  */
#line 406 "grammar.y"
              { (yyval.llistvar) = (yyvsp[0].llistvar);
        }
#line 1582 "grammar.tab.c"
    break;

  case 7: /* cmd: ENQUANTO ID FACA cmds FIMENQUANTO  */
#line 409 "grammar.y"
                                          {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");
            llist->line.v1 = (yyvsp[-3].content);
            llist->line.cmd = CODE_WHILE;
            addLLISTend((yyvsp[-1].llistvar), llist);

            LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING END ENQUANTO");

            aux->line.cmd = CODE_END;
            addLLISTend(aux, llist);
            (yyval.llistvar) = llist;
        }
#line 1601 "grammar.tab.c"
    break;

  case 8: /* cmd: ENQUANTO expr FACA cmds FIMENQUANTO  */
#line 424 "grammar.y"
                                                {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");
            llist->line.cmd = CODE_WHILE_GL;
            addLLISTend((yyvsp[-3].llistvar), llist); 
            addLLISTend((yyvsp[-1].llistvar), llist); 

            LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING END ENQUANTO");
            
            aux->line.cmd = CODE_END;
            addLLISTend(aux, llist);
            (yyval.llistvar) = llist;
        }
#line 1620 "grammar.tab.c"
    break;

  case 9: /* cmd: ID IGUAL cmd  */
#line 439 "grammar.y"
                       {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IGUAL\n");

            LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING END ENQUANTO");
            
            llist->line.v1 = (yyvsp[-2].content);
            aux->line.cmd = CODE_EQUAL;
            addLLISTend((yyvsp[0].llistvar), llist);
            
            aux->line.v1 = (yyvsp[-2].content);
            aux->line.v2 = auxiliarGeral;
            
            addLLISTend(aux, llist);
            
            (yyval.llistvar) = llist;
        }
#line 1643 "grammar.tab.c"
    break;

  case 10: /* cmd: VETOR ABRE ID VIRG ID VIRG ID FECHA  */
#line 457 "grammar.y"
                                              {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IGUAL\n");

            LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING END ENQUANTO");
            
            llist->line.v1 = (yyvsp[-5].content);
            llist->line.v2 = (yyvsp[-3].content);
            llist->line.v3 = (yyvsp[-1].content);
            llist->line.cmd = CODE_INIT_VETOR;
            
            (yyval.llistvar) = llist;
        }
#line 1662 "grammar.tab.c"
    break;

  case 11: /* cmd: VALORVETOR ABRE ID VIRG ID VIRG ID VIRG ID FECHA  */
#line 471 "grammar.y"
                                                           {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IGUAL\n");

            LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING END ENQUANTO");
            
            llist->line.v1 = (yyvsp[-7].content);
            llist->line.v2 = (yyvsp[-5].content);
            llist->line.v3 = (yyvsp[-3].content);
            llist->line.v4 = (yyvsp[-1].content);
            llist->line.cmd = CODE_VETOR_VALOR;
            
            (yyval.llistvar) = llist;
        }
#line 1682 "grammar.tab.c"
    break;

  case 12: /* cmd: SOMA ABRE ID VIRG ID FECHA  */
#line 486 "grammar.y"
                                     {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_OPR_ADD;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1698 "grammar.tab.c"
    break;

  case 13: /* cmd: RSHIFT ABRE ID VIRG ID FECHA  */
#line 498 "grammar.y"
                                       {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_RSHIFT;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1714 "grammar.tab.c"
    break;

  case 14: /* cmd: LSHIFT ABRE ID VIRG ID FECHA  */
#line 509 "grammar.y"
                                       {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_LSHIFT;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1730 "grammar.tab.c"
    break;

  case 15: /* cmd: DIV ABRE ID VIRG ID FECHA  */
#line 520 "grammar.y"
                                    {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_OPR_DIV;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1746 "grammar.tab.c"
    break;

  case 16: /* cmd: SUB ABRE ID VIRG ID FECHA  */
#line 532 "grammar.y"
                                    {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_OPR_SUB;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1762 "grammar.tab.c"
    break;

  case 17: /* cmd: ID IGUAL ID  */
#line 544 "grammar.y"
                      {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IGUAL\n");
            llist->line.v1 = (yyvsp[-2].content);
            llist->line.v2 = (yyvsp[0].content);
            char *auxVar = (yyvsp[-2].content);
            int auxConta = 0;

            while(*auxVar != ',' && *auxVar != '\0'){
                auxVar++;
                auxConta++;
            }
            auxVar = (char*)malloc(auxConta+1);

            memcpy(auxVar, (yyvsp[-2].content), auxConta);
            auxVar[auxConta] = '\0';
            puts(auxVar);
            if(existsInBuffer(auxVar) == 0){
                llist->line.cmd = CODE_ID_NOVO;  
            } else {
                
                llist->line.cmd = CODE_EQUAL;
                
            }
            (yyval.llistvar) = llist;
        }
#line 1793 "grammar.tab.c"
    break;

  case 18: /* cmd: EQUALM ABRE ID VIRG ID VIRG ID VIRG ID FECHA  */
#line 570 "grammar.y"
                                                       {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IGUAL\n");

            LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING END ENQUANTO");
            
            llist->line.v1 = (yyvsp[-7].content);
            llist->line.v2 = (yyvsp[-5].content);
            llist->line.v3 = (yyvsp[-3].content);
            llist->line.v4 = (yyvsp[-1].content);
            llist->line.cmd = CODE_EQUAL_MATRIZ;
            
            (yyval.llistvar) = llist;
        }
#line 1813 "grammar.tab.c"
    break;

  case 19: /* cmd: EXECUTE ABRE ID VIRG cmds FECHA  */
#line 585 "grammar.y"
                                          {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING LOOP");
            
            llist->line.v1 = (yyvsp[-3].content);
            llist->line.cmd = CODE_REPEAT;
            addLLISTend((yyvsp[-1].llistvar),llist);

            LLIST *aux = (LLIST*)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING LOOP");

            aux->line.cmd = CODE_END;
            addLLISTend(aux,llist);
            (yyval.llistvar) = llist;
        }
#line 1833 "grammar.tab.c"
    break;

  case 20: /* cmd: SE ID ENTAO cmds FIMSE  */
#line 601 "grammar.y"
                                 {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IF");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.cmd = CODE_IF;
            addLLISTend((yyvsp[-1].llistvar),llist);

            LLIST *aux = (LLIST*)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING IF");

            aux->line.cmd = CODE_END;
            addLLISTend(aux,llist);
            (yyval.llistvar) = llist;
        }
#line 1853 "grammar.tab.c"
    break;

  case 21: /* cmd: SE expr ENTAO cmds FIMSE  */
#line 617 "grammar.y"
                                   {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND IF");
            llist->line.cmd = CODE_IF_GL;
            addLLISTend((yyvsp[-3].llistvar),llist);
	        addLLISTend((yyvsp[-1].llistvar), llist); 

            LLIST * aux = (LLIST *)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING END IF");
            
            aux->line.cmd = CODE_END;
            addLLISTend(aux, llist);
            (yyval.llistvar) = llist;
        }
#line 1872 "grammar.tab.c"
    break;

  case 22: /* cmd: SE ID ENTAO cmds SENAO cmds FIMSE  */
#line 632 "grammar.y"
                                            {
    
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING IF IF NOT");

            llist->line.v1 = (yyvsp[-5].content);
            llist->line.cmd = CODE_IF;
            addLLISTend((yyvsp[-3].llistvar),llist);
            
            LLIST *aux = (LLIST*)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING IFNOT ");
            
            aux->line.cmd = CODE_IF_NOT;
            
            addLLISTend(aux,llist);
            addLLISTend((yyvsp[-1].llistvar),llist);

            LLIST *aux2 = (LLIST*)malloc(sizeof(LLIST));
            if (aux2 == NULL) printf("ERROR READING IFNOT ");
            aux2->line.cmd = CODE_END;
            addLLISTend(aux2,llist);

            (yyval.llistvar) = llist;
        }
#line 1901 "grammar.tab.c"
    break;

  case 23: /* cmd: SE expr ENTAO cmds SENAO cmds FIMSE  */
#line 657 "grammar.y"
                                              {
        
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND IF");
            llist->line.cmd = CODE_IF_GL;
            addLLISTend((yyvsp[-5].llistvar),llist);
	        addLLISTend((yyvsp[-3].llistvar), llist); 
            
            LLIST *aux = (LLIST*)malloc(sizeof(LLIST));
            if (aux == NULL) printf("ERROR READING IFNOT ");
            
            aux->line.cmd = CODE_IF_NOT;
            
            addLLISTend(aux,llist);
            addLLISTend((yyvsp[-1].llistvar),llist);

            LLIST *aux2 = (LLIST*)malloc(sizeof(LLIST));
            if (aux2 == NULL) printf("ERROR READING IFNOT ");
            aux2->line.cmd = CODE_END;
            addLLISTend(aux2,llist);

            (yyval.llistvar) = llist;
        }
#line 1929 "grammar.tab.c"
    break;

  case 24: /* cmd: ZERO ABRE ID FECHA  */
#line 681 "grammar.y"
                             {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING ZERO");

            llist->line.v1 = (yyvsp[-1].content);
            llist->line.cmd = CODE_OPR_ZERO;
            (yyval.llistvar) = llist;
        }
#line 1942 "grammar.tab.c"
    break;

  case 25: /* cmd: MULT ABRE ID VIRG ID FECHA  */
#line 690 "grammar.y"
                                     {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING MULT");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);  
            llist->line.cmd = CODE_OPR_MULT;
            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1957 "grammar.tab.c"
    break;

  case 26: /* cmd: NEWLINE  */
#line 701 "grammar.y"
                 { 
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING NEWLINE");

            llist->line.cmd = CODE_SPACE;
        }
#line 1968 "grammar.tab.c"
    break;

  case 27: /* expr: GT ABRE ID VIRG ID FECHA  */
#line 708 "grammar.y"
                                 {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_MAIOR;
            (yyval.llistvar) = llist;
        }
#line 1982 "grammar.tab.c"
    break;

  case 28: /* expr: EQUAL ABRE ID VIRG ID FECHA  */
#line 717 "grammar.y"
                                      {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_ABSOLUTE_EQUAL;
            (yyval.llistvar) = llist;
        }
#line 1996 "grammar.tab.c"
    break;

  case 29: /* expr: GE ABRE ID VIRG ID FECHA  */
#line 726 "grammar.y"
                                   {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_MAIOR_IGUAL;
            (yyval.llistvar) = llist;
        }
#line 2010 "grammar.tab.c"
    break;

  case 30: /* expr: LT ABRE ID VIRG ID FECHA  */
#line 736 "grammar.y"
                                   {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_MENOR;
            (yyval.llistvar) = llist;
        }
#line 2024 "grammar.tab.c"
    break;

  case 31: /* expr: DIF ABRE ID VIRG ID FECHA  */
#line 745 "grammar.y"
                                    {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_ABSOLUTE_DIF;
            (yyval.llistvar) = llist;
        }
#line 2038 "grammar.tab.c"
    break;

  case 32: /* expr: LE ABRE ID VIRG ID FECHA  */
#line 754 "grammar.y"
                                   {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_MENOR_IGUAL;
            (yyval.llistvar) = llist;
        }
#line 2052 "grammar.tab.c"
    break;


#line 2056 "grammar.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 764 "grammar.y"


int main(int argc, char **argv){
    FILE *hShowCode = fopen(argv[1], "r");
    openFile();
    yyin = hShowCode;
    yyparse();
    return 0;
}
