/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 1 "src/parser.y"

    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    #include <cstring>
    #include <stack>
    extern Ast ast;

    int yylex();
    int yyerror(char const*);
    ArrayType* arrayType;
    int idx;
    int* intArrayValue;
    float* floatArrayValue;
    std::stack<InitValueListExpr*> initStack;
    InitValueListExpr* top;
    int leftCnt = 0;
    std::string tempType;

#line 87 "src/parser.cpp"




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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_INCLUDE_PARSER_H_INCLUDED
# define YY_YY_INCLUDE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 21 "src/parser.y"

    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"

#line 139 "src/parser.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    STRING = 259,
    INTEGER = 260,
    FLOATNUM = 261,
    CONST = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    CONTINUE = 266,
    BREAK = 267,
    INT = 268,
    VOID = 269,
    FLOAT = 270,
    LPAREN = 271,
    RPAREN = 272,
    LBRACE = 273,
    RBRACE = 274,
    SEMICOLON = 275,
    LBRACKET = 276,
    RBRACKET = 277,
    COMMA = 278,
    ADD = 279,
    SUB = 280,
    MUL = 281,
    DIV = 282,
    MOD = 283,
    OR = 284,
    AND = 285,
    LESS = 286,
    LESSEQ = 287,
    GREATER = 288,
    GREATEREQ = 289,
    ASSIGN = 290,
    EQUAL = 291,
    NOTEQUAL = 292,
    NOT = 293,
    RETURN = 294,
    THEN = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "src/parser.y"

    int itype;
    float ftype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;
    SymbolEntry* se;

#line 201 "src/parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_PARSER_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    64,    65,    71,    73,    74,    76,    77,
      79,    80,    81,    83,    84,    85,    89,    97,   108,   115,
     121,   127,   127,   136,   142,   145,   151,   157,   163,   169,
     172,   179,   184,   188,   191,   194,   205,   209,   216,   217,
     226,   233,   234,   244,   251,   252,   263,   274,   287,   288,
     299,   313,   314,   318,   322,   326,   333,   334,   338,   345,
     346,   353,   354,   361,   365,   366,   372,   376,   380,   387,
     388,   391,   394,   400,   404,   408,   412,   415,   426,   481,
     498,   498,   562,   577,   577,   641,   644,   650,   699,   746,
     746,   785,   823,   866,   866,   903,   906,   911,   914,   920,
     923,   920,   949,   950,   952,   956,   959,   969,   994,   997
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INTEGER", "FLOATNUM",
  "CONST", "IF", "ELSE", "WHILE", "CONTINUE", "BREAK", "INT", "VOID",
  "FLOAT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "LBRACKET",
  "RBRACKET", "COMMA", "ADD", "SUB", "MUL", "DIV", "MOD", "OR", "AND",
  "LESS", "LESSEQ", "GREATER", "GREATEREQ", "ASSIGN", "EQUAL", "NOTEQUAL",
  "NOT", "RETURN", "THEN", "$accept", "Program", "Stmts", "Stmt", "LVal",
  "AssignStmt", "ExprStmt", "BlankStmt", "BlockStmt", "$@1", "IfStmt",
  "WhileStmt", "BreakStmt", "ContinueStmt", "ReturnStmt", "Exp", "Cond",
  "PrimaryExp", "UnaryExp", "MulExp", "AddExp", "RelExp", "EqExp",
  "LAndExp", "LOrExp", "ConstExp", "FuncRParams", "Type", "DeclStmt",
  "VarDeclStmt", "ConstDeclStmt", "VarDefList", "ConstDefList", "VarDef",
  "@2", "ConstDef", "@3", "ArrayIndices", "InitVal", "@4", "ConstInitVal",
  "@5", "InitValList", "ConstInitValList", "FuncDef", "$@6", "@7",
  "InterFuncFParams", "FuncFParams", "FuncFParam", "FuncArrayIndices", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-100)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     162,    29,  -129,  -129,  -129,    59,    -9,    38,    41,    49,
    -129,  -129,  -129,   217,    10,  -129,   217,   217,   217,    15,
      56,   162,  -129,    40,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,    69,  -129,  -129,    60,    88,    89,  -129,
    -129,  -129,  -129,   186,   217,    87,   118,   217,   217,  -129,
    -129,  -129,   111,  -129,   162,  -129,  -129,  -129,  -129,   112,
    -129,  -129,   217,  -129,   217,   217,   217,   217,   217,   -11,
      21,  -129,  -129,  -129,    -6,    88,   109,   217,    12,    37,
    -129,   116,    88,    34,    81,   106,   113,   121,  -129,    91,
    -129,   120,  -129,  -129,  -129,    60,    60,   190,    13,   125,
    -129,   140,  -129,   217,  -129,   122,   213,    16,  -129,   118,
     162,   217,   217,   217,   217,   217,   217,   217,   217,   162,
    -129,  -129,   126,  -129,  -129,  -129,    59,    17,  -129,  -129,
    -129,   127,  -129,  -129,  -129,  -129,   138,    88,    88,    88,
      88,    34,    34,    81,   106,  -129,  -129,   190,   190,   145,
     132,   128,  -129,  -129,   213,   213,   162,  -129,     9,  -129,
     129,  -129,    59,  -129,    36,  -129,  -129,  -129,   190,   130,
     133,   135,  -129,  -129,   213,  -129,  -129,   217,  -129,  -129,
     134,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,    35,    36,    37,     0,     0,     0,     0,     0,
      66,    67,    68,     0,    21,    20,     0,     0,     0,     0,
       0,     2,     3,    34,     5,     6,     8,     7,     9,    10,
      11,    12,    13,     0,    38,    44,    48,    31,     0,    14,
      69,    70,    15,     0,     0,    17,     0,     0,     0,    28,
      27,    34,     0,    23,     0,    41,    42,    43,    29,     0,
       1,     4,     0,    19,     0,     0,     0,     0,     0,    77,
       0,    74,    40,    64,     0,    63,     0,     0,     0,     0,
      76,     0,    51,    56,    59,    61,    32,     0,    33,     0,
      30,     0,    45,    46,    47,    49,    50,     0,    78,     0,
      71,     0,    39,     0,    85,     0,     0,     0,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    18,    89,    87,    79,    80,   103,    77,    73,    65,
      86,    93,    91,    82,    83,    75,    24,    52,    53,    54,
      55,    57,    58,    60,    62,    26,    88,     0,     0,     0,
       0,   102,   105,    92,     0,     0,     0,    95,     0,    81,
     106,   100,     0,    97,     0,    84,    25,    90,     0,     0,
     107,     0,   104,    94,     0,    96,   108,     0,   101,    98,
       0,   109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   103,   -19,     4,  -129,  -129,  -129,   -12,  -129,
    -129,  -129,  -129,  -129,  -129,   -13,   114,  -129,    -2,    57,
     -35,    11,    44,    45,  -129,   -41,  -129,    -4,  -129,  -129,
    -129,  -129,  -129,    70,  -129,    72,  -129,     7,  -125,  -129,
    -128,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,    22,
    -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    51,    24,    25,    26,    27,    54,
      28,    29,    30,    31,    32,    33,    81,    34,    35,    36,
      37,    83,    84,    85,    86,   132,    74,    38,    39,    40,
      41,    70,    79,    71,   148,    80,   155,    98,   124,   147,
     133,   154,   158,   164,    42,    99,   171,   150,   151,   152,
     170
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    46,    61,    76,    23,   -99,    59,    47,    45,    75,
      44,   102,    82,    82,    55,    56,    57,   103,     1,     2,
       3,     4,   157,   159,    97,    23,   163,   165,   167,    53,
      73,    13,   168,    44,    77,    58,   105,    77,    44,    16,
      17,   100,    75,   175,   101,    43,   179,   106,   125,    91,
      44,   134,    97,    18,    48,   173,    60,   108,    23,   174,
     109,    49,    92,    93,    94,   111,   112,   113,   114,    50,
      61,    75,    10,    11,    12,    62,   137,   138,   139,   140,
      82,    82,    82,    82,   123,   107,    64,    65,    66,    63,
     129,   136,    69,    23,     1,     2,     3,     4,     5,     6,
     145,     7,     8,     9,    10,    11,    12,    13,    77,    14,
     120,    15,    67,    68,    23,    16,    17,   115,   116,    75,
      75,    78,   149,    23,    95,    96,   141,   142,    88,    18,
      19,   104,    90,   110,   123,   123,   117,   166,   119,    75,
     121,   126,   118,   127,   130,   146,   153,   156,   160,   161,
     169,   162,   176,    14,   177,   123,   181,    89,   149,   178,
      23,   143,    87,   144,   180,     1,     2,     3,     4,     5,
       6,   128,     7,     8,     9,    10,    11,    12,    13,     0,
      14,   135,    15,     0,   172,     0,    16,    17,     0,     1,
       2,     3,     4,     1,     2,     3,     4,     0,     0,     0,
      18,    19,    13,    72,     0,     0,    13,     0,   122,     0,
      16,    17,     0,     0,    16,    17,     1,     2,     3,     4,
       1,     2,     3,     4,    18,     0,     0,     0,    18,    13,
       0,   131,     0,    13,     0,     0,     0,    16,    17,     0,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,    18
};

static const yytype_int16 yycheck[] =
{
      13,     5,    21,    44,     0,    16,    19,    16,     1,    44,
      21,    17,    47,    48,    16,    17,    18,    23,     3,     4,
       5,     6,   147,   148,    35,    21,   154,   155,    19,    19,
      43,    16,    23,    21,    21,    20,    77,    21,    21,    24,
      25,    20,    77,   168,    23,    16,   174,    35,    35,    62,
      21,    35,    35,    38,    16,    19,     0,    20,    54,    23,
      23,    20,    64,    65,    66,    31,    32,    33,    34,    20,
      89,   106,    13,    14,    15,    35,   111,   112,   113,   114,
     115,   116,   117,   118,    97,    78,    26,    27,    28,    20,
     103,   110,     3,    89,     3,     4,     5,     6,     7,     8,
     119,    10,    11,    12,    13,    14,    15,    16,    21,    18,
      19,    20,    24,    25,   110,    24,    25,    36,    37,   154,
     155,     3,   126,   119,    67,    68,   115,   116,    17,    38,
      39,    22,    20,    17,   147,   148,    30,   156,    17,   174,
      20,    16,    29,     3,    22,    19,    19,     9,     3,    17,
      21,    23,    22,    18,    21,   168,    22,    54,   162,   171,
     156,   117,    48,   118,   177,     3,     4,     5,     6,     7,
       8,   101,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,   109,    20,    -1,   162,    -1,    24,    25,    -1,     3,
       4,     5,     6,     3,     4,     5,     6,    -1,    -1,    -1,
      38,    39,    16,    17,    -1,    -1,    16,    -1,    18,    -1,
      24,    25,    -1,    -1,    24,    25,     3,     4,     5,     6,
       3,     4,     5,     6,    38,    -1,    -1,    -1,    38,    16,
      -1,    18,    -1,    16,    -1,    -1,    -1,    24,    25,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    12,
      13,    14,    15,    16,    18,    20,    24,    25,    38,    39,
      42,    43,    44,    45,    46,    47,    48,    49,    51,    52,
      53,    54,    55,    56,    58,    59,    60,    61,    68,    69,
      70,    71,    85,    16,    21,    78,    68,    16,    16,    20,
      20,    45,    56,    19,    50,    59,    59,    59,    20,    56,
       0,    44,    35,    20,    26,    27,    28,    24,    25,     3,
      72,    74,    17,    56,    67,    61,    66,    21,     3,    73,
      76,    57,    61,    62,    63,    64,    65,    57,    17,    43,
      20,    56,    59,    59,    59,    60,    60,    35,    78,    86,
      20,    23,    17,    23,    22,    66,    35,    78,    20,    23,
      17,    31,    32,    33,    34,    36,    37,    30,    29,    17,
      19,    20,    18,    56,    79,    35,    16,     3,    74,    56,
      22,    18,    66,    81,    35,    76,    44,    61,    61,    61,
      61,    62,    62,    63,    64,    44,    19,    80,    75,    68,
      88,    89,    90,    19,    82,    77,     9,    79,    83,    79,
       3,    17,    23,    81,    84,    81,    44,    19,    23,    21,
      91,    87,    90,    19,    23,    79,    22,    21,    49,    81,
      56,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    46,    47,
      48,    50,    49,    49,    51,    51,    52,    53,    54,    55,
      55,    56,    57,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    60,    60,    60,    60,    61,    61,
      61,    62,    62,    62,    62,    62,    63,    63,    63,    64,
      64,    65,    65,    66,    67,    67,    68,    68,    68,    69,
      69,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      75,    74,    76,    77,    76,    78,    78,    79,    79,    80,
      79,    81,    81,    82,    81,    83,    83,    84,    84,    86,
      87,    85,    88,    88,    89,    89,    90,    90,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     2,
       1,     0,     4,     2,     5,     7,     5,     2,     2,     2,
       3,     1,     1,     3,     1,     1,     1,     1,     1,     4,
       3,     2,     2,     2,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     4,     3,     1,     3,     1,     1,     2,     3,
       0,     5,     3,     0,     5,     3,     4,     1,     2,     0,
       4,     1,     2,     0,     4,     1,     3,     1,     3,     0,
       0,     8,     1,     0,     3,     1,     2,     3,     2,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
# undef YYSTACK_RELOCATE
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
  case 2:
#line 58 "src/parser.y"
            {
        ast.setRoot((yyvsp[0].stmttype));
    }
#line 1529 "src/parser.cpp"
    break;

  case 3:
#line 64 "src/parser.y"
           {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1535 "src/parser.cpp"
    break;

  case 4:
#line 65 "src/parser.y"
                {
        (yyval.stmttype) = new SeqNode((yyvsp[-1].stmttype), (yyvsp[0].stmttype));
    }
#line 1543 "src/parser.cpp"
    break;

  case 5:
#line 71 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1549 "src/parser.cpp"
    break;

  case 6:
#line 73 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1555 "src/parser.cpp"
    break;

  case 7:
#line 74 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1561 "src/parser.cpp"
    break;

  case 8:
#line 76 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1567 "src/parser.cpp"
    break;

  case 9:
#line 77 "src/parser.y"
             {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1573 "src/parser.cpp"
    break;

  case 10:
#line 79 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1579 "src/parser.cpp"
    break;

  case 11:
#line 80 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1585 "src/parser.cpp"
    break;

  case 12:
#line 81 "src/parser.y"
                   {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1591 "src/parser.cpp"
    break;

  case 13:
#line 83 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1597 "src/parser.cpp"
    break;

  case 14:
#line 84 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1603 "src/parser.cpp"
    break;

  case 15:
#line 85 "src/parser.y"
              {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1609 "src/parser.cpp"
    break;

  case 16:
#line 89 "src/parser.y"
         {
        SymbolEntry* se;
        se = identifiers->lookup((yyvsp[0].strtype));
        if(se == nullptr)
            fprintf(stderr, "[ERROR] Identifier \"%s\" is undefined\n", (char*)(yyvsp[0].strtype));
        (yyval.exprtype) = new IdExpr(se);
        delete [](yyvsp[0].strtype);
    }
#line 1622 "src/parser.cpp"
    break;

  case 17:
#line 97 "src/parser.y"
                     {
        SymbolEntry* se;
        se = identifiers->lookup((yyvsp[-1].strtype));
        if(se == nullptr)
            fprintf(stderr, "[ERROR] Identifier \"%s\" is undefined\n", (char*)(yyvsp[-1].strtype));
        (yyval.exprtype) = new IdExpr(se, (yyvsp[0].exprtype));
        delete [](yyvsp[-1].strtype);
    }
#line 1635 "src/parser.cpp"
    break;

  case 18:
#line 108 "src/parser.y"
                                {
        (yyval.stmttype) = new AssignStmt((yyvsp[-3].exprtype), (yyvsp[-1].exprtype));
        //printf("[INFO] AssignStmt\n");
    }
#line 1644 "src/parser.cpp"
    break;

  case 19:
#line 115 "src/parser.y"
                    {
        (yyval.stmttype) = new ExprStmt((yyvsp[-1].exprtype));
    }
#line 1652 "src/parser.cpp"
    break;

  case 20:
#line 121 "src/parser.y"
                {
        (yyval.stmttype) = new BlankStmt();
    }
#line 1660 "src/parser.cpp"
    break;

  case 21:
#line 127 "src/parser.y"
             {
        identifiers = new SymbolTable(identifiers); 
    }
#line 1668 "src/parser.cpp"
    break;

  case 22:
#line 130 "src/parser.y"
                   {
        (yyval.stmttype) = new CompoundStmt((yyvsp[-1].stmttype));
        SymbolTable* top = identifiers;
        identifiers = identifiers->getPrev();  //return to the prev identifiers
        delete top;
    }
#line 1679 "src/parser.cpp"
    break;

  case 23:
#line 136 "src/parser.y"
                    {
        (yyval.stmttype) = new CompoundStmt();
    }
#line 1687 "src/parser.cpp"
    break;

  case 24:
#line 142 "src/parser.y"
                                            {
        (yyval.stmttype) = new IfStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1695 "src/parser.cpp"
    break;

  case 25:
#line 145 "src/parser.y"
                                           {
        (yyval.stmttype) = new IfElseStmt((yyvsp[-4].exprtype), (yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 1703 "src/parser.cpp"
    break;

  case 26:
#line 151 "src/parser.y"
                                    {
        (yyval.stmttype) = new WhileStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1711 "src/parser.cpp"
    break;

  case 27:
#line 157 "src/parser.y"
                      {
        (yyval.stmttype) = new BreakStmt();
    }
#line 1719 "src/parser.cpp"
    break;

  case 28:
#line 163 "src/parser.y"
                         {
        (yyval.stmttype) = new ContinueStmt();
    }
#line 1727 "src/parser.cpp"
    break;

  case 29:
#line 169 "src/parser.y"
                       {
        (yyval.stmttype) = new ReturnStmt();
    }
#line 1735 "src/parser.cpp"
    break;

  case 30:
#line 172 "src/parser.y"
                           {
        (yyval.stmttype) = new ReturnStmt((yyvsp[-1].exprtype));
    }
#line 1743 "src/parser.cpp"
    break;

  case 31:
#line 179 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1749 "src/parser.cpp"
    break;

  case 32:
#line 184 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1755 "src/parser.cpp"
    break;

  case 33:
#line 188 "src/parser.y"
                        {
        (yyval.exprtype) = (yyvsp[-1].exprtype);
    }
#line 1763 "src/parser.cpp"
    break;

  case 34:
#line 191 "src/parser.y"
           {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1771 "src/parser.cpp"
    break;

  case 35:
#line 194 "src/parser.y"
             {
        SymbolEntry* se;
        se = globals->lookup(std::string((yyvsp[0].strtype)));
        if(se == nullptr){
            Type* type = new StringType(strlen((yyvsp[0].strtype)));
            se = new ConstantSymbolEntry(type, std::string((yyvsp[0].strtype)));
            globals->install(std::string((yyvsp[0].strtype)), se);
        }
        ExprNode* expr = new ExprNode(se);
        (yyval.exprtype) = expr;
    }
#line 1787 "src/parser.cpp"
    break;

  case 36:
#line 205 "src/parser.y"
              {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[0].itype));
        (yyval.exprtype) = new ConstExpr(se);
    }
#line 1796 "src/parser.cpp"
    break;

  case 37:
#line 209 "src/parser.y"
               {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::floatType, (yyvsp[0].ftype));
        (yyval.exprtype) = new ConstExpr(se);
    }
#line 1805 "src/parser.cpp"
    break;

  case 38:
#line 216 "src/parser.y"
                 {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1811 "src/parser.cpp"
    break;

  case 39:
#line 217 "src/parser.y"
                                   {
        //printf("[Unaray]\n");
        SymbolEntry* se;
        se = identifiers->lookup((yyvsp[-3].strtype));
        if(se == nullptr)
            fprintf(stderr, "[ERROR] Function \"%s\" is undefined\n", (char*)(yyvsp[-3].strtype));
        (yyval.exprtype) = new CallExpr(se, (yyvsp[-1].exprtype));
        //printf("[INFO] callexpr\n");
    }
#line 1825 "src/parser.cpp"
    break;

  case 40:
#line 226 "src/parser.y"
                       {
        SymbolEntry* se;
        se = identifiers->lookup((yyvsp[-2].strtype));
        if(se == nullptr)
            fprintf(stderr, "[ERROR] Function \"%s\" is undefined\n", (char*)(yyvsp[-2].strtype));
        (yyval.exprtype) = new CallExpr(se);
    }
#line 1837 "src/parser.cpp"
    break;

  case 41:
#line 233 "src/parser.y"
                   {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1843 "src/parser.cpp"
    break;

  case 42:
#line 234 "src/parser.y"
                   {
        SymbolEntry* se;
        if((yyvsp[0].exprtype)->getType()->isInt())
            se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        else if((yyvsp[0].exprtype)->getType()->isFloat())
            se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
        else 
            fprintf(stderr, "[ERROR] Something wrong in parser.y SUB UnaryExp!\n");
        (yyval.exprtype) = new UnaryExpr(se, OP_SUB, (yyvsp[0].exprtype));
    }
#line 1858 "src/parser.cpp"
    break;

  case 43:
#line 244 "src/parser.y"
                   {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, OP_NOT, (yyvsp[0].exprtype));
    }
#line 1867 "src/parser.cpp"
    break;

  case 44:
#line 251 "src/parser.y"
               {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1873 "src/parser.cpp"
    break;

  case 45:
#line 252 "src/parser.y"
                          {
        Type* temp1 = (yyvsp[-2].exprtype)->getType();
        Type* temp2 = (yyvsp[0].exprtype)->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
            (yyval.exprtype) = new BinaryExpr(se, OP_MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            (yyval.exprtype) = new BinaryExpr(se, OP_MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        }
    }
#line 1889 "src/parser.cpp"
    break;

  case 46:
#line 263 "src/parser.y"
                          {
        Type* temp1 = (yyvsp[-2].exprtype)->getType();
        Type* temp2 = (yyvsp[0].exprtype)->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
            (yyval.exprtype) = new BinaryExpr(se, OP_DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            (yyval.exprtype) = new BinaryExpr(se, OP_DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        }
    }
#line 1905 "src/parser.cpp"
    break;

  case 47:
#line 274 "src/parser.y"
                          {
        Type* temp1 = (yyvsp[-2].exprtype)->getType();
        Type* temp2 = (yyvsp[0].exprtype)->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            fprintf(stderr, "[ERROR] Module operator can't be float!\n");
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            (yyval.exprtype) = new BinaryExpr(se, OP_MOD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        }
    }
#line 1920 "src/parser.cpp"
    break;

  case 48:
#line 287 "src/parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1926 "src/parser.cpp"
    break;

  case 49:
#line 288 "src/parser.y"
                        {
        Type* temp1 = (yyvsp[-2].exprtype)->getType();
        Type* temp2 = (yyvsp[0].exprtype)->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
            (yyval.exprtype) = new BinaryExpr(se, OP_ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            (yyval.exprtype) = new BinaryExpr(se, OP_ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        }
    }
#line 1942 "src/parser.cpp"
    break;

  case 50:
#line 299 "src/parser.y"
                        {
        Type* temp1 = (yyvsp[-2].exprtype)->getType();
        Type* temp2 = (yyvsp[0].exprtype)->getType();
        if(temp1->isFloat() || temp2->isFloat()){
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::floatType, SymbolTable::getLabel());
            (yyval.exprtype) = new BinaryExpr(se, OP_SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        }else{
            SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
            (yyval.exprtype) = new BinaryExpr(se, OP_SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
        }
    }
#line 1958 "src/parser.cpp"
    break;

  case 51:
#line 313 "src/parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1964 "src/parser.cpp"
    break;

  case 52:
#line 314 "src/parser.y"
                         {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, OP_LESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1973 "src/parser.cpp"
    break;

  case 53:
#line 318 "src/parser.y"
                           {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, OP_LESSEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1982 "src/parser.cpp"
    break;

  case 54:
#line 322 "src/parser.y"
                            {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, OP_GREATER, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1991 "src/parser.cpp"
    break;

  case 55:
#line 326 "src/parser.y"
                              {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, OP_GREATEREQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2000 "src/parser.cpp"
    break;

  case 56:
#line 333 "src/parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2006 "src/parser.cpp"
    break;

  case 57:
#line 334 "src/parser.y"
                         {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, OP_EQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2015 "src/parser.cpp"
    break;

  case 58:
#line 338 "src/parser.y"
                            {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, OP_NOTEQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2024 "src/parser.cpp"
    break;

  case 59:
#line 345 "src/parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2030 "src/parser.cpp"
    break;

  case 60:
#line 346 "src/parser.y"
                        {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, OP_AND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2039 "src/parser.cpp"
    break;

  case 61:
#line 353 "src/parser.y"
              {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2045 "src/parser.cpp"
    break;

  case 62:
#line 354 "src/parser.y"
                        {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, OP_OR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 2054 "src/parser.cpp"
    break;

  case 63:
#line 361 "src/parser.y"
             {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2060 "src/parser.cpp"
    break;

  case 64:
#line 365 "src/parser.y"
          {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 2066 "src/parser.cpp"
    break;

  case 65:
#line 366 "src/parser.y"
                            {
        (yyval.exprtype) = (yyvsp[-2].exprtype);
        (yyval.exprtype)->setNextNode((yyvsp[0].exprtype));
    }
#line 2075 "src/parser.cpp"
    break;

  case 66:
#line 372 "src/parser.y"
          {
        (yyval.type) = TypeSystem::intType;
        tempType = "int";
    }
#line 2084 "src/parser.cpp"
    break;

  case 67:
#line 376 "src/parser.y"
           {
        (yyval.type) = TypeSystem::voidType;
        tempType = "void";
    }
#line 2093 "src/parser.cpp"
    break;

  case 68:
#line 380 "src/parser.y"
            {
        (yyval.type) = TypeSystem::floatType;
        tempType = "float";
    }
#line 2102 "src/parser.cpp"
    break;

  case 69:
#line 387 "src/parser.y"
                  {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 2108 "src/parser.cpp"
    break;

  case 70:
#line 388 "src/parser.y"
                    {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 2114 "src/parser.cpp"
    break;

  case 71:
#line 391 "src/parser.y"
                                {(yyval.stmttype) = (yyvsp[-1].stmttype);}
#line 2120 "src/parser.cpp"
    break;

  case 72:
#line 394 "src/parser.y"
                                        {
        (yyval.stmttype) = (yyvsp[-1].stmttype);
    }
#line 2128 "src/parser.cpp"
    break;

  case 73:
#line 400 "src/parser.y"
                              {
        (yyval.stmttype) = (yyvsp[-2].stmttype);
        (yyvsp[-2].stmttype)->setNextNode((yyvsp[0].stmttype));
    }
#line 2137 "src/parser.cpp"
    break;

  case 74:
#line 404 "src/parser.y"
             {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 2143 "src/parser.cpp"
    break;

  case 75:
#line 408 "src/parser.y"
                                  {
        (yyval.stmttype) = (yyvsp[-2].stmttype);
        (yyvsp[-2].stmttype)->setNextNode((yyvsp[0].stmttype));
    }
#line 2152 "src/parser.cpp"
    break;

  case 76:
#line 412 "src/parser.y"
               {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 2158 "src/parser.cpp"
    break;

  case 77:
#line 415 "src/parser.y"
         {
        SymbolEntry* se;
        if(tempType=="int")
            se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[0].strtype), identifiers->getLevel());
        else if(tempType=="float")
            se = new IdentifierSymbolEntry(TypeSystem::floatType, (yyvsp[0].strtype), identifiers->getLevel());
        if(!identifiers->install((yyvsp[0].strtype), se))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)(yyvsp[0].strtype));
        (yyval.stmttype) = new DeclStmt(new IdExpr(se));
        delete [](yyvsp[0].strtype);
    }
#line 2174 "src/parser.cpp"
    break;

  case 78:
#line 426 "src/parser.y"
                      {
        SymbolEntry* se;
        if(tempType == "int"){
            std::vector<int> intVec;
            ExprNode* tempNode = (yyvsp[0].exprtype);  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [8]
                intVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::intType;
            Type* temp;
            while(!intVec.empty()){
                temp = new ArrayType(type, intVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                intVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, (yyvsp[-1].strtype), identifiers->getLevel());
            intArrayValue = new int[arrayType->getSize()];
            ((IdentifierSymbolEntry*)se)->setIntArrayValue(intArrayValue);
            if(!identifiers->install((yyvsp[-1].strtype), se))
                fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)(yyvsp[-1].strtype));
            (yyval.stmttype) = new DeclStmt(new IdExpr(se));
            delete [](yyvsp[-1].strtype);
        }
        else if(tempType=="float"){
            std::vector<float> floatVec;
            ExprNode* tempNode = (yyvsp[0].exprtype);  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [7]
                floatVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::floatType;
            Type* temp;
            while(!floatVec.empty()){
                temp = new ArrayType(type, floatVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                floatVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, (yyvsp[-1].strtype), identifiers->getLevel());
            floatArrayValue = new float[arrayType->getSize()];
            ((IdentifierSymbolEntry*)se)->setFloatArrayValue(floatArrayValue);
            if(!identifiers->install((yyvsp[-1].strtype), se))
                fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)(yyvsp[-1].strtype));
            (yyval.stmttype) = new DeclStmt(new IdExpr(se));
            delete [](yyvsp[-1].strtype);
        }
    }
#line 2234 "src/parser.cpp"
    break;

  case 79:
#line 481 "src/parser.y"
                        {
        //printf("[INFO] assign1\n");
        SymbolEntry* se;
        if(tempType=="int")
            se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        else if(tempType=="float")
            se = new IdentifierSymbolEntry(TypeSystem::floatType, (yyvsp[-2].strtype), identifiers->getLevel());
        if(!identifiers->install((yyvsp[-2].strtype), se))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)(yyvsp[-2].strtype));
        if(tempType=="int")
            ((IdentifierSymbolEntry*)se)->setIntValue((yyvsp[0].exprtype)->getIntValue());
        else if(tempType=="float"){
            ((IdentifierSymbolEntry*)se)->setFloatValue((yyvsp[0].exprtype)->getFloatValue());
        }
        (yyval.stmttype) = new DeclStmt(new IdExpr(se), (yyvsp[0].exprtype));
        delete [](yyvsp[-2].strtype);
    }
#line 2256 "src/parser.cpp"
    break;

  case 80:
#line 498 "src/parser.y"
                             {
        SymbolEntry* se;
        if(tempType == "int"){
            std::vector<int> intVec;
            ExprNode* tempNode = (yyvsp[-1].exprtype);  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [7]
                intVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::intType;
            Type* temp;
            while(!intVec.empty()){
                temp = new ArrayType(type, intVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                intVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, (yyvsp[-2].strtype), identifiers->getLevel());
            intArrayValue = new int[arrayType->getSize()];
        }
        else if(tempType=="float"){
            std::vector<float> floatVec;
            ExprNode* tempNode = (yyvsp[-1].exprtype);  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [8]
                floatVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::floatType;
            Type* temp;
            while(!floatVec.empty()){
                temp = new ArrayType(type, floatVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                floatVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, (yyvsp[-2].strtype), identifiers->getLevel());
            floatArrayValue = new float[arrayType->getSize()];
        }
        idx = 0;
        std::stack<InitValueListExpr*>().swap(initStack);
        (yyval.se) = se;
    }
#line 2309 "src/parser.cpp"
    break;

  case 81:
#line 546 "src/parser.y"
              {
        if(tempType=="int"){
            ((IdentifierSymbolEntry*)(yyvsp[-1].se))->setIntArrayValue(intArrayValue);
            if(!identifiers->install((yyvsp[-4].strtype), (yyvsp[-1].se)))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)(yyvsp[-4].strtype));
            (yyval.stmttype) = new DeclStmt(new IdExpr((yyvsp[-1].se)), (yyvsp[0].exprtype));
        }else if(tempType=="float"){
            ((IdentifierSymbolEntry*)(yyvsp[-1].se))->setFloatArrayValue(floatArrayValue);
            if(!identifiers->install((yyvsp[-4].strtype), (yyvsp[-1].se)))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)(yyvsp[-4].strtype));
            (yyval.stmttype) = new DeclStmt(new IdExpr((yyvsp[-1].se)), (yyvsp[0].exprtype));
        }
        delete [](yyvsp[-4].strtype);
    }
#line 2328 "src/parser.cpp"
    break;

  case 82:
#line 562 "src/parser.y"
                             {
        SymbolEntry* se;
        if(tempType=="int")
            se = new IdentifierSymbolEntry(TypeSystem::constIntType, (yyvsp[-2].strtype), identifiers->getLevel());
        else if(tempType=="float")
            se = new IdentifierSymbolEntry(TypeSystem::constFloatType, (yyvsp[-2].strtype), identifiers->getLevel());
        if(!identifiers->install((yyvsp[-2].strtype), se))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)(yyvsp[-2].strtype));
        if(tempType=="int")
            ((IdentifierSymbolEntry*)se)->setIntValue((yyvsp[0].exprtype)->getIntValue());
        else if(tempType=="float")
            ((IdentifierSymbolEntry*)se)->setFloatValue((yyvsp[0].exprtype)->getFloatValue());
        (yyval.stmttype) = new DeclStmt(new IdExpr(se), (yyvsp[0].exprtype));
        delete [](yyvsp[-2].strtype);
    }
#line 2348 "src/parser.cpp"
    break;

  case 83:
#line 577 "src/parser.y"
                             {
        SymbolEntry* se;
        if(tempType == "int"){
            std::vector<int> intVec;
            ExprNode* tempNode = (yyvsp[-1].exprtype);  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [7]
                intVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::constIntType;
            Type* temp;
            while(!intVec.empty()){
                temp = new ArrayType(type, intVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                intVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, (yyvsp[-2].strtype), identifiers->getLevel());
            intArrayValue = new int[arrayType->getSize()];
        }
        else if(tempType=="float"){
            std::vector<float> floatVec;
            ExprNode* tempNode = (yyvsp[-1].exprtype);  //get the idx
            while(tempNode){
                // int a[6][7][8] => [6] -> [7] -> [7]
                floatVec.push_back(tempNode->getIntValue());
                tempNode = (ExprNode*)(tempNode->getNextNode());
            }
            Type* type = TypeSystem::constFloatType;
            Type* temp;
            while(!floatVec.empty()){
                temp = new ArrayType(type, floatVec.back());
                if(type->isArray())
                    ((ArrayType*)type)->setArrayType(temp);
                type = temp;
                floatVec.pop_back();
            }
            arrayType = (ArrayType*)type;
            se = new IdentifierSymbolEntry(type, (yyvsp[-2].strtype), identifiers->getLevel());
            floatArrayValue = new float[arrayType->getSize()];
        }
        idx = 0;
        std::stack<InitValueListExpr*>().swap(initStack);
        (yyval.se) = se;
    }
#line 2401 "src/parser.cpp"
    break;

  case 84:
#line 625 "src/parser.y"
                   {
        if(tempType=="int"){
            ((IdentifierSymbolEntry*)(yyvsp[-1].se))->setIntArrayValue(intArrayValue);
            if(!identifiers->install((yyvsp[-4].strtype), (yyvsp[-1].se)))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)(yyvsp[-4].strtype));
            (yyval.stmttype) = new DeclStmt(new IdExpr((yyvsp[-1].se)), (yyvsp[0].exprtype));
        }else if(tempType=="float"){
            ((IdentifierSymbolEntry*)(yyvsp[-1].se))->setFloatArrayValue(floatArrayValue);
            if(!identifiers->install((yyvsp[-4].strtype), (yyvsp[-1].se)))
            fprintf(stderr, "[ERROR] Identifier \"%s\" is already defined!\n", (char*)(yyvsp[-4].strtype));
            (yyval.stmttype) = new DeclStmt(new IdExpr((yyvsp[-1].se)), (yyvsp[0].exprtype));
        }
        delete [](yyvsp[-4].strtype);
    }
#line 2420 "src/parser.cpp"
    break;

  case 85:
#line 641 "src/parser.y"
                                 {
        (yyval.exprtype) = (yyvsp[-1].exprtype);
    }
#line 2428 "src/parser.cpp"
    break;

  case 86:
#line 644 "src/parser.y"
                                              {
        (yyval.exprtype) = (yyvsp[-3].exprtype);
        (yyvsp[-3].exprtype)->setNextNode((yyvsp[-1].exprtype));
    }
#line 2437 "src/parser.cpp"
    break;

  case 87:
#line 650 "src/parser.y"
          {
        /*
        int a = 1.1；不报错，但是这里设置为报错因为是高精度转低精度
        float b = 1； 不报错
        int c[3] = {1.1,1.2,1.3}; 报错
        float d[3] = {1,2,3}; 不报错
        */
        //printf("[InitVal]\n");
        if(tempType=="int"){
            //printf("[INFO] %s\n",((IdExpr*)$1)->getType()->toStr().c_str());
            //printf("[INFO] %s\n",$1->getSymbolEntry()->getType()->toStr().c_str());
            if(!(yyvsp[0].exprtype)->getType()->isInt())
                fprintf(stderr,"[ERROR] Cannot initialize a variable of type \'int\' with a value of type \'%s\'\n",(yyvsp[0].exprtype)->getType()->toStr().c_str());
        }else if(tempType=="float") {
            if(!(yyvsp[0].exprtype)->getType()->isNum()) {
                fprintf(stderr,"[ERROR] Cannot initialize a variable of type \'int\' or \'float\' with a value of type \'%s\'\n",(yyvsp[0].exprtype)->getSymbolEntry()->getType()->toStr().c_str());
            }
        }
        (yyval.exprtype) = (yyvsp[0].exprtype);
        //printf("[InitVal]1\n");
        if(!initStack.empty()){
            if(tempType=="int"){
                intArrayValue[idx++] = (yyvsp[0].exprtype)->getIntValue();
            }else if(tempType=="float"){
                floatArrayValue[idx++] = (yyvsp[0].exprtype)->getFloatValue();
            }
            Type* arrTy = initStack.top()->getSymbolEntry()->getType();
            if(arrTy->isNum())
                initStack.top()->addExpr((yyvsp[0].exprtype));
            else
                while(arrTy){
                    if(((ArrayType*)arrTy)->getElementType() != TypeSystem::intType && ((ArrayType*)arrTy)->getElementType() != TypeSystem::floatType){
                        arrTy = ((ArrayType*)arrTy)->getElementType();
                        SymbolEntry* se = new ConstantSymbolEntry(arrTy);
                        InitValueListExpr* list = new InitValueListExpr(se);
                        initStack.top()->addExpr(list);
                        initStack.push(list);
                    }else{
                        initStack.top()->addExpr((yyvsp[0].exprtype));
                        while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                            arrTy = ((ArrayType*)arrTy)->getArrayType();
                            initStack.pop();
                        }
                        break;
                    }
                }
        }
        //printf("[InitVal]2\n");         
    }
#line 2491 "src/parser.cpp"
    break;

  case 88:
#line 699 "src/parser.y"
                    {
        SymbolEntry* se;
        ExprNode* list;
        if(tempType=="int")
        {
            if(initStack.empty()){
                // 如果只用一个{}初始化数组，那么栈一定为空
                memset(intArrayValue, 0, arrayType->getSize());
                idx += arrayType->getSize() / TypeSystem::intType->getSize(); //here int.size == float.size
                se = new ConstantSymbolEntry(arrayType);
                list = new InitValueListExpr(se);
            }else{
                Type* type = ((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType();
                int len = type->getSize() / TypeSystem::intType->getSize();
                memset(intArrayValue + idx, 0, type->getSize());
                idx += len;
                se = new ConstantSymbolEntry(type);
                list = new InitValueListExpr(se);
                initStack.top()->addExpr(list);
                while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                    initStack.pop();
                }
            }
        }else if(tempType=="float")
        {
            if(initStack.empty()){
                // 如果只用一个{}初始化数组，那么栈一定为空
                memset(floatArrayValue, 0, arrayType->getSize());
                idx += arrayType->getSize() / TypeSystem::intType->getSize(); //here int.size == float.size
                se = new ConstantSymbolEntry(arrayType);
                list = new InitValueListExpr(se);
            }else{
                Type* type = ((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType();
                int len = type->getSize() / TypeSystem::intType->getSize();
                memset(floatArrayValue + idx, 0, type->getSize());
                idx += len;
                se = new ConstantSymbolEntry(type);
                list = new InitValueListExpr(se);
                initStack.top()->addExpr(list);
                while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                    initStack.pop();
                }
            }
        }
        
        (yyval.exprtype) = list;
    }
#line 2543 "src/parser.cpp"
    break;

  case 89:
#line 746 "src/parser.y"
             {
        SymbolEntry* se;
        if(!initStack.empty())
            arrayType = (ArrayType*)(((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType());
        se = new ConstantSymbolEntry(arrayType);
        if(arrayType->getElementType() != TypeSystem::intType && arrayType->getElementType() != TypeSystem::floatType){
            arrayType = (ArrayType*)(arrayType->getElementType());
        }
        InitValueListExpr* expr = new InitValueListExpr(se);
        if(!initStack.empty())
            initStack.top()->addExpr(expr);
        initStack.push(expr);
        (yyval.exprtype) = expr;
        leftCnt++;
    }
#line 2563 "src/parser.cpp"
    break;

  case 90:
#line 761 "src/parser.y"
                         {
        leftCnt--;
        while(initStack.top() != (yyvsp[-2].exprtype) && initStack.size() > (long unsigned int)(leftCnt + 1))
            initStack.pop();
        if(initStack.top() == (yyvsp[-2].exprtype))
            initStack.pop();
        (yyval.exprtype) = (yyvsp[-2].exprtype);
        if(!initStack.empty())
            while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                initStack.pop();
            }
        while(idx % (((ArrayType*)((yyval.exprtype)->getSymbolEntry()->getType()))->getSize()/ sizeof(int)) !=0 ){
            if(tempType=="int")
                intArrayValue[idx++] = 0;
            else if(tempType=="float")
                floatArrayValue[idx++] = 0;
        }
            
        if(!initStack.empty())
            arrayType = (ArrayType*)(((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType());
    }
#line 2589 "src/parser.cpp"
    break;

  case 91:
#line 785 "src/parser.y"
               {
        if(tempType=="int"){
            if(!(yyvsp[0].exprtype)->getType()->isInt())
                fprintf(stderr,"[ERROR] Cannot initialize a variable of type \'int\' or \'float\' with a value of type \'%s\'\n",(yyvsp[0].exprtype)->getSymbolEntry()->getType()->toStr().c_str());
        }else if(tempType=="float") {
            if(!(yyvsp[0].exprtype)->getType()->isNum()) {
                fprintf(stderr,"[ERROR] Cannot initialize a variable of type \'int\' or \'float\' with a value of type \'%s\'\n",(yyvsp[0].exprtype)->getSymbolEntry()->getType()->toStr().c_str());
            }
        }
        (yyval.exprtype) = (yyvsp[0].exprtype);
        if(!initStack.empty()){
            if(tempType=="int"){
                intArrayValue[idx++] = (yyvsp[0].exprtype)->getIntValue();
            }else if(tempType=="float"){
                floatArrayValue[idx++] = (yyvsp[0].exprtype)->getFloatValue();
            }
            Type* arrTy = initStack.top()->getSymbolEntry()->getType();
            if(arrTy == TypeSystem::constIntType||arrTy == TypeSystem::constFloatType)
                initStack.top()->addExpr((yyvsp[0].exprtype));
            else
                while(arrTy){
                    if(((ArrayType*)arrTy)->getElementType() != TypeSystem::constIntType&&((ArrayType*)arrTy)->getElementType() != TypeSystem::constFloatType){
                        arrTy = ((ArrayType*)arrTy)->getElementType();
                        SymbolEntry* se = new ConstantSymbolEntry(arrTy);
                        InitValueListExpr* list = new InitValueListExpr(se);
                        initStack.top()->addExpr(list);
                        initStack.push(list);
                    }else{
                        initStack.top()->addExpr((yyvsp[0].exprtype));
                        while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                            arrTy = ((ArrayType*)arrTy)->getArrayType();
                            initStack.pop();
                        }
                        break;
                    }
                }
        }
    }
#line 2632 "src/parser.cpp"
    break;

  case 92:
#line 823 "src/parser.y"
                    {
        SymbolEntry* se;
        ExprNode* list;
        if(tempType=="int"){
            if(initStack.empty()){
                memset(intArrayValue, 0, arrayType->getSize());
                idx += arrayType->getSize() / TypeSystem::constIntType->getSize();
                se = new ConstantSymbolEntry(arrayType);
                list = new InitValueListExpr(se);
            }else{
                Type* type = ((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType();
                int len = type->getSize() / TypeSystem::constIntType->getSize();
                memset(intArrayValue + idx, 0, type->getSize());
                idx += len;
                se = new ConstantSymbolEntry(type);
                list = new InitValueListExpr(se);
                initStack.top()->addExpr(list);
                while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                    initStack.pop();
                }
            }
        }else if(tempType=="float"){
            if(initStack.empty()){
                memset(floatArrayValue, 0, arrayType->getSize());
                idx += arrayType->getSize() / TypeSystem::constIntType->getSize();
                se = new ConstantSymbolEntry(arrayType);
                list = new InitValueListExpr(se);
            }else{
                Type* type = ((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType();
                int len = type->getSize() / TypeSystem::constIntType->getSize();
                memset(floatArrayValue + idx, 0, type->getSize());
                idx += len;
                se = new ConstantSymbolEntry(type);
                list = new InitValueListExpr(se);
                initStack.top()->addExpr(list);
                while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                    initStack.pop();
                }
            }
        }
        
        (yyval.exprtype) = list;
    }
#line 2680 "src/parser.cpp"
    break;

  case 93:
#line 866 "src/parser.y"
             {
        SymbolEntry* se;
        if(!initStack.empty())
            arrayType = (ArrayType*)(((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType());
        se = new ConstantSymbolEntry(arrayType);
        if(arrayType->getElementType() != TypeSystem::intType && arrayType->getElementType() != TypeSystem::floatType){
            arrayType = (ArrayType*)(arrayType->getElementType());
        }
        InitValueListExpr* expr = new InitValueListExpr(se);
        if(!initStack.empty())
            initStack.top()->addExpr(expr);
        initStack.push(expr);
        (yyval.exprtype) = expr;
        leftCnt++;
    }
#line 2700 "src/parser.cpp"
    break;

  case 94:
#line 881 "src/parser.y"
                              {
        leftCnt--;
        while(initStack.top() != (yyvsp[-2].exprtype) && initStack.size() > (long unsigned int)(leftCnt + 1))
            initStack.pop();
        if(initStack.top() == (yyvsp[-2].exprtype))
            initStack.pop();
        (yyval.exprtype) = (yyvsp[-2].exprtype);
        if(!initStack.empty())
            while(initStack.top()->isFull() && initStack.size() != (long unsigned int)leftCnt){
                initStack.pop();
            }
        while(idx % (((ArrayType*)((yyval.exprtype)->getSymbolEntry()->getType()))->getSize()/ sizeof(int)) !=0 ){
            if(tempType=="int")
                intArrayValue[idx++] = 0;
            else if(tempType=="float")
                floatArrayValue[idx++] = 0;
        }
        if(!initStack.empty())
            arrayType = (ArrayType*)(((ArrayType*)(initStack.top()->getSymbolEntry()->getType()))->getElementType());
    }
#line 2725 "src/parser.cpp"
    break;

  case 95:
#line 903 "src/parser.y"
              {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 2733 "src/parser.cpp"
    break;

  case 96:
#line 906 "src/parser.y"
                                {
        (yyval.exprtype) = (yyvsp[-2].exprtype);
    }
#line 2741 "src/parser.cpp"
    break;

  case 97:
#line 911 "src/parser.y"
                   {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 2749 "src/parser.cpp"
    break;

  case 98:
#line 914 "src/parser.y"
                                          {
        (yyval.exprtype) = (yyvsp[-2].exprtype);
    }
#line 2757 "src/parser.cpp"
    break;

  case 99:
#line 920 "src/parser.y"
            {
        identifiers = new SymbolTable(identifiers);
    }
#line 2765 "src/parser.cpp"
    break;

  case 100:
#line 923 "src/parser.y"
                                   {
        Type* funcType;
        std::vector<Type*> vecType;
        std::vector<SymbolEntry*> vecSe;
        DeclStmt* temp = (DeclStmt*)(yyvsp[-1].stmttype);
        while(temp){
            vecType.push_back(temp->getId()->getSymbolEntry()->getType());
            vecSe.push_back(temp->getId()->getSymbolEntry());
            temp = (DeclStmt*)(temp->getNextNode());
        }
        funcType = new FuncType((yyvsp[-5].type), vecType, vecSe);
        SymbolEntry* se = new IdentifierSymbolEntry(funcType, (yyvsp[-4].strtype), identifiers->getPrev()->getLevel());
        if(!identifiers->getPrev()->install((yyvsp[-4].strtype), se))
            fprintf(stderr, "[ERROR] Redifinition of \'%s %s\'\n",se->getType()->toStr().c_str(), (yyvsp[-4].strtype));
        (yyval.se) = se;
        //printf("[INFO] funcdef\n");
    }
#line 2787 "src/parser.cpp"
    break;

  case 101:
#line 940 "src/parser.y"
              {
        (yyval.stmttype) = new FunDefStmt((yyvsp[-1].se), (DeclStmt*)(yyvsp[-3].stmttype), (yyvsp[0].stmttype));
        SymbolTable* top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete [](yyvsp[-6].strtype);
    }
#line 2799 "src/parser.cpp"
    break;

  case 102:
#line 949 "src/parser.y"
                  {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 2805 "src/parser.cpp"
    break;

  case 103:
#line 950 "src/parser.y"
             {(yyval.stmttype) = nullptr;}
#line 2811 "src/parser.cpp"
    break;

  case 104:
#line 952 "src/parser.y"
                                   {
        (yyval.stmttype) = (yyvsp[-2].stmttype);
        (yyval.stmttype)->setNextNode((yyvsp[0].stmttype));
    }
#line 2820 "src/parser.cpp"
    break;

  case 105:
#line 956 "src/parser.y"
                 {(yyval.stmttype) = (yyvsp[0].stmttype);}
#line 2826 "src/parser.cpp"
    break;

  case 106:
#line 959 "src/parser.y"
              {
        SymbolEntry* se;
        se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        //here need to set params addr for the IR
        ((IdentifierSymbolEntry*)se)->setLabel();
        ((IdentifierSymbolEntry*)se)->setAddr(new Operand(se));
        (yyval.stmttype) = new DeclStmt(new IdExpr(se));
        delete [](yyvsp[0].strtype);
    }
#line 2841 "src/parser.cpp"
    break;

  case 107:
#line 969 "src/parser.y"
                               {
        // 这里也需要求值
        SymbolEntry* se;
        ExprNode* temp = (yyvsp[0].exprtype);
        Type* arr = TypeSystem::intType;
        std::stack<ExprNode*> stk;
        while(temp){
            stk.push(temp);
            temp = (ExprNode*)(temp->getNextNode());
        }
        while(!stk.empty()){
            arr = new ArrayType(arr, stk.top()->getIntValue());
            stk.pop();
        }
        se = new IdentifierSymbolEntry(arr, (yyvsp[-1].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-1].strtype), se);
        //here need to set params addr for the IR
        ((IdentifierSymbolEntry*)se)->setLabel();
        ((IdentifierSymbolEntry*)se)->setAddr(new Operand(se));
        (yyval.stmttype) = new DeclStmt(new IdExpr(se));
        delete [](yyvsp[-1].strtype);
    }
#line 2868 "src/parser.cpp"
    break;

  case 108:
#line 994 "src/parser.y"
                        {
        (yyval.exprtype) = new ExprNode(nullptr);
    }
#line 2876 "src/parser.cpp"
    break;

  case 109:
#line 997 "src/parser.y"
                                             {
        (yyval.exprtype) = (yyvsp[-3].exprtype);
        (yyval.exprtype)->setNextNode((yyvsp[-1].exprtype));
    }
#line 2885 "src/parser.cpp"
    break;


#line 2889 "src/parser.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 1002 "src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
