/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
#define YYBISON_VERSION "3.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"

#include <stdio.h>
#include <stdlib.h>
#include "ASTCreateIndexInfo.h"
#include "ASTCreateInfo.h"
#include "ASTCreator.h"
#include "ASTDeleteInfo.h"
#include "ASTDropIndexInfo.h"
#include "ASTDropTableInfo.h"
#include "ASTExit.h"
#include "ASTInsertInfo.h"
#include "ASTSelectInfo.h"
#include "ASTSetOutput.h"
#include "ASTShowTableInfo.h"
#include "ASTUpdateInfo.h"
#include "ColumnRef.h"
#include "defs.h"
#include "ExprNode.h"
#include "FieldDef.h"
#include "IAST.h"
#include "IASTNeedPlan.h"
#include "IASTNotNeedPlan.h"
#include "SQLParser.h"
#include "SQLParserResult.h"
#include "TableConstraint.h"
#include "TableFrom.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace Parser;
using namespace std;

void yyerror(Parser::SQLParserResult* result, const char *s);

#include "sql.yy.cc"

#line 107 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"

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
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_HOME_TYPHIGH_DESKTOP_OPENSOURCE_TCOLDB_BUILD_SRC_PARSER_SQL_TAB_HH_INCLUDED
# define YY_YY_HOME_TYPHIGH_DESKTOP_OPENSOURCE_TCOLDB_BUILD_SRC_PARSER_SQL_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 44 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"


#include <stdio.h>
#include <stdlib.h>
#include "ASTCreateIndexInfo.h"
#include "ASTCreateInfo.h"
#include "ASTCreator.h"
#include "ASTDeleteInfo.h"
#include "ASTDropIndexInfo.h"
#include "ASTDropTableInfo.h"
#include "ASTExit.h"
#include "ASTInsertInfo.h"
#include "ASTSelectInfo.h"
#include "ASTSetOutput.h"
#include "ASTShowTableInfo.h"
#include "ASTUpdateInfo.h"
#include "ColumnRef.h"
#include "defs.h"
#include "ExprNode.h"
#include "FieldDef.h"
#include "IAST.h"
#include "IASTNeedPlan.h"
#include "IASTNotNeedPlan.h"
#include "SQLParser.h"
#include "SQLParserResult.h"
#include "TableConstraint.h"
#include "TableFrom.h"
#include <iostream>
#include <memory>
#include <vector>


#line 183 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TRUE = 258,
    FALSE = 259,
    NULL_TOKEN = 260,
    MIN = 261,
    MAX = 262,
    SUM = 263,
    AVG = 264,
    COUNT = 265,
    LIKE = 266,
    IS = 267,
    OR = 268,
    AND = 269,
    NOT = 270,
    NEQ = 271,
    GEQ = 272,
    LEQ = 273,
    INTEGER = 274,
    DOUBLE = 275,
    FLOAT = 276,
    CHAR = 277,
    VARCHAR = 278,
    DATE = 279,
    BOOL = 280,
    INTO = 281,
    FROM = 282,
    WHERE = 283,
    VALUES = 284,
    JOIN = 285,
    INNER = 286,
    OUTER = 287,
    LEFT = 288,
    RIGHT = 289,
    FULL = 290,
    ASC = 291,
    DESC = 292,
    ORDER = 293,
    BY = 294,
    IN = 295,
    ON = 296,
    AS = 297,
    DISTINCT = 298,
    GROUP = 299,
    USING = 300,
    INDEX = 301,
    TABLE = 302,
    DATABASE = 303,
    DEFAULT = 304,
    UNIQUE = 305,
    PRIMARY = 306,
    FOREIGN = 307,
    REFERENCES = 308,
    CHECK = 309,
    KEY = 310,
    OUTPUT = 311,
    USE = 312,
    CREATE = 313,
    DROP = 314,
    SELECT = 315,
    INSERT = 316,
    UPDATE = 317,
    DELETE = 318,
    SHOW = 319,
    SET = 320,
    EXIT = 321,
    IDENTIFIER = 322,
    DATE_LITERAL = 323,
    STRING_LITERAL = 324,
    FLOAT_LITERAL = 325,
    INT_LITERAL = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"

//	std::string val_name;
	char *val_s;
	int   val_i;
	float val_f;
	bool  val_b;
	Parser::FieldType_t					field_type;				
	Parser::FieldDef*					field_def;
	Parser::FieldDefList*				field_defs;
	Parser::IAST*						ast;
	Parser::IASTNeedPlan*				ast_plan;
	Parser::IASTNotNeedPlan*			ast_noplan;
	Parser::ColumnRef*					column_ref;
	Parser::ColumnRefList*				column_refs;
	Parser::TableConstraint*			constraint;
	Parser::TableConstraintList*		constraints;
	Parser::ASTCreateInfo*				table_def;
	Parser::ASTDeleteInfo*				delete_info;
	Parser::ASTDropTableInfo*			table_drop;
	Parser::ASTExit*					exit;		
	Parser::ASTInsertInfo*				insert;
	Parser::ASTSelectInfo*				select_info;
	Parser::ASTSetOutput*				set_path;
	Parser::ASTShowTableInfo*			table_show;
	Parser::ASTUpdateInfo*				update_info;
	Parser::TableFrom*					join_info;
	Parser::TableFromList*				join_infos;
	Parser::ExprNode*					expr;
	Parser::ExprNodeList*		 		exprs;

#line 297 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (Parser::SQLParserResult* thisptr);

#endif /* !YY_YY_HOME_TYPHIGH_DESKTOP_OPENSOURCE_TCOLDB_BUILD_SRC_PARSER_SQL_TAB_HH_INCLUDED  */



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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   280

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

#define YYUNDEFTOK  2
#define YYMAXUTOK   326


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
      73,    74,    77,    81,    75,    82,    78,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    72,
      79,    76,    80,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    84,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   162,   162,   165,   166,   169,   170,   171,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   188,   196,
     197,   198,   199,   201,   207,   213,   219,   225,   233,   239,
     247,   254,   263,   271,   274,   281,   285,   291,   296,   304,
     305,   307,   311,   317,   318,   320,   325,   330,   337,   344,
     345,   346,   347,   350,   351,   354,   355,   358,   362,   368,
     375,   385,   390,   397,   402,   409,   413,   420,   424,   428,
     431,   441,   442,   444,   445,   448,   449,   450,   453,   454,
     457,   458,   459,   460,   461,   462,   463,   466,   467,   469,
     470,   471,   472,   473,   474,   475,   478,   484,   487,   493,
     499,   504,   509,   514,   515,   522,   526,   532,   538,   544,
     547,   553,   559,   562,   567,   572,   573,   577,   580,   585,
     590,   595,   602,   603,   606,   610,   616,   622,   623,   626
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TRUE", "FALSE", "NULL_TOKEN", "MIN",
  "MAX", "SUM", "AVG", "COUNT", "LIKE", "IS", "OR", "AND", "NOT", "NEQ",
  "GEQ", "LEQ", "INTEGER", "DOUBLE", "FLOAT", "CHAR", "VARCHAR", "DATE",
  "BOOL", "INTO", "FROM", "WHERE", "VALUES", "JOIN", "INNER", "OUTER",
  "LEFT", "RIGHT", "FULL", "ASC", "DESC", "ORDER", "BY", "IN", "ON", "AS",
  "DISTINCT", "GROUP", "USING", "INDEX", "TABLE", "DATABASE", "DEFAULT",
  "UNIQUE", "PRIMARY", "FOREIGN", "REFERENCES", "CHECK", "KEY", "OUTPUT",
  "USE", "CREATE", "DROP", "SELECT", "INSERT", "UPDATE", "DELETE", "SHOW",
  "SET", "EXIT", "IDENTIFIER", "DATE_LITERAL", "STRING_LITERAL",
  "FLOAT_LITERAL", "INT_LITERAL", "';'", "'('", "')'", "','", "'='", "'*'",
  "'.'", "'<'", "'>'", "'+'", "'-'", "'/'", "'`'", "$accept", "sql_start",
  "sql_stmt", "sql_plan_stmt", "sql_noplan_stmt", "create_table_stmt",
  "create_database_stmt", "use_database_stmt", "drop_database_stmt",
  "show_database_stmt", "drop_table_stmt", "show_table_stmt",
  "insert_stmt", "insert_values", "insert_columns", "delete_stmt",
  "update_stmt", "select_stmt", "exit_stmt", "setpath_stmt", "table_refs",
  "table_item", "select_expr_list_s", "select_expr_list", "select_expr",
  "aggregate_expr", "aggregate_term", "aggregate_op", "where_clause",
  "table_extra_options", "table_extra_option_list", "table_extra_option",
  "column_ref", "column_list", "table_fields", "table_field",
  "default_expr", "field_flags", "field_flag", "field_width", "field_type",
  "logical_op", "compare_op", "condition", "cond_term", "expr_list",
  "expr", "factor", "term", "literal", "BOOL_LITERAL", "literal_list",
  "literal_list_expr", "table_name", "database_name", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,    59,    40,    41,    44,    61,    42,    46,    60,
      62,    43,    45,    47,    96
};
# endif

#define YYPACT_NINF (-140)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     117,   -52,   -10,    45,     3,    -7,   -40,    -5,    55,   -16,
    -140,    42,  -140,  -140,  -140,   -27,   -12,    48,    66,   126,
     127,   128,   129,   130,   131,   132,   134,   136,  -140,  -140,
     -40,   -52,   -40,   -52,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,    -6,    28,    22,  -140,  -140,  -140,  -140,    28,  -140,
      64,    51,   145,     0,  -140,  -140,    54,  -140,   109,  -140,
     146,    59,  -140,  -140,  -140,   138,   -40,  -140,    96,   -40,
     -40,   -52,   135,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,   137,  -140,  -140,
    -140,   -43,  -140,     7,   133,    64,  -140,   121,   -40,    46,
      21,  -140,  -140,    28,  -140,    31,  -140,  -140,  -140,   144,
    -140,  -140,  -140,    64,    64,    64,    64,    64,   151,   190,
     147,    21,   193,  -140,  -140,   154,   157,   155,   156,  -140,
    -140,  -140,    73,  -140,    11,  -140,   189,  -140,   158,  -140,
    -140,   228,   100,    59,    59,    71,  -140,  -140,  -140,   161,
      21,   159,    28,  -140,  -140,   168,   162,  -140,  -140,  -140,
     -40,  -140,   169,  -140,  -140,  -140,   163,   165,    64,   166,
    -140,    91,    64,   109,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,   167,    57,   170,  -140,  -140,   100,  -140,   110,    71,
     172,  -140,    21,    -3,   171,  -140,   173,   188,   192,   175,
     174,  -140,  -140,  -140,  -140,  -140,    64,    64,  -140,  -140,
     176,     8,    21,   178,   179,    28,    89,    71,   120,  -140,
     248,   100,  -140,   199,  -140,  -140,   181,   191,   194,    16,
    -140,  -140,  -140,  -140,  -140,  -140,   182,   183,  -140,  -140,
     206,   195,   187,   196,   197,  -140
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     2,     3,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,    20,
       0,     0,     0,     0,   122,   123,   116,    51,    52,    49,
      50,     0,     0,    63,   120,   121,   119,   118,     0,    40,
       0,     0,     0,    39,    42,    44,     0,   113,    43,    97,
       0,   109,   112,   115,   104,     0,     0,   127,     0,     0,
       0,     0,     0,     1,     8,     9,    10,    12,    11,    14,
      13,    15,     6,     5,     7,    16,    17,     0,    19,    23,
      21,     0,   102,     0,     0,     0,   114,     0,     0,     0,
       0,    88,    87,     0,    95,     0,    94,    93,    92,     0,
      89,    90,    91,     0,     0,     0,     0,     0,     0,     0,
      28,     0,    54,    24,    22,     0,    69,     0,     0,    48,
     103,   117,     0,   128,    54,    36,    37,    41,     0,    96,
     100,     0,     0,   107,   108,    98,   110,   111,    64,     0,
       0,     0,     0,    30,    34,     0,    56,    67,    47,    46,
       0,    32,     0,    45,   101,   125,   126,     0,     0,    25,
      66,     0,     0,    53,    80,    82,    81,    83,    85,    84,
      86,    79,     0,     0,    35,    38,     0,    99,     0,   106,
       0,    29,     0,    54,     0,    74,     0,     0,     0,     0,
      55,    58,    68,    18,   124,    26,     0,     0,    65,    31,
       0,    72,     0,     0,     0,     0,     0,   105,     0,    78,
       0,     0,    76,     0,    70,    73,     0,     0,     0,     0,
      57,    27,    75,    71,    77,    61,     0,     0,    62,    59,
       0,     0,     0,     0,     0,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,   104,  -140,  -140,   177,  -140,   180,  -140,  -130,  -140,
    -140,    49,   -86,  -140,  -140,    84,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,   -48,   -26,    60,   -47,    83,   -33,  -139,
    -140,  -140,  -140,    -4,    58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   169,   119,    23,    24,    25,    26,    27,
     134,   135,    52,    53,    54,    55,   128,    56,   153,   183,
     200,   201,    57,   171,   156,   157,   224,   211,   225,   195,
     181,   103,   115,    58,    59,   188,    60,    61,    62,    63,
      64,   166,   167,    65,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    94,    68,   165,   161,   129,    34,    35,    36,    37,
      38,    39,    40,    41,   129,    28,    92,    96,    42,    66,
     101,   102,    69,   220,    43,   152,    87,    67,    89,   101,
     102,    34,    35,    36,   127,   151,   140,    30,    31,   152,
      72,    51,    73,    42,    51,    74,   141,   204,   132,    34,
      35,    36,    37,    38,    39,    40,    41,   221,   222,   223,
      75,    42,   120,   209,   170,   122,   123,    91,   145,    36,
      43,    44,    45,    46,    47,    99,    48,   139,   113,   114,
      49,   130,   233,   146,   147,    50,   160,    51,    43,    88,
     238,    90,    32,    33,   136,    43,    44,    45,    46,    47,
    -127,    48,    70,    71,   173,    51,   208,   196,   197,   198,
      50,   199,    51,    43,    44,    45,    46,    47,    97,    48,
      76,   189,   101,   102,   155,   193,   226,   100,    50,   124,
      51,    43,    44,    45,    46,    47,   116,    95,    77,   196,
     197,   198,   117,   199,   104,   105,    50,   131,    51,   106,
     107,   108,   113,   114,   113,   114,   136,   104,   105,   217,
     189,   121,   106,   107,   108,   191,   192,   229,    44,    45,
      46,    47,    98,   109,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,   205,   206,   109,   174,   175,   176,
     177,   178,   179,   180,   231,   206,   143,   144,    78,    79,
      80,    81,    82,    83,    84,   133,    85,   131,    86,   110,
     126,   125,   111,   112,   113,   114,   118,   142,   148,   149,
     150,   152,   110,   154,   155,   111,   112,   113,   114,   158,
     159,   162,   163,   164,   168,   172,   185,   182,   186,   187,
     194,   190,   210,   213,   203,   207,   212,   214,   215,   216,
     219,   227,   228,   232,   234,   235,   239,   240,   236,   241,
     243,   237,   242,   244,   184,   230,   202,   218,     0,     0,
       0,   245,     0,     0,     0,     0,   137,     0,     0,     0,
     138
};

static const yytype_int16 yycheck[] =
{
      48,    48,     6,   142,   134,    91,     3,     4,     5,     6,
       7,     8,     9,    10,   100,    67,    42,    50,    15,    26,
      13,    14,    27,    15,    67,    28,    30,    67,    32,    13,
      14,     3,     4,     5,    77,   121,     5,    47,    48,    28,
      56,    84,     0,    15,    84,    72,    15,   186,    95,     3,
       4,     5,     6,     7,     8,     9,    10,    49,    50,    51,
      72,    15,    66,   193,   150,    69,    70,    73,   115,     5,
      67,    68,    69,    70,    71,    75,    73,   103,    81,    82,
      77,    74,   221,   116,   117,    82,    75,    84,    67,    31,
      74,    33,    47,    48,    98,    67,    68,    69,    70,    71,
      78,    73,    47,    48,   152,    84,   192,    50,    51,    52,
      82,    54,    84,    67,    68,    69,    70,    71,    67,    73,
      72,   168,    13,    14,    67,   172,   212,    73,    82,    71,
      84,    67,    68,    69,    70,    71,    77,    73,    72,    50,
      51,    52,    83,    54,    11,    12,    82,    74,    84,    16,
      17,    18,    81,    82,    81,    82,   160,    11,    12,   206,
     207,    65,    16,    17,    18,    74,    75,   215,    68,    69,
      70,    71,    27,    40,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    74,    75,    40,    19,    20,    21,
      22,    23,    24,    25,    74,    75,   113,   114,    72,    72,
      72,    72,    72,    72,    72,    84,    72,    74,    72,    76,
      73,    76,    79,    80,    81,    82,    78,    73,    67,    29,
      73,    28,    76,    69,    67,    79,    80,    81,    82,    74,
      74,    42,    74,     5,    73,    76,    67,    75,    75,    74,
      73,    75,    71,    55,    74,    73,    73,    55,    73,    75,
      74,    73,    73,     5,    55,    74,    74,    74,    67,    53,
      73,    67,    67,    67,   160,   216,   182,   207,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
     100
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,   100,   101,   102,   103,   104,    67,   139,
      47,    48,    47,    48,     3,     4,     5,     6,     7,     8,
       9,    10,    15,    67,    68,    69,    70,    71,    73,    77,
      82,    84,   107,   108,   109,   110,   112,   117,   128,   129,
     131,   132,   133,   134,   135,   138,    26,    67,   138,    27,
      47,    48,    56,     0,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,   138,   139,   138,
     139,    73,   129,   128,   131,    73,   133,    67,    27,    75,
      73,    13,    14,   126,    11,    12,    16,    17,    18,    40,
      76,    79,    80,    81,    82,   127,    77,    83,    78,    99,
     138,    65,   138,   138,   139,    76,    73,    77,   111,   117,
      74,    74,   131,    84,   105,   106,   138,   109,   111,   129,
       5,    15,    73,   132,   132,   131,   133,   133,    67,    29,
      73,   117,    28,   113,    69,    67,   119,   120,    74,    74,
      75,   113,    42,    74,     5,   134,   136,   137,    73,    98,
     117,   118,    76,   128,    19,    20,    21,    22,    23,    24,
      25,   125,    75,   114,   106,    67,    75,    74,   130,   131,
      75,    74,    75,   131,    73,   124,    50,    51,    52,    54,
     115,   116,   120,    74,   134,    74,    75,    73,   117,   113,
      71,   122,    73,    55,    55,    73,    75,   131,   130,    74,
      15,    49,    50,    51,   121,   123,   117,    73,    73,   128,
     116,    74,     5,   134,    55,    74,    67,    67,    74,    74,
      74,    53,    67,    73,    67,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    98,    99,    99,
     100,   101,   102,   103,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   109,   110,   110,   110,   111,   112,
     112,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   116,   117,   117,   118,   118,   119,   119,   119,
     120,   121,   121,   122,   122,   123,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   127,
     127,   127,   127,   127,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   130,   130,   131,   131,   131,
     132,   132,   132,   133,   133,   133,   133,   133,   134,   134,
     134,   134,   135,   135,   136,   136,   137,   138,   138,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     7,     3,
       2,     3,     3,     3,     3,     5,     3,     5,     1,     4,
       4,     7,     5,     1,     4,     3,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     4,     4,     4,     1,     1,
       1,     1,     1,     2,     0,     2,     0,     3,     1,     5,
      10,     4,     4,     1,     3,     3,     1,     1,     3,     0,
       5,     2,     0,     2,     0,     2,     1,     2,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     5,
       3,     4,     2,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     1,     1,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1
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
        yyerror (thisptr, YY_("syntax error: cannot back up")); \
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
                  Type, Value, thisptr); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, Parser::SQLParserResult* thisptr)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (thisptr);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, Parser::SQLParserResult* thisptr)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, thisptr);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, Parser::SQLParserResult* thisptr)
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
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , thisptr);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, thisptr); \
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
      int yyn = yypact[*yyssp];
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, Parser::SQLParserResult* thisptr)
{
  YYUSE (yyvaluep);
  YYUSE (thisptr);
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
yyparse (Parser::SQLParserResult* thisptr)
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
#line 162 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                   { thisptr->Set((yyvsp[0].ast));}
#line 1672 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 3:
#line 165 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                { (yyval.ast) = (yyvsp[0].ast_plan);}
#line 1678 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 4:
#line 166 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                { (yyval.ast) = (yyvsp[0].ast_noplan);}
#line 1684 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 5:
#line 169 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                            { (yyval.ast_plan) = (yyvsp[-1].update_info);}
#line 1690 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 6:
#line 170 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                            { (yyval.ast_plan) = (yyvsp[-1].delete_info);}
#line 1696 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 7:
#line 171 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                            { (yyval.ast_plan) = (yyvsp[-1].select_info);}
#line 1702 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 8:
#line 176 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                { (yyval.ast_noplan) = (yyvsp[-1].table_def);}
#line 1708 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 9:
#line 177 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                            {}
#line 1714 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 10:
#line 178 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                {}
#line 1720 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 11:
#line 179 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                {}
#line 1726 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 12:
#line 180 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                {}
#line 1732 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 13:
#line 181 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                { (yyval.ast_noplan) = (yyvsp[-1].table_show);}
#line 1738 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 14:
#line 182 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                { (yyval.ast_noplan) = (yyvsp[-1].table_drop);}
#line 1744 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 15:
#line 183 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                        { (yyval.ast_noplan) = (yyvsp[-1].insert);}
#line 1750 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 16:
#line 184 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                        { (yyval.ast_noplan) = (yyvsp[-1].exit);}
#line 1756 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 17:
#line 185 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                        { (yyval.ast_noplan) = (yyvsp[-1].set_path);}
#line 1762 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 18:
#line 188 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                                     {
				  	(yyval.table_def) = new ASTCreateInfo();
					(yyval.table_def)->name = (yyvsp[-4].val_s);
					(yyval.table_def)->fields = (yyvsp[-2].field_defs);
					(yyval.table_def)->constraints = (yyvsp[-1].constraints);
				  }
#line 1773 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 19:
#line 196 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                       { (yyval.val_s) = (yyvsp[0].val_s); }
#line 1779 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 20:
#line 197 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                       { (yyval.val_s) = (yyvsp[0].val_s); }
#line 1785 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 21:
#line 198 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                       { (yyval.val_s) = (yyvsp[0].val_s); }
#line 1791 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 22:
#line 199 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                       { (yyval.val_s) = (yyvsp[0].val_s); }
#line 1797 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 23:
#line 201 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                       { 
						(yyval.table_drop) = new ASTDropTableInfo();
						(yyval.table_drop)->table = (yyvsp[0].val_s);
					 }
#line 1806 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 24:
#line 207 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                       { 
						(yyval.table_show) = new ASTShowTableInfo();
						(yyval.table_show)->table = (yyvsp[0].val_s); 
					 }
#line 1815 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 25:
#line 213 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                       {
					 	(yyval.insert) = (yyvsp[-2].insert);
						(yyval.insert)->values = (yyvsp[0].exprs);
					 }
#line 1824 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 26:
#line 219 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                         {
					 	(yyval.exprs) = new ExprNodeList ();
						ExprNode* newNode = new ExprNode();
						newNode->literal_list = (yyvsp[-1].exprs);
						(yyval.exprs)->push_back(newNode);
					 }
#line 1835 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 27:
#line 225 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                               {
						ExprNode* newNode = new ExprNode();
						newNode->literal_list = (yyvsp[-1].exprs);
					 	(yyvsp[-4].exprs)->push_back(newNode);
						(yyval.exprs) = (yyvsp[-4].exprs);
					 }
#line 1846 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 28:
#line 233 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                  {
					 	(yyval.insert) = new ASTInsertInfo();
						(yyval.insert)->table   = (yyvsp[0].val_s);
						(yyval.insert)->columns = NULL;
						(yyval.insert)->values  = NULL;
					 }
#line 1857 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 29:
#line 239 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                          {
					 	(yyval.insert) = new ASTInsertInfo();
						(yyval.insert)->table   = (yyvsp[-3].val_s);
						(yyval.insert)->columns = (yyvsp[-1].column_refs);
						(yyval.insert)->values  = NULL;
					 }
#line 1868 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 30:
#line 247 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                          {
					 	(yyval.delete_info) = new ASTDeleteInfo();
						(yyval.delete_info)->table = (yyvsp[-1].val_s);
						(yyval.delete_info)->where = (yyvsp[0].expr);
					}
#line 1878 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 31:
#line 254 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                             {
					 	(yyval.update_info) = new ASTUpdateInfo();
						(yyval.update_info)->table = (yyvsp[-5].val_s);
						(yyval.update_info)->value = (yyvsp[-1].expr);
						(yyval.update_info)->where = (yyvsp[0].expr);
						(yyval.update_info)->column_ref = (yyvsp[-3].column_ref);
					}
#line 1890 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 32:
#line 263 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                             {
					 	(yyval.select_info) = new ASTSelectInfo();
						(yyval.select_info)->tables = (yyvsp[-1].join_infos);
						(yyval.select_info)->exprs  = (yyvsp[-3].exprs);
						(yyval.select_info)->where  = (yyvsp[0].expr);
					}
#line 1901 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 33:
#line 271 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                { (yyval.exit) = new ASTExit(); }
#line 1907 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 34:
#line 274 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                        { 
			   			ASTSetOutput* node = new ASTSetOutput();
			   			node->path = (yyvsp[0].val_s);
			   			(yyval.set_path) = node; 
		   			}
#line 1917 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 35:
#line 281 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                {
						(yyvsp[-2].join_infos)->push_back((yyvsp[0].join_info));
						(yyval.join_infos) = (yyvsp[-2].join_infos);
					}
#line 1926 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 36:
#line 285 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                     {
						(yyval.join_infos) = new TableFromList();
						(yyval.join_infos)->push_back((yyvsp[0].join_info));
					}
#line 1935 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 37:
#line 291 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                 {
					 	(yyval.join_info) = new TableFrom();
						(yyval.join_info)->join_type = TABLE_JOIN_NONE;
						(yyval.join_info)->table = (yyvsp[0].val_s);
					}
#line 1945 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 38:
#line 296 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                               {
					 	(yyval.join_info) = new TableFrom();
						(yyval.join_info)->join_type = TABLE_JOIN_NONE;
						(yyval.join_info)->table = (yyvsp[-2].val_s);
						(yyval.join_info)->alias = (yyvsp[0].val_s);
					}
#line 1956 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 39:
#line 304 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                       { (yyval.exprs) = (yyvsp[0].exprs); }
#line 1962 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 40:
#line 305 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                           { (yyval.exprs) = NULL; }
#line 1968 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 41:
#line 307 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                       {
						(yyvsp[-2].exprs)->push_back((yyvsp[0].expr));
						(yyval.exprs) = (yyvsp[-2].exprs);
					}
#line 1977 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 42:
#line 311 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                      {
						(yyval.exprs) = new ExprNodeList();
						(yyval.exprs)->push_back((yyvsp[0].expr));
					}
#line 1986 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 43:
#line 317 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                      { (yyval.expr) = (yyvsp[0].expr); }
#line 1992 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 44:
#line 318 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1998 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 45:
#line 320 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                          {
						(yyval.expr) = new ExprNode();
						(yyval.expr)->left  = (yyvsp[-1].expr);
						(yyval.expr)->op    = (operator_type_t) (yyvsp[-3].val_i);
					}
#line 2008 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 46:
#line 325 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                       {
						(yyval.expr) = new ExprNode();
						(yyval.expr)->left  = (yyvsp[-1].expr);
						(yyval.expr)->op    = OPERATOR_COUNT;
					}
#line 2018 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 47:
#line 330 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                            {
						(yyval.expr) = new ExprNode();
						(yyval.expr)->left  = NULL;
						(yyval.expr)->op    = OPERATOR_COUNT;
					}
#line 2028 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 48:
#line 337 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                 {
						(yyval.expr) = new ExprNode();
						(yyval.expr)->column_ref = (yyvsp[0].column_ref);
						(yyval.expr)->term_type  = TERM_COLUMN_REF;
					}
#line 2038 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 49:
#line 344 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                            { (yyval.val_i) = OPERATOR_SUM; }
#line 2044 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 50:
#line 345 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                { (yyval.val_i) = OPERATOR_AVG; }
#line 2050 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 51:
#line 346 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                { (yyval.val_i) = OPERATOR_MIN; }
#line 2056 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 52:
#line 347 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                { (yyval.val_i) = OPERATOR_MAX; }
#line 2062 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 53:
#line 350 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                      { (yyval.expr) = (yyvsp[0].expr); }
#line 2068 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 54:
#line 351 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                          { (yyval.expr) = NULL; }
#line 2074 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 55:
#line 354 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                   { (yyval.constraints) = (yyvsp[0].constraints); }
#line 2080 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 56:
#line 355 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                       { (yyval.constraints) = NULL; }
#line 2086 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 57:
#line 358 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                         {
							(yyvsp[-2].constraints)->push_back((yyvsp[0].constraint));
							(yyval.constraints) = (yyvsp[-2].constraints);
						}
#line 2095 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 58:
#line 362 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                     {
							(yyval.constraints) = new vector<TableConstraint*> ();
							(yyval.constraints)->push_back((yyvsp[0].constraint));
						}
#line 2104 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 59:
#line 368 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                    {
					(yyval.constraint) = new TableConstraint();
					(yyval.constraint)->column_ref = (ColumnRef*)malloc(sizeof(ColumnRef));
					(yyval.constraint)->column_ref->table = NULL;
					(yyval.constraint)->column_ref->column = (yyvsp[-1].val_s);
					(yyval.constraint)->type = TABLE_CONSTRAINT_PRIMARY_KEY;
				   }
#line 2116 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 60:
#line 375 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                                                             {
				   	(yyval.constraint) = new TableConstraint();
					(yyval.constraint)->column_ref = (ColumnRef*)malloc(sizeof(ColumnRef));
					(yyval.constraint)->column_ref->table = NULL;
					(yyval.constraint)->column_ref->column = (yyvsp[-6].val_s);
					(yyval.constraint)->foreign_column_ref = (ColumnRef*)malloc(sizeof(ColumnRef));
					(yyval.constraint)->foreign_column_ref->table = (yyvsp[-3].val_s);
					(yyval.constraint)->foreign_column_ref->column = (yyvsp[-1].val_s);
					(yyval.constraint)->type = TABLE_CONSTRAINT_FOREIGN_KEY;
				   }
#line 2131 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 61:
#line 385 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                               {
				   	(yyval.constraint) = new TableConstraint();
					(yyval.constraint)->type = TABLE_CONSTRAINT_UNIQUE;
					(yyval.constraint)->column_ref = (yyvsp[-1].column_ref);
				   }
#line 2141 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 62:
#line 390 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                             {
				   	(yyval.constraint) = new TableConstraint();
					(yyval.constraint)->type = TABLE_CONSTRAINT_CHECK;
					(yyval.constraint)->check_cond = (yyvsp[-1].expr);
				   }
#line 2151 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 63:
#line 397 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          {
				(yyval.column_ref) = new ColumnRef();
				(yyval.column_ref)->table  = NULL;
				(yyval.column_ref)->column = (yyvsp[0].val_s);
			 }
#line 2161 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 64:
#line 402 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                     {
			 	(yyval.column_ref) = new ColumnRef();
				(yyval.column_ref)->table  = (yyvsp[-2].val_s);
				(yyval.column_ref)->column = (yyvsp[0].val_s);
			 }
#line 2171 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 65:
#line 409 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                          {
				(yyvsp[-2].column_refs)->push_back((yyvsp[0].column_ref));
				(yyval.column_refs) = (yyvsp[-2].column_refs);
			 }
#line 2180 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 66:
#line 413 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                      {
			 	(yyval.column_refs) = new ColumnRefList();
				(yyval.column_refs)->push_back((yyvsp[0].column_ref));
			 }
#line 2189 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 67:
#line 420 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                           { 
				(yyval.field_defs) = new vector<FieldDef*>(); 
				(yyval.field_defs)->push_back((yyvsp[0].field_def));
			 }
#line 2198 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 68:
#line 424 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                        { 
				(yyvsp[-2].field_defs)->push_back((yyvsp[0].field_def)); 
				(yyval.field_defs) = (yyvsp[-2].field_defs);
			 }
#line 2207 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 69:
#line 428 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                           {(yyval.field_defs) = NULL;}
#line 2213 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 70:
#line 431 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                                          {
			 	(yyval.field_def) = new FieldDef();
				(yyval.field_def)->name = (yyvsp[-4].val_s);
				(yyval.field_def)->type = (yyvsp[-3].field_type);
				(yyval.field_def)->width = (yyvsp[-2].val_i);
				(yyval.field_def)->flags = (yyvsp[-1].val_i);
				(yyval.field_def)->default_value = (yyvsp[0].expr);
			 }
#line 2226 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 71:
#line 441 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                               { (yyval.expr) = (yyvsp[0].expr); }
#line 2232 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 72:
#line 442 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                           { (yyval.expr) = NULL; }
#line 2238 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 73:
#line 444 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                      { (yyval.val_i) = (yyvsp[-1].val_i) | (yyvsp[0].val_i); }
#line 2244 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 74:
#line 445 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                  { (yyval.val_i) = 0; }
#line 2250 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 75:
#line 448 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                              { (yyval.val_i) = FIELD_FLAG_NOTNULL; }
#line 2256 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 76:
#line 449 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                          { (yyval.val_i) = FIELD_FLAG_UNIQUE; }
#line 2262 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 77:
#line 450 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                          { (yyval.val_i) = FIELD_FLAG_PRIMARY; }
#line 2268 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 78:
#line 453 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                   { (yyval.val_i) = (yyvsp[-1].val_i); }
#line 2274 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 79:
#line 454 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                               { (yyval.val_i) = 0; }
#line 2280 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 80:
#line 457 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                      { (yyval.field_type) = FIELD_TYPE_INT; }
#line 2286 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 81:
#line 458 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                              { (yyval.field_type) = FIELD_TYPE_FLOAT; }
#line 2292 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 82:
#line 459 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                              { (yyval.field_type) = FIELD_TYPE_FLOAT; }
#line 2298 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 83:
#line 460 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                              { (yyval.field_type) = FIELD_TYPE_CHAR; }
#line 2304 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 84:
#line 461 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                              { (yyval.field_type) = FIELD_TYPE_DATE; }
#line 2310 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 85:
#line 462 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                              { (yyval.field_type) = FIELD_TYPE_VARCHAR; }
#line 2316 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 86:
#line 463 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                  { (yyval.field_type) = FIELD_TYPE_BOOL; }
#line 2322 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 87:
#line 466 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                  { (yyval.val_i) = OPERATOR_AND; }
#line 2328 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 88:
#line 467 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          { (yyval.val_i) = OPERATOR_OR; }
#line 2334 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 89:
#line 469 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                  { (yyval.val_i) = OPERATOR_EQ; }
#line 2340 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 90:
#line 470 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          { (yyval.val_i) = OPERATOR_LT; }
#line 2346 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 91:
#line 471 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          { (yyval.val_i) = OPERATOR_GT; }
#line 2352 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 92:
#line 472 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          { (yyval.val_i) = OPERATOR_LEQ; }
#line 2358 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 93:
#line 473 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          { (yyval.val_i) = OPERATOR_GEQ; }
#line 2364 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 94:
#line 474 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          { (yyval.val_i) = OPERATOR_NEQ; }
#line 2370 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 95:
#line 475 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          { (yyval.val_i) = OPERATOR_LIKE; }
#line 2376 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 96:
#line 478 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                            {
				(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[-2].expr);
				(yyval.expr)->right = (yyvsp[0].expr);
				(yyval.expr)->op    = (operator_type_t) (yyvsp[-1].val_i);
		   }
#line 2387 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 97:
#line 484 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                               { (yyval.expr) = (yyvsp[0].expr); }
#line 2393 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 98:
#line 487 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                  {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[-2].expr);
				(yyval.expr)->right = (yyvsp[0].expr);
				(yyval.expr)->op    = (operator_type_t) (yyvsp[-1].val_i);
		   }
#line 2404 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 99:
#line 493 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                                       {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[-4].expr);
				(yyval.expr)->right = (yyvsp[-1].expr);
				(yyval.expr)->op    = OPERATOR_IN;
		   }
#line 2415 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 100:
#line 499 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                        {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[-2].expr);
				(yyval.expr)->op    = OPERATOR_ISNULL;
		   }
#line 2425 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 101:
#line 504 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                            {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[-3].expr);
				(yyval.expr)->op    = OPERATOR_NOTNULL;
		   }
#line 2435 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 102:
#line 509 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                   {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[0].expr);
				(yyval.expr)->op    = OPERATOR_NOT;
		   }
#line 2445 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 103:
#line 514 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 2451 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 104:
#line 515 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                  {
			   (yyval.expr) = new ExprNode();
			   (yyval.expr)->val_b	   = (yyvsp[0].val_b);
			   (yyval.expr)->term_type   = TERM_BOOL; 
		   }
#line 2461 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 105:
#line 522 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                {
				(yyvsp[-2].exprs)->push_back((yyvsp[0].expr));
				(yyval.exprs) = (yyvsp[-2].exprs);
		   }
#line 2470 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 106:
#line 526 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          {
				(yyval.exprs) = new ExprNodeList();
				(yyval.exprs)->push_back((yyvsp[0].expr));
		   }
#line 2479 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 107:
#line 532 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                             {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[-2].expr);
				(yyval.expr)->right = (yyvsp[0].expr);
				(yyval.expr)->op    = OPERATOR_ADD;
		   }
#line 2490 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 108:
#line 538 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                     {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[-2].expr);
				(yyval.expr)->right = (yyvsp[0].expr);
				(yyval.expr)->op    = OPERATOR_MINUS;
		   }
#line 2501 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 109:
#line 544 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2507 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 110:
#line 547 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                             {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[-2].expr);
				(yyval.expr)->right = (yyvsp[0].expr);
				(yyval.expr)->op    = OPERATOR_MUL;
		   }
#line 2518 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 111:
#line 553 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                     {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[-2].expr);
				(yyval.expr)->right = (yyvsp[0].expr);
				(yyval.expr)->op    = OPERATOR_DIV;
		   }
#line 2529 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 112:
#line 559 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2535 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 113:
#line 562 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                        {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->column_ref = (yyvsp[0].column_ref);
				(yyval.expr)->term_type  = TERM_COLUMN_REF;
		   }
#line 2545 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 114:
#line 567 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                              {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->left  = (yyvsp[0].expr);
				(yyval.expr)->op    = OPERATOR_NEGATE;
		   }
#line 2555 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 115:
#line 572 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                  { (yyval.expr) = (yyvsp[0].expr); }
#line 2561 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 116:
#line 573 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->term_type  = TERM_NULL;
		   }
#line 2570 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 117:
#line 577 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                  { (yyval.expr) = (yyvsp[-1].expr); }
#line 2576 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 118:
#line 580 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                         {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->val_i      = (yyvsp[0].val_i);
				(yyval.expr)->term_type  = TERM_INT;
		   }
#line 2586 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 119:
#line 585 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                   {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->val_f      = (yyvsp[0].val_f);
				(yyval.expr)->term_type  = TERM_FLOAT;
		   }
#line 2596 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 120:
#line 590 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                  {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->val_s      = (yyvsp[0].val_s);
				(yyval.expr)->term_type  = TERM_DATE;
		   }
#line 2606 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 121:
#line 595 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                    {
		   		(yyval.expr) = new ExprNode();
				(yyval.expr)->val_s      = (yyvsp[0].val_s);
				(yyval.expr)->term_type  = TERM_STRING;
		   }
#line 2616 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 122:
#line 602 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                        {(yyval.val_b) = true;}
#line 2622 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 123:
#line 603 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                        {(yyval.val_b) = false;}
#line 2628 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 124:
#line 606 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                        {
				(yyvsp[-2].exprs)->push_back((yyvsp[0].expr));
				(yyval.exprs) = (yyvsp[-2].exprs);
			 }
#line 2637 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 125:
#line 610 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                   {
				(yyval.exprs) = new ExprNodeList();
				(yyval.exprs)->push_back((yyvsp[0].expr));
			 }
#line 2646 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 126:
#line 616 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                 {
					(yyval.expr) = new ExprNode();
					(yyval.expr)->literal_list = (yyvsp[0].exprs);
					(yyval.expr)->term_type    = TERM_LITERAL_LIST;
				  }
#line 2656 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 127:
#line 622 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                 { (yyval.val_s) = (yyvsp[0].val_s); }
#line 2662 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 128:
#line 623 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                         { (yyval.val_s) = (yyvsp[-1].val_s); }
#line 2668 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;

  case 129:
#line 626 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"
                                 { (yyval.val_s) = (yyvsp[0].val_s); }
#line 2674 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"
    break;


#line 2678 "/home/typhigh/Desktop/OpenSource/TColDB/build/src/Parser/sql.tab.cc"

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
      yyerror (thisptr, YY_("syntax error"));
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
        yyerror (thisptr, yymsgp);
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
                      yytoken, &yylval, thisptr);
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
                  yystos[yystate], yyvsp, thisptr);
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
  yyerror (thisptr, YY_("memory exhausted"));
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
                  yytoken, &yylval, thisptr);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, thisptr);
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
#line 629 "/home/typhigh/Desktop/OpenSource/TColDB/src/Parser/sql.y"


void yyerror(const char *msg)
{
	fprintf(stderr, "[Error] %s\n", msg);
}

int yywrap()
{
	return 1;
}

/*
char run_parser(const char *input)
{
	char ret;
	if(input) {
		YY_BUFFER_STATE buf = yy_scan_string(input);
		yy_switch_to_buffer(buf);
		ret = yyparse();
		yy_delete_buffer(buf);
	} else {
		ret = yyparse();
	}

	return ret;
}
*/
