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
#line 2 "compiler.y"

    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;
    ObjectType tempType = OBJECT_TYPE_INT;
    Object* tempObject = NULL;
    char *tempName = NULL;
    int arr_length = 0;

#line 83 "compiler.tab.c"

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
    COUT = 258,                    /* COUT  */
    SHR = 259,                     /* SHR  */
    SHL = 260,                     /* SHL  */
    BAN = 261,                     /* BAN  */
    BOR = 262,                     /* BOR  */
    BNT = 263,                     /* BNT  */
    BXO = 264,                     /* BXO  */
    ADD = 265,                     /* ADD  */
    SUB = 266,                     /* SUB  */
    MUL = 267,                     /* MUL  */
    DIV = 268,                     /* DIV  */
    REM = 269,                     /* REM  */
    NOT = 270,                     /* NOT  */
    GTR = 271,                     /* GTR  */
    LES = 272,                     /* LES  */
    GEQ = 273,                     /* GEQ  */
    LEQ = 274,                     /* LEQ  */
    EQL = 275,                     /* EQL  */
    NEQ = 276,                     /* NEQ  */
    LAN = 277,                     /* LAN  */
    LOR = 278,                     /* LOR  */
    VAL_ASSIGN = 279,              /* VAL_ASSIGN  */
    ADD_ASSIGN = 280,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 281,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 282,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 283,              /* DIV_ASSIGN  */
    REM_ASSIGN = 284,              /* REM_ASSIGN  */
    BAN_ASSIGN = 285,              /* BAN_ASSIGN  */
    BOR_ASSIGN = 286,              /* BOR_ASSIGN  */
    BXO_ASSIGN = 287,              /* BXO_ASSIGN  */
    SHR_ASSIGN = 288,              /* SHR_ASSIGN  */
    SHL_ASSIGN = 289,              /* SHL_ASSIGN  */
    INC_ASSIGN = 290,              /* INC_ASSIGN  */
    DEC_ASSIGN = 291,              /* DEC_ASSIGN  */
    IF = 292,                      /* IF  */
    ELSE = 293,                    /* ELSE  */
    FOR = 294,                     /* FOR  */
    WHILE = 295,                   /* WHILE  */
    RETURN = 296,                  /* RETURN  */
    BREAK = 297,                   /* BREAK  */
    CONTINUE = 298,                /* CONTINUE  */
    VARIABLE_T = 299,              /* VARIABLE_T  */
    IDENT = 300,                   /* IDENT  */
    STR_LIT = 301,                 /* STR_LIT  */
    BOOL_LIT = 302,                /* BOOL_LIT  */
    INT_LIT = 303,                 /* INT_LIT  */
    FLOAT_LIT = 304,               /* FLOAT_LIT  */
    IFELSE = 305,                  /* IFELSE  */
    UMINUS = 306,                  /* UMINUS  */
    CAST = 307                     /* CAST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "compiler.y"

    ObjectType var_type;

    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val; /* compiler_common.h */

#line 193 "compiler.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



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
  YYSYMBOL_CAST = 52,                      /* CAST  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* '{'  */
  YYSYMBOL_57_ = 57,                       /* '}'  */
  YYSYMBOL_58_ = 58,                       /* ','  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_61_ = 61,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_Program = 63,                   /* Program  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_GlobalStmtList = 65,            /* GlobalStmtList  */
  YYSYMBOL_GlobalStmt = 66,                /* GlobalStmt  */
  YYSYMBOL_DefineVariableStmt = 67,        /* DefineVariableStmt  */
  YYSYMBOL_Expression = 68,                /* Expression  */
  YYSYMBOL_FunctionDefStmt = 69,           /* FunctionDefStmt  */
  YYSYMBOL_70_2 = 70,                      /* $@2  */
  YYSYMBOL_71_3 = 71,                      /* $@3  */
  YYSYMBOL_72_4 = 72,                      /* $@4  */
  YYSYMBOL_FunctionParameterStmtList = 73, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 74,     /* FunctionParameterStmt  */
  YYSYMBOL_StmtList = 75,                  /* StmtList  */
  YYSYMBOL_Stmt = 76,                      /* Stmt  */
  YYSYMBOL_CoutParmListStmt = 77,          /* CoutParmListStmt  */
  YYSYMBOL_DeclareVarStmt = 78,            /* DeclareVarStmt  */
  YYSYMBOL_79_5 = 79,                      /* $@5  */
  YYSYMBOL_VarList = 80,                   /* VarList  */
  YYSYMBOL_Var = 81,                       /* Var  */
  YYSYMBOL_82_6 = 82,                      /* $@6  */
  YYSYMBOL_83_7 = 83,                      /* $@7  */
  YYSYMBOL_84_8 = 84,                      /* $@8  */
  YYSYMBOL_85_9 = 85,                      /* $@9  */
  YYSYMBOL_InitArr = 86,                   /* InitArr  */
  YYSYMBOL_ArrCall = 87,                   /* ArrCall  */
  YYSYMBOL_AssignVarStmt = 88,             /* AssignVarStmt  */
  YYSYMBOL_89_10 = 89,                     /* $@10  */
  YYSYMBOL_90_11 = 90,                     /* $@11  */
  YYSYMBOL_91_12 = 91,                     /* $@12  */
  YYSYMBOL_AssignmentOperator = 92,        /* AssignmentOperator  */
  YYSYMBOL_IfStmt = 93,                    /* IfStmt  */
  YYSYMBOL_94_13 = 94,                     /* $@13  */
  YYSYMBOL_95_14 = 95,                     /* $@14  */
  YYSYMBOL_96_15 = 96,                     /* $@15  */
  YYSYMBOL_ELSEStmt = 97,                  /* ELSEStmt  */
  YYSYMBOL_98_16 = 98,                     /* $@16  */
  YYSYMBOL_WhileStmt = 99,                 /* WhileStmt  */
  YYSYMBOL_100_17 = 100,                   /* $@17  */
  YYSYMBOL_101_18 = 101,                   /* $@18  */
  YYSYMBOL_ForStmt = 102,                  /* ForStmt  */
  YYSYMBOL_103_19 = 103,                   /* $@19  */
  YYSYMBOL_104_20 = 104,                   /* $@20  */
  YYSYMBOL_ForInside = 105,                /* ForInside  */
  YYSYMBOL_ForInit = 106,                  /* ForInit  */
  YYSYMBOL_ForCondition = 107,             /* ForCondition  */
  YYSYMBOL_ForUpdate = 108,                /* ForUpdate  */
  YYSYMBOL_FuncCall = 109,                 /* FuncCall  */
  YYSYMBOL_110_21 = 110,                   /* $@21  */
  YYSYMBOL_111_22 = 111,                   /* $@22  */
  YYSYMBOL_ParamList = 112                 /* ParamList  */
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
#define YYLAST   566

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      54,    55,     2,     2,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    72,    73,    77,    78,    82,    83,    88,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   122,   123,   124,   132,
     132,   132,   132,   135,   136,   137,   140,   141,   152,   153,
     157,   158,   159,   160,   162,   163,   164,   165,   166,   167,
     168,   169,   173,   174,   187,   187,   191,   192,   196,   197,
     198,   199,   199,   200,   200,   201,   201,   201,   207,   208,
     209,   213,   214,   219,   219,   220,   220,   221,   221,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   244,   244,   244,   245,   245,   249,   249,   250,
     265,   265,   265,   270,   270,   270,   275,   276,   283,   284,
     285,   305,   306,   310,   311,   316,   316,   316,   320,   321
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
  "INT_LIT", "FLOAT_LIT", "IFELSE", "UMINUS", "CAST", "';'", "'('", "')'",
  "'{'", "'}'", "','", "'['", "']'", "':'", "$accept", "Program", "$@1",
  "GlobalStmtList", "GlobalStmt", "DefineVariableStmt", "Expression",
  "FunctionDefStmt", "$@2", "$@3", "$@4", "FunctionParameterStmtList",
  "FunctionParameterStmt", "StmtList", "Stmt", "CoutParmListStmt",
  "DeclareVarStmt", "$@5", "VarList", "Var", "$@6", "$@7", "$@8", "$@9",
  "InitArr", "ArrCall", "AssignVarStmt", "$@10", "$@11", "$@12",
  "AssignmentOperator", "IfStmt", "$@13", "$@14", "$@15", "ELSEStmt",
  "$@16", "WhileStmt", "$@17", "$@18", "ForStmt", "$@19", "$@20",
  "ForInside", "ForInit", "ForCondition", "ForUpdate", "FuncCall", "$@21",
  "$@22", "ParamList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-172)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,    14,   -27,  -172,    -1,   -27,  -172,  -172,  -172,   -15,
    -172,   238,  -172,   238,   238,   238,   -43,  -172,  -172,  -172,
    -172,   415,   379,  -172,  -172,     4,   516,  -172,  -172,   238,
     238,     3,   289,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
    -172,    30,    28,  -172,   427,    31,   174,   238,  -172,   130,
     516,   480,   498,    58,    58,  -172,  -172,  -172,    87,    87,
      87,    87,   534,   534,   349,   461,    35,     4,    40,   238,
    -172,    46,  -172,    56,  -172,    62,   427,    64,   238,  -172,
    -172,  -172,   194,    70,  -172,   115,    71,  -172,  -172,   238,
    -172,  -172,  -172,    -9,  -172,    12,  -172,    93,    95,  -172,
    -172,  -172,    96,   238,     8,   238,  -172,    98,   399,    79,
     102,   530,  -172,  -172,  -172,  -172,  -172,   427,   238,  -172,
     309,    99,   238,  -172,   -18,    97,  -172,   101,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,  -172,
    -172,  -172,   427,   100,   -24,   329,   238,   109,    79,   104,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     427,  -172,    70,   105,   107,  -172,   103,   106,   110,   427,
     111,  -172,   117,   530,    70,   334,   124,   114,   238,  -172,
     -16,   112,  -172,    39,   118,  -172,  -172,    70,   427,   120,
      70,   127,   155,  -172,  -172,  -172,   186,   137,   218,   139,
     146,   530,   171,    70,  -172,  -172,  -172,  -172,   196,   238,
    -172,  -172,   237,  -172,  -172,   427,     6,  -172,   198,  -172,
     238,   162,   427,   238,     9,  -172
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
    -172,  -172,  -172,  -172,   219,  -172,   -11,  -172,  -172,  -172,
    -172,  -172,   156,  -110,  -100,  -172,    78,  -172,  -172,    77,
    -172,  -172,  -172,  -172,     5,  -172,  -147,  -172,  -172,  -172,
    -171,  -172,  -172,  -172,  -172,    24,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,   -46,  -172,  -172,
    -172
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
      22,    -4,    26,    27,    28,   123,   156,   175,   -71,    11,
      32,    29,   192,   128,     3,    95,    30,     4,    54,    56,
     102,   173,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    12,
     220,   157,    95,   201,     9,    29,    82,   112,    51,    96,
     120,    97,    98,    99,   100,   101,   102,   103,    57,   112,
     215,   129,   185,   229,   230,   104,   235,   230,    86,   122,
      39,    40,    41,    95,   193,    76,    96,    92,    97,    98,
      99,   100,   101,   102,   103,   123,    77,   206,   118,    79,
     208,    33,   104,   123,    83,    85,   204,    37,    38,    39,
      40,    41,   127,   222,   130,    88,   123,    96,   123,    97,
      98,    99,   100,   101,   102,   103,    89,   152,    90,    91,
     113,   155,   123,   104,   134,   115,   112,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   112,   112,
      37,    38,    39,    40,    41,   179,   124,   112,   125,   126,
     137,   112,   132,   154,   112,   158,   171,   180,   187,   188,
     112,   159,   112,   182,   120,   191,   189,   112,   186,   196,
     197,   190,   203,   207,   205,   209,   112,   198,    33,   210,
      34,    35,   173,    36,    37,    38,    39,    40,    41,    95,
      42,    43,    44,    45,    46,    47,    48,    49,    33,   218,
      34,    35,   219,    36,    37,    38,    39,    40,    41,   194,
      42,    43,    44,    45,    46,    47,    48,    49,   233,   232,
     -75,    95,   231,    96,    10,    97,    98,    99,   100,   101,
     102,   103,   174,    84,    81,   181,   221,     0,   234,   104,
      95,     0,     0,   214,     0,     0,    13,     0,     0,    14,
       0,     0,     0,    15,    94,    96,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,    96,   217,    97,    98,    99,   100,
     101,   102,   103,    16,    17,    18,    19,    20,     0,     0,
     104,     0,    21,    33,   227,    34,    35,     0,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    33,     0,    34,    35,     0,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    33,     0,    34,    35,    95,    36,    37,
      38,    39,    40,    41,    58,    42,    43,    44,    45,    46,
      47,    48,    49,    33,     0,    34,    35,     0,    36,    37,
      38,    39,    40,    41,   153,    42,    43,    44,    45,    46,
      47,    96,   194,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,    33,   178,    34,    35,   104,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    33,     0,    34,    35,     0,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    13,     0,     0,    14,     0,     0,     0,
      15,    33,    50,    34,    35,     0,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,    47,    48,
      49,     0,   133,     0,     0,     0,     0,     0,     0,    31,
      16,    17,    18,    19,    20,    33,     0,    34,    35,    21,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    48,    33,     0,    34,     0,     0,    36,
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
      11,     0,    13,    14,    15,   105,    24,   154,    24,    24,
      21,    54,   183,     5,     0,     3,    59,    44,    29,    30,
      44,    45,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    54,
     211,    59,     3,    59,    45,    54,    57,    93,    44,    37,
      59,    39,    40,    41,    42,    43,    44,    45,    55,   105,
     207,    53,   172,    57,    58,    53,    57,    58,    79,    57,
      12,    13,    14,     3,   184,    45,    37,    88,    39,    40,
      41,    42,    43,    44,    45,   185,    58,   197,    99,    58,
     200,     4,    53,   193,    59,    55,    57,    10,    11,    12,
      13,    14,   113,   213,   115,    59,   206,    37,   208,    39,
      40,    41,    42,    43,    44,    45,    60,   128,    56,    55,
       5,   132,   222,    53,    45,    54,   172,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   184,   185,
      10,    11,    12,    13,    14,   156,    53,   193,    53,    53,
      48,   197,    54,    54,   200,    58,    56,    48,    55,    53,
     206,    60,   208,    59,    59,    48,    56,   213,    61,    45,
      56,    60,    60,    53,    56,    48,   222,   188,     4,    24,
       6,     7,    45,     9,    10,    11,    12,    13,    14,     3,
      16,    17,    18,    19,    20,    21,    22,    23,     4,    60,
       6,     7,    56,     9,    10,    11,    12,    13,    14,    38,
      16,    17,    18,    19,    20,    21,    22,    23,    56,   230,
      24,     3,    24,    37,     5,    39,    40,    41,    42,    43,
      44,    45,   154,    77,    60,   158,   212,    -1,   233,    53,
       3,    -1,    -1,    57,    -1,    -1,     8,    -1,    -1,    11,
      -1,    -1,    -1,    15,    60,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    37,    57,    39,    40,    41,    42,
      43,    44,    45,    45,    46,    47,    48,    49,    -1,    -1,
      53,    -1,    54,     4,    57,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,     4,    -1,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,     4,    -1,     6,     7,     3,     9,    10,
      11,    12,    13,    14,    55,    16,    17,    18,    19,    20,
      21,    22,    23,     4,    -1,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    55,    16,    17,    18,    19,    20,
      21,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,     4,    55,     6,     7,    53,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,     4,    -1,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,     8,    -1,    -1,    11,    -1,    -1,    -1,
      15,     4,    53,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,     4,    -1,     6,     7,    54,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,     4,    -1,     6,    -1,    -1,     9,
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
       0,    63,    64,     0,    44,    65,    66,    67,    69,    45,
      66,    24,    54,     8,    11,    15,    45,    46,    47,    48,
      49,    54,    68,    87,   109,    70,    68,    68,    68,    54,
      59,    44,    68,     4,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    17,    18,    19,    20,    21,    22,    23,
      53,    44,    73,    74,    68,   112,    68,    55,    55,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    45,    58,    71,    58,
     110,    60,    68,    59,    74,    55,    68,   111,    59,    60,
      56,    55,    68,    72,    60,     3,    37,    39,    40,    41,
      42,    43,    44,    45,    53,    75,    76,    78,    88,    93,
      99,   102,   109,     5,    77,    54,   103,   100,    68,    79,
      59,    89,    57,    76,    53,    53,    53,    68,     5,    53,
      68,   104,    54,    53,    45,    80,    81,    48,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    92,    68,    55,    54,    68,    24,    59,    58,    60,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    56,    96,    45,    78,    88,   105,   106,    55,    68,
      48,    81,    59,    90,    94,    75,    61,    55,    53,    56,
      60,    48,    92,    75,    38,    97,    45,    56,    68,   107,
     101,    59,    82,    60,    57,    56,    75,    53,    75,    48,
      24,    91,    95,    98,    57,    88,   108,    57,    60,    56,
      92,    97,    75,    83,    84,    68,    86,    57,    85,    57,
      58,    24,    68,    56,    86,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    64,    63,    63,    65,    65,    66,    66,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    70,
      71,    72,    69,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    79,    78,    80,    80,    81,    81,
      81,    82,    81,    83,    81,    84,    85,    81,    86,    86,
      86,    87,    87,    89,    88,    90,    88,    91,    88,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    94,    95,    93,    96,    93,    98,    97,    97,
     100,   101,    99,   103,   104,   102,   105,   105,   106,   106,
     106,   107,   107,   108,   108,   110,   111,   109,   112,   112
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
#line 72 "compiler.y"
      { pushScope(); }
#line 1518 "compiler.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 72 "compiler.y"
                                      { dumpScope(); }
#line 1524 "compiler.tab.c"
    break;

  case 10: /* Expression: Expression ADD Expression  */
#line 95 "compiler.y"
                                { printf("ADD\n"); }
#line 1530 "compiler.tab.c"
    break;

  case 11: /* Expression: Expression SUB Expression  */
#line 96 "compiler.y"
                                { printf("SUB\n"); }
#line 1536 "compiler.tab.c"
    break;

  case 12: /* Expression: Expression MUL Expression  */
#line 97 "compiler.y"
                                { printf("MUL\n"); }
#line 1542 "compiler.tab.c"
    break;

  case 13: /* Expression: Expression DIV Expression  */
#line 98 "compiler.y"
                                { printf("DIV\n"); }
#line 1548 "compiler.tab.c"
    break;

  case 14: /* Expression: Expression REM Expression  */
#line 99 "compiler.y"
                                { printf("REM\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1554 "compiler.tab.c"
    break;

  case 15: /* Expression: SUB Expression  */
#line 100 "compiler.y"
                                  { printf("NEG\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1560 "compiler.tab.c"
    break;

  case 16: /* Expression: Expression GTR Expression  */
#line 101 "compiler.y"
                                { printf("GTR\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1566 "compiler.tab.c"
    break;

  case 17: /* Expression: Expression LES Expression  */
#line 102 "compiler.y"
                                { printf("LES\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1572 "compiler.tab.c"
    break;

  case 18: /* Expression: Expression GEQ Expression  */
#line 103 "compiler.y"
                                { printf("GEQ\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1578 "compiler.tab.c"
    break;

  case 19: /* Expression: Expression LEQ Expression  */
#line 104 "compiler.y"
                                { printf("LEQ\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1584 "compiler.tab.c"
    break;

  case 20: /* Expression: Expression EQL Expression  */
#line 105 "compiler.y"
                                { printf("EQL\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1590 "compiler.tab.c"
    break;

  case 21: /* Expression: Expression NEQ Expression  */
#line 106 "compiler.y"
                                { printf("NEQ\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1596 "compiler.tab.c"
    break;

  case 22: /* Expression: Expression LAN Expression  */
#line 107 "compiler.y"
                                { printf("LAN\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1602 "compiler.tab.c"
    break;

  case 23: /* Expression: Expression LOR Expression  */
#line 108 "compiler.y"
                                { printf("LOR\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1608 "compiler.tab.c"
    break;

  case 24: /* Expression: NOT Expression  */
#line 109 "compiler.y"
                     { printf("NOT\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1614 "compiler.tab.c"
    break;

  case 25: /* Expression: Expression BAN Expression  */
#line 110 "compiler.y"
                                { printf("BAN\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1620 "compiler.tab.c"
    break;

  case 26: /* Expression: Expression BOR Expression  */
#line 111 "compiler.y"
                                { printf("BOR\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1626 "compiler.tab.c"
    break;

  case 27: /* Expression: Expression BXO Expression  */
#line 112 "compiler.y"
                                { printf("BXO\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1632 "compiler.tab.c"
    break;

  case 28: /* Expression: BNT Expression  */
#line 113 "compiler.y"
                     { printf("BNT\n"); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1638 "compiler.tab.c"
    break;

  case 29: /* Expression: Expression SHR Expression  */
#line 114 "compiler.y"
                                { printf("SHR\n"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1644 "compiler.tab.c"
    break;

  case 30: /* Expression: STR_LIT  */
#line 115 "compiler.y"
              { printf ("STR_LIT \"%s\"\n", (yyvsp[0].s_var)); (yyval.object_val).type = OBJECT_TYPE_STR; }
#line 1650 "compiler.tab.c"
    break;

  case 31: /* Expression: FLOAT_LIT  */
#line 116 "compiler.y"
                { printf ("FLOAT_LIT %f\n", (yyvsp[0].f_var)); (yyval.object_val).type = OBJECT_TYPE_FLOAT; }
#line 1656 "compiler.tab.c"
    break;

  case 32: /* Expression: BOOL_LIT  */
#line 117 "compiler.y"
               { printf("BOOL_LIT %s\n", (yyvsp[0].b_var) ? "TRUE" : "FALSE"); (yyval.object_val).type = OBJECT_TYPE_BOOL; }
#line 1662 "compiler.tab.c"
    break;

  case 33: /* Expression: INT_LIT  */
#line 118 "compiler.y"
              { printf ("INT_LIT %d\n", (yyvsp[0].i_var)); (yyval.object_val).type = OBJECT_TYPE_INT; }
#line 1668 "compiler.tab.c"
    break;

  case 34: /* Expression: IDENT  */
#line 119 "compiler.y"
            { PrintIdent((yyvsp[0].s_var)); (yyval.object_val).type = findType((yyvsp[0].s_var)); }
#line 1674 "compiler.tab.c"
    break;

  case 35: /* Expression: '(' Expression ')'  */
#line 120 "compiler.y"
                         { (yyval.object_val) = (yyvsp[-1].object_val); }
#line 1680 "compiler.tab.c"
    break;

  case 36: /* Expression: '(' VARIABLE_T ')' Expression  */
#line 122 "compiler.y"
                                               { objCast((yyvsp[-2].var_type)); }
#line 1686 "compiler.tab.c"
    break;

  case 37: /* Expression: FuncCall  */
#line 123 "compiler.y"
               { (yyval.object_val).type = tempType; }
#line 1692 "compiler.tab.c"
    break;

  case 38: /* Expression: ArrCall  */
#line 124 "compiler.y"
              { (yyval.object_val).type = tempType; }
#line 1698 "compiler.tab.c"
    break;

  case 39: /* $@2: %empty  */
#line 132 "compiler.y"
                           { createFunction((yyvsp[-2].var_type), (yyvsp[-1].s_var)); }
#line 1704 "compiler.tab.c"
    break;

  case 40: /* $@3: %empty  */
#line 132 "compiler.y"
                                                                                                  { addFuncSignal((yyvsp[-4].var_type), VAR_FLAG_FUNCTION_RETURN); }
#line 1710 "compiler.tab.c"
    break;

  case 41: /* $@4: %empty  */
#line 132 "compiler.y"
                                                                                                                                                                     {}
#line 1716 "compiler.tab.c"
    break;

  case 42: /* FunctionDefStmt: VARIABLE_T IDENT '(' $@2 FunctionParameterStmtList $@3 ')' '{' $@4 StmtList '}'  */
#line 132 "compiler.y"
                                                                                                                                                                                     { dumpScope(); }
#line 1722 "compiler.tab.c"
    break;

  case 46: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 140 "compiler.y"
                       { pushFunParm((yyvsp[-1].var_type), (yyvsp[0].s_var), VAR_FLAG_DEFAULT); addFuncSignal((yyvsp[-1].var_type), VAR_FLAG_DEFAULT); }
#line 1728 "compiler.tab.c"
    break;

  case 47: /* FunctionParameterStmt: VARIABLE_T IDENT '[' ']'  */
#line 141 "compiler.y"
                               { pushFunParm((yyvsp[-3].var_type), (yyvsp[-2].s_var), VAR_FLAG_ARRAY); addFuncSignal((yyvsp[-3].var_type), VAR_FLAG_ARRAY); }
#line 1734 "compiler.tab.c"
    break;

  case 51: /* Stmt: COUT CoutParmListStmt ';'  */
#line 158 "compiler.y"
                                { stdoutPrint(); }
#line 1740 "compiler.tab.c"
    break;

  case 52: /* Stmt: RETURN Expression ';'  */
#line 159 "compiler.y"
                            { printf("RETURN\n"); }
#line 1746 "compiler.tab.c"
    break;

  case 59: /* Stmt: BREAK  */
#line 167 "compiler.y"
            { printf ("BREAK\n"); }
#line 1752 "compiler.tab.c"
    break;

  case 60: /* Stmt: CONTINUE  */
#line 168 "compiler.y"
               { printf ("CONTINUE\n"); }
#line 1758 "compiler.tab.c"
    break;

  case 61: /* Stmt: RETURN  */
#line 169 "compiler.y"
             { printf ("RETURN\n"); }
#line 1764 "compiler.tab.c"
    break;

  case 62: /* CoutParmListStmt: CoutParmListStmt SHL Expression  */
#line 173 "compiler.y"
                                      { pushFunInParm(&(yyvsp[0].object_val)); }
#line 1770 "compiler.tab.c"
    break;

  case 63: /* CoutParmListStmt: SHL Expression  */
#line 174 "compiler.y"
                     { pushFunInParm(&(yyvsp[0].object_val)); }
#line 1776 "compiler.tab.c"
    break;

  case 64: /* $@5: %empty  */
#line 187 "compiler.y"
                 { tempType = (yyvsp[0].var_type); }
#line 1782 "compiler.tab.c"
    break;

  case 68: /* Var: IDENT  */
#line 196 "compiler.y"
            { pushFunParm(tempType, (yyvsp[0].s_var), VAR_FLAG_DEFAULT); tempName = (yyvsp[0].s_var); }
#line 1788 "compiler.tab.c"
    break;

  case 69: /* Var: IDENT VAL_ASSIGN Expression  */
#line 197 "compiler.y"
                                  { if (tempType == OBJECT_TYPE_AUTO) tempType = (yyvsp[0].object_val).type; pushFunParm(tempType, (yyvsp[-2].s_var), VAR_FLAG_DEFAULT); }
#line 1794 "compiler.tab.c"
    break;

  case 70: /* Var: IDENT '[' INT_LIT ']'  */
#line 198 "compiler.y"
                            { printf("create array: %d\n", arr_length); arr_length = 0; pushFunParm(tempType, (yyvsp[-3].s_var), VAR_FLAG_ARRAY); }
#line 1800 "compiler.tab.c"
    break;

  case 71: /* $@6: %empty  */
#line 199 "compiler.y"
                            { printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); }
#line 1806 "compiler.tab.c"
    break;

  case 72: /* Var: IDENT '[' INT_LIT ']' $@6 VAL_ASSIGN '{' InitArr '}'  */
#line 199 "compiler.y"
                                                                                               { printf("create array: %d\n", arr_length) ; arr_length = 0 ; pushFunParm(tempType, (yyvsp[-8].s_var), VAR_FLAG_ARRAY); }
#line 1812 "compiler.tab.c"
    break;

  case 73: /* $@7: %empty  */
#line 200 "compiler.y"
                                            { printf ("INT_LIT %d\n", (yyvsp[-4].i_var)); printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); PrintIdent((yyvsp[-6].s_var)); }
#line 1818 "compiler.tab.c"
    break;

  case 74: /* Var: IDENT '[' INT_LIT ']' '[' INT_LIT ']' $@7  */
#line 200 "compiler.y"
                                                                                                                                              { arr_length = 0; pushFunParm(tempType, (yyvsp[-7].s_var), VAR_FLAG_ARRAY); }
#line 1824 "compiler.tab.c"
    break;

  case 75: /* $@8: %empty  */
#line 201 "compiler.y"
                                            { printf ("INT_LIT %d\n", (yyvsp[-4].i_var)); printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); PrintIdent((yyvsp[-6].s_var)); }
#line 1830 "compiler.tab.c"
    break;

  case 76: /* $@9: %empty  */
#line 201 "compiler.y"
                                                                                                                                               { printf ("INT_LIT %d\n", (yyvsp[-5].i_var)); }
#line 1836 "compiler.tab.c"
    break;

  case 77: /* Var: IDENT '[' INT_LIT ']' '[' INT_LIT ']' $@8 $@9 VAL_ASSIGN '{' InitArr '}'  */
#line 201 "compiler.y"
                                                                                                                                                                                                                  { arr_length = 0 ; pushFunParm(tempType, (yyvsp[-12].s_var), VAR_FLAG_ARRAY); }
#line 1842 "compiler.tab.c"
    break;

  case 78: /* InitArr: InitArr ',' Expression  */
#line 207 "compiler.y"
                             { arr_length ++; }
#line 1848 "compiler.tab.c"
    break;

  case 79: /* InitArr: Expression  */
#line 208 "compiler.y"
                 { arr_length ++; }
#line 1854 "compiler.tab.c"
    break;

  case 81: /* ArrCall: IDENT '[' Expression ']'  */
#line 213 "compiler.y"
                               { PrintIdent((yyvsp[-3].s_var)); tempType = findType((yyvsp[-3].s_var)); }
#line 1860 "compiler.tab.c"
    break;

  case 82: /* ArrCall: IDENT '[' Expression ']' '[' Expression ']'  */
#line 214 "compiler.y"
                                                  { PrintIdent((yyvsp[-6].s_var)); tempType = findType((yyvsp[-6].s_var)); }
#line 1866 "compiler.tab.c"
    break;

  case 83: /* $@10: %empty  */
#line 219 "compiler.y"
            { PrintIdent((yyvsp[0].s_var)); }
#line 1872 "compiler.tab.c"
    break;

  case 85: /* $@11: %empty  */
#line 220 "compiler.y"
                            { printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); PrintIdent((yyvsp[-3].s_var)); }
#line 1878 "compiler.tab.c"
    break;

  case 87: /* $@12: %empty  */
#line 221 "compiler.y"
                                            { printf ("INT_LIT %d\n", (yyvsp[-4].i_var)); printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); PrintIdent((yyvsp[-6].s_var)); }
#line 1884 "compiler.tab.c"
    break;

  case 89: /* AssignmentOperator: VAL_ASSIGN Expression  */
#line 226 "compiler.y"
                            { printf("EQL_ASSIGN\n"); }
#line 1890 "compiler.tab.c"
    break;

  case 90: /* AssignmentOperator: ADD_ASSIGN Expression  */
#line 227 "compiler.y"
                            { printf("ADD_ASSIGN\n"); }
#line 1896 "compiler.tab.c"
    break;

  case 91: /* AssignmentOperator: SUB_ASSIGN Expression  */
#line 228 "compiler.y"
                            { printf("SUB_ASSIGN\n"); }
#line 1902 "compiler.tab.c"
    break;

  case 92: /* AssignmentOperator: MUL_ASSIGN Expression  */
#line 229 "compiler.y"
                            { printf("MUL_ASSIGN\n"); }
#line 1908 "compiler.tab.c"
    break;

  case 93: /* AssignmentOperator: DIV_ASSIGN Expression  */
#line 230 "compiler.y"
                            { printf("DIV_ASSIGN\n"); }
#line 1914 "compiler.tab.c"
    break;

  case 94: /* AssignmentOperator: REM_ASSIGN Expression  */
#line 231 "compiler.y"
                            { printf("REM_ASSIGN\n"); }
#line 1920 "compiler.tab.c"
    break;

  case 95: /* AssignmentOperator: BAN_ASSIGN Expression  */
#line 232 "compiler.y"
                            { printf("BAN_ASSIGN\n"); }
#line 1926 "compiler.tab.c"
    break;

  case 96: /* AssignmentOperator: BOR_ASSIGN Expression  */
#line 233 "compiler.y"
                            { printf("BOR_ASSIGN\n"); }
#line 1932 "compiler.tab.c"
    break;

  case 97: /* AssignmentOperator: BXO_ASSIGN Expression  */
#line 234 "compiler.y"
                            { printf("BXO_ASSIGN\n"); }
#line 1938 "compiler.tab.c"
    break;

  case 98: /* AssignmentOperator: SHR_ASSIGN Expression  */
#line 235 "compiler.y"
                            { printf("SHR_ASSIGN\n"); }
#line 1944 "compiler.tab.c"
    break;

  case 99: /* AssignmentOperator: SHL_ASSIGN Expression  */
#line 236 "compiler.y"
                            { printf("SHL_ASSIGN\n"); }
#line 1950 "compiler.tab.c"
    break;

  case 100: /* AssignmentOperator: INC_ASSIGN  */
#line 237 "compiler.y"
                 { printf("INC_ASSIGN\n"); }
#line 1956 "compiler.tab.c"
    break;

  case 101: /* AssignmentOperator: DEC_ASSIGN  */
#line 238 "compiler.y"
                 { printf("DEC_ASSIGN\n"); }
#line 1962 "compiler.tab.c"
    break;

  case 102: /* $@13: %empty  */
#line 244 "compiler.y"
                                             { printf("IF\n"); pushScope(); }
#line 1968 "compiler.tab.c"
    break;

  case 103: /* $@14: %empty  */
#line 244 "compiler.y"
                                                                                           { dumpScope(); }
#line 1974 "compiler.tab.c"
    break;

  case 105: /* $@15: %empty  */
#line 245 "compiler.y"
                                          { printf("IF\n"); }
#line 1980 "compiler.tab.c"
    break;

  case 107: /* $@16: %empty  */
#line 249 "compiler.y"
               { printf("ELSE\n"); pushScope(); }
#line 1986 "compiler.tab.c"
    break;

  case 108: /* ELSEStmt: ELSE '{' $@16 StmtList '}'  */
#line 249 "compiler.y"
                                                               { dumpScope(); }
#line 1992 "compiler.tab.c"
    break;

  case 110: /* $@17: %empty  */
#line 265 "compiler.y"
            { printf("WHILE\n"); }
#line 1998 "compiler.tab.c"
    break;

  case 111: /* $@18: %empty  */
#line 265 "compiler.y"
                                                          { pushScope(); }
#line 2004 "compiler.tab.c"
    break;

  case 112: /* WhileStmt: WHILE $@17 '(' Expression ')' '{' $@18 StmtList '}'  */
#line 265 "compiler.y"
                                                                                        { dumpScope(); }
#line 2010 "compiler.tab.c"
    break;

  case 113: /* $@19: %empty  */
#line 270 "compiler.y"
          { printf("FOR\n"); }
#line 2016 "compiler.tab.c"
    break;

  case 114: /* $@20: %empty  */
#line 270 "compiler.y"
                                { pushScope(); }
#line 2022 "compiler.tab.c"
    break;

  case 115: /* ForStmt: FOR $@19 $@20 '(' ForInside ')' '{' StmtList '}'  */
#line 270 "compiler.y"
                                                                                    { dumpScope(); }
#line 2028 "compiler.tab.c"
    break;

  case 117: /* ForInside: DeclareVarStmt ':' IDENT  */
#line 276 "compiler.y"
                               { PrintIdent((yyvsp[0].s_var));  if (tempType == OBJECT_TYPE_AUTO) {
                                                          
                                                          findObjectByName(tempName)->type = findObjectByName((yyvsp[0].s_var))->type; } }
#line 2036 "compiler.tab.c"
    break;

  case 125: /* $@21: %empty  */
#line 316 "compiler.y"
                          { PrintIdent((yyvsp[-2].s_var)); }
#line 2042 "compiler.tab.c"
    break;

  case 126: /* $@22: %empty  */
#line 316 "compiler.y"
                                                     { tempType = checkFunction((yyvsp[-3].s_var)); }
#line 2048 "compiler.tab.c"
    break;


#line 2052 "compiler.tab.c"

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

#line 327 "compiler.y"

/* C code section */
