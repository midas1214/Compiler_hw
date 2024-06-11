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
#line 2 "./compiler.y"

    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;
    ObjectType tempType = OBJECT_TYPE_INT;
    ObjectType returnType = OBJECT_TYPE_INT;
    Object* tempObject = NULL;
    char *tempName = NULL;
    int arr_length = 0;

#line 84 "./build/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COUT = 3,                       /* COUT  */
  YYSYMBOL_SHR = 4,                        /* SHR  */
  YYSYMBOL_SHL = 5,                        /* SHL  */
  YYSYMBOL_BAN = 6,                        /* BAN  */
  YYSYMBOL_BOR = 7,                        /* BOR  */
  YYSYMBOL_BNT = 8,                        /* BNT  */
  YYSYMBOL_BXO = 9,                        /* BXO  */
  YYSYMBOL_ADD = 10,                       /* ADD  */
  YYSYMBOL_SUB = 11,                       /* SUB  */
  YYSYMBOL_MUL = 12,                       /* MUL  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_REM = 14,                       /* REM  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_GTR = 16,                       /* GTR  */
  YYSYMBOL_LES = 17,                       /* LES  */
  YYSYMBOL_GEQ = 18,                       /* GEQ  */
  YYSYMBOL_LEQ = 19,                       /* LEQ  */
  YYSYMBOL_EQL = 20,                       /* EQL  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_LAN = 22,                       /* LAN  */
  YYSYMBOL_LOR = 23,                       /* LOR  */
  YYSYMBOL_VAL_ASSIGN = 24,                /* VAL_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 25,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 26,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 27,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 28,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 29,                /* REM_ASSIGN  */
  YYSYMBOL_BAN_ASSIGN = 30,                /* BAN_ASSIGN  */
  YYSYMBOL_BOR_ASSIGN = 31,                /* BOR_ASSIGN  */
  YYSYMBOL_BXO_ASSIGN = 32,                /* BXO_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 33,                /* SHR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 34,                /* SHL_ASSIGN  */
  YYSYMBOL_INC_ASSIGN = 35,                /* INC_ASSIGN  */
  YYSYMBOL_DEC_ASSIGN = 36,                /* DEC_ASSIGN  */
  YYSYMBOL_IF = 37,                        /* IF  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 43,                  /* CONTINUE  */
  YYSYMBOL_VARIABLE_T = 44,                /* VARIABLE_T  */
  YYSYMBOL_IDENT = 45,                     /* IDENT  */
  YYSYMBOL_STR_LIT = 46,                   /* STR_LIT  */
  YYSYMBOL_BOOL_LIT = 47,                  /* BOOL_LIT  */
  YYSYMBOL_INT_LIT = 48,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 49,                 /* FLOAT_LIT  */
  YYSYMBOL_IFELSE = 50,                    /* IFELSE  */
  YYSYMBOL_UMINUS = 51,                    /* UMINUS  */
  YYSYMBOL_CALL = 52,                      /* CALL  */
  YYSYMBOL_CAST = 53,                      /* CAST  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* '['  */
  YYSYMBOL_61_ = 61,                       /* ']'  */
  YYSYMBOL_62_ = 62,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_Program = 64,                   /* Program  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_GlobalStmtList = 66,            /* GlobalStmtList  */
  YYSYMBOL_GlobalStmt = 67,                /* GlobalStmt  */
  YYSYMBOL_DefineVariableStmt = 68,        /* DefineVariableStmt  */
  YYSYMBOL_Expression = 69,                /* Expression  */
  YYSYMBOL_FunctionDefStmt = 70,           /* FunctionDefStmt  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_72_3 = 72,                      /* $@3  */
  YYSYMBOL_73_4 = 73,                      /* $@4  */
  YYSYMBOL_FunctionParameterStmtList = 74, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 75,     /* FunctionParameterStmt  */
  YYSYMBOL_StmtList = 76,                  /* StmtList  */
  YYSYMBOL_Stmt = 77,                      /* Stmt  */
  YYSYMBOL_CoutParmListStmt = 78,          /* CoutParmListStmt  */
  YYSYMBOL_DeclareVarStmt = 79,            /* DeclareVarStmt  */
  YYSYMBOL_80_5 = 80,                      /* $@5  */
  YYSYMBOL_VarList = 81,                   /* VarList  */
  YYSYMBOL_Var = 82,                       /* Var  */
  YYSYMBOL_83_6 = 83,                      /* $@6  */
  YYSYMBOL_84_7 = 84,                      /* $@7  */
  YYSYMBOL_85_8 = 85,                      /* $@8  */
  YYSYMBOL_86_9 = 86,                      /* $@9  */
  YYSYMBOL_InitArr = 87,                   /* InitArr  */
  YYSYMBOL_ArrCall = 88,                   /* ArrCall  */
  YYSYMBOL_AssignVarStmt = 89,             /* AssignVarStmt  */
  YYSYMBOL_90_10 = 90,                     /* $@10  */
  YYSYMBOL_91_11 = 91,                     /* $@11  */
  YYSYMBOL_92_12 = 92,                     /* $@12  */
  YYSYMBOL_AssignmentOperator = 93,        /* AssignmentOperator  */
  YYSYMBOL_IfStmt = 94,                    /* IfStmt  */
  YYSYMBOL_95_13 = 95,                     /* $@13  */
  YYSYMBOL_96_14 = 96,                     /* $@14  */
  YYSYMBOL_97_15 = 97,                     /* $@15  */
  YYSYMBOL_ELSEStmt = 98,                  /* ELSEStmt  */
  YYSYMBOL_99_16 = 99,                     /* $@16  */
  YYSYMBOL_WhileStmt = 100,                /* WhileStmt  */
  YYSYMBOL_101_17 = 101,                   /* $@17  */
  YYSYMBOL_102_18 = 102,                   /* $@18  */
  YYSYMBOL_ForStmt = 103,                  /* ForStmt  */
  YYSYMBOL_104_19 = 104,                   /* $@19  */
  YYSYMBOL_105_20 = 105,                   /* $@20  */
  YYSYMBOL_ForInside = 106,                /* ForInside  */
  YYSYMBOL_ForInit = 107,                  /* ForInit  */
  YYSYMBOL_ForCondition = 108,             /* ForCondition  */
  YYSYMBOL_ForUpdate = 109,                /* ForUpdate  */
  YYSYMBOL_FuncCall = 110,                 /* FuncCall  */
  YYSYMBOL_111_21 = 111,                   /* $@21  */
  YYSYMBOL_112_22 = 112,                   /* $@22  */
  YYSYMBOL_ParamList = 113                 /* ParamList  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   656

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      55,    56,     2,     2,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    74,    75,    79,    80,    84,    85,    90,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   124,   125,   126,   134,
     134,   134,   134,   137,   138,   139,   142,   143,   154,   155,
     159,   160,   161,   162,   164,   165,   166,   167,   168,   169,
     170,   171,   175,   176,   189,   189,   193,   194,   198,   199,
     200,   201,   201,   202,   202,   203,   203,   203,   209,   210,
     211,   215,   216,   221,   221,   222,   222,   223,   223,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   246,   246,   246,   247,   247,   251,   251,   252,
     267,   267,   267,   272,   272,   272,   277,   278,   285,   286,
     287,   307,   308,   312,   313,   318,   318,   318,   322,   323
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
  "\"end of file\"", "error", "\"invalid token\"", "COUT", "SHR", "SHL",
  "BAN", "BOR", "BNT", "BXO", "ADD", "SUB", "MUL", "DIV", "REM", "NOT",
  "GTR", "LES", "GEQ", "LEQ", "EQL", "NEQ", "LAN", "LOR", "VAL_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "REM_ASSIGN",
  "BAN_ASSIGN", "BOR_ASSIGN", "BXO_ASSIGN", "SHR_ASSIGN", "SHL_ASSIGN",
  "INC_ASSIGN", "DEC_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "RETURN",
  "BREAK", "CONTINUE", "VARIABLE_T", "IDENT", "STR_LIT", "BOOL_LIT",
  "INT_LIT", "FLOAT_LIT", "IFELSE", "UMINUS", "CALL", "CAST", "';'", "'('",
  "')'", "'{'", "'}'", "','", "'['", "']'", "':'", "$accept", "Program",
  "$@1", "GlobalStmtList", "GlobalStmt", "DefineVariableStmt",
  "Expression", "FunctionDefStmt", "$@2", "$@3", "$@4",
  "FunctionParameterStmtList", "FunctionParameterStmt", "StmtList", "Stmt",
  "CoutParmListStmt", "DeclareVarStmt", "$@5", "VarList", "Var", "$@6",
  "$@7", "$@8", "$@9", "InitArr", "ArrCall", "AssignVarStmt", "$@10",
  "$@11", "$@12", "AssignmentOperator", "IfStmt", "$@13", "$@14", "$@15",
  "ELSEStmt", "$@16", "WhileStmt", "$@17", "$@18", "ForStmt", "$@19",
  "$@20", "ForInside", "ForInit", "ForCondition", "ForUpdate", "FuncCall",
  "$@21", "$@22", "ParamList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    41,     8,  -173,    31,     8,  -173,  -173,  -173,   -15,
    -173,   307,  -173,   307,   307,   307,   -54,  -173,  -173,  -173,
    -173,    34,   467,  -173,  -173,    40,   606,  -173,  -173,   307,
     307,    30,   359,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
    -173,    47,    42,  -173,   513,    48,    44,   307,  -173,    84,
     606,   570,   588,     1,     1,  -173,  -173,  -173,   145,   145,
     145,   145,   624,   624,   552,   533,    39,    40,    54,   307,
    -173,    51,  -173,    52,  -173,    55,   513,    58,   307,  -173,
    -173,  -173,   174,   421,  -173,   110,    63,  -173,  -173,   307,
    -173,  -173,  -173,   -43,  -173,   217,  -173,    65,    66,  -173,
    -173,  -173,    69,   307,    16,   307,  -173,    70,   487,    79,
     307,   620,  -173,  -173,  -173,  -173,  -173,   513,   307,  -173,
     379,    85,   307,  -173,   -17,    82,  -173,   194,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,  -173,
    -173,  -173,   513,    86,    27,   400,   307,    94,    79,    88,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   513,
     513,  -173,   421,    90,    91,  -173,    96,    92,    87,   513,
     100,  -173,   307,   620,   421,   405,   118,   107,   307,  -173,
     -16,   220,  -173,   243,   108,  -173,  -173,   421,   513,   112,
     421,   120,   146,  -173,  -173,  -173,   263,   124,   286,   111,
     116,   620,   136,   421,  -173,  -173,  -173,  -173,   151,   307,
    -173,  -173,   306,  -173,  -173,   513,    15,  -173,   155,  -173,
     307,   125,   513,   307,    32,  -173
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     7,     8,     0,
       5,     0,    39,     0,     0,     0,    34,    30,    32,    33,
      31,     0,     0,    38,    37,    45,    28,    15,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    40,    44,   128,   125,     0,     0,    35,    29,
      25,    26,    27,    10,    11,    12,    13,    14,    16,    17,
      18,    19,    20,    21,    22,    23,    46,     0,     0,     0,
     126,    81,    36,     0,    43,     0,   129,     0,     0,    47,
      41,   127,     0,     0,    82,     0,     0,   113,   110,    61,
      59,    60,    64,    83,    50,     0,    49,     0,     0,    55,
      56,    57,     0,     0,     0,     0,   114,     0,     0,     0,
       0,     0,    42,    48,    53,    54,    58,    63,     0,    51,
       0,     0,     0,    52,    68,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,    84,    62,   105,   120,     0,     0,     0,     0,    85,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   102,     0,    83,   118,   119,     0,     0,     0,    69,
       0,    67,     0,     0,     0,   109,     0,     0,   122,   111,
      70,     0,    86,     0,     0,   106,   117,     0,   121,     0,
       0,     0,     0,    87,   103,   107,     0,   124,     0,     0,
       0,     0,   109,     0,   115,   123,   116,   112,    73,    80,
      88,   104,     0,    74,    76,    79,     0,   108,     0,    72,
       0,     0,    78,    80,     0,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,  -173,  -173,   184,  -173,   -11,  -173,  -173,  -173,
    -173,  -173,   122,   -97,  -100,  -173,    64,  -173,  -173,    67,
    -173,  -173,  -173,  -173,   -31,  -173,  -138,  -173,  -173,  -173,
    -172,  -173,  -173,  -173,  -173,    -3,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,   -46,  -173,  -173,
    -173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,     7,   225,     8,    25,    78,
      93,    52,    53,   105,   106,   114,   107,   119,   135,   136,
     202,   223,   224,   228,   226,    23,   108,   121,   183,   211,
     151,   109,   184,   212,   172,   195,   213,   110,   117,   200,
     111,   116,   131,   176,   177,   199,   216,    24,    80,    87,
      55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    29,    26,    27,    28,   123,    30,   156,   -71,    11,
      32,   192,    29,    39,    40,    41,   175,   120,    54,    56,
      -4,   128,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   220,
      12,     3,    13,   157,   201,    14,    82,   112,    33,    15,
      34,    35,     4,    36,    37,    38,    39,    40,    41,   112,
      42,    43,    44,    45,    46,    47,    48,    49,    86,   215,
     129,   102,   173,   229,   230,   185,     9,    92,    31,    16,
      17,    18,    19,    20,    51,   123,    57,   193,   118,    21,
     235,   230,    76,   123,    37,    38,    39,    40,    41,    83,
     206,    77,   127,   208,   130,    81,   123,    79,   123,   137,
      85,    88,    90,    89,    91,   113,   222,   152,   115,   124,
     125,   155,   123,   126,   134,   132,   112,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   112,   112,
     154,   158,   180,   171,   189,   179,   188,   112,   182,    33,
     120,   112,   187,   186,   112,    37,    38,    39,    40,    41,
     112,   190,   112,   196,   197,   205,   207,   112,   209,   173,
     210,   191,   218,   219,   194,   -75,   112,   198,    33,   231,
      34,    35,   233,    36,    37,    38,    39,    40,    41,    10,
      42,    43,    44,    45,    46,    47,    48,    49,    33,    84,
      34,    35,   234,    36,    37,    38,    39,    40,    41,   221,
      42,    43,    44,    45,    46,    47,    48,    49,   174,   232,
      95,     0,     0,     0,    33,   181,    34,    35,     0,    36,
      37,    38,    39,    40,    41,    94,    42,    43,    44,    45,
      46,    47,    48,    49,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,    96,   159,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,    95,     0,     0,     0,
       0,   104,     0,     0,     0,   122,     0,     0,     0,     0,
      96,   203,    97,    98,    99,   100,   101,   102,   103,    95,
       0,     0,     0,     0,     0,     0,     0,   104,     0,     0,
      96,   204,    97,    98,    99,   100,   101,   102,   103,    95,
       0,     0,     0,     0,     0,    13,     0,   104,    14,     0,
       0,   214,    15,    96,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,    96,   217,    97,    98,    99,   100,   101,
     102,   103,    16,    17,    18,    19,    20,     0,     0,     0,
     104,     0,    21,    33,   227,    34,    35,     0,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    33,     0,    34,    35,     0,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,     0,    33,     0,    34,    35,    95,    36,
      37,    38,    39,    40,    41,    58,    42,    43,    44,    45,
      46,    47,    48,    49,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,     0,     0,     0,     0,
       0,     0,    96,   194,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,   178,     0,    96,   104,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,    33,     0,    34,    35,   104,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    33,     0,    34,    35,     0,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,    47,    48,
      49,     0,     0,     0,     0,     0,     0,    33,     0,    34,
      35,    50,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    33,     0,    34,
      35,   133,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    33,     0,    34,    35,
       0,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,    47,    33,     0,    34,     0,     0,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,    33,     0,    34,     0,     0,     0,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,    47,
      33,     0,     0,     0,     0,     0,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    33,     0,
       0,     0,     0,     0,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150
};

static const yytype_int16 yycheck[] =
{
      11,    55,    13,    14,    15,   105,    60,    24,    24,    24,
      21,   183,    55,    12,    13,    14,   154,    60,    29,    30,
       0,     5,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,   211,
      55,     0,     8,    60,    60,    11,    57,    93,     4,    15,
       6,     7,    44,     9,    10,    11,    12,    13,    14,   105,
      16,    17,    18,    19,    20,    21,    22,    23,    79,   207,
      54,    44,    45,    58,    59,   172,    45,    88,    44,    45,
      46,    47,    48,    49,    44,   185,    56,   184,    99,    55,
      58,    59,    45,   193,    10,    11,    12,    13,    14,    60,
     197,    59,   113,   200,   115,    61,   206,    59,   208,   120,
      56,    60,    57,    61,    56,     5,   213,   128,    55,    54,
      54,   132,   222,    54,    45,    55,   172,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   184,   185,
      55,    59,    48,    57,    57,   156,    54,   193,    60,     4,
      60,   197,    56,    62,   200,    10,    11,    12,    13,    14,
     206,    61,   208,    45,    57,    57,    54,   213,    48,    45,
      24,   182,    61,    57,    38,    24,   222,   188,     4,    24,
       6,     7,    57,     9,    10,    11,    12,    13,    14,     5,
      16,    17,    18,    19,    20,    21,    22,    23,     4,    77,
       6,     7,   233,     9,    10,    11,    12,    13,    14,   212,
      16,    17,    18,    19,    20,    21,    22,    23,   154,   230,
       3,    -1,    -1,    -1,     4,   158,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    61,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    61,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      37,    61,    39,    40,    41,    42,    43,    44,    45,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      37,    58,    39,    40,    41,    42,    43,    44,    45,     3,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    54,    11,    -1,
      -1,    58,    15,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    37,    58,    39,    40,    41,    42,    43,
      44,    45,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      54,    -1,    55,     4,    58,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,     4,    -1,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,     4,    -1,     6,     7,     3,     9,
      10,    11,    12,    13,    14,    56,    16,    17,    18,    19,
      20,    21,    22,    23,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    56,    -1,    37,    54,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,     4,    -1,     6,     7,    54,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,     4,    -1,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,     6,
       7,    54,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,     4,    -1,     6,
       7,    54,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,     4,    -1,     6,     7,
      -1,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,     4,    -1,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,     4,    -1,     6,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
       4,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,     4,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,     0,    44,    66,    67,    68,    70,    45,
      67,    24,    55,     8,    11,    15,    45,    46,    47,    48,
      49,    55,    69,    88,   110,    71,    69,    69,    69,    55,
      60,    44,    69,     4,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    17,    18,    19,    20,    21,    22,    23,
      54,    44,    74,    75,    69,   113,    69,    56,    56,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    45,    59,    72,    59,
     111,    61,    69,    60,    75,    56,    69,   112,    60,    61,
      57,    56,    69,    73,    61,     3,    37,    39,    40,    41,
      42,    43,    44,    45,    54,    76,    77,    79,    89,    94,
     100,   103,   110,     5,    78,    55,   104,   101,    69,    80,
      60,    90,    58,    77,    54,    54,    54,    69,     5,    54,
      69,   105,    55,    54,    45,    81,    82,    69,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    93,    69,    56,    55,    69,    24,    60,    59,    61,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    57,    97,    45,    79,    89,   106,   107,    56,    69,
      48,    82,    60,    91,    95,    76,    62,    56,    54,    57,
      61,    69,    93,    76,    38,    98,    45,    57,    69,   108,
     102,    60,    83,    61,    58,    57,    76,    54,    76,    48,
      24,    92,    96,    99,    58,    89,   109,    58,    61,    57,
      93,    98,    76,    84,    85,    69,    87,    58,    86,    58,
      59,    24,    69,    57,    87,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    65,    64,    64,    66,    66,    67,    67,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    71,
      72,    73,    70,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    80,    79,    81,    81,    82,    82,
      82,    83,    82,    84,    82,    85,    86,    82,    87,    87,
      87,    88,    88,    90,    89,    91,    89,    92,    89,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    95,    96,    94,    97,    94,    99,    98,    98,
     101,   102,   100,   104,   105,   103,   106,   106,   107,   107,
     107,   108,   108,   109,   109,   111,   112,   110,   113,   113
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     5,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     1,     3,     4,     1,     1,     0,
       0,     0,    11,     3,     1,     0,     2,     4,     2,     1,
       1,     3,     3,     2,     2,     1,     1,     1,     2,     1,
       1,     1,     3,     2,     0,     3,     1,     3,     1,     3,
       4,     0,     9,     0,     8,     0,     0,    13,     3,     1,
       0,     4,     7,     0,     3,     0,     6,     0,     9,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     0,     0,    10,     0,     7,     0,     5,     0,
       0,     0,     9,     0,     0,     9,     5,     3,     1,     1,
       0,     1,     0,     1,     0,     0,     0,     6,     1,     3
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
  case 2: /* $@1: %empty  */
#line 74 "./compiler.y"
      { pushScope(); }
#line 1436 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 74 "./compiler.y"
                                      { dumpScope(); }
#line 1442 "./build/y.tab.c"
    break;

  case 10: /* Expression: Expression ADD Expression  */
#line 97 "./compiler.y"
                                { printf("ADD\n"); }
#line 1448 "./build/y.tab.c"
    break;

  case 11: /* Expression: Expression SUB Expression  */
#line 98 "./compiler.y"
                                { printf("SUB\n"); }
#line 1454 "./build/y.tab.c"
    break;

  case 12: /* Expression: Expression MUL Expression  */
#line 99 "./compiler.y"
                                { printf("MUL\n"); }
#line 1460 "./build/y.tab.c"
    break;

  case 13: /* Expression: Expression DIV Expression  */
#line 100 "./compiler.y"
                                { printf("DIV\n"); }
#line 1466 "./build/y.tab.c"
    break;

  case 14: /* Expression: Expression REM Expression  */
#line 101 "./compiler.y"
                                { printf("REM\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1472 "./build/y.tab.c"
    break;

  case 15: /* Expression: SUB Expression  */
#line 102 "./compiler.y"
                                  { printf("NEG\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1478 "./build/y.tab.c"
    break;

  case 16: /* Expression: Expression GTR Expression  */
#line 103 "./compiler.y"
                                { printf("GTR\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1484 "./build/y.tab.c"
    break;

  case 17: /* Expression: Expression LES Expression  */
#line 104 "./compiler.y"
                                { printf("LES\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1490 "./build/y.tab.c"
    break;

  case 18: /* Expression: Expression GEQ Expression  */
#line 105 "./compiler.y"
                                { printf("GEQ\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1496 "./build/y.tab.c"
    break;

  case 19: /* Expression: Expression LEQ Expression  */
#line 106 "./compiler.y"
                                { printf("LEQ\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1502 "./build/y.tab.c"
    break;

  case 20: /* Expression: Expression EQL Expression  */
#line 107 "./compiler.y"
                                { printf("EQL\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1508 "./build/y.tab.c"
    break;

  case 21: /* Expression: Expression NEQ Expression  */
#line 108 "./compiler.y"
                                { printf("NEQ\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1514 "./build/y.tab.c"
    break;

  case 22: /* Expression: Expression LAN Expression  */
#line 109 "./compiler.y"
                                { printf("LAN\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1520 "./build/y.tab.c"
    break;

  case 23: /* Expression: Expression LOR Expression  */
#line 110 "./compiler.y"
                                { printf("LOR\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1526 "./build/y.tab.c"
    break;

  case 24: /* Expression: NOT Expression  */
#line 111 "./compiler.y"
                     { printf("NOT\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1532 "./build/y.tab.c"
    break;

  case 25: /* Expression: Expression BAN Expression  */
#line 112 "./compiler.y"
                                { printf("BAN\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1538 "./build/y.tab.c"
    break;

  case 26: /* Expression: Expression BOR Expression  */
#line 113 "./compiler.y"
                                { printf("BOR\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1544 "./build/y.tab.c"
    break;

  case 27: /* Expression: Expression BXO Expression  */
#line 114 "./compiler.y"
                                { printf("BXO\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1550 "./build/y.tab.c"
    break;

  case 28: /* Expression: BNT Expression  */
#line 115 "./compiler.y"
                     { printf("BNT\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1556 "./build/y.tab.c"
    break;

  case 29: /* Expression: Expression SHR Expression  */
#line 116 "./compiler.y"
                                { printf("SHR\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1562 "./build/y.tab.c"
    break;

  case 30: /* Expression: STR_LIT  */
#line 117 "./compiler.y"
              { printf ("STR_LIT \"%s\"\n", (yyvsp[0].s_var)); (yyval.object_val).type = OBJECT_TYPE_STR; }
#line 1568 "./build/y.tab.c"
    break;

  case 31: /* Expression: FLOAT_LIT  */
#line 118 "./compiler.y"
                { printf ("FLOAT_LIT %f\n", (yyvsp[0].f_var)); (yyval.object_val).type = OBJECT_TYPE_FLOAT; }
#line 1574 "./build/y.tab.c"
    break;

  case 32: /* Expression: BOOL_LIT  */
#line 119 "./compiler.y"
               { printf("BOOL_LIT %s\n", (yyvsp[0].b_var) ? "TRUE" : "FALSE"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1580 "./build/y.tab.c"
    break;

  case 33: /* Expression: INT_LIT  */
#line 120 "./compiler.y"
              { printf ("INT_LIT %d\n", (yyvsp[0].i_var)); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1586 "./build/y.tab.c"
    break;

  case 34: /* Expression: IDENT  */
#line 121 "./compiler.y"
            { PrintIdent((yyvsp[0].s_var)); (yyval.object_val).type = findType((yyvsp[0].s_var)); }
#line 1592 "./build/y.tab.c"
    break;

  case 35: /* Expression: '(' Expression ')'  */
#line 122 "./compiler.y"
                         { (yyval.object_val) = (yyvsp[-1].object_val); }
#line 1598 "./build/y.tab.c"
    break;

  case 36: /* Expression: '(' VARIABLE_T ')' Expression  */
#line 124 "./compiler.y"
                                               { objCast((yyvsp[-2].var_type)); }
#line 1604 "./build/y.tab.c"
    break;

  case 37: /* Expression: FuncCall  */
#line 125 "./compiler.y"
                          { (yyval.object_val).type = returnType; }
#line 1610 "./build/y.tab.c"
    break;

  case 38: /* Expression: ArrCall  */
#line 126 "./compiler.y"
                         { (yyval.object_val).type = tempType; }
#line 1616 "./build/y.tab.c"
    break;

  case 39: /* $@2: %empty  */
#line 134 "./compiler.y"
                           { createFunction((yyvsp[-2].var_type), (yyvsp[-1].s_var)); }
#line 1622 "./build/y.tab.c"
    break;

  case 40: /* $@3: %empty  */
#line 134 "./compiler.y"
                                                                                                  { addFuncSignal((yyvsp[-4].var_type), VAR_FLAG_FUNCTION_RETURN); }
#line 1628 "./build/y.tab.c"
    break;

  case 41: /* $@4: %empty  */
#line 134 "./compiler.y"
                                                                                                                                                                     {}
#line 1634 "./build/y.tab.c"
    break;

  case 42: /* FunctionDefStmt: VARIABLE_T IDENT '(' $@2 FunctionParameterStmtList $@3 ')' '{' $@4 StmtList '}'  */
#line 134 "./compiler.y"
                                                                                                                                                                                     { dumpScope(); }
#line 1640 "./build/y.tab.c"
    break;

  case 46: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 142 "./compiler.y"
                       { pushFunParm((yyvsp[-1].var_type), (yyvsp[0].s_var), VAR_FLAG_DEFAULT); addFuncSignal((yyvsp[-1].var_type), VAR_FLAG_DEFAULT); }
#line 1646 "./build/y.tab.c"
    break;

  case 47: /* FunctionParameterStmt: VARIABLE_T IDENT '[' ']'  */
#line 143 "./compiler.y"
                               { pushFunParm((yyvsp[-3].var_type), (yyvsp[-2].s_var), VAR_FLAG_ARRAY); addFuncSignal((yyvsp[-3].var_type), VAR_FLAG_ARRAY); }
#line 1652 "./build/y.tab.c"
    break;

  case 51: /* Stmt: COUT CoutParmListStmt ';'  */
#line 160 "./compiler.y"
                                { stdoutPrint(); }
#line 1658 "./build/y.tab.c"
    break;

  case 52: /* Stmt: RETURN Expression ';'  */
#line 161 "./compiler.y"
                            { printf("RETURN\n"); }
#line 1664 "./build/y.tab.c"
    break;

  case 59: /* Stmt: BREAK  */
#line 169 "./compiler.y"
            { printf ("BREAK\n"); }
#line 1670 "./build/y.tab.c"
    break;

  case 60: /* Stmt: CONTINUE  */
#line 170 "./compiler.y"
               { printf ("CONTINUE\n"); }
#line 1676 "./build/y.tab.c"
    break;

  case 61: /* Stmt: RETURN  */
#line 171 "./compiler.y"
             { printf ("RETURN\n"); }
#line 1682 "./build/y.tab.c"
    break;

  case 62: /* CoutParmListStmt: CoutParmListStmt SHL Expression  */
#line 175 "./compiler.y"
                                      { pushFunInParm(&(yyvsp[0].object_val)); }
#line 1688 "./build/y.tab.c"
    break;

  case 63: /* CoutParmListStmt: SHL Expression  */
#line 176 "./compiler.y"
                     { pushFunInParm(&(yyvsp[0].object_val)); }
#line 1694 "./build/y.tab.c"
    break;

  case 64: /* $@5: %empty  */
#line 189 "./compiler.y"
                 { tempType = (yyvsp[0].var_type); }
#line 1700 "./build/y.tab.c"
    break;

  case 68: /* Var: IDENT  */
#line 198 "./compiler.y"
            { pushFunParm(tempType, (yyvsp[0].s_var), VAR_FLAG_DEFAULT); tempName = (yyvsp[0].s_var); }
#line 1706 "./build/y.tab.c"
    break;

  case 69: /* Var: IDENT VAL_ASSIGN Expression  */
#line 199 "./compiler.y"
                                  { if (tempType == OBJECT_TYPE_AUTO) tempType = (yyvsp[0].object_val).type; pushFunParm(tempType, (yyvsp[-2].s_var), VAR_FLAG_DEFAULT); }
#line 1712 "./build/y.tab.c"
    break;

  case 70: /* Var: IDENT '[' INT_LIT ']'  */
#line 200 "./compiler.y"
                            { printf("create array: %d\n", arr_length); arr_length = 0; pushFunParm(tempType, (yyvsp[-3].s_var), VAR_FLAG_ARRAY); }
#line 1718 "./build/y.tab.c"
    break;

  case 71: /* $@6: %empty  */
#line 201 "./compiler.y"
                            { printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); }
#line 1724 "./build/y.tab.c"
    break;

  case 72: /* Var: IDENT '[' INT_LIT ']' $@6 VAL_ASSIGN '{' InitArr '}'  */
#line 201 "./compiler.y"
                                                                                               { printf("create array: %d\n", arr_length) ; arr_length = 0 ; pushFunParm(tempType, (yyvsp[-8].s_var), VAR_FLAG_ARRAY); }
#line 1730 "./build/y.tab.c"
    break;

  case 73: /* $@7: %empty  */
#line 202 "./compiler.y"
                                            { printf ("INT_LIT %d\n", (yyvsp[-4].i_var)); printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); PrintIdent((yyvsp[-6].s_var)); }
#line 1736 "./build/y.tab.c"
    break;

  case 74: /* Var: IDENT '[' INT_LIT ']' '[' INT_LIT ']' $@7  */
#line 202 "./compiler.y"
                                                                                                                                              { arr_length = 0; pushFunParm(tempType, (yyvsp[-7].s_var), VAR_FLAG_ARRAY); }
#line 1742 "./build/y.tab.c"
    break;

  case 75: /* $@8: %empty  */
#line 203 "./compiler.y"
                                            { printf ("INT_LIT %d\n", (yyvsp[-4].i_var)); printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); PrintIdent((yyvsp[-6].s_var)); }
#line 1748 "./build/y.tab.c"
    break;

  case 76: /* $@9: %empty  */
#line 203 "./compiler.y"
                                                                                                                                               { printf ("INT_LIT %d\n", (yyvsp[-5].i_var)); }
#line 1754 "./build/y.tab.c"
    break;

  case 77: /* Var: IDENT '[' INT_LIT ']' '[' INT_LIT ']' $@8 $@9 VAL_ASSIGN '{' InitArr '}'  */
#line 203 "./compiler.y"
                                                                                                                                                                                                                  { arr_length = 0 ; pushFunParm(tempType, (yyvsp[-12].s_var), VAR_FLAG_ARRAY); }
#line 1760 "./build/y.tab.c"
    break;

  case 78: /* InitArr: InitArr ',' Expression  */
#line 209 "./compiler.y"
                             { arr_length ++; }
#line 1766 "./build/y.tab.c"
    break;

  case 79: /* InitArr: Expression  */
#line 210 "./compiler.y"
                 { arr_length ++; }
#line 1772 "./build/y.tab.c"
    break;

  case 81: /* ArrCall: IDENT '[' Expression ']'  */
#line 215 "./compiler.y"
                               { PrintIdent((yyvsp[-3].s_var)); tempType = findType((yyvsp[-3].s_var)); }
#line 1778 "./build/y.tab.c"
    break;

  case 82: /* ArrCall: IDENT '[' Expression ']' '[' Expression ']'  */
#line 216 "./compiler.y"
                                                  { PrintIdent((yyvsp[-6].s_var)); tempType = findType((yyvsp[-6].s_var)); }
#line 1784 "./build/y.tab.c"
    break;

  case 83: /* $@10: %empty  */
#line 221 "./compiler.y"
            { PrintIdent((yyvsp[0].s_var)); }
#line 1790 "./build/y.tab.c"
    break;

  case 85: /* $@11: %empty  */
#line 222 "./compiler.y"
                               { PrintIdent((yyvsp[-3].s_var)); }
#line 1796 "./build/y.tab.c"
    break;

  case 87: /* $@12: %empty  */
#line 223 "./compiler.y"
                                                  { PrintIdent((yyvsp[-6].s_var)); }
#line 1802 "./build/y.tab.c"
    break;

  case 89: /* AssignmentOperator: VAL_ASSIGN Expression  */
#line 228 "./compiler.y"
                            { printf("EQL_ASSIGN\n"); }
#line 1808 "./build/y.tab.c"
    break;

  case 90: /* AssignmentOperator: ADD_ASSIGN Expression  */
#line 229 "./compiler.y"
                            { printf("ADD_ASSIGN\n"); }
#line 1814 "./build/y.tab.c"
    break;

  case 91: /* AssignmentOperator: SUB_ASSIGN Expression  */
#line 230 "./compiler.y"
                            { printf("SUB_ASSIGN\n"); }
#line 1820 "./build/y.tab.c"
    break;

  case 92: /* AssignmentOperator: MUL_ASSIGN Expression  */
#line 231 "./compiler.y"
                            { printf("MUL_ASSIGN\n"); }
#line 1826 "./build/y.tab.c"
    break;

  case 93: /* AssignmentOperator: DIV_ASSIGN Expression  */
#line 232 "./compiler.y"
                            { printf("DIV_ASSIGN\n"); }
#line 1832 "./build/y.tab.c"
    break;

  case 94: /* AssignmentOperator: REM_ASSIGN Expression  */
#line 233 "./compiler.y"
                            { printf("REM_ASSIGN\n"); }
#line 1838 "./build/y.tab.c"
    break;

  case 95: /* AssignmentOperator: BAN_ASSIGN Expression  */
#line 234 "./compiler.y"
                            { printf("BAN_ASSIGN\n"); }
#line 1844 "./build/y.tab.c"
    break;

  case 96: /* AssignmentOperator: BOR_ASSIGN Expression  */
#line 235 "./compiler.y"
                            { printf("BOR_ASSIGN\n"); }
#line 1850 "./build/y.tab.c"
    break;

  case 97: /* AssignmentOperator: BXO_ASSIGN Expression  */
#line 236 "./compiler.y"
                            { printf("BXO_ASSIGN\n"); }
#line 1856 "./build/y.tab.c"
    break;

  case 98: /* AssignmentOperator: SHR_ASSIGN Expression  */
#line 237 "./compiler.y"
                            { printf("SHR_ASSIGN\n"); }
#line 1862 "./build/y.tab.c"
    break;

  case 99: /* AssignmentOperator: SHL_ASSIGN Expression  */
#line 238 "./compiler.y"
                            { printf("SHL_ASSIGN\n"); }
#line 1868 "./build/y.tab.c"
    break;

  case 100: /* AssignmentOperator: INC_ASSIGN  */
#line 239 "./compiler.y"
                 { printf("INC_ASSIGN\n"); }
#line 1874 "./build/y.tab.c"
    break;

  case 101: /* AssignmentOperator: DEC_ASSIGN  */
#line 240 "./compiler.y"
                 { printf("DEC_ASSIGN\n"); }
#line 1880 "./build/y.tab.c"
    break;

  case 102: /* $@13: %empty  */
#line 246 "./compiler.y"
                                             { printf("IF\n"); pushScope(); }
#line 1886 "./build/y.tab.c"
    break;

  case 103: /* $@14: %empty  */
#line 246 "./compiler.y"
                                                                                           { dumpScope(); }
#line 1892 "./build/y.tab.c"
    break;

  case 105: /* $@15: %empty  */
#line 247 "./compiler.y"
                                          { printf("IF\n"); }
#line 1898 "./build/y.tab.c"
    break;

  case 107: /* $@16: %empty  */
#line 251 "./compiler.y"
               { printf("ELSE\n"); pushScope(); }
#line 1904 "./build/y.tab.c"
    break;

  case 108: /* ELSEStmt: ELSE '{' $@16 StmtList '}'  */
#line 251 "./compiler.y"
                                                               { dumpScope(); }
#line 1910 "./build/y.tab.c"
    break;

  case 110: /* $@17: %empty  */
#line 267 "./compiler.y"
            { printf("WHILE\n"); }
#line 1916 "./build/y.tab.c"
    break;

  case 111: /* $@18: %empty  */
#line 267 "./compiler.y"
                                                          { pushScope(); }
#line 1922 "./build/y.tab.c"
    break;

  case 112: /* WhileStmt: WHILE $@17 '(' Expression ')' '{' $@18 StmtList '}'  */
#line 267 "./compiler.y"
                                                                                        { dumpScope(); }
#line 1928 "./build/y.tab.c"
    break;

  case 113: /* $@19: %empty  */
#line 272 "./compiler.y"
          { printf("FOR\n"); }
#line 1934 "./build/y.tab.c"
    break;

  case 114: /* $@20: %empty  */
#line 272 "./compiler.y"
                                { pushScope(); }
#line 1940 "./build/y.tab.c"
    break;

  case 115: /* ForStmt: FOR $@19 $@20 '(' ForInside ')' '{' StmtList '}'  */
#line 272 "./compiler.y"
                                                                                    { dumpScope(); }
#line 1946 "./build/y.tab.c"
    break;

  case 117: /* ForInside: DeclareVarStmt ':' IDENT  */
#line 278 "./compiler.y"
                               { PrintIdent((yyvsp[0].s_var));  if (tempType == OBJECT_TYPE_AUTO) {
                                                          
                                                          findObjectByName(tempName)->type = findObjectByName((yyvsp[0].s_var))->type; } }
#line 1954 "./build/y.tab.c"
    break;

  case 125: /* $@21: %empty  */
#line 318 "./compiler.y"
                          { PrintIdent((yyvsp[-2].s_var)); }
#line 1960 "./build/y.tab.c"
    break;

  case 126: /* $@22: %empty  */
#line 318 "./compiler.y"
                                                     { returnType = checkFunction((yyvsp[-3].s_var)); }
#line 1966 "./build/y.tab.c"
    break;


#line 1970 "./build/y.tab.c"

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

#line 329 "./compiler.y"

/* C code section */
