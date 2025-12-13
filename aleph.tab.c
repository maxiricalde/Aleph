/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "aleph.y"

#include <stdio.h>
#include "aleph.h"
#include "tData.h"
#include "sym_table.h"

extern int yylex();
extern void yyrestart();
extern FILE * yyin;
extern int yylex_destroy(void);
tData rta;


#line 85 "aleph.tab.c"

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

#include "aleph.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEF = 3,                        /* DEF  */
  YYSYMBOL_RETURN = 4,                     /* RETURN  */
  YYSYMBOL_PRINT = 5,                      /* PRINT  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_FOREACH = 7,                    /* FOREACH  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_OP_UNION = 10,                  /* OP_UNION  */
  YYSYMBOL_OP_INTER = 11,                  /* OP_INTER  */
  YYSYMBOL_OP_DIFF = 12,                   /* OP_DIFF  */
  YYSYMBOL_OP_GET = 13,                    /* OP_GET  */
  YYSYMBOL_OP_POP = 14,                    /* OP_POP  */
  YYSYMBOL_OP_PUSH = 15,                   /* OP_PUSH  */
  YYSYMBOL_OP_ADD = 16,                    /* OP_ADD  */
  YYSYMBOL_OP_FIRST = 17,                  /* OP_FIRST  */
  YYSYMBOL_OP_LAST = 18,                   /* OP_LAST  */
  YYSYMBOL_OP_SIZE = 19,                   /* OP_SIZE  */
  YYSYMBOL_B_AND = 20,                     /* B_AND  */
  YYSYMBOL_B_NOT = 21,                     /* B_NOT  */
  YYSYMBOL_B_OR = 22,                      /* B_OR  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NEQ = 24,                       /* NEQ  */
  YYSYMBOL_MYEQ = 25,                      /* MYEQ  */
  YYSYMBOL_MNEQ = 26,                      /* MNEQ  */
  YYSYMBOL_MY = 27,                        /* MY  */
  YYSYMBOL_MN = 28,                        /* MN  */
  YYSYMBOL_ASSIGN = 29,                    /* ASSIGN  */
  YYSYMBOL_OP_IN = 30,                     /* OP_IN  */
  YYSYMBOL_BELONG = 31,                    /* BELONG  */
  YYSYMBOL_SUBSET = 32,                    /* SUBSET  */
  YYSYMBOL_OPENLL = 33,                    /* OPENLL  */
  YYSYMBOL_CLOSELL = 34,                   /* CLOSELL  */
  YYSYMBOL_OPENPAR = 35,                   /* OPENPAR  */
  YYSYMBOL_CLOSEPAR = 36,                  /* CLOSEPAR  */
  YYSYMBOL_OPENCOR = 37,                   /* OPENCOR  */
  YYSYMBOL_CLOSECOR = 38,                  /* CLOSECOR  */
  YYSYMBOL_SEMI = 39,                      /* SEMI  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_ELEM = 41,                      /* ELEM  */
  YYSYMBOL_IDEN = 42,                      /* IDEN  */
  YYSYMBOL_NUMBER = 43,                    /* NUMBER  */
  YYSYMBOL_BOOL_T = 44,                    /* BOOL_T  */
  YYSYMBOL_BOOL_F = 45,                    /* BOOL_F  */
  YYSYMBOL_EOFF = 46,                      /* EOFF  */
  YYSYMBOL_47_ = 47,                       /* '+'  */
  YYSYMBOL_48_ = 48,                       /* '-'  */
  YYSYMBOL_49_ = 49,                       /* '*'  */
  YYSYMBOL_50_ = 50,                       /* '/'  */
  YYSYMBOL_UMINUS = 51,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_program = 53,                   /* program  */
  YYSYMBOL_body = 54,                      /* body  */
  YYSYMBOL_eol = 55,                       /* eol  */
  YYSYMBOL_stmt = 56,                      /* stmt  */
  YYSYMBOL_asig_mult = 57,                 /* asig_mult  */
  YYSYMBOL_if = 58,                        /* if  */
  YYSYMBOL_while = 59,                     /* while  */
  YYSYMBOL_for_each = 60,                  /* for_each  */
  YYSYMBOL_lista_stmt = 61,                /* lista_stmt  */
  YYSYMBOL_lista_expr = 62,                /* lista_expr  */
  YYSYMBOL_symlist = 63,                   /* symlist  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_expr_relacionales = 65,         /* expr_relacionales  */
  YYSYMBOL_expr_log = 66,                  /* expr_log  */
  YYSYMBOL_set = 67,                       /* set  */
  YYSYMBOL_list = 68                       /* list  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   682

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
       2,     2,    49,    47,     2,    48,     2,    50,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    54,    68,    69,    70,    73,    74,    75,
      76,    77,    78,    79,    80,    88,    91,    92,    94,    96,
      98,    99,   101,   102,   107,   108,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   137,   138,   139,   140,   141,   142,   143,   144,
     146,   147,   148,   151,   152,   154,   155
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
  "\"end of file\"", "error", "\"invalid token\"", "DEF", "RETURN",
  "PRINT", "WHILE", "FOREACH", "IF", "ELSE", "OP_UNION", "OP_INTER",
  "OP_DIFF", "OP_GET", "OP_POP", "OP_PUSH", "OP_ADD", "OP_FIRST",
  "OP_LAST", "OP_SIZE", "B_AND", "B_NOT", "B_OR", "EQ", "NEQ", "MYEQ",
  "MNEQ", "MY", "MN", "ASSIGN", "OP_IN", "BELONG", "SUBSET", "OPENLL",
  "CLOSELL", "OPENPAR", "CLOSEPAR", "OPENCOR", "CLOSECOR", "SEMI", "COMMA",
  "ELEM", "IDEN", "NUMBER", "BOOL_T", "BOOL_F", "EOFF", "'+'", "'-'",
  "'*'", "'/'", "UMINUS", "$accept", "program", "body", "eol", "stmt",
  "asig_mult", "if", "while", "for_each", "lista_stmt", "lista_expr",
  "symlist", "expr", "expr_relacionales", "expr_log", "set", "list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    43,    45,    42,
      47,   302
};
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-26)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,   -38,   634,   -19,   -18,   -21,    -8,   634,   634,   634,
     634,   634,   634,   568,   634,   601,  -103,   -11,  -103,  -103,
    -103,   634,    28,  -103,    -9,  -103,  -103,  -103,  -103,    11,
     451,  -103,  -103,  -103,  -103,     7,     8,   451,   634,   634,
      14,   634,   123,   -15,   -15,   -15,   -15,   520,  -103,    16,
     164,   205,  -103,    13,   634,     3,  -103,  -103,  -103,    84,
     634,   634,   634,   634,   634,   634,   634,   634,   634,   634,
     634,   634,   634,   634,   634,   634,   634,   634,   634,   634,
       3,   246,   287,   634,   328,   634,  -103,   634,  -103,  -103,
      17,    15,  -103,  -103,  -103,    -1,    -1,    -1,   -15,   -15,
     520,   492,   548,   548,   548,   548,   548,   548,   548,   548,
     -47,   -47,  -103,  -103,    18,  -103,    23,   369,    24,   410,
    -103,  -103,    45,    84,    84,    84,  -103,    84,    43,    50,
      59,    60,    61,    84,  -103,  -103,    87,  -103,  -103,    66,
      84,    70,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    27,    28,    30,
      29,     0,     0,     3,     0,    10,    11,    12,    13,     0,
       7,    45,    46,    39,    38,     0,    27,     8,     0,     0,
       0,     0,     0,    49,    35,    36,    47,    61,    64,     0,
      23,     0,    66,     0,     0,     0,    40,     1,     6,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,    34,    65,
       0,    25,    24,     4,    15,    31,    32,    33,    50,    37,
      60,    62,    52,    53,    56,    57,    54,    55,    58,    59,
      41,    42,    43,    44,     0,     9,     0,     0,     0,     0,
      22,    51,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,    21,    18,    19,    16,    14,    20,     0,
       0,     0,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,    41,  -103,    20,  -103,  -103,  -103,  -103,  -102,
      26,   -54,    -2,  -103,  -103,  -103,  -103
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    22,    23,    59,   128,    25,    26,    27,    28,   129,
      49,    29,    30,    31,    32,    33,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    92,    78,    79,    35,    42,    43,    44,    45,    46,
      47,    50,    51,    50,    64,    65,    38,    39,   -25,    56,
      24,    40,   130,   131,    54,   132,   114,    41,    57,    55,
      58,   138,    76,    77,    78,    79,    81,    82,   141,    84,
      60,    53,    80,    54,    83,    91,    76,    77,    78,    79,
      86,    89,    50,   121,   122,    55,   123,   125,    50,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   127,    24,
      90,   117,   133,   119,   134,    50,    94,     1,     2,     3,
       4,     5,     6,   135,   136,   137,   139,     7,     8,   140,
      93,     9,    10,    11,   142,    12,     0,     0,     0,     0,
       0,     0,     0,   120,     0,     0,     0,    13,     0,    14,
       0,    15,     0,     0,     0,    16,    17,    18,    19,    20,
       0,     0,    21,    61,    62,    63,     0,     0,    64,    65,
       0,     0,     0,    66,     0,    67,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,     0,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    61,    62,    63,     0,     0,    64,
      65,     0,     0,     0,    66,     0,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    61,    62,    63,     0,     0,
      64,    65,     0,     0,     0,    66,     0,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    61,    62,    63,     0,
       0,    64,    65,     0,     0,     0,    66,     0,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    61,    62,    63,
       0,     0,    64,    65,     0,     0,     0,    66,     0,    67,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    61,    62,
      63,     0,     0,    64,    65,     0,     0,     0,    66,     0,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    61,
      62,    63,     0,     0,    64,    65,     0,     0,     0,    66,
       0,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      61,    62,    63,     0,     0,    64,    65,     0,     0,     0,
      66,     0,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    61,    62,    63,     0,     0,    64,    65,     0,     0,
       0,    66,     0,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    61,    62,    63,     0,     0,    64,    65,     0,
       0,     0,    66,     0,     0,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,     0,     0,
      61,    62,    63,     0,     0,    64,    65,     0,     0,    76,
      77,    78,    79,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,     0,     0,    61,    62,
      63,     0,     0,    64,    65,     0,     0,    76,    77,    78,
      79,   -26,   -26,   -26,   -26,   -26,   -26,     0,     0,   -26,
     -26,     7,     8,     0,     0,     9,    10,    11,     0,    12,
       0,     0,     0,     0,     0,    76,    77,    78,    79,     0,
       0,    13,    48,    14,     0,    15,     0,     0,     0,    16,
      36,    18,    19,    20,     7,     8,    21,     0,     9,    10,
      11,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,    14,     0,    15,    52,
       0,     0,    16,    36,    18,    19,    20,     7,     8,    21,
       0,     9,    10,    11,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,    14,
       0,    15,     0,     0,     0,    16,    36,    18,    19,    20,
       0,     0,    21
};

static const yytype_int16 yycheck[] =
{
       2,    55,    49,    50,    42,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    15,    16,    35,    35,    29,    21,
       0,    42,   124,   125,    35,   127,    80,    35,     0,    40,
      39,   133,    47,    48,    49,    50,    38,    39,   140,    41,
      29,    15,    35,    35,    30,    42,    47,    48,    49,    50,
      34,    38,    54,    36,    36,    40,    33,    33,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    33,    59,
      54,    83,    39,    85,    34,    87,    60,     3,     4,     5,
       6,     7,     8,    34,    34,    34,     9,    13,    14,    33,
      59,    17,    18,    19,    34,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    33,    -1,    35,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    48,    10,    11,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    10,    11,    12,    -1,    -1,    15,
      16,    -1,    -1,    -1,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    10,    11,    12,    -1,    -1,
      15,    16,    -1,    -1,    -1,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    10,    11,    12,    -1,
      -1,    15,    16,    -1,    -1,    -1,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    10,    11,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    32,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    10,    11,
      12,    -1,    -1,    15,    16,    -1,    -1,    -1,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    10,
      11,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      10,    11,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,
      20,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    10,    11,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    10,    11,    12,    -1,    -1,    15,    16,    -1,
      -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    -1,    -1,    47,
      48,    49,    50,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    -1,    -1,    47,    48,    49,
      50,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    13,    14,    -1,    -1,    17,    18,    19,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    -1,
      -1,    33,    34,    35,    -1,    37,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    13,    14,    48,    -1,    17,    18,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    37,    38,
      -1,    -1,    41,    42,    43,    44,    45,    13,    14,    48,
      -1,    17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    13,    14,    17,
      18,    19,    21,    33,    35,    37,    41,    42,    43,    44,
      45,    48,    53,    54,    56,    57,    58,    59,    60,    63,
      64,    65,    66,    67,    68,    42,    42,    64,    35,    35,
      42,    35,    64,    64,    64,    64,    64,    64,    34,    62,
      64,    64,    38,    62,    35,    40,    64,     0,    39,    55,
      29,    10,    11,    12,    15,    16,    20,    22,    23,    24,
      25,    26,    27,    28,    31,    32,    47,    48,    49,    50,
      35,    64,    64,    30,    64,    37,    34,    40,    36,    38,
      62,    42,    63,    54,    62,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    63,    36,    36,    64,    36,    64,
      62,    36,    36,    33,    33,    33,    38,    33,    56,    61,
      61,    61,    61,    39,    34,    34,    34,    34,    61,     9,
      33,    61,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    58,    59,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    66,    67,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     3,     2,     1,     1,     2,     4,
       1,     1,     1,     1,     8,     3,     7,    11,     7,     7,
       3,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       2,     3,     3,     3,     3,     1,     1,     2,     5,     2,
       3,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     2,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* program: %empty  */
#line 51 "aleph.y"
          { 
           printf("\n>");
          }
#line 1351 "aleph.tab.c"
    break;

  case 3: /* program: body  */
#line 54 "aleph.y"
         {rta=eval((yyvsp[0].t)); print_symbol_tables();
        freeast((yyvsp[0].t));
           if(rta){
                        printf("\n>>"); 
                      //  printData(rta);     
                }
                //printf("\n>");
                //treefree($2);
                //freeAST($2);
                dataFree(&rta);
        
                }
#line 1368 "aleph.tab.c"
    break;

  case 4: /* body: stmt eol body  */
#line 68 "aleph.y"
                    {(yyval.t)=newast(LIST_STMT,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1374 "aleph.tab.c"
    break;

  case 5: /* body: stmt eol  */
#line 69 "aleph.y"
               {(yyval.t)=newast(LIST_STMT,(yyvsp[-1].t),NULL);}
#line 1380 "aleph.tab.c"
    break;

  case 8: /* stmt: RETURN expr  */
#line 74 "aleph.y"
                             {(yyval.t)=newast(T_RETURN,(yyvsp[0].t),NULL);}
#line 1386 "aleph.tab.c"
    break;

  case 9: /* stmt: PRINT OPENPAR expr CLOSEPAR  */
#line 75 "aleph.y"
                             {(yyval.t)=newast(T_PRINT,(yyvsp[-1].t),NULL);}
#line 1392 "aleph.tab.c"
    break;

  case 14: /* stmt: DEF IDEN OPENPAR symlist CLOSEPAR OPENLL lista_stmt CLOSELL  */
#line 80 "aleph.y"
                                                             {(yyval.t)=dodef(add_symbol_to_current_scope((yyvsp[-6].c)),(yyvsp[-4].t),(yyvsp[-1].t));
                                                                free((yyvsp[-6].c));
                                                                printf("\nDefinida>");}
#line 1400 "aleph.tab.c"
    break;

  case 15: /* asig_mult: symlist ASSIGN lista_expr  */
#line 88 "aleph.y"
                                     {(yyval.t)=newast(T_ASIGN,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1406 "aleph.tab.c"
    break;

  case 16: /* if: IF OPENPAR expr CLOSEPAR OPENLL lista_stmt CLOSELL  */
#line 91 "aleph.y"
                                                       { (yyval.t) = newFlow(T_IF, (yyvsp[-4].t), (yyvsp[-1].t), NULL); }
#line 1412 "aleph.tab.c"
    break;

  case 17: /* if: IF OPENPAR expr CLOSEPAR OPENLL lista_stmt CLOSELL ELSE OPENLL lista_stmt CLOSELL  */
#line 92 "aleph.y"
                                                                                   { (yyval.t) = newFlow(T_IF, (yyvsp[-8].t), (yyvsp[-5].t),(yyvsp[-1].t) ); }
#line 1418 "aleph.tab.c"
    break;

  case 18: /* while: WHILE OPENPAR expr CLOSEPAR OPENLL lista_stmt CLOSELL  */
#line 94 "aleph.y"
                                                              { (yyval.t) = newFlow(T_WH, (yyvsp[-4].t), (yyvsp[-1].t), NULL); }
#line 1424 "aleph.tab.c"
    break;

  case 19: /* for_each: FOREACH IDEN OP_IN expr OPENLL lista_stmt CLOSELL  */
#line 96 "aleph.y"
                                                           {(yyval.t)=newForeach(T_FOREACH,newref((yyvsp[-5].c)),(yyvsp[-3].t),(yyvsp[-1].t));}
#line 1430 "aleph.tab.c"
    break;

  case 20: /* lista_stmt: stmt SEMI lista_stmt  */
#line 98 "aleph.y"
                                       {(yyval.t)=newast(LIST_STMT,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1436 "aleph.tab.c"
    break;

  case 21: /* lista_stmt: stmt SEMI  */
#line 99 "aleph.y"
                                           {(yyval.t)=newast(LIST_STMT,(yyvsp[-1].t),NULL);}
#line 1442 "aleph.tab.c"
    break;

  case 22: /* lista_expr: expr COMMA lista_expr  */
#line 101 "aleph.y"
                                        {(yyval.t)=newast(LIST_EXPR,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1448 "aleph.tab.c"
    break;

  case 23: /* lista_expr: expr  */
#line 102 "aleph.y"
                                        {(yyval.t)=newast(LIST_EXPR,(yyvsp[0].t),NULL);}
#line 1454 "aleph.tab.c"
    break;

  case 24: /* symlist: IDEN COMMA symlist  */
#line 107 "aleph.y"
                                        {(yyval.t)=newNOML(LIST_ID,(yyvsp[-2].c),(struct nomlist*)(yyvsp[0].t));}
#line 1460 "aleph.tab.c"
    break;

  case 25: /* symlist: IDEN  */
#line 108 "aleph.y"
                                        {(yyval.t)=newNOML(LIST_ID,(yyvsp[0].c),NULL);}
#line 1466 "aleph.tab.c"
    break;

  case 26: /* expr: ELEM  */
#line 110 "aleph.y"
                        {(yyval.t)=newElem((yyvsp[0].c));}
#line 1472 "aleph.tab.c"
    break;

  case 27: /* expr: IDEN  */
#line 111 "aleph.y"
                        {(yyval.t)=newref((yyvsp[0].c));}
#line 1478 "aleph.tab.c"
    break;

  case 28: /* expr: NUMBER  */
#line 112 "aleph.y"
                        {(yyval.t)=newInt((yyvsp[0].i));}
#line 1484 "aleph.tab.c"
    break;

  case 29: /* expr: BOOL_F  */
#line 113 "aleph.y"
                        {(yyval.t)=newBool(0);}
#line 1490 "aleph.tab.c"
    break;

  case 30: /* expr: BOOL_T  */
#line 114 "aleph.y"
                        {(yyval.t)=newBool(1);}
#line 1496 "aleph.tab.c"
    break;

  case 31: /* expr: expr OP_UNION expr  */
#line 115 "aleph.y"
                        {(yyval.t)=newast(T_UNION,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1502 "aleph.tab.c"
    break;

  case 32: /* expr: expr OP_INTER expr  */
#line 116 "aleph.y"
                        {(yyval.t)=newast(T_INTER,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1508 "aleph.tab.c"
    break;

  case 33: /* expr: expr OP_DIFF expr  */
#line 117 "aleph.y"
                        {(yyval.t)=newast(T_DIFF,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1514 "aleph.tab.c"
    break;

  case 34: /* expr: OPENPAR expr CLOSEPAR  */
#line 118 "aleph.y"
                           {(yyval.t)=(yyvsp[-1].t);}
#line 1520 "aleph.tab.c"
    break;

  case 35: /* expr: OP_FIRST expr  */
#line 119 "aleph.y"
                    {(yyval.t)=newast(T_FIRST,(yyvsp[0].t),NULL);}
#line 1526 "aleph.tab.c"
    break;

  case 36: /* expr: OP_LAST expr  */
#line 120 "aleph.y"
                   {(yyval.t)=newast(T_LAST,(yyvsp[0].t),NULL);}
#line 1532 "aleph.tab.c"
    break;

  case 37: /* expr: expr OP_ADD expr  */
#line 121 "aleph.y"
                       {(yyval.t)=newast(T_ADD,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1538 "aleph.tab.c"
    break;

  case 40: /* expr: '-' expr  */
#line 124 "aleph.y"
                             { (yyval.t) = newast('u', (yyvsp[0].t), NULL); }
#line 1544 "aleph.tab.c"
    break;

  case 41: /* expr: expr '+' expr  */
#line 125 "aleph.y"
                             { (yyval.t) = newast('+', (yyvsp[-2].t),(yyvsp[0].t)); }
#line 1550 "aleph.tab.c"
    break;

  case 42: /* expr: expr '-' expr  */
#line 126 "aleph.y"
                             { (yyval.t) = newast('-', (yyvsp[-2].t),(yyvsp[0].t));}
#line 1556 "aleph.tab.c"
    break;

  case 43: /* expr: expr '*' expr  */
#line 127 "aleph.y"
                             { (yyval.t) = newast('*', (yyvsp[-2].t),(yyvsp[0].t)); }
#line 1562 "aleph.tab.c"
    break;

  case 44: /* expr: expr '/' expr  */
#line 128 "aleph.y"
                             { (yyval.t) = newast('/', (yyvsp[-2].t),(yyvsp[0].t)); }
#line 1568 "aleph.tab.c"
    break;

  case 45: /* expr: expr_relacionales  */
#line 129 "aleph.y"
                       {(yyval.t)=(yyvsp[0].t);}
#line 1574 "aleph.tab.c"
    break;

  case 46: /* expr: expr_log  */
#line 130 "aleph.y"
              {(yyval.t)=(yyvsp[0].t);}
#line 1580 "aleph.tab.c"
    break;

  case 47: /* expr: OP_SIZE expr  */
#line 131 "aleph.y"
                  {(yyval.t)=newast(T_SIZE,(yyvsp[0].t),NULL);}
#line 1586 "aleph.tab.c"
    break;

  case 48: /* expr: OP_GET expr OPENCOR expr CLOSECOR  */
#line 132 "aleph.y"
                                        {(yyval.t)=newast(T_GET,(yyvsp[-3].t),(yyvsp[-1].t));}
#line 1592 "aleph.tab.c"
    break;

  case 49: /* expr: OP_POP expr  */
#line 133 "aleph.y"
                  {(yyval.t)=newast(T_POP,(yyvsp[0].t),NULL);}
#line 1598 "aleph.tab.c"
    break;

  case 50: /* expr: expr OP_PUSH expr  */
#line 134 "aleph.y"
                       {(yyval.t)=newast(T_PUSH,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1604 "aleph.tab.c"
    break;

  case 51: /* expr: IDEN OPENPAR lista_expr CLOSEPAR  */
#line 135 "aleph.y"
                                      {(yyval.t)=newcall((yyvsp[-3].c),(yyvsp[-1].t));}
#line 1610 "aleph.tab.c"
    break;

  case 52: /* expr_relacionales: expr EQ expr  */
#line 137 "aleph.y"
                                     {(yyval.t) = newast(T_EQ, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1616 "aleph.tab.c"
    break;

  case 53: /* expr_relacionales: expr NEQ expr  */
#line 138 "aleph.y"
                                     {(yyval.t) = newast(T_NEQ, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1622 "aleph.tab.c"
    break;

  case 54: /* expr_relacionales: expr MY expr  */
#line 139 "aleph.y"
                                     {(yyval.t) = newast(T_MY, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1628 "aleph.tab.c"
    break;

  case 55: /* expr_relacionales: expr MN expr  */
#line 140 "aleph.y"
                                     {(yyval.t) = newast(T_MN, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1634 "aleph.tab.c"
    break;

  case 56: /* expr_relacionales: expr MYEQ expr  */
#line 141 "aleph.y"
                                     {(yyval.t) = newast(T_MYEQ, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1640 "aleph.tab.c"
    break;

  case 57: /* expr_relacionales: expr MNEQ expr  */
#line 142 "aleph.y"
                                     {(yyval.t) = newast(T_MNEQ, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1646 "aleph.tab.c"
    break;

  case 58: /* expr_relacionales: expr BELONG expr  */
#line 143 "aleph.y"
                                     {(yyval.t) = newast(T_BE, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1652 "aleph.tab.c"
    break;

  case 59: /* expr_relacionales: expr SUBSET expr  */
#line 144 "aleph.y"
                                     {(yyval.t) = newast(T_SUBSET, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1658 "aleph.tab.c"
    break;

  case 60: /* expr_log: expr B_AND expr  */
#line 146 "aleph.y"
                          {(yyval.t) = newast(T_AND, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1664 "aleph.tab.c"
    break;

  case 61: /* expr_log: B_NOT expr  */
#line 147 "aleph.y"
                    {(yyval.t) = newast(T_NOT,(yyvsp[0].t),NULL);}
#line 1670 "aleph.tab.c"
    break;

  case 62: /* expr_log: expr B_OR expr  */
#line 148 "aleph.y"
                        {(yyval.t) = newast(T_OR, (yyvsp[-2].t), (yyvsp[0].t));}
#line 1676 "aleph.tab.c"
    break;

  case 63: /* set: OPENLL lista_expr CLOSELL  */
#line 151 "aleph.y"
                               {(yyval.t)=newast(T_SET,(yyvsp[-1].t),NULL);}
#line 1682 "aleph.tab.c"
    break;

  case 64: /* set: OPENLL CLOSELL  */
#line 152 "aleph.y"
                 {(yyval.t)=newast(T_SET,NULL,NULL);}
#line 1688 "aleph.tab.c"
    break;

  case 65: /* list: OPENCOR lista_expr CLOSECOR  */
#line 154 "aleph.y"
                                  {(yyval.t)=newast(T_LIST,(yyvsp[-1].t),NULL);}
#line 1694 "aleph.tab.c"
    break;

  case 66: /* list: OPENCOR CLOSECOR  */
#line 155 "aleph.y"
                    {(yyval.t)=newast(T_LIST,NULL,NULL);}
#line 1700 "aleph.tab.c"
    break;


#line 1704 "aleph.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 172 "aleph.y"


int main(int argc, char** argv) {
if(argc<2){ // leemos de stdin
        printf("aleph");
        
        yyparse();
        exit_scope();
        yylex_destroy();
        return 0; //corto aca
}
for(int i=1; i<argc;i++){
        FILE* f= fopen(argv[i],"r");
        if(!f){
                perror(argv[i]); //indica wue hubo un error al abrir el archivo
                return(1);
        }
        yyrestart(f);
        printf("aleph");
        printf(">");
        enter_scope();
        while(!feof(yyin)){
           yyparse();
        }
        exit_scope();
        fclose(f);    
}
yylex_destroy();
return 0;
}
extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "Error: %s en la linea %d\n ", s,yylineno);
}

int yylex(void);



