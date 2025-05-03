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
#line 1 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"

#include "vslc.h"

// State variables from the flex generated scanner
extern int yylineno;  // The line currently being read
extern char yytext[]; // The text of the last consumed lexeme

// The main flex driver function used by the parser
int yylex(void);

// The function called by the parser when errors occur
int yyerror(const char *error)
{
  fprintf(stderr, "%s on line %d\n", error, yylineno);
  exit(EXIT_FAILURE);
}

// Helper macros for creating nodes
#define N0C(type) \
  node_create( (type), 0 )
#define N1C(type, child0) \
  node_create( (type), 1, (child0) )
#define N2C(type, child0, child1) \
  node_create( (type), 2, (child0), (child1) )
#define N3C(type, child0, child1, child2) \
  node_create( (type), 3, (child0), (child1), (child2) )

#line 99 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FUNC = 3,                       /* FUNC  */
  YYSYMBOL_PRINT = 4,                      /* PRINT  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_BREAK = 6,                      /* BREAK  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_THEN = 8,                       /* THEN  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_VAR = 12,                       /* VAR  */
  YYSYMBOL_NUMBER_TOKEN = 13,              /* NUMBER_TOKEN  */
  YYSYMBOL_IDENTIFIER_TOKEN = 14,          /* IDENTIFIER_TOKEN  */
  YYSYMBOL_STRING_TOKEN = 15,              /* STRING_TOKEN  */
  YYSYMBOL_16_ = 16,                       /* '='  */
  YYSYMBOL_17_ = 17,                       /* '!'  */
  YYSYMBOL_18_ = 18,                       /* '<'  */
  YYSYMBOL_19_ = 19,                       /* '>'  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '-'  */
  YYSYMBOL_22_ = 22,                       /* '*'  */
  YYSYMBOL_23_ = 23,                       /* '/'  */
  YYSYMBOL_UNARY_OPERATORS = 24,           /* UNARY_OPERATORS  */
  YYSYMBOL_25_ = 25,                       /* ','  */
  YYSYMBOL_26_ = 26,                       /* '['  */
  YYSYMBOL_27_ = 27,                       /* ']'  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_global_list = 34,               /* global_list  */
  YYSYMBOL_global = 35,                    /* global  */
  YYSYMBOL_global_declaration = 36,        /* global_declaration  */
  YYSYMBOL_global_variable_list = 37,      /* global_variable_list  */
  YYSYMBOL_global_variable = 38,           /* global_variable  */
  YYSYMBOL_array_indexing = 39,            /* array_indexing  */
  YYSYMBOL_variable_list = 40,             /* variable_list  */
  YYSYMBOL_local_declaration = 41,         /* local_declaration  */
  YYSYMBOL_local_declaration_list = 42,    /* local_declaration_list  */
  YYSYMBOL_parameter_list = 43,            /* parameter_list  */
  YYSYMBOL_function = 44,                  /* function  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_block = 46,                     /* block  */
  YYSYMBOL_statement_list = 47,            /* statement_list  */
  YYSYMBOL_assignment_statement = 48,      /* assignment_statement  */
  YYSYMBOL_return_statement = 49,          /* return_statement  */
  YYSYMBOL_print_statement = 50,           /* print_statement  */
  YYSYMBOL_print_list = 51,                /* print_list  */
  YYSYMBOL_print_item = 52,                /* print_item  */
  YYSYMBOL_break_statement = 53,           /* break_statement  */
  YYSYMBOL_if_statement = 54,              /* if_statement  */
  YYSYMBOL_while_statement = 55,           /* while_statement  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_function_call = 57,             /* function_call  */
  YYSYMBOL_argument_list = 58,             /* argument_list  */
  YYSYMBOL_expression_list = 59,           /* expression_list  */
  YYSYMBOL_identifier = 60,                /* identifier  */
  YYSYMBOL_number = 61,                    /* number  */
  YYSYMBOL_string = 62                     /* string  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


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
       2,     2,     2,    17,     2,     2,     2,     2,     2,     2,
      28,    29,    22,    20,    25,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      18,    16,    19,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    48,    49,    52,    53,    56,    59,    60,
      63,    64,    67,    70,    71,    74,    77,    78,    81,    82,
      85,    89,    90,    91,    92,    93,    94,    95,    96,    99,
     101,   105,   106,   109,   110,   113,   117,   121,   122,   125,
     126,   129,   132,   134,   138,   142,   147,   152,   157,   162,
     167,   172,   177,   182,   187,   192,   197,   202,   203,   204,
     205,   206,   209,   211,   212,   215,   216,   219,   226,   232
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
  "\"end of file\"", "error", "\"invalid token\"", "FUNC", "PRINT",
  "RETURN", "BREAK", "IF", "THEN", "ELSE", "WHILE", "DO", "VAR",
  "NUMBER_TOKEN", "IDENTIFIER_TOKEN", "STRING_TOKEN", "'='", "'!'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "UNARY_OPERATORS", "','", "'['",
  "']'", "'('", "')'", "'{'", "'}'", "$accept", "program", "global_list",
  "global", "global_declaration", "global_variable_list",
  "global_variable", "array_indexing", "variable_list",
  "local_declaration", "local_declaration_list", "parameter_list",
  "function", "statement", "block", "statement_list",
  "assignment_statement", "return_statement", "print_statement",
  "print_list", "print_item", "break_statement", "if_statement",
  "while_statement", "expression", "function_call", "argument_list",
  "expression_list", "identifier", "number", "string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    16,    16,    14,     0,   -32,   -32,   -32,   -32,   -15,
      10,   -32,   -32,    19,   -32,   -32,    16,    16,    64,    36,
      21,   -32,   -32,   -32,    64,    64,    64,   -32,   208,   -32,
      28,   -32,    16,   147,   -32,   -32,   186,    43,    47,    12,
      25,    64,    64,    64,    64,   -32,    64,   -32,    34,    64,
     -32,    64,    64,   159,    48,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,     8,   -32,    64,    64,    64,   -12,
      64,   -12,   -18,   -18,   -32,   -32,   220,    37,    42,   -32,
      44,   -32,   220,   -32,   220,   178,   200,    16,   -32,   159,
     -32,    13,    64,    64,   160,   160,   160,   160,   -32,    64,
      34,   147,   147,    36,   -32,   116,   -32,   -32,   220,   220,
     220,   -32,    59,   -32,   -32,   147,   -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     6,     5,    67,     0,
       7,     8,    11,    10,     1,     4,    18,     0,     0,    19,
       0,    13,     9,    68,     0,     0,     0,    60,     0,    61,
      59,    58,     0,     0,    56,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    64,    14,     0,     0,
      41,     0,     0,     0,     0,    20,    28,    21,    22,    23,
      26,    24,    25,    27,     0,    57,     0,     0,     0,    47,
       0,    49,    51,    52,    53,    54,    65,     0,    63,    69,
      36,    37,    39,    40,    35,     0,     0,     0,    16,     0,
      31,     0,     0,     0,    45,    46,    48,    50,    62,     0,
       0,     0,     0,    15,    17,     0,    30,    32,    34,    33,
      66,    38,    42,    44,    29,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,    68,   -32,   -32,    56,     4,    -7,    -6,
     -32,   -32,   -32,   -26,   -32,    -2,   -32,   -32,   -32,   -32,
      -9,   -32,   -32,   -32,    92,   -31,   -32,   -32,    -1,   -32,
     -32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    10,    11,    27,    19,    88,
      89,    20,     7,    90,    56,    91,    57,    58,    59,    80,
      81,    60,    61,    62,    82,    29,    77,    78,    30,    31,
      83
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       9,    13,    63,     1,    43,    44,    12,    55,    41,    42,
      43,    44,     2,    16,    14,    21,    13,    48,    49,    50,
      51,    12,    63,    52,    93,    23,     8,     8,    68,    24,
       8,    47,    64,    25,    18,    17,    46,    54,    23,     8,
      26,    70,    24,    53,   106,    18,    25,    23,     8,    79,
      33,    24,    64,    26,    18,    25,    46,    54,    63,    66,
      63,    32,    26,    67,    92,   107,    98,    99,   115,   100,
      63,    63,    15,    22,    63,   112,   113,    23,     8,   107,
     103,    24,     0,   104,    63,    25,    21,   105,    64,   116,
      64,   111,    26,    54,     0,    54,     0,     0,     0,     0,
      64,    64,     0,     0,    64,    54,    54,     0,     0,    54,
      28,     0,     0,     0,    64,     0,    34,    35,    36,    54,
      48,    49,    50,    51,     0,     0,    52,     0,     0,     0,
       8,    69,    71,    72,    73,    74,    75,     0,    76,     0,
       0,    84,     0,    85,    86,     0,    53,   114,     0,     0,
       0,    48,    49,    50,    51,     0,     0,    52,    94,    95,
      96,     8,    97,    48,    49,    50,    51,     0,     0,    52,
       0,    87,     0,     8,     0,     0,     0,    53,    39,    40,
      41,    42,    43,    44,   108,   109,   101,     0,     0,    53,
       0,   110,     0,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    37,    38,    39,    40,    41,    42,    43,    44,
       0,   102,     0,     0,     0,    65,    37,    38,    39,    40,
      41,    42,    43,    44,    37,    38,    39,    40,    41,    42,
      43,    44,     0,     0,     0,    45,    37,    38,    39,    40,
      41,    42,    43,    44
};

static const yytype_int8 yycheck[] =
{
       1,     2,    33,     3,    22,    23,     2,    33,    20,    21,
      22,    23,    12,    28,     0,    16,    17,     4,     5,     6,
       7,    17,    53,    10,    16,    13,    14,    14,    16,    17,
      14,    32,    33,    21,    26,    25,    28,    33,    13,    14,
      28,    16,    17,    30,    31,    26,    21,    13,    14,    15,
      29,    17,    53,    28,    26,    21,    28,    53,    89,    16,
      91,    25,    28,    16,    16,    91,    29,    25,     9,    25,
     101,   102,     4,    17,   105,   101,   102,    13,    14,   105,
      87,    17,    -1,    89,   115,    21,    87,    89,    89,   115,
      91,   100,    28,    89,    -1,    91,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,   101,   102,    -1,    -1,   105,
      18,    -1,    -1,    -1,   115,    -1,    24,    25,    26,   115,
       4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,
      14,    39,    40,    41,    42,    43,    44,    -1,    46,    -1,
      -1,    49,    -1,    51,    52,    -1,    30,    31,    -1,    -1,
      -1,     4,     5,     6,     7,    -1,    -1,    10,    66,    67,
      68,    14,    70,     4,     5,     6,     7,    -1,    -1,    10,
      -1,    12,    -1,    14,    -1,    -1,    -1,    30,    18,    19,
      20,    21,    22,    23,    92,    93,     8,    -1,    -1,    30,
      -1,    99,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    11,    -1,    -1,    -1,    29,    16,    17,    18,    19,
      20,    21,    22,    23,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    27,    16,    17,    18,    19,
      20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    12,    33,    34,    35,    36,    44,    14,    60,
      37,    38,    39,    60,     0,    35,    28,    25,    26,    40,
      43,    60,    38,    13,    17,    21,    28,    39,    56,    57,
      60,    61,    25,    29,    56,    56,    56,    16,    17,    18,
      19,    20,    21,    22,    23,    27,    28,    60,     4,     5,
       6,     7,    10,    30,    39,    45,    46,    48,    49,    50,
      53,    54,    55,    57,    60,    29,    16,    16,    16,    56,
      16,    56,    56,    56,    56,    56,    56,    58,    59,    15,
      51,    52,    56,    62,    56,    56,    56,    12,    41,    42,
      45,    47,    16,    16,    56,    56,    56,    56,    29,    25,
      25,     8,    11,    40,    41,    47,    31,    45,    56,    56,
      56,    52,    45,    45,    31,     9,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    37,    37,
      38,    38,    39,    40,    40,    41,    42,    42,    43,    43,
      44,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    50,    51,    51,    52,
      52,    53,    54,    54,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    58,    58,    59,    59,    60,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     1,     3,
       1,     1,     4,     1,     3,     2,     1,     2,     0,     1,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     1,     2,     3,     3,     2,     2,     1,     3,     1,
       1,     1,     4,     6,     4,     4,     4,     3,     4,     3,
       4,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       1,     1,     4,     1,     0,     1,     3,     1,     1,     1
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
  case 2: /* program: global_list  */
#line 45 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                  { root = yyvsp[0]; }
#line 1252 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 3: /* global_list: global  */
#line 48 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
             { yyval = N1C(LIST, yyvsp[0]); }
#line 1258 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 4: /* global_list: global_list global  */
#line 49 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                         { yyval = append_to_list_node(yyvsp[-1], yyvsp[0]); }
#line 1264 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 5: /* global: function  */
#line 52 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
               { yyval = yyvsp[0]; }
#line 1270 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 6: /* global: global_declaration  */
#line 53 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                         { yyval = yyvsp[0]; }
#line 1276 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 7: /* global_declaration: VAR global_variable_list  */
#line 56 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                               { yyval = N1C(GLOBAL_DECLARATION, yyvsp[0]); }
#line 1282 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 8: /* global_variable_list: global_variable  */
#line 59 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                      { yyval = N1C(LIST, yyvsp[0]); }
#line 1288 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 9: /* global_variable_list: global_variable_list ',' global_variable  */
#line 60 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                                               { yyval = append_to_list_node(yyvsp[-2], yyvsp[0]); }
#line 1294 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 10: /* global_variable: identifier  */
#line 63 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                 { yyval = yyvsp[0]; }
#line 1300 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 11: /* global_variable: array_indexing  */
#line 64 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                     { yyval = yyvsp[0]; }
#line 1306 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 12: /* array_indexing: identifier '[' expression ']'  */
#line 67 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                                    { yyval = N2C(ARRAY_INDEXING, yyvsp[-3], yyvsp[-1]); }
#line 1312 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 13: /* variable_list: identifier  */
#line 70 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                 { yyval = N1C(LIST, yyvsp[0]); }
#line 1318 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 14: /* variable_list: variable_list ',' identifier  */
#line 71 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                                   { yyval = append_to_list_node(yyvsp[-2], yyvsp[0]); }
#line 1324 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 15: /* local_declaration: VAR variable_list  */
#line 74 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                        { yyval = yyvsp[0]; }
#line 1330 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 16: /* local_declaration_list: local_declaration  */
#line 77 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                        { yyval = N1C(LIST, yyvsp[0]); }
#line 1336 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 17: /* local_declaration_list: local_declaration_list local_declaration  */
#line 78 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                                               { yyval = append_to_list_node(yyvsp[-1], yyvsp[0]); }
#line 1342 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 18: /* parameter_list: %empty  */
#line 81 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                   { yyval = N0C(LIST); }
#line 1348 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 19: /* parameter_list: variable_list  */
#line 82 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                    { yyval = yyvsp[0]; }
#line 1354 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 20: /* function: FUNC identifier '(' parameter_list ')' statement  */
#line 86 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        { yyval = N3C(FUNCTION, yyvsp[-4], yyvsp[-2], yyvsp[0]); }
#line 1360 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 21: /* statement: assignment_statement  */
#line 89 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                           { yyval = yyvsp[0]; }
#line 1366 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 22: /* statement: return_statement  */
#line 90 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                       { yyval = yyvsp[0]; }
#line 1372 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 23: /* statement: print_statement  */
#line 91 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                      { yyval = yyvsp[0]; }
#line 1378 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 24: /* statement: if_statement  */
#line 92 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                   { yyval = yyvsp[0]; }
#line 1384 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 25: /* statement: while_statement  */
#line 93 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                      { yyval = yyvsp[0]; }
#line 1390 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 26: /* statement: break_statement  */
#line 94 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                      { yyval = yyvsp[0]; }
#line 1396 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 27: /* statement: function_call  */
#line 95 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                    { yyval = yyvsp[0]; }
#line 1402 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 28: /* statement: block  */
#line 96 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
            { yyval = yyvsp[0]; }
#line 1408 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 29: /* block: '{' local_declaration_list statement_list '}'  */
#line 100 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        { yyval = N2C(BLOCK, yyvsp[-2], yyvsp[-1]); }
#line 1414 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 30: /* block: '{' statement_list '}'  */
#line 102 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        { yyval = N1C(BLOCK, yyvsp[-1]); }
#line 1420 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 31: /* statement_list: statement  */
#line 105 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                { yyval = N1C(LIST, yyvsp[0]); }
#line 1426 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 32: /* statement_list: statement_list statement  */
#line 106 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                               { yyval = append_to_list_node(yyvsp[-1], yyvsp[0]); }
#line 1432 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 33: /* assignment_statement: identifier '=' expression  */
#line 109 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                                { yyval = N2C(ASSIGNMENT_STATEMENT, yyvsp[-2], yyvsp[0]); }
#line 1438 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 34: /* assignment_statement: array_indexing '=' expression  */
#line 110 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                                    { yyval = N2C(ASSIGNMENT_STATEMENT, yyvsp[-2], yyvsp[0]); }
#line 1444 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 35: /* return_statement: RETURN expression  */
#line 114 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        { yyval = N1C(RETURN_STATEMENT, yyvsp[0]); }
#line 1450 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 36: /* print_statement: PRINT print_list  */
#line 118 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        { yyval = N1C(PRINT_STATEMENT, yyvsp[0]); }
#line 1456 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 37: /* print_list: print_item  */
#line 121 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                 { yyval = N1C(LIST, yyvsp[0]); }
#line 1462 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 38: /* print_list: print_list ',' print_item  */
#line 122 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                                { yyval = append_to_list_node(yyvsp[-2], yyvsp[0]); }
#line 1468 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 39: /* print_item: expression  */
#line 125 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                 { yyval = yyvsp[0]; }
#line 1474 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 40: /* print_item: string  */
#line 126 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
             { yyval = yyvsp[0]; }
#line 1480 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 41: /* break_statement: BREAK  */
#line 129 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
            { yyval = N0C(BREAK_STATEMENT); }
#line 1486 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 42: /* if_statement: IF expression THEN statement  */
#line 133 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        { yyval = N2C(IF_STATEMENT, yyvsp[-2], yyvsp[0]); }
#line 1492 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 43: /* if_statement: IF expression THEN statement ELSE statement  */
#line 135 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        { yyval = N3C(IF_STATEMENT, yyvsp[-4], yyvsp[-2], yyvsp[0]); }
#line 1498 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 44: /* while_statement: WHILE expression DO statement  */
#line 139 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        { yyval = N2C(WHILE_STATEMENT, yyvsp[-2], yyvsp[0]); }
#line 1504 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 45: /* expression: expression '=' '=' expression  */
#line 143 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-3], yyvsp[0]);
          yyval->data.operator = "==";
        }
#line 1513 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 46: /* expression: expression '!' '=' expression  */
#line 148 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-3], yyvsp[0]);
          yyval->data.operator = "!=";
        }
#line 1522 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 47: /* expression: expression '<' expression  */
#line 153 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-2], yyvsp[0]);
          yyval->data.operator = "<";
        }
#line 1531 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 48: /* expression: expression '<' '=' expression  */
#line 158 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-3], yyvsp[0]);
          yyval->data.operator = "<=";
        }
#line 1540 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 49: /* expression: expression '>' expression  */
#line 163 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-2], yyvsp[0]);
          yyval->data.operator = ">";
        }
#line 1549 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 50: /* expression: expression '>' '=' expression  */
#line 168 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-3], yyvsp[0]);
          yyval->data.operator = ">=";
        }
#line 1558 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 51: /* expression: expression '+' expression  */
#line 173 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-2], yyvsp[0]);
          yyval->data.operator = "+";
        }
#line 1567 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 52: /* expression: expression '-' expression  */
#line 178 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-2], yyvsp[0]);
          yyval->data.operator = "-";
        }
#line 1576 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 53: /* expression: expression '*' expression  */
#line 183 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-2], yyvsp[0]);
          yyval->data.operator = "*";
        }
#line 1585 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 54: /* expression: expression '/' expression  */
#line 188 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N2C(OPERATOR, yyvsp[-2], yyvsp[0]);
          yyval->data.operator = "/";
        }
#line 1594 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 55: /* expression: '-' expression  */
#line 193 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N1C(OPERATOR, yyvsp[0]);
          yyval->data.operator = "-";
        }
#line 1603 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 56: /* expression: '!' expression  */
#line 198 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
        {
          yyval = N1C(OPERATOR, yyvsp[0]);
          yyval->data.operator = "!";
        }
#line 1612 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 57: /* expression: '(' expression ')'  */
#line 202 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                         { yyval = yyvsp[-1]; }
#line 1618 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 58: /* expression: number  */
#line 203 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
             { yyval = yyvsp[0]; }
#line 1624 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 59: /* expression: identifier  */
#line 204 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                 { yyval = yyvsp[0]; }
#line 1630 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 60: /* expression: array_indexing  */
#line 205 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                     { yyval = yyvsp[0]; }
#line 1636 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 61: /* expression: function_call  */
#line 206 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                    { yyval = yyvsp[0]; }
#line 1642 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 62: /* function_call: identifier '(' argument_list ')'  */
#line 209 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                                       { yyval = N2C(FUNCTION_CALL, yyvsp[-3], yyvsp[-1]); }
#line 1648 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 63: /* argument_list: expression_list  */
#line 211 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                      { yyval = yyvsp[0]; }
#line 1654 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 64: /* argument_list: %empty  */
#line 212 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                      { yyval = N0C(LIST); }
#line 1660 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 65: /* expression_list: expression  */
#line 215 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                 { yyval = N1C(LIST, yyvsp[0]); }
#line 1666 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 66: /* expression_list: expression_list ',' expression  */
#line 216 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
                                     { yyval = append_to_list_node(yyvsp[-2], yyvsp[0]); }
#line 1672 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 67: /* identifier: IDENTIFIER_TOKEN  */
#line 220 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
      {
        yyval = N0C(IDENTIFIER);
        // Allocate a copy of yytext to keep in the syntax tree as data
        yyval->data.identifier = strdup(yytext);
      }
#line 1682 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 68: /* number: NUMBER_TOKEN  */
#line 227 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
      {
        yyval = N0C(NUMBER_LITERAL);
        yyval->data.number_literal = strtol(yytext, NULL, 10);
      }
#line 1691 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;

  case 69: /* string: STRING_TOKEN  */
#line 233 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"
      {
        yyval = N0C(STRING_LITERAL);
        yyval->data.string_literal = strdup(yytext);
      }
#line 1700 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"
    break;


#line 1704 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/build/parser.c"

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

#line 237 "/home/crd/Documents/y5s2/compcon-TDT4205/rep/rep6/src/parser.y"

