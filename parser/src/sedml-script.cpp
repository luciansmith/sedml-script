/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         SED_YYSTYPE
/* Substitute the variable and function names.  */
#define yyparse         sed_yyparse
#define yylex           sed_yylex
#define yyerror         sed_yyerror
#define yydebug         sed_yydebug
#define yynerrs         sed_yynerrs

#define yylval          sed_yylval
#define yychar          sed_yychar

/* Copy the first part of user declarations.  */
#line 26 "sedml-script.ypp" /* yacc.c:339  */

  //#define YYSTYPE double
#include <cassert>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#include "registry.h"
//#include "module.h"
//#include "unitdef.h"
#include "stringx.h"
#include <sbml/math/ASTNode.h>
//#include "modelChange.h"

  using namespace std;
  using namespace sedmlscript;
  int sed_yylex(void);
  void sed_yyerror(char const *);
  Registry g_registry;
  int sed_yylloc_last_line = 1;

#line 102 "sedml-script.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef SED_YYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define SED_YYDEBUG 1
#  else
#   define SED_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define SED_YYDEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined SED_YYDEBUG */
#if SED_YYDEBUG
extern int sed_yydebug;
#endif

/* Token type.  */
#ifndef SED_YYTOKENTYPE
# define SED_YYTOKENTYPE
  enum sed_yytokentype
  {
    YYEOF = 0,
    ANDWORD = 258,
    ORWORD = 259,
    NOT = 260,
    NEG = 261,
    UPLUS = 262,
    NUM = 263,
    SEDWORD = 264,
    TEXTSTRING = 265,
    ERROR = 266,
    INDENT = 267,
    DEINDENT = 268,
    NOTWORD = 269,
    FORWORD = 270,
    INWORD = 271,
    IFWORD = 272
  };
#endif

/* Value type.  */
#if ! defined SED_YYSTYPE && ! defined SED_YYSTYPE_IS_DECLARED

union SED_YYSTYPE
{
#line 54 "sedml-script.ypp" /* yacc.c:355  */

  const string* word;
  vector<const string*>* words;
  ASTNode* astnode;
  double number;
  map<const string*, ASTNode*>* dict;

#line 174 "sedml-script.cpp" /* yacc.c:355  */
};

typedef union SED_YYSTYPE SED_YYSTYPE;
# define SED_YYSTYPE_IS_TRIVIAL 1
# define SED_YYSTYPE_IS_DECLARED 1
#endif


extern SED_YYSTYPE sed_yylval;

int sed_yyparse (void);



/* Copy the second part of user declarations.  */

#line 191 "sedml-script.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined SED_YYSTYPE_IS_TRIVIAL && SED_YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   476

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     8,     2,     2,     2,    13,     2,     2,
      33,    34,    11,    10,    38,     9,    31,    12,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    30,
       5,     7,     6,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    18,     2,    32,    17,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      14,    15,    16,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28
};

#if SED_YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    94,    95,    96,    97,    98,    99,   102,
     103,   106,   107,   109,   110,   113,   114,   117,   118,   121,
     121,   122,   122,   125,   129,   143,   144,   145,   146,   157,
     168,   169,   176,   177,   182,   183,   187,   188,   189,   190,
     191,   195,   196,   197,   198,   209,   219,   220,   268,   276,
     282,   294,   297,   298,   299,   300,   301,   304,   305,   306,
     316,   327
};
#endif

#if SED_YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"the keyword 'and'\"",
  "\"the keyword 'or'\"", "'<'", "'>'", "'='", "'!'", "'-'", "'+'", "'*'",
  "'/'", "'%'", "NOT", "NEG", "UPLUS", "'^'", "'['", "\"number\"",
  "\"element name\"", "\"text string in quotes\"", "\"an error\"",
  "\"an indentation increase\"", "\"an indentation decrease\"",
  "\"the keyword 'not'\"", "\"the keyword 'for'\"", "\"the keyword 'in'\"",
  "\"the keyword 'if'\"", "'\\n'", "';'", "'.'", "']'", "'('", "')'",
  "':'", "'{'", "'}'", "','", "$accept", "input", "lineend",
  "varOrKeyword", "subscriptable", "equals", "execute", "block", "$@1",
  "$@2", "node", "vector", "nodelist", "nodecolonlist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,    60,    62,    61,    33,    45,
      43,    42,    47,    37,   260,   261,   262,    94,    91,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,    10,
      59,    46,    93,    40,    41,    58,   123,   125,    44
};
# endif

#define YYPACT_NINF -99

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -99,     5,   -99,   -99,   -99,   -99,   394,   394,   -99,   -99,
     -99,    37,   -26,   -26,   -99,   394,   394,   280,   -99,   -99,
     394,   394,   260,   -22,   -13,   428,   -99,   -19,    81,   394,
     394,    25,   299,   -99,   -99,    11,    11,   -99,   -16,    11,
     139,    22,   -99,     1,    42,   318,   394,   394,   176,   156,
      13,    52,   394,   394,   337,   356,   394,   394,   375,   394,
     394,   -26,   428,   210,   -99,   -99,    -2,   -99,   -99,   394,
     -99,   -99,    47,   -99,    35,   458,   458,   394,   394,   411,
     394,   394,   411,   394,   394,    84,    84,   394,    11,   394,
      11,    11,    11,   -99,   226,   123,   444,    53,    75,   -99,
     428,    65,   -99,   411,   411,   411,   411,   411,   411,    11,
      11,   -99,   -26,   241,   -99,   394,   394,    80,   428,   -99,
     428,   428,   -99,    36,   -99,   -99,   178,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,    13,     8,     0,     0,     9,    10,
       6,     0,     0,     0,     5,     0,     0,     0,    23,    11,
       0,     0,     0,    24,    12,    57,    51,     0,     0,     0,
       0,     0,     0,     3,     4,    35,    34,    52,     0,    46,
       0,    13,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,    14,    18,     0,    53,    25,     0,
      55,    56,     0,    48,     0,    44,    45,     0,     0,    37,
       0,     0,    36,     0,     0,    32,    29,     0,    28,     0,
      30,    33,    26,    50,     0,     0,    58,     0,     0,    17,
      60,     0,    47,    42,    39,    43,    38,    40,    41,    27,
      31,    49,     0,     0,    19,     0,     0,     0,    59,     2,
      16,    61,    21,     0,     2,    20,     0,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -98,     0,   -99,    -1,   -99,   -99,   -99,   -99,   -99,
      -6,   -99,   -15,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    10,    23,    24,    12,    13,    14,   119,   124,
      25,    26,    27,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    28,    38,     8,     9,     2,     3,    43,    59,    35,
      36,    45,    33,    34,    39,    40,    67,    66,    31,    60,
      83,   123,    60,    62,    63,     4,   126,     5,    57,    58,
      74,     6,    99,     7,     8,     9,    60,     3,    70,    60,
      75,    76,    79,    82,    29,    64,    85,    86,    88,    90,
      91,    92,    94,    95,    96,    30,     4,    69,     5,    84,
     125,    97,     6,   100,     7,     8,     9,   101,    31,   102,
      32,   103,   104,    60,   105,   106,   114,   107,   108,    71,
      72,   109,   115,   110,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    54,    55,    56,    57,    58,
     116,    57,    58,   122,     0,     0,     0,   118,     0,   120,
     121,     0,   117,     0,     0,     0,    61,     0,     0,     0,
       0,     0,    11,     0,     0,    11,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
      57,    58,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,    57,    58,   112,     0,
       0,    80,     0,    81,     0,    15,    16,     0,     0,     0,
       0,     0,     0,    68,    17,    18,     4,    19,     0,     3,
       0,    20,    77,    78,     0,    15,    16,     0,     0,    21,
       0,     0,    22,     0,    17,    18,     4,    19,     4,     0,
       5,    20,   127,     0,     6,     0,     7,     8,     9,    21,
       0,     0,    22,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,     0,     0,    57,    58,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,    98,    57,    58,     0,     0,     0,    83,     0,
      15,    16,     0,     0,     0,     0,     0,     0,   111,    17,
      18,     4,    19,     0,     0,     0,    20,     0,     0,    15,
      16,     0,     0,     0,    21,     0,     0,    22,    17,    18,
      41,    19,     0,     0,     0,    20,     0,     0,     0,    15,
      16,     0,     0,    21,     0,     0,    22,    42,    17,    18,
       4,    19,     0,     0,     0,    20,     0,     0,    15,    16,
       0,     0,    37,    21,     0,     0,    22,    17,    18,     4,
      19,     0,     0,     0,    20,     0,     0,    15,    16,     0,
       0,     0,    21,    65,     0,    22,    17,    18,     4,    19,
       0,     0,     0,    20,     0,     0,    15,    16,    87,     0,
       0,    21,    73,     0,    22,    17,    18,     4,    19,     0,
       0,     0,    20,     0,     0,    15,    16,     0,    89,     0,
      21,     0,     0,    22,    17,    18,     4,    19,     0,     0,
       0,    20,     0,     0,    15,    16,     0,     0,     0,    21,
       0,     0,    22,    17,    18,     4,    19,     0,     0,     0,
      20,     0,     0,    15,    16,     0,     0,    93,    21,     0,
       0,    22,    17,    18,     4,    19,     0,     0,     0,    20,
      52,    53,    54,    55,    56,     0,     0,    21,    57,    58,
      22,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,    57,    58,    46,    47,    48,
      49,   113,    51,    52,    53,    54,    55,    56,     0,     0,
       0,    57,    58,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,    57,    58
};

static const yytype_int8 yycheck[] =
{
       1,     7,    17,    29,    30,     0,     1,    22,    27,    15,
      16,    33,    12,    13,    20,    21,    32,    32,    31,    38,
       7,   119,    38,    29,    30,    20,   124,    22,    17,    18,
      45,    26,    34,    28,    29,    30,    38,     1,    37,    38,
      46,    47,    48,    49,     7,    20,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    18,    20,    35,    22,     7,
      24,    61,    26,    69,    28,    29,    30,    20,    31,    34,
      33,    77,    78,    38,    80,    81,    23,    83,    84,    37,
      38,    87,     7,    89,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    11,    12,    13,    17,    18,
      35,    17,    18,    23,    -1,    -1,    -1,   113,    -1,   115,
     116,    -1,   112,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,   123,    -1,    -1,   126,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    18,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    35,    -1,
      -1,     5,    -1,     7,    -1,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    18,    19,    20,    21,    -1,     1,
      -1,    25,     6,     7,    -1,     9,    10,    -1,    -1,    33,
      -1,    -1,    36,    -1,    18,    19,    20,    21,    20,    -1,
      22,    25,    24,    -1,    26,    -1,    28,    29,    30,    33,
      -1,    -1,    36,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    18,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    32,    17,    18,    -1,    -1,    -1,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    32,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,     9,
      10,    -1,    -1,    -1,    33,    -1,    -1,    36,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,     9,
      10,    -1,    -1,    33,    -1,    -1,    36,    37,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    -1,    -1,     9,    10,
      -1,    -1,    32,    33,    -1,    -1,    36,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    -1,    -1,     9,    10,    -1,
      -1,    -1,    33,    34,    -1,    36,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    -1,    -1,     9,    10,    11,    -1,
      -1,    33,    34,    -1,    36,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,     9,    10,    -1,    12,    -1,
      33,    -1,    -1,    36,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,     9,    10,    -1,    -1,    -1,    33,
      -1,    -1,    36,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,     9,    10,    -1,    -1,    32,    33,    -1,
      -1,    36,    18,    19,    20,    21,    -1,    -1,    -1,    25,
       9,    10,    11,    12,    13,    -1,    -1,    33,    17,    18,
      36,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    17,    18,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    17,    18,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,     0,     1,    20,    22,    26,    28,    29,    30,
      41,    43,    44,    45,    46,     9,    10,    18,    19,    21,
      25,    33,    36,    42,    43,    49,    50,    51,    49,     7,
      18,    31,    33,    41,    41,    49,    49,    32,    51,    49,
      49,    20,    37,    51,    52,    33,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    17,    18,    27,
      38,    35,    49,    49,    20,    34,    51,    32,    34,    35,
      37,    37,    38,    34,    51,    49,    49,     6,     7,    49,
       5,     7,    49,     7,     7,    49,    49,    11,    49,    12,
      49,    49,    49,    32,    49,    49,    49,    41,    32,    34,
      49,    20,    34,    49,    49,    49,    49,    49,    49,    49,
      49,    32,    35,     7,    23,     7,    35,    41,    49,    47,
      49,    49,    23,    40,    48,    24,    40,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    40,    40,    40,    40,    41,
      41,    42,    42,    43,    43,    44,    44,    45,    45,    47,
      46,    48,    46,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    51,
      52,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     3,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     3,     3,     6,     4,     3,     0,
       8,     0,    10,     1,     1,     3,     3,     4,     3,     3,
       3,     4,     3,     3,     2,     2,     3,     3,     4,     4,
       4,     4,     4,     4,     3,     3,     2,     4,     3,     4,
       3,     1,     2,     3,     2,     3,     3,     1,     3,     5,
       3,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if SED_YYDEBUG

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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
#else /* !SED_YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !SED_YYDEBUG */


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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 94 "sedml-script.ypp" /* yacc.c:1646  */
    {}
#line 1419 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "sedml-script.ypp" /* yacc.c:1646  */
    {}
#line 1425 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 96 "sedml-script.ypp" /* yacc.c:1646  */
    {}
#line 1431 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "sedml-script.ypp" /* yacc.c:1646  */
    {}
#line 1437 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 98 "sedml-script.ypp" /* yacc.c:1646  */
    {YYABORT;}
#line 1443 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 99 "sedml-script.ypp" /* yacc.c:1646  */
    {YYABORT;}
#line 1449 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 102 "sedml-script.ypp" /* yacc.c:1646  */
    {}
#line 1455 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 103 "sedml-script.ypp" /* yacc.c:1646  */
    {}
#line 1461 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 106 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.words) = new vector<const string*>; (yyval.words)->push_back((yyvsp[0].word));}
#line 1467 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 107 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.words) = (yyvsp[0].words);}
#line 1473 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 109 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.words) = new vector<const string*>; (yyval.words)->push_back((yyvsp[0].word));}
#line 1479 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 110 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.words) = (yyvsp[-2].words); (yyval.words)->push_back((yyvsp[0].word));}
#line 1485 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 113 "sedml-script.ypp" /* yacc.c:1646  */
    {if (g_registry.addEquals((yyvsp[-2].words), (yyvsp[0].astnode))) YYABORT;}
#line 1491 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 114 "sedml-script.ypp" /* yacc.c:1646  */
    {if (g_registry.addSelectedEquals((yyvsp[-5].words), (yyvsp[-3].astnode), (yyvsp[0].astnode))) YYABORT;}
#line 1497 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "sedml-script.ypp" /* yacc.c:1646  */
    {if (g_registry.addExecute((yyvsp[-3].words), (yyvsp[-1].astnode))) YYABORT;}
#line 1503 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 118 "sedml-script.ypp" /* yacc.c:1646  */
    {if (g_registry.addExecute((yyvsp[-2].words), NULL)) YYABORT;}
#line 1509 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 121 "sedml-script.ypp" /* yacc.c:1646  */
    {if (g_registry.startBlock((yyvsp[-4].word), (yyvsp[-3].astnode))) YYABORT;}
#line 1515 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 121 "sedml-script.ypp" /* yacc.c:1646  */
    {if (g_registry.endBlock()) YYABORT;}
#line 1521 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 122 "sedml-script.ypp" /* yacc.c:1646  */
    {if (g_registry.startForInBlock((yyvsp[-5].astnode), (yyvsp[-3].astnode))) YYABORT;}
#line 1527 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 122 "sedml-script.ypp" /* yacc.c:1646  */
    {if (g_registry.endBlock()) YYABORT;}
#line 1533 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 125 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  (yyval.astnode) = new ASTNode(); 
                  (yyval.astnode)->setValue((yyvsp[0].number)); 
                }
#line 1542 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 129 "sedml-script.ypp" /* yacc.c:1646  */
    {
                   (yyval.astnode) = new ASTNode();
                   string name = getStringFrom((yyvsp[0].words));
                   (yyval.astnode)->setName(name.c_str());
                   //The symbol is not used in any other mathematical context in the SBML model, so we can see if it matches a list of pre-defined names
                   ASTNodeType_t type = g_registry.getSymbolFor(name);
                   if (type != AST_UNKNOWN) (yyval.astnode)->setType(type);
                   if (type==AST_REAL) {
                     if (g_registry.l3StrCmp(name, "inf"))          (yyval.astnode)->setValue(numeric_limits<double>::infinity());
                     if (g_registry.l3StrCmp(name, "infinity"))     (yyval.astnode)->setValue(numeric_limits<double>::infinity());
                     if (g_registry.l3StrCmp(name, "nan"))          (yyval.astnode)->setValue(numeric_limits<double>::quiet_NaN());
                     if (g_registry.l3StrCmp(name, "notanumber"))   (yyval.astnode)->setValue(numeric_limits<double>::quiet_NaN());
                   }
                }
#line 1561 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 143 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode);}
#line 1567 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 144 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = new ASTNode(AST_LOGICAL_XOR); (yyval.astnode)->addChild((yyvsp[-2].astnode)); (yyval.astnode)->addChild((yyvsp[0].astnode));}
#line 1573 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 145 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = new ASTNode(AST_POWER); (yyval.astnode)->addChild((yyvsp[-3].astnode)); (yyval.astnode)->addChild((yyvsp[0].astnode));}
#line 1579 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 146 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  if ((yyvsp[-2].astnode)->getType()==AST_TIMES) {
                    (yyval.astnode) = (yyvsp[-2].astnode);
                    (yyval.astnode)->addChild((yyvsp[0].astnode));
                  }
                  else {
                    (yyval.astnode) = new ASTNode(AST_TIMES);
                    (yyval.astnode)->addChild((yyvsp[-2].astnode));
                    (yyval.astnode)->addChild((yyvsp[0].astnode));
                  }
                }
#line 1595 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 157 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  if ((yyvsp[-2].astnode)->getType()==AST_PLUS) {
                    (yyval.astnode) = (yyvsp[-2].astnode);
                    (yyval.astnode)->addChild((yyvsp[0].astnode));
                  }
                  else {
                    (yyval.astnode) = new ASTNode(AST_PLUS);
                    (yyval.astnode)->addChild((yyvsp[-2].astnode));
                    (yyval.astnode)->addChild((yyvsp[0].astnode));
                  }
                }
#line 1611 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 168 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = new ASTNode(AST_DIVIDE); (yyval.astnode)->addChild((yyvsp[-2].astnode)); (yyval.astnode)->addChild((yyvsp[0].astnode));}
#line 1617 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 169 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  (yyval.astnode) = new ASTNode(AST_FUNCTION_FLOOR);
                  ASTNode* astn = new ASTNode(AST_DIVIDE);
                  astn->addChild((yyvsp[-3].astnode));
                  (yyval.astnode)->addChild((yyvsp[0].astnode));
                  (yyval.astnode)->addChild(astn);
                }
#line 1629 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 176 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = new ASTNode(AST_MINUS); (yyval.astnode)->addChild((yyvsp[-2].astnode)); (yyval.astnode)->addChild((yyvsp[0].astnode));}
#line 1635 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 177 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  (yyval.astnode) = new ASTNode(AST_FUNCTION_REM);
                  (yyval.astnode)->addChild((yyvsp[-2].astnode));
                  (yyval.astnode)->addChild((yyvsp[0].astnode));
                }
#line 1645 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 182 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1651 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 183 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  (yyval.astnode) = new ASTNode(AST_MINUS);
                  (yyval.astnode)->addChild((yyvsp[0].astnode));
                }
#line 1660 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 187 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = g_registry.combineRelationalElements((yyvsp[-2].astnode), (yyvsp[0].astnode), AST_RELATIONAL_GT);}
#line 1666 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 188 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = g_registry.combineRelationalElements((yyvsp[-2].astnode), (yyvsp[0].astnode), AST_RELATIONAL_LT);}
#line 1672 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 189 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = g_registry.combineRelationalElements((yyvsp[-3].astnode), (yyvsp[0].astnode), AST_RELATIONAL_GEQ);}
#line 1678 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 190 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = g_registry.combineRelationalElements((yyvsp[-3].astnode), (yyvsp[0].astnode), AST_RELATIONAL_LEQ);}
#line 1684 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 191 "sedml-script.ypp" /* yacc.c:1646  */
    {
                   (yyval.astnode) = g_registry.combineRelationalElements((yyvsp[-3].astnode), (yyvsp[0].astnode), AST_RELATIONAL_EQ);
                   (yyval.astnode)->setClass("boolean"); //To distinguish it from '='
                }
#line 1693 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 195 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = g_registry.combineRelationalElements((yyvsp[-3].astnode), (yyvsp[0].astnode), AST_RELATIONAL_NEQ);}
#line 1699 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 196 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = g_registry.combineRelationalElements((yyvsp[-3].astnode), (yyvsp[0].astnode), AST_RELATIONAL_NEQ);}
#line 1705 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 197 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = g_registry.combineRelationalElements((yyvsp[-3].astnode), (yyvsp[0].astnode), AST_RELATIONAL_NEQ);}
#line 1711 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 198 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  if ((yyvsp[-2].astnode)->getType()==AST_LOGICAL_AND) {
                    (yyval.astnode) = (yyvsp[-2].astnode);
                    (yyval.astnode)->addChild((yyvsp[0].astnode));
                  }
                  else {
                    (yyval.astnode) = new ASTNode(AST_LOGICAL_AND);
                    (yyval.astnode)->addChild((yyvsp[-2].astnode));
                    (yyval.astnode)->addChild((yyvsp[0].astnode));
                  }
                }
#line 1727 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 209 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  if ((yyvsp[-2].astnode)->getType()==AST_LOGICAL_OR) {
                    (yyval.astnode) = (yyvsp[-2].astnode);
                    (yyval.astnode)->addChild((yyvsp[0].astnode));                  }
                  else {
                    (yyval.astnode) = new ASTNode(AST_LOGICAL_OR);
                    (yyval.astnode)->addChild((yyvsp[-2].astnode));
                    (yyval.astnode)->addChild((yyvsp[0].astnode));
                  }
                }
#line 1742 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 219 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = new ASTNode(AST_LOGICAL_NOT); (yyval.astnode)->addChild((yyvsp[0].astnode));}
#line 1748 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 220 "sedml-script.ypp" /* yacc.c:1646  */
    {
                   (yyval.astnode) = (yyvsp[-1].astnode);
                   string name = getStringFrom((yyvsp[-3].words));
                   (yyval.astnode)->setName(name.c_str());
                   (yyval.astnode)->setType(AST_FUNCTION);
                   if (g_registry.isDef((yyvsp[-3].words)) == false) {
                     //The symbol is not a function definition, so we can see if it matches a list of pre-defined names
                     ASTNodeType_t type = g_registry.getFunctionFor(name);
                     if (type != AST_UNKNOWN) (yyval.astnode)->setType(type);
                     if (type==AST_FUNCTION_ROOT && g_registry.l3StrCmp(name, "sqrt")) {
                       //If the number of arguments is wrong, set an error now instead of waiting for later.
                       if ((yyval.astnode)->getNumChildren() != 1) {
                         sed_yyerror("The function 'sqrt' takes exactly one argument.");
                         delete (yyval.astnode);
                         YYABORT;
                       }
                       //Add a '2' node before the existing child.
                       ASTNode* int2 = new ASTNode(AST_INTEGER);
                       int2->setValue(2);
                       (yyval.astnode)->prependChild(int2);
                     }
                     if (type==AST_FUNCTION_POWER && g_registry.l3StrCmp(name, "sqr")) {
                       //Add a '2' node after the existing child.
                       ASTNode* int2 = new ASTNode(AST_INTEGER);
                       int2->setValue(2);
                       (yyval.astnode)->addChild(int2);
                     }
                     if (type==AST_FUNCTION_LOG && g_registry.l3StrCmp(name, "log10")) {
                       //Add a '10' node before the existing child.
                       ASTNode* int10 = new ASTNode(AST_INTEGER);
                       int10->setValue(10);
                       (yyval.astnode)->prependChild(int10);
                     }
                     else if (type==AST_FUNCTION_LOG && g_registry.l3StrCmp(name, "log")) {
                       //If there is exactly one argument, change it to ln (since math.log(x) is ln in python).
                       if ((yyval.astnode)->getNumChildren() == 1) {
                         (yyval.astnode)->setType(AST_FUNCTION_LN);
                       }
                     }
                     else if (type==AST_FUNCTION_LOG && (yyval.astnode)->getNumChildren()==2) {
                       //Swap the arguments for MathML: SBML's infix has "log(10, 3)", but Python has "log(3, 10)".
                       ASTNode* moveme = (yyval.astnode)->getChild(0);
                       (yyval.astnode)->removeChild(0);
                       (yyval.astnode)->addChild(moveme);
                     }
                   }
                   if (g_registry.checkNumArguments((yyval.astnode))) YYABORT;
        }
#line 1801 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 268 "sedml-script.ypp" /* yacc.c:1646  */
    {
                   (yyval.astnode) = new ASTNode(AST_FUNCTION);
                   string name = getStringFrom((yyvsp[-2].words));
                   (yyval.astnode)->setName(name.c_str());
                   ASTNodeType_t type = g_registry.getFunctionFor(name);
                   if (type != AST_UNKNOWN) (yyval.astnode)->setType(type);
                   if (g_registry.checkNumArguments((yyval.astnode))) YYABORT;
        }
#line 1814 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 276 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  (yyval.astnode) = new ASTNode();
                  (yyval.astnode)->setType(AST_LINEAR_ALGEBRA_SELECTOR);
                  (yyval.astnode)->addChild((yyvsp[-3].astnode));
                  (yyval.astnode)->addChild((yyvsp[-1].astnode));
                }
#line 1825 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 282 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  sed_yyerror("Illegal to define empty square brackets as a selector.");
                  YYABORT;
                }
#line 1834 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 294 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1840 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 297 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = new ASTNode(AST_LINEAR_ALGEBRA_VECTOR);}
#line 1846 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 298 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode); (yyval.astnode)->setType(AST_LINEAR_ALGEBRA_VECTOR);}
#line 1852 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 299 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = new ASTNode(AST_SET_THEORY_SET);}
#line 1858 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 300 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode); (yyval.astnode)->setType(AST_SET_THEORY_SET);}
#line 1864 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 301 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-1].astnode); }
#line 1870 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 304 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = new ASTNode(AST_FUNCTION); (yyval.astnode)->addChild((yyvsp[0].astnode)); }
#line 1876 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 305 "sedml-script.ypp" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[-2].astnode);  (yyval.astnode)->addChild((yyvsp[0].astnode));}
#line 1882 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 306 "sedml-script.ypp" /* yacc.c:1646  */
    {
                  (yyval.astnode) = (yyvsp[-4].astnode);
                  ASTNode* astn = new ASTNode(AST_RELATIONAL_EQ);
                  astn->setClass("assignment"); //To distinguish it from '=='
                  astn->addChild((yyvsp[-2].astnode));
                  astn->addChild((yyvsp[0].astnode));
                  (yyval.astnode)->addChild(astn);
                }
#line 1895 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 316 "sedml-script.ypp" /* yacc.c:1646  */
    { 
                  (yyval.astnode) = new ASTNode(AST_SET_THEORY_SET);
                  (yyval.astnode)->setClass("dictionary");
                  ASTNode* eq = new ASTNode(AST_RELATIONAL_EQ);
                  eq->setClass("key/value pair");
                  ASTNode* key= new ASTNode(AST_NAME);
                  key->setName((*(yyvsp[-2].word)).c_str());
                  eq->addChild(key);
                  eq->addChild((yyvsp[0].astnode));
                  (yyval.astnode)->addChild(eq);
                }
#line 1911 "sedml-script.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 327 "sedml-script.ypp" /* yacc.c:1646  */
    { 
                  (yyval.astnode) = (yyvsp[-4].astnode);
                  ASTNode* eq = new ASTNode(AST_RELATIONAL_EQ);
                  eq->setClass("key/value pair");
                  ASTNode* key= new ASTNode(AST_NAME);
                  key->setName((*(yyvsp[-2].word)).c_str());
                  eq->addChild(key);
                  eq->addChild((yyvsp[0].astnode));
                  (yyval.astnode)->addChild(eq);
                }
#line 1926 "sedml-script.cpp" /* yacc.c:1646  */
    break;


#line 1930 "sedml-script.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 339 "sedml-script.ypp" /* yacc.c:1906  */



void sed_yyerror(char const *s)
{
  stringstream err;
  err << "Error in line " << sed_yylloc_last_line << ": " << s;
  if (g_registry.getError()=="") {
    g_registry.setError(err.str(), sed_yylloc_last_line);
  }
}

int getLastIndent()
{
  size_t numIndents = g_registry.indents.size();
  if (numIndents > 0) {
    return g_registry.indents[numIndents-1];
  }
  return 0;
}

int sed_yylex(void)
{
  //First check to see if we need to immediately return a 'DEINDENT' based on the previous parse.
  int lastIndent = getLastIndent();
  if (lastIndent > g_registry.currIndent) {
    g_registry.indents.pop_back();
    lastIndent = getLastIndent();
    if (g_registry.currIndent > lastIndent) {
      //We didn't de-indent enough:
      g_registry.setError("The indentation decreased to an indentation level not previously seen.", sed_yylloc_last_line);
      return ERROR;
    }
    return DEINDENT;
  }
  char cc = 0;
  g_registry.input->get(cc);

  //If we're done with the file:
  if (g_registry.input->eof()) {
    if (g_registry.indents.size()>0) {
      g_registry.indents.pop_back();
      return DEINDENT;
    }
    if (g_registry.finalize()) {
      return ERROR;
    }
    return 0;
  }
  if (!g_registry.input->good()) {
    //Something else went wrong!
    g_registry.setError("Unparseable content in line " + g_registry.ftoa(sed_yylloc_last_line) + ".", sed_yylloc_last_line);
    return ERROR;
  }

  // Read white space.
  if (g_registry.midline) {
    //Skip whitespace.
    while ((cc == ' ' ||
            cc == '\t') &&
           !g_registry.input->eof()) {
      g_registry.input->get(cc);
    }
    if (g_registry.input->eof()) return sed_yylex();
  }
  else {
    //We're at the beginning of a line: check for indentation change:
    g_registry.currIndent = 0;
    while ((cc == ' ' ||
            cc == '\t') &&
           !g_registry.input->eof()) {
      if (cc==' ') {
        g_registry.currIndent += 1;
      }
      if (cc=='\t') {
        g_registry.currIndent += 4;
      }
      g_registry.input->get(cc);
    }
    if (cc=='#') {
      //It's a comment.
      while (cc != '\n' && !g_registry.input->eof()) {
        g_registry.input->get(cc);
        //At some point, maybe save comments?
      }
      ++sed_yylloc_last_line;
      g_registry.currIndent = getLastIndent();
      return sed_yylex();
    }
    if (cc=='\r' || cc=='\n') {
      //It was a blank line.
      ++sed_yylloc_last_line;
      g_registry.currIndent = getLastIndent();
      return sed_yylex();
    }
    //Back up: we parsed all the whitespace.
    g_registry.input->unget();
    g_registry.midline = true;

    //Compare this indent with the current suite.
    int lastIndent = getLastIndent();
    if (g_registry.currIndent == lastIndent) {
      //We're good: keep parsing.
      return sed_yylex();
    }
    if (g_registry.currIndent > lastIndent) {
      //We just increased the indent: return INDENT
      g_registry.indents.push_back(g_registry.currIndent);
      return INDENT;
    }
    //Otherwise, we decreased the indent.
    int lastLastIndent = 0;
    size_t numIndents = g_registry.indents.size();
    if (numIndents > 1) {
      lastLastIndent = g_registry.indents[numIndents-2];
    }
    if (g_registry.currIndent > lastLastIndent) {
      //We didn't de-indent enough:
      g_registry.setError("The indentation decreased to an indentation level not previously seen.", sed_yylloc_last_line);
      return ERROR;
    }
    g_registry.indents.pop_back();
    return DEINDENT;
  }

  // Skip carriage returns after '\':
  if (cc == '\\') {
    g_registry.input->get(cc);
    if (cc == '\r' || cc == '\n' || cc == ' ') {
      while ((cc == '\r' || cc == '\n' || cc == ' ') && !g_registry.input->eof()) {
        g_registry.input->get(cc);
      }
      ++sed_yylloc_last_line;
      g_registry.input->unget();
      return sed_yylex();
    }
    else {
      g_registry.input->unget();
      cc = '\\';
    }
 }

  // Parse words
  if (cc > 0 && cc < 256 && (isalpha(cc) || cc == '_')) {
    string word;
    while (cc > 0 && cc < 256 && (isalpha(cc) || isdigit(cc) || cc == '_') && !g_registry.input->eof()) {
      word += cc;
      g_registry.input->get(cc);
    }
    if (!g_registry.input->eof()) {
      g_registry.input->unget();
    }
    if (word == "and") {
      return ANDWORD;
    }
    if (word == "or") {
      return ORWORD;
    }
    if (word == "not") {
      return NOTWORD;
    }
    if (word == "for") {
      return FORWORD;
    }
    if (word == "in") {
      return INWORD;
    }
    if (word == "if") {
      return IFWORD;
    }
    sed_yylval.word = g_registry.addWord(word);
    //cout << "\tRead word '" << word << "'." << endl;
    if (word == "vs" && g_registry.input->peek() == '.') {
      g_registry.input->get(cc);
    }
    return SEDWORD;
  }

  // Parse numbers
  if (cc > 0 && cc < 256 && (isdigit(cc) || (cc=='.' && isdigit(g_registry.input->peek())))) {
    if (cc=='.') {
      //If the element *before* the '.' was a-z, we just return '.'.  This is for things like 'kisao.424':
      streampos here = g_registry.input->tellg();
      if (here>0) {
        g_registry.input->unget();
        g_registry.input->unget();
        char prev;
        g_registry.input->get(prev);
        g_registry.input->get(cc);
        if (('a' <= prev && prev <= 'z') || ('A' <= prev && prev <= 'Z')) {
          return cc;
        }
      }
    }
    double number;
    g_registry.input->unget();
    streampos numbegin = g_registry.input->tellg();
    *g_registry.input >> number;
    streampos numend = g_registry.input->tellg();
    if (g_registry.input->fail()) {
      //The gcc 4.4.3 parser fails if there's an 'e' after a number with no exponent.
      g_registry.input->clear();
      g_registry.input->seekg(numbegin);
      int numint;
      *g_registry.input >> numint;
      sed_yylval.number = numint;
      if (g_registry.input->peek() == '.') {
        g_registry.input->get();
        *g_registry.input >> numint;
        double fraction = numint;
        while (fraction >= 1.0) {
          fraction = fraction/10;
        }
        sed_yylval.number += fraction;
      }
      return NUM;
    }
    assert(g_registry.input->good());
    sed_yylval.number = number;
    //However, pre-4.4.3 parsers would read the 'e' anyway, and we don't want it to, so unget the 'e'.
    g_registry.input->unget();
    if (!g_registry.input->good()) {
      //Sometimes you can't do this?  For some reason?  If this happens we'll assume there was no 'e'.
      g_registry.input->clear();
    }
    else {
      g_registry.input->get(cc);
      if (cc == 'e' || cc == 'E') {
        g_registry.input->unget();
      }
      if (cc == '.') {
        //We might be in a 'kisao.43.c' situation.  Which is wrong, but at least clear what was meant.
        char next = g_registry.input->peek();
        if (('a' <= next && next <= 'z') || ('A' <= next && next <= 'Z')) {
          g_registry.input->unget();
        }
      }
    }
    return NUM;
  }

  //Skip comments:
  if (cc == '#') {
      while (cc != '\n' && cc != '\r' && !g_registry.input->eof()) {
        g_registry.input->get(cc);
      }
      if (!g_registry.input->eof()) {
        g_registry.input->unget();
      }
      return sed_yylex();
  }

  //Parse text strings
  if (cc == '"' || cc=='\'') {
    string textstring;
    long ccount = 0;
    char match = cc;
    textstring += match;
    g_registry.input->get(cc);
    while (cc != match && cc != '\r' && cc != '\n' && !g_registry.input->eof()) {
      textstring += cc;
      ccount++;
      g_registry.input->get(cc);
    }
    textstring += match;
    if (cc == '\r' || cc == '\n' || g_registry.input->eof()) {
      for (; ccount > 0; ccount--) {
        g_registry.input->unget();
      }
      cc = match;
    }
    else {
      sed_yylval.word = g_registry.addWord(textstring);
      return TEXTSTRING;
    }
  }

  //This converts PC and Mac end-of-line characters to \n:
  if (cc == '\r') {
    g_registry.input->get(cc);
    if (cc != '\n') {
      g_registry.input->unget();
    }
    cc = '\n';
  }
  if (cc == '\n') {
    ++sed_yylloc_last_line;
    g_registry.midline = false;
  }
  return cc;
}
