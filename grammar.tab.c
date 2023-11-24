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
             /* CASE WHILE "WHILE(expr);" */
            case CODE_WHILE_GL: {
                fprintf(cFile, "\twhile");
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
                fprintf(cFile, "\tfor (int i = 0; i < %s; i++) {\n\n", llist->line.v1 );   
                break;
            }

            /* CASE MAIOR IGUAL */
            case CODE_MAIOR_IGUAL: {
                fprintf(cFile, "\(%s >= %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }

            /* CASE MAIOR QUE */
            case CODE_MAIOR: {
                fprintf(cFile, "\t(%s > %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }

            /* CASE MENOR_IGUAL */
            case CODE_MENOR_IGUAL: {
                fprintf(cFile, "\(%s <= %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }

            /* CASE MENOR QUE */
            case CODE_MENOR: {
                fprintf(cFile, "\t(%s < %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }
            /* CASE ABSOLUTE EQUAL */
            case CODE_ABSOLUTE_EQUAL: {
                fprintf(cFile, "\t(%s == %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }
            /* CASE ABSOLUTE DIF */
            case CODE_ABSOLUTE_DIF: {
                fprintf(cFile, "\t(%s != %s){\n\n", llist->line.v1,llist->line.v2);
                break;
            }
            /* CASE ID IGUAL ID NOVO */
            case CODE_ID_NOVO: {
                fprintf(cFile, "\tint %s;\n\t%s = %s;\n", llist->line.v1, llist->line.v1, llist->line.v2);
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


#line 315 "grammar.tab.c"

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
  YYSYMBOL_SUB = 23,                       /* SUB  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_SE = 25,                        /* SE  */
  YYSYMBOL_SENAO = 26,                     /* SENAO  */
  YYSYMBOL_MULT = 27,                      /* MULT  */
  YYSYMBOL_FIMENQUANTO = 28,               /* FIMENQUANTO  */
  YYSYMBOL_VIRG = 29,                      /* VIRG  */
  YYSYMBOL_DIV = 30,                       /* DIV  */
  YYSYMBOL_DIF = 31,                       /* DIF  */
  YYSYMBOL_EQUAL = 32,                     /* EQUAL  */
  YYSYMBOL_NEWLINE = 33,                   /* NEWLINE  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_varlist = 36,                   /* varlist  */
  YYSYMBOL_cmds = 37,                      /* cmds  */
  YYSYMBOL_cmd = 38,                       /* cmd  */
  YYSYMBOL_expr = 39                       /* expr  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  29
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   291,   291,   310,   323,   340,   344,   347,   362,   377,
     396,   408,   419,   430,   442,   454,   481,   497,   513,   528,
     553,   577,   586,   597,   604,   613,   622,   632,   641,   650
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
  "ENTAO", "SOMA", "SUB", "ID", "SE", "SENAO", "MULT", "FIMENQUANTO",
  "VIRG", "DIV", "DIF", "EQUAL", "NEWLINE", "$accept", "program",
  "varlist", "cmds", "cmd", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -18,     7,   -50,    -2,   -50,   -18,   -16,    -5,   -50,
     221,    22,    -1,     0,     9,    10,    11,    15,    20,   260,
      25,    28,   -50,    77,   -50,    33,    34,    35,    38,    46,
      53,    54,    59,   -12,    32,    36,    44,    47,    55,   244,
      49,    57,    61,    63,   -50,   -50,    64,    66,    71,    72,
     221,    73,    74,   221,    68,    79,    82,    84,    85,    86,
      20,   -50,   221,   221,    89,    90,    91,    92,    97,   103,
     100,   105,   107,   126,   -50,   221,   113,   115,   116,   117,
       6,    50,   120,   121,   122,   123,   128,   131,   -50,   134,
     136,   -50,   152,    93,   149,   150,   153,   -50,   221,   -50,
     221,   154,   157,   158,   159,   160,   165,   168,   170,   -50,
     -50,   -50,   -50,   -50,   175,   198,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     8,     0,     0,     0,     0,     0,    17,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      12,    11,    10,    14,     0,     0,    22,    13,    24,    27,
      26,    29,    28,    25,    19,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   182,   -49,   -23,   110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     4,    23,    24,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      45,    70,     6,    10,    73,     1,     3,     5,     9,    33,
      34,    11,    54,    80,    81,    12,    61,    97,    13,    35,
      36,    37,    14,    15,     7,    38,    92,     7,    16,    17,
      18,    19,    98,    20,    39,    42,    21,    25,    43,    22,
      26,    27,    28,    46,    47,    48,    29,    45,    49,   114,
      45,   115,    50,    30,    31,    11,    55,    45,    45,    12,
      56,    99,    13,    51,    52,    53,    14,    15,    57,    45,
      62,    58,    16,    17,    18,    19,   100,    20,    63,    59,
      21,    74,    11,    22,    44,    64,    12,    65,    66,    13,
      67,    45,    45,    14,    15,    68,    69,    71,    72,    16,
      17,    18,    19,     0,    20,    11,   110,    21,    75,    12,
      22,    76,    13,    77,    78,    79,    14,    15,    82,    83,
      84,    85,    16,    17,    18,    19,    86,    20,    88,    41,
      21,    11,    87,    22,    89,    12,    90,    93,    13,    94,
      95,    96,    14,    15,   101,   102,   103,   104,    16,    17,
      18,    19,   105,    20,    91,   106,    21,    11,   107,    22,
     108,    12,   111,   112,    13,   109,   113,   116,    14,    15,
     117,   118,   119,   120,    16,    17,    18,    19,   121,    20,
      11,   122,    21,   123,    12,    22,   124,    13,     8,     0,
       0,    14,    15,     0,     0,     0,     0,    16,    17,    18,
      19,     0,    20,    11,     0,    21,     0,    12,    22,   125,
      13,     0,     0,     0,    14,    15,     0,     0,     0,     0,
      16,    17,    18,    19,     0,    20,    11,     0,    21,     0,
      12,    22,     0,    13,     0,     0,     0,    14,    15,     0,
       0,     0,     0,    16,    17,    18,    19,     0,    20,    11,
       0,    21,     0,    12,    22,     0,    13,     0,     0,     0,
      14,    15,     0,     0,     0,     0,    16,    17,    60,    19,
       0,    20,     0,     0,    21,    25,     0,    22,    26,    27,
      28,     0,     0,     0,    40,     0,     0,     0,     0,     0,
       0,    30,    31
};

static const yytype_int8 yycheck[] =
{
      23,    50,     4,     8,    53,     3,    24,     0,    24,    10,
      10,     5,    24,    62,    63,     9,    39,    11,    12,    10,
      10,    10,    16,    17,    29,    10,    75,    29,    22,    23,
      24,    25,    26,    27,    14,    10,    30,    15,    10,    33,
      18,    19,    20,    10,    10,    10,    24,    70,    10,    98,
      73,   100,     6,    31,    32,     5,    24,    80,    81,     9,
      24,    11,    12,    10,    10,     6,    16,    17,    24,    92,
      21,    24,    22,    23,    24,    25,    26,    27,    21,    24,
      30,    13,     5,    33,     7,    24,     9,    24,    24,    12,
      24,   114,   115,    16,    17,    24,    24,    24,    24,    22,
      23,    24,    25,    -1,    27,     5,    13,    30,    29,     9,
      33,    29,    12,    29,    29,    29,    16,    17,    29,    29,
      29,    29,    22,    23,    24,    25,    29,    27,    28,    19,
      30,     5,    29,    33,    29,     9,    29,    24,    12,    24,
      24,    24,    16,    17,    24,    24,    24,    24,    22,    23,
      24,    25,    24,    27,    28,    24,    30,     5,    24,    33,
      24,     9,    13,    13,    12,    13,    13,    13,    16,    17,
      13,    13,    13,    13,    22,    23,    24,    25,    13,    27,
       5,    13,    30,    13,     9,    33,    11,    12,     6,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    -1,    27,     5,    -1,    30,    -1,     9,    33,    11,
      12,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    -1,    27,     5,    -1,    30,    -1,
       9,    33,    -1,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    -1,    27,     5,
      -1,    30,    -1,     9,    33,    -1,    12,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    15,    -1,    33,    18,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    35,    24,    36,     0,     4,    29,    36,    24,
       8,     5,     9,    12,    16,    17,    22,    23,    24,    25,
      27,    30,    33,    37,    38,    15,    18,    19,    20,    24,
      31,    32,    39,    10,    10,    10,    10,    10,    10,    14,
      24,    39,    10,    10,     7,    38,    10,    10,    10,    10,
       6,    10,    10,     6,    24,    24,    24,    24,    24,    24,
      24,    38,    21,    21,    24,    24,    24,    24,    24,    24,
      37,    24,    24,    37,    13,    29,    29,    29,    29,    29,
      37,    37,    29,    29,    29,    29,    29,    29,    28,    29,
      29,    28,    37,    24,    24,    24,    24,    11,    26,    11,
      26,    24,    24,    24,    24,    24,    24,    24,    24,    13,
      13,    13,    13,    13,    37,    37,    13,    13,    13,    13,
      13,    13,    13,    13,    11,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    39,    39,    39,    39,    39,    39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     3,     1,     2,     1,     5,     5,     3,
       6,     6,     6,     6,     6,     3,     6,     5,     5,     7,
       7,     4,     6,     1,     6,     6,     6,     6,     6,     6
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
#line 291 "grammar.y"
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
#line 1451 "grammar.tab.c"
    break;

  case 3: /* varlist: varlist VIRG ID  */
#line 310 "grammar.y"
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
#line 1468 "grammar.tab.c"
    break;

  case 4: /* varlist: ID  */
#line 323 "grammar.y"
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
#line 1488 "grammar.tab.c"
    break;

  case 5: /* cmds: cmds cmd  */
#line 340 "grammar.y"
                 { 
            addLLISTend((yyvsp[0].llistvar), (yyvsp[-1].llistvar)); (yyval.llistvar) = (yyvsp[-1].llistvar); 
        }
#line 1496 "grammar.tab.c"
    break;

  case 6: /* cmds: cmd  */
#line 344 "grammar.y"
              { (yyval.llistvar) = (yyvsp[0].llistvar);
        }
#line 1503 "grammar.tab.c"
    break;

  case 7: /* cmd: ENQUANTO ID FACA cmds FIMENQUANTO  */
#line 347 "grammar.y"
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
#line 1522 "grammar.tab.c"
    break;

  case 8: /* cmd: ENQUANTO expr FACA cmds FIMENQUANTO  */
#line 362 "grammar.y"
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
#line 1541 "grammar.tab.c"
    break;

  case 9: /* cmd: ID IGUAL cmd  */
#line 377 "grammar.y"
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
#line 1564 "grammar.tab.c"
    break;

  case 10: /* cmd: SOMA ABRE ID VIRG ID FECHA  */
#line 396 "grammar.y"
                                     {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_OPR_ADD;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1580 "grammar.tab.c"
    break;

  case 11: /* cmd: RSHIFT ABRE ID VIRG ID FECHA  */
#line 408 "grammar.y"
                                       {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_RSHIFT;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1596 "grammar.tab.c"
    break;

  case 12: /* cmd: LSHIFT ABRE ID VIRG ID FECHA  */
#line 419 "grammar.y"
                                       {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_LSHIFT;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1612 "grammar.tab.c"
    break;

  case 13: /* cmd: DIV ABRE ID VIRG ID FECHA  */
#line 430 "grammar.y"
                                    {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_OPR_DIV;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1628 "grammar.tab.c"
    break;

  case 14: /* cmd: SUB ABRE ID VIRG ID FECHA  */
#line 442 "grammar.y"
                                    {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READGING COMMAND SOMA");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_OPR_SUB;

            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1644 "grammar.tab.c"
    break;

  case 15: /* cmd: ID IGUAL ID  */
#line 454 "grammar.y"
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
#line 1675 "grammar.tab.c"
    break;

  case 16: /* cmd: EXECUTE ABRE ID VIRG cmds FECHA  */
#line 481 "grammar.y"
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
#line 1695 "grammar.tab.c"
    break;

  case 17: /* cmd: SE ID ENTAO cmds FIMSE  */
#line 497 "grammar.y"
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
#line 1715 "grammar.tab.c"
    break;

  case 18: /* cmd: SE expr ENTAO cmds FIMSE  */
#line 513 "grammar.y"
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
#line 1734 "grammar.tab.c"
    break;

  case 19: /* cmd: SE ID ENTAO cmds SENAO cmds FIMSE  */
#line 528 "grammar.y"
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
#line 1763 "grammar.tab.c"
    break;

  case 20: /* cmd: SE expr ENTAO cmds SENAO cmds FIMSE  */
#line 553 "grammar.y"
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
#line 1791 "grammar.tab.c"
    break;

  case 21: /* cmd: ZERO ABRE ID FECHA  */
#line 577 "grammar.y"
                             {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING ZERO");

            llist->line.v1 = (yyvsp[-1].content);
            llist->line.cmd = CODE_OPR_ZERO;
            (yyval.llistvar) = llist;
        }
#line 1804 "grammar.tab.c"
    break;

  case 22: /* cmd: MULT ABRE ID VIRG ID FECHA  */
#line 586 "grammar.y"
                                     {
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING MULT");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);  
            llist->line.cmd = CODE_OPR_MULT;
            auxiliarGeral = (yyvsp[-3].content);
            (yyval.llistvar) = llist;
        }
#line 1819 "grammar.tab.c"
    break;

  case 23: /* cmd: NEWLINE  */
#line 597 "grammar.y"
                 { 
            LLIST *llist = (LLIST*)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING NEWLINE");

            llist->line.cmd = CODE_SPACE;
        }
#line 1830 "grammar.tab.c"
    break;

  case 24: /* expr: GT ABRE ID VIRG ID FECHA  */
#line 604 "grammar.y"
                                 {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_MAIOR;
            (yyval.llistvar) = llist;
        }
#line 1844 "grammar.tab.c"
    break;

  case 25: /* expr: EQUAL ABRE ID VIRG ID FECHA  */
#line 613 "grammar.y"
                                      {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_ABSOLUTE_EQUAL;
            (yyval.llistvar) = llist;
        }
#line 1858 "grammar.tab.c"
    break;

  case 26: /* expr: GE ABRE ID VIRG ID FECHA  */
#line 622 "grammar.y"
                                   {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_MAIOR_IGUAL;
            (yyval.llistvar) = llist;
        }
#line 1872 "grammar.tab.c"
    break;

  case 27: /* expr: LT ABRE ID VIRG ID FECHA  */
#line 632 "grammar.y"
                                   {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_MENOR;
            (yyval.llistvar) = llist;
        }
#line 1886 "grammar.tab.c"
    break;

  case 28: /* expr: DIF ABRE ID VIRG ID FECHA  */
#line 641 "grammar.y"
                                    {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_ABSOLUTE_DIF;
            (yyval.llistvar) = llist;
        }
#line 1900 "grammar.tab.c"
    break;

  case 29: /* expr: LE ABRE ID VIRG ID FECHA  */
#line 650 "grammar.y"
                                   {
            LLIST *llist = (LLIST *)malloc(sizeof(LLIST));
            if (llist == NULL) printf("ERROR READING COMMAND ENQUANTO");

            llist->line.v1 = (yyvsp[-3].content);
            llist->line.v2 = (yyvsp[-1].content);
            llist->line.cmd = CODE_MENOR_IGUAL;
            (yyval.llistvar) = llist;
        }
#line 1914 "grammar.tab.c"
    break;


#line 1918 "grammar.tab.c"

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

#line 660 "grammar.y"


int main(int argc, char **argv){
    FILE *hShowCode = fopen(argv[1], "r");
    openFile();
    yyin = hShowCode;
    yyparse();
    return 0;
}
