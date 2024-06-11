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
    #include <string.h>

    int yydebug = 1;
    ObjectType tempType = OBJECT_TYPE_INT;
    ObjectType returnType = OBJECT_TYPE_INT;
    Object* tempObject = NULL;
    char *tempName = NULL;
    int arr_length = 0;
    int isReturning = 0; // returning or not
    int isMain = 0; // main funct or not
    char *assignIdentName = NULL;
    char *nowFuncName = NULL;
    int isStoringArr = 0;
    int whileOrFor = 0; // 0 : while, 1 : for


#line 92 "./build/y.tab.c"

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
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_FunctionParameterStmtList = 75, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 76,     /* FunctionParameterStmt  */
  YYSYMBOL_StmtList = 77,                  /* StmtList  */
  YYSYMBOL_Stmt = 78,                      /* Stmt  */
  YYSYMBOL_79_6 = 79,                      /* $@6  */
  YYSYMBOL_80_7 = 80,                      /* $@7  */
  YYSYMBOL_CoutParmListStmt = 81,          /* CoutParmListStmt  */
  YYSYMBOL_82_8 = 82,                      /* $@8  */
  YYSYMBOL_83_9 = 83,                      /* $@9  */
  YYSYMBOL_DeclareVarStmt = 84,            /* DeclareVarStmt  */
  YYSYMBOL_85_10 = 85,                     /* $@10  */
  YYSYMBOL_VarList = 86,                   /* VarList  */
  YYSYMBOL_Var = 87,                       /* Var  */
  YYSYMBOL_88_11 = 88,                     /* $@11  */
  YYSYMBOL_89_12 = 89,                     /* $@12  */
  YYSYMBOL_90_13 = 90,                     /* $@13  */
  YYSYMBOL_InitArr = 91,                   /* InitArr  */
  YYSYMBOL_92_14 = 92,                     /* $@14  */
  YYSYMBOL_93_15 = 93,                     /* $@15  */
  YYSYMBOL_ArrCall = 94,                   /* ArrCall  */
  YYSYMBOL_95_16 = 95,                     /* $@16  */
  YYSYMBOL_96_17 = 96,                     /* $@17  */
  YYSYMBOL_AssignVarStmt = 97,             /* AssignVarStmt  */
  YYSYMBOL_98_18 = 98,                     /* $@18  */
  YYSYMBOL_99_19 = 99,                     /* $@19  */
  YYSYMBOL_100_20 = 100,                   /* $@20  */
  YYSYMBOL_ArrayIndices = 101,             /* ArrayIndices  */
  YYSYMBOL_102_21 = 102,                   /* $@21  */
  YYSYMBOL_AssignmentOperator = 103,       /* AssignmentOperator  */
  YYSYMBOL_IfStmt = 104,                   /* IfStmt  */
  YYSYMBOL_105_22 = 105,                   /* $@22  */
  YYSYMBOL_106_23 = 106,                   /* $@23  */
  YYSYMBOL_107_24 = 107,                   /* $@24  */
  YYSYMBOL_108_25 = 108,                   /* $@25  */
  YYSYMBOL_109_26 = 109,                   /* $@26  */
  YYSYMBOL_110_27 = 110,                   /* $@27  */
  YYSYMBOL_111_28 = 111,                   /* $@28  */
  YYSYMBOL_ELSEStmt = 112,                 /* ELSEStmt  */
  YYSYMBOL_113_29 = 113,                   /* $@29  */
  YYSYMBOL_114_30 = 114,                   /* $@30  */
  YYSYMBOL_115_31 = 115,                   /* $@31  */
  YYSYMBOL_WhileStmt = 116,                /* WhileStmt  */
  YYSYMBOL_117_32 = 117,                   /* $@32  */
  YYSYMBOL_118_33 = 118,                   /* $@33  */
  YYSYMBOL_119_34 = 119,                   /* $@34  */
  YYSYMBOL_120_35 = 120,                   /* $@35  */
  YYSYMBOL_121_36 = 121,                   /* $@36  */
  YYSYMBOL_ForStmt = 122,                  /* ForStmt  */
  YYSYMBOL_123_37 = 123,                   /* $@37  */
  YYSYMBOL_124_38 = 124,                   /* $@38  */
  YYSYMBOL_125_39 = 125,                   /* $@39  */
  YYSYMBOL_126_40 = 126,                   /* $@40  */
  YYSYMBOL_127_41 = 127,                   /* $@41  */
  YYSYMBOL_ForInside = 128,                /* ForInside  */
  YYSYMBOL_ForInit = 129,                  /* ForInit  */
  YYSYMBOL_ForCondition = 130,             /* ForCondition  */
  YYSYMBOL_131_42 = 131,                   /* $@42  */
  YYSYMBOL_ForUpdate = 132,                /* ForUpdate  */
  YYSYMBOL_133_43 = 133,                   /* $@43  */
  YYSYMBOL_FuncCall = 134,                 /* FuncCall  */
  YYSYMBOL_135_44 = 135,                   /* $@44  */
  YYSYMBOL_136_45 = 136,                   /* $@45  */
  YYSYMBOL_ParamList = 137                 /* ParamList  */
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
#define YYLAST   557

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

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
       0,    82,    82,    82,    83,    87,    88,    92,    93,    98,
     103,   110,   116,   122,   128,   135,   142,   149,   156,   163,
     170,   177,   184,   191,   198,   206,   213,   220,   227,   235,
     242,   251,   258,   265,   280,   289,   293,   300,   305,   316,
     316,   316,   316,   316,   319,   320,   321,   324,   325,   336,
     337,   341,   342,   343,   343,   344,   346,   347,   348,   349,
     350,   351,   362,   363,   363,   367,   367,   368,   368,   381,
     381,   385,   386,   390,   394,   413,   422,   425,   422,   432,
     444,   444,   458,   458,   459,   459,   460,   464,   464,   464,
     472,   472,   478,   478,   478,   483,   483,   484,   490,   512,
     527,   542,   557,   572,   576,   580,   584,   588,   592,   596,
     600,   608,   608,   608,   608,   608,   609,   609,   609,   609,
     613,   613,   613,   613,   614,   629,   629,   629,   629,   629,
     629,   634,   634,   634,   634,   634,   634,   639,   640,   647,
     648,   649,   669,   669,   670,   674,   674,   675,   680,   680,
     680,   684,   685
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
  "Expression", "FunctionDefStmt", "$@2", "$@3", "$@4", "$@5",
  "FunctionParameterStmtList", "FunctionParameterStmt", "StmtList", "Stmt",
  "$@6", "$@7", "CoutParmListStmt", "$@8", "$@9", "DeclareVarStmt", "$@10",
  "VarList", "Var", "$@11", "$@12", "$@13", "InitArr", "$@14", "$@15",
  "ArrCall", "$@16", "$@17", "AssignVarStmt", "$@18", "$@19", "$@20",
  "ArrayIndices", "$@21", "AssignmentOperator", "IfStmt", "$@22", "$@23",
  "$@24", "$@25", "$@26", "$@27", "$@28", "ELSEStmt", "$@29", "$@30",
  "$@31", "WhileStmt", "$@32", "$@33", "$@34", "$@35", "$@36", "ForStmt",
  "$@37", "$@38", "$@39", "$@40", "$@41", "ForInside", "ForInit",
  "ForCondition", "$@42", "ForUpdate", "$@43", "FuncCall", "$@44", "$@45",
  "ParamList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-177)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-148)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    13,   -29,  -177,    -8,   -29,  -177,  -177,  -177,   -17,
    -177,   381,  -177,   381,   381,   381,   -46,  -177,  -177,  -177,
    -177,   139,   344,  -177,  -177,     3,   507,  -177,  -177,   381,
     -16,    -3,   283,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
    -177,    10,    -2,  -177,   433,    19,   381,    20,   381,  -177,
      85,   507,   471,   489,    28,    28,  -177,  -177,  -177,   104,
     104,   104,   104,   525,   525,   453,   396,    25,     3,    31,
     381,  -177,    52,  -177,  -177,  -177,    41,  -177,    48,   433,
      54,  -177,   381,  -177,  -177,  -177,   195,   118,  -177,   106,
      57,  -177,  -177,   386,  -177,  -177,  -177,   -43,  -177,    49,
    -177,    68,    71,  -177,  -177,  -177,    72,  -177,     0,   381,
    -177,  -177,   381,  -177,    82,   521,   -16,  -177,  -177,  -177,
    -177,  -177,   381,  -177,  -177,   303,  -177,    73,   365,   -21,
      84,  -177,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,  -177,  -177,  -177,    20,  -177,   433,   381,
      87,    86,   381,  -177,   381,    97,    82,   433,   433,   433,
     433,   433,   433,   433,   433,   433,   433,   433,   521,   433,
      95,  -177,   -26,   324,   433,    92,  -177,  -177,  -177,   118,
     105,   102,  -177,   110,   113,  -177,   -14,   118,  -177,   124,
    -177,   116,   117,   125,   151,   187,   140,  -177,   120,   126,
     381,  -177,   121,  -177,  -177,   132,  -177,   118,   136,   433,
     118,   157,   138,  -177,  -177,   118,  -177,   148,   207,   172,
      -9,   140,  -177,   142,  -177,  -177,   146,    18,   381,  -177,
     118,  -177,  -177,    -9,  -177,  -177,   433,   230,    24,   381,
    -177,  -177,   433,  -177
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     7,     8,     0,
       5,     0,    39,     0,     0,     0,    34,    30,    32,    33,
      31,     0,     0,    38,    37,    46,    28,    15,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    40,    45,   151,   148,     0,    88,     0,    35,
      29,    25,    26,    27,    10,    11,    12,    13,    14,    16,
      17,    18,    19,    20,    21,    22,    23,    47,     0,     0,
       0,   149,     0,    95,    89,    36,     0,    44,     0,   152,
       0,    97,     0,    48,    41,   150,     0,     0,    96,     0,
       0,   131,   125,    63,    61,    62,    69,    90,    51,     0,
      50,     0,     0,    57,    58,    59,     0,    67,     0,     0,
     132,   126,     0,    64,     0,     0,     0,    42,    49,    55,
      56,    60,     0,    65,    52,     0,   133,     0,     0,    73,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,    91,    93,    43,    68,     0,
     116,     0,     0,    54,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,    66,
       0,   117,   141,     0,    74,     0,    72,    94,   112,     0,
      90,   139,   140,     0,     0,   127,    75,     0,   118,     0,
     134,   142,     0,     0,     0,     0,   124,   138,     0,     0,
       0,   128,     0,    77,   113,     0,   119,     0,   145,   143,
       0,    79,     0,   114,   120,   135,   137,     0,     0,     0,
      84,   124,   121,     0,   146,   129,     0,     0,     0,   115,
       0,   136,   130,    84,    78,    82,    85,     0,     0,     0,
     122,    81,    83,   123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,  -177,  -177,   214,  -177,   -13,  -177,  -177,  -177,
    -177,  -177,  -177,   143,  -116,  -105,  -177,  -177,  -177,  -177,
    -177,    38,  -177,  -177,    56,  -177,  -177,  -177,   -20,  -177,
    -177,  -177,  -177,  -177,  -176,  -177,  -177,  -177,   108,  -177,
      59,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,     4,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,   -49,  -177,  -177,  -177
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,     7,    22,     8,    25,    79,
      97,   157,    52,    53,   109,   110,   122,   123,   118,   159,
     132,   111,   124,   140,   141,   204,   222,   229,   237,   249,
     238,    23,    30,    84,   112,   125,   126,   178,    57,    92,
     155,   113,   180,   197,   223,   231,   181,   189,   206,   216,
     232,   240,   253,   114,   121,   137,   202,   220,   242,   115,
     120,   136,   161,   208,   233,   193,   194,   209,   210,   226,
     227,    24,    81,    90,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    27,    28,   164,   128,   133,   192,    11,    32,    29,
     -76,    -4,    29,     3,   -87,     4,    54,   -92,   106,   190,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,     9,    12,   165,
      39,    40,    41,    82,    56,    85,   203,    51,   116,   -86,
     -86,   234,    99,    58,   134,    77,    33,    78,    34,    35,
     116,    36,    37,    38,    39,    40,    41,    89,    42,    43,
      44,    45,    46,    47,    48,    49,   244,   245,    80,    96,
      83,   205,   251,   245,   198,    86,   100,    88,   101,   102,
     103,   104,   105,   106,   107,    37,    38,    39,    40,    41,
     128,   225,    93,   108,   228,    94,   135,   127,    33,   138,
      95,   117,   119,    91,    37,    38,    39,    40,    41,   158,
     128,    99,   129,   128,   247,   130,   131,   139,   162,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     116,   182,   128,   166,  -111,   185,   179,    13,   116,   183,
      14,   184,   188,   196,    15,   100,   116,   101,   102,   103,
     104,   105,   106,   107,   199,   -92,   200,   201,   116,   207,
    -144,   116,   108,   212,   211,   213,   116,   217,   215,   116,
     218,   -80,   221,    31,    16,    17,    18,    19,    20,   224,
      99,   116,  -147,   190,    21,   230,   236,   219,   116,    33,
     241,    34,    35,   243,    36,    37,    38,    39,    40,    41,
      99,    42,    43,    44,    45,    46,    47,    48,    49,    10,
     191,    87,   186,   248,   100,   246,   101,   102,   103,   104,
     105,   106,   107,    99,   156,   239,   252,   187,     0,     0,
       0,   108,     0,     0,   100,   214,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,    98,     0,     0,     0,
       0,   108,     0,     0,     0,   235,     0,   100,     0,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,    33,   250,    34,
      35,     0,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    33,     0,    34,
      35,     0,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,     0,    33,     0,
      34,    35,     0,    36,    37,    38,    39,    40,    41,    59,
      42,    43,    44,    45,    46,    47,    48,    49,    33,     0,
      34,    35,     0,    36,    37,    38,    39,    40,    41,   160,
      42,    43,    44,    45,    46,    47,    48,    49,     0,    33,
       0,    34,    35,     0,    36,    37,    38,    39,    40,    41,
     195,    42,    43,    44,    45,    46,    47,    48,    49,    13,
       0,     0,    14,     0,   -53,     0,    15,   -53,    50,     0,
      33,   -53,    34,    35,     0,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,   163,
       0,     0,     0,     0,     0,     0,    16,    17,    18,    19,
      20,   -53,   -53,   -53,   -53,   -53,    21,    33,     0,    34,
      35,   -53,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    33,     0,    34,
      35,     0,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    33,     0,    34,     0,     0,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    33,     0,    34,     0,     0,     0,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    33,     0,     0,     0,     0,     0,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,    47,    33,
       0,     0,     0,     0,     0,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154
};

static const yytype_int16 yycheck[] =
{
      13,    14,    15,    24,   109,     5,   182,    24,    21,    55,
      24,     0,    55,     0,    60,    44,    29,    60,    44,    45,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    45,    55,    60,
      12,    13,    14,    56,    60,    58,    60,    44,    97,    58,
      59,   227,     3,    56,    54,    45,     4,    59,     6,     7,
     109,     9,    10,    11,    12,    13,    14,    80,    16,    17,
      18,    19,    20,    21,    22,    23,    58,    59,    59,    92,
      60,   197,    58,    59,   189,    60,    37,    56,    39,    40,
      41,    42,    43,    44,    45,    10,    11,    12,    13,    14,
     205,   217,    61,    54,   220,    57,   119,    58,     4,   122,
      56,     5,    55,    61,    10,    11,    12,    13,    14,   132,
     225,     3,    54,   228,   240,    54,    54,    45,    55,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     189,    55,   247,    59,    57,    48,   159,     8,   197,   162,
      11,   164,    57,    61,    15,    37,   205,    39,    40,    41,
      42,    43,    44,    45,    62,    60,    56,    54,   217,    45,
      54,   220,    54,    48,    57,    24,   225,    57,    38,   228,
      54,    24,    61,    44,    45,    46,    47,    48,    49,    57,
       3,   240,    56,    45,    55,    57,    24,   210,   247,     4,
      58,     6,     7,    57,     9,    10,    11,    12,    13,    14,
       3,    16,    17,    18,    19,    20,    21,    22,    23,     5,
     182,    78,   166,   243,    37,   238,    39,    40,    41,    42,
      43,    44,    45,     3,   126,   231,   249,   178,    -1,    -1,
      -1,    54,    -1,    -1,    37,    58,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    -1,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,     4,    58,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,     4,    -1,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,     4,    -1,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    56,
      16,    17,    18,    19,    20,    21,    22,    23,     4,    -1,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    56,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,     4,
      -1,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      56,    16,    17,    18,    19,    20,    21,    22,    23,     8,
      -1,    -1,    11,    -1,     8,    -1,    15,    11,    54,    -1,
       4,    15,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    45,    46,    47,    48,    49,    55,     4,    -1,     6,
       7,    55,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,     4,    -1,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,     4,    -1,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,     4,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    65,     0,    44,    66,    67,    68,    70,    45,
      67,    24,    55,     8,    11,    15,    45,    46,    47,    48,
      49,    55,    69,    94,   134,    71,    69,    69,    69,    55,
      95,    44,    69,     4,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    17,    18,    19,    20,    21,    22,    23,
      54,    44,    75,    76,    69,   137,    60,   101,    56,    56,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    45,    59,    72,
      59,   135,    69,    60,    96,    69,    60,    76,    56,    69,
     136,    61,   102,    61,    57,    56,    69,    73,    61,     3,
      37,    39,    40,    41,    42,    43,    44,    45,    54,    77,
      78,    84,    97,   104,   116,   122,   134,     5,    81,    55,
     123,   117,    79,    80,    85,    98,    99,    58,    78,    54,
      54,    54,    83,     5,    54,    69,   124,   118,    69,    45,
      86,    87,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,   103,   101,    74,    69,    82,
      56,   125,    55,    54,    24,    60,    59,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,   100,    69,
     105,   109,    55,    69,    69,    48,    87,   103,    57,   110,
      45,    84,    97,   128,   129,    56,    61,   106,    78,    62,
      56,    54,   119,    60,    88,    77,   111,    45,   126,   130,
     131,    57,    48,    24,    58,    38,   112,    57,    54,    69,
     120,    61,    89,   107,    57,    77,   132,   133,    77,    90,
      57,   108,   113,   127,    97,    58,    24,    91,    93,   112,
     114,    58,   121,    57,    58,    59,    69,    77,    91,    92,
      58,    58,    69,   115
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    65,    64,    64,    66,    66,    67,    67,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    71,
      72,    73,    74,    70,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    79,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    80,    78,    82,    81,    83,    81,    85,
      84,    86,    86,    87,    87,    87,    88,    89,    87,    87,
      90,    87,    92,    91,    93,    91,    91,    95,    96,    94,
      98,    97,    99,   100,    97,   102,   101,   101,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   105,   106,   107,   108,   104,   109,   110,   111,   104,
     113,   114,   115,   112,   112,   117,   118,   119,   120,   121,
     116,   123,   124,   125,   126,   127,   122,   128,   128,   129,
     129,   129,   131,   130,   130,   133,   132,   132,   135,   136,
     134,   137,   137
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     5,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     1,     3,     4,     1,     1,     0,
       0,     0,     0,    12,     3,     1,     0,     2,     4,     2,
       1,     1,     3,     0,     4,     2,     2,     1,     1,     1,
       2,     1,     1,     0,     2,     0,     4,     0,     3,     0,
       3,     1,     3,     1,     3,     4,     0,     0,    10,     7,
       0,    12,     0,     4,     0,     2,     0,     0,     0,     4,
       0,     3,     0,     0,     5,     0,     5,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     0,     0,     0,     0,    12,     0,     0,     0,     9,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,    12,     5,     3,     1,
       1,     0,     0,     2,     0,     0,     2,     0,     0,     0,
       6,     1,     3
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
#line 82 "./compiler.y"
      { pushScope(); }
#line 1470 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 82 "./compiler.y"
                                      { dumpScope(); }
#line 1476 "./build/y.tab.c"
    break;

  case 10: /* Expression: Expression ADD Expression  */
#line 103 "./compiler.y"
                                { 
        printf("ADD\n");
        // Generate Jasmin code for addition
        //code("iadd");
        j_add(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
        (yyval.object_val).type = (yyvsp[-2].object_val).type;
    }
#line 1488 "./build/y.tab.c"
    break;

  case 11: /* Expression: Expression SUB Expression  */
#line 110 "./compiler.y"
                                { 
        printf("SUB\n");
        // Generate Jasmin code for subtraction
        //code("isub");
        j_sub(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1499 "./build/y.tab.c"
    break;

  case 12: /* Expression: Expression MUL Expression  */
#line 116 "./compiler.y"
                                { 
        printf("MUL\n");
        // Generate Jasmin code for multiplication
        //code("imul");
        j_mul(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1510 "./build/y.tab.c"
    break;

  case 13: /* Expression: Expression DIV Expression  */
#line 122 "./compiler.y"
                                { 
        printf("DIV\n");
        // Generate Jasmin code for division
        //code("idiv");
        j_div(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1521 "./build/y.tab.c"
    break;

  case 14: /* Expression: Expression REM Expression  */
#line 128 "./compiler.y"
                                { 
        printf("REM\n");
        (yyval.object_val).type = OBJECT_TYPE_INT;
        // Generate Jasmin code for remainder
        //code("irem");
        j_rem();
    }
#line 1533 "./build/y.tab.c"
    break;

  case 15: /* Expression: SUB Expression  */
#line 135 "./compiler.y"
                                  { 
        printf("NEG\n");
        (yyval.object_val).type = (yyvsp[0].object_val).type;
        // Generate Jasmin code for negation
        //code("ineg");
        j_neg(&(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1545 "./build/y.tab.c"
    break;

  case 16: /* Expression: Expression GTR Expression  */
#line 142 "./compiler.y"
                                { 
        printf("GTR\n");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for greater than comparison
        //code("if_icmpgt");
        j_gtr(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1557 "./build/y.tab.c"
    break;

  case 17: /* Expression: Expression LES Expression  */
#line 149 "./compiler.y"
                                { 
        printf("LES\n");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for less than comparison
        //code("if_icmplt");
        j_les(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1569 "./build/y.tab.c"
    break;

  case 18: /* Expression: Expression GEQ Expression  */
#line 156 "./compiler.y"
                                { 
        printf("GEQ\n");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for greater than or equal comparison
        //code("if_icmpge");
        j_geq(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1581 "./build/y.tab.c"
    break;

  case 19: /* Expression: Expression LEQ Expression  */
#line 163 "./compiler.y"
                                { 
        printf("LEQ\n");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for less than or equal comparison
        //code("if_icmple");
        j_leq(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1593 "./build/y.tab.c"
    break;

  case 20: /* Expression: Expression EQL Expression  */
#line 170 "./compiler.y"
                                { 
        printf("EQL\n");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for equality comparison
        //code("if_icmpeq");
        j_eql(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1605 "./build/y.tab.c"
    break;

  case 21: /* Expression: Expression NEQ Expression  */
#line 177 "./compiler.y"
                                { 
        printf("NEQ\n");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for inequality comparison
        //code("if_icmpne");
        j_neq(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1617 "./build/y.tab.c"
    break;

  case 22: /* Expression: Expression LAN Expression  */
#line 184 "./compiler.y"
                                { 
        printf("LAN\n");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for logical AND
        //code("iand");
        j_lan(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1629 "./build/y.tab.c"
    break;

  case 23: /* Expression: Expression LOR Expression  */
#line 191 "./compiler.y"
                                { 
        printf("LOR\n");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for logical OR
        //code("ior");
        j_lor(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1641 "./build/y.tab.c"
    break;

  case 24: /* Expression: NOT Expression  */
#line 198 "./compiler.y"
                     { 
        printf("NOT\n");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for logical NOT
        //code("iconst_1");
        //code("ixor");
        j_not(&(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1654 "./build/y.tab.c"
    break;

  case 25: /* Expression: Expression BAN Expression  */
#line 206 "./compiler.y"
                                { 
        printf("BAN\n");
        (yyval.object_val).type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise AND
        //code("iand");
        j_ban(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1666 "./build/y.tab.c"
    break;

  case 26: /* Expression: Expression BOR Expression  */
#line 213 "./compiler.y"
                                { 
        printf("BOR\n");
        (yyval.object_val).type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise OR
        //code("ior");
        j_bor(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1678 "./build/y.tab.c"
    break;

  case 27: /* Expression: Expression BXO Expression  */
#line 220 "./compiler.y"
                                { 
        printf("BXO\n");
        (yyval.object_val).type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise XOR
        //code("ixor");
        j_bxo(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1690 "./build/y.tab.c"
    break;

  case 28: /* Expression: BNT Expression  */
#line 227 "./compiler.y"
                     { 
        printf("BNT\n");
        (yyval.object_val).type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise NOT
        //code("iconst_m1");
        //code("ixor");
        j_bnt(&(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1703 "./build/y.tab.c"
    break;

  case 29: /* Expression: Expression SHR Expression  */
#line 235 "./compiler.y"
                                { 
        printf("SHR\n");
        (yyval.object_val).type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise shift right
        //code("ishr");
        j_shr(&(yyvsp[-2].object_val), &(yyvsp[0].object_val), &(yyval.object_val));
    }
#line 1715 "./build/y.tab.c"
    break;

  case 30: /* Expression: STR_LIT  */
#line 242 "./compiler.y"
              { 
        printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var));
        (yyval.object_val).type = OBJECT_TYPE_STR;
        (yyval.object_val).symbol = (SymbolTable*)malloc(sizeof(SymbolTable));
        (yyval.object_val).symbol->name = (yyvsp[0].s_var);
        // Generate Jasmin code for string literal
        //code("ldc \"%s\"", $<s_var>1);
        j_strlit((yyvsp[0].s_var));
    }
#line 1729 "./build/y.tab.c"
    break;

  case 31: /* Expression: FLOAT_LIT  */
#line 251 "./compiler.y"
                { 
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_var));
        (yyval.object_val).type = OBJECT_TYPE_FLOAT;
        // Generate Jasmin code for float literal
        //code("ldc %f", $<f_var>1);
        j_floatlit((yyvsp[0].f_var));
    }
#line 1741 "./build/y.tab.c"
    break;

  case 32: /* Expression: BOOL_LIT  */
#line 258 "./compiler.y"
               { 
        printf("BOOL_LIT %s\n", (yyvsp[0].b_var) ? "TRUE" : "FALSE");
        (yyval.object_val).type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for boolean literal
        //code("iconst_%d", $<b_var>1 ? 1 : 0);
        j_boollit((yyvsp[0].b_var));
    }
#line 1753 "./build/y.tab.c"
    break;

  case 33: /* Expression: INT_LIT  */
#line 265 "./compiler.y"
              { 
        printf("INT_LIT %d\n", (yyvsp[0].i_var));
        (yyval.object_val).type = OBJECT_TYPE_INT;
        // Generate Jasmin code for integer literal
        //code("ldc %d", $<i_var>1);
        if (!(isMain && isReturning))
        {
            j_intlit((yyvsp[0].i_var));
        }
        else
        {
            isMain = 0;
            isReturning = 0;
        }
    }
#line 1773 "./build/y.tab.c"
    break;

  case 34: /* Expression: IDENT  */
#line 280 "./compiler.y"
            { 
        PrintIdent((yyvsp[0].s_var));
        (yyval.object_val).type = findType((yyvsp[0].s_var));
        (yyval.object_val).symbol = (SymbolTable*)malloc(sizeof(SymbolTable));
        (yyval.object_val).symbol->name = (yyvsp[0].s_var);
        // Generate Jasmin code for identifier (load variable)
        //code("iload %d", findIndex($<s_var>1));
        j_loadIdent((yyvsp[0].s_var));
    }
#line 1787 "./build/y.tab.c"
    break;

  case 35: /* Expression: '(' Expression ')'  */
#line 289 "./compiler.y"
                         { 
        (yyval.object_val) = (yyvsp[-1].object_val);
        // No need to generate code, just pass the value
    }
#line 1796 "./build/y.tab.c"
    break;

  case 36: /* Expression: '(' VARIABLE_T ')' Expression  */
#line 293 "./compiler.y"
                                               { 
        objCast((yyvsp[-2].var_type));
        (yyval.object_val).type = (yyvsp[-2].var_type);
        //$$.type = $<var_type>2;
        // Generate Jasmin code for casting
        //code("cast");
    }
#line 1808 "./build/y.tab.c"
    break;

  case 37: /* Expression: FuncCall  */
#line 300 "./compiler.y"
                          { 
        (yyval.object_val).type = returnType;
        // Generate Jasmin code for function call
        //code("invokestatic %s", getFuncSig($<s_var>1));
    }
#line 1818 "./build/y.tab.c"
    break;

  case 38: /* Expression: ArrCall  */
#line 305 "./compiler.y"
                         { 
        (yyval.object_val).type = tempType;
        // Generate Jasmin code for array access
        //code("aload %d", findIndex($<s_var>1));
    }
#line 1828 "./build/y.tab.c"
    break;

  case 39: /* $@2: %empty  */
#line 316 "./compiler.y"
                           { createFunction((yyvsp[-2].var_type), (yyvsp[-1].s_var)); }
#line 1834 "./build/y.tab.c"
    break;

  case 40: /* $@3: %empty  */
#line 316 "./compiler.y"
                                                                                                  { addFuncSignal((yyvsp[-4].var_type), VAR_FLAG_FUNCTION_RETURN); }
#line 1840 "./build/y.tab.c"
    break;

  case 41: /* $@4: %empty  */
#line 316 "./compiler.y"
                                                                                                                                                                     { j_createfunction((yyvsp[-6].s_var)); nowFuncName = (yyvsp[-6].s_var); }
#line 1846 "./build/y.tab.c"
    break;

  case 42: /* $@5: %empty  */
#line 316 "./compiler.y"
                                                                                                                                                                                                                                            { dumpScope(); }
#line 1852 "./build/y.tab.c"
    break;

  case 43: /* FunctionDefStmt: VARIABLE_T IDENT '(' $@2 FunctionParameterStmtList $@3 ')' '{' $@4 StmtList '}' $@5  */
#line 316 "./compiler.y"
                                                                                                                                                                                                                                                             { j_endfunction(); }
#line 1858 "./build/y.tab.c"
    break;

  case 47: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 324 "./compiler.y"
                       { pushFunParm((yyvsp[-1].var_type), (yyvsp[0].s_var), VAR_FLAG_DEFAULT); addFuncSignal((yyvsp[-1].var_type), VAR_FLAG_DEFAULT); }
#line 1864 "./build/y.tab.c"
    break;

  case 48: /* FunctionParameterStmt: VARIABLE_T IDENT '[' ']'  */
#line 325 "./compiler.y"
                               { pushFunParm((yyvsp[-3].var_type), (yyvsp[-2].s_var), VAR_FLAG_ARRAY); addFuncSignal((yyvsp[-3].var_type), VAR_FLAG_ARRAY); }
#line 1870 "./build/y.tab.c"
    break;

  case 52: /* Stmt: COUT CoutParmListStmt ';'  */
#line 342 "./compiler.y"
                                { stdoutPrint(); }
#line 1876 "./build/y.tab.c"
    break;

  case 53: /* $@6: %empty  */
#line 343 "./compiler.y"
             { isReturning = 1; if(strcmp(nowFuncName, "main") == 0) isMain = 1; }
#line 1882 "./build/y.tab.c"
    break;

  case 54: /* Stmt: RETURN $@6 Expression ';'  */
#line 343 "./compiler.y"
                                                                                                  { printf("RETURN\n"); j_return(nowFuncName); }
#line 1888 "./build/y.tab.c"
    break;

  case 61: /* Stmt: BREAK  */
#line 351 "./compiler.y"
            {  
        printf ("BREAK\n"); 
        if (whileOrFor == 0)
        {  
            j_breakWhile();
        }
        else if (whileOrFor == 1)
        {
            j_breakFor();
        }
    }
#line 1904 "./build/y.tab.c"
    break;

  case 62: /* Stmt: CONTINUE  */
#line 362 "./compiler.y"
               { printf ("CONTINUE\n"); }
#line 1910 "./build/y.tab.c"
    break;

  case 63: /* $@7: %empty  */
#line 363 "./compiler.y"
             { isReturning = 1; if(strcmp(nowFuncName, "main") == 0) isMain = 1; }
#line 1916 "./build/y.tab.c"
    break;

  case 64: /* Stmt: RETURN $@7  */
#line 363 "./compiler.y"
                                                                                   { printf ("RETURN\n"); j_return(nowFuncName); }
#line 1922 "./build/y.tab.c"
    break;

  case 65: /* $@8: %empty  */
#line 367 "./compiler.y"
                           { j_cout(); }
#line 1928 "./build/y.tab.c"
    break;

  case 66: /* CoutParmListStmt: CoutParmListStmt SHL $@8 Expression  */
#line 367 "./compiler.y"
                                                    { pushFunInParm(&(yyvsp[0].object_val)); }
#line 1934 "./build/y.tab.c"
    break;

  case 67: /* $@9: %empty  */
#line 368 "./compiler.y"
          { j_cout(); }
#line 1940 "./build/y.tab.c"
    break;

  case 68: /* CoutParmListStmt: SHL $@9 Expression  */
#line 368 "./compiler.y"
                                   { pushFunInParm(&(yyvsp[0].object_val)); }
#line 1946 "./build/y.tab.c"
    break;

  case 69: /* $@10: %empty  */
#line 381 "./compiler.y"
                 { tempType = (yyvsp[0].var_type); }
#line 1952 "./build/y.tab.c"
    break;

  case 73: /* Var: IDENT  */
#line 390 "./compiler.y"
            { 
        pushFunParm(tempType, (yyvsp[0].s_var), VAR_FLAG_DEFAULT); 
        tempName = (yyvsp[0].s_var); 
    }
#line 1961 "./build/y.tab.c"
    break;

  case 74: /* Var: IDENT VAL_ASSIGN Expression  */
#line 394 "./compiler.y"
                                  { 
        if (tempType == OBJECT_TYPE_AUTO)
        {
            tempType = (yyvsp[0].object_val).type;
        }
        pushFunParm(tempType, (yyvsp[-2].s_var), VAR_FLAG_DEFAULT);
        if ((yyvsp[0].object_val).type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && (yyvsp[0].object_val).type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && (yyvsp[0].object_val).type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_storeIdent((yyvsp[-2].s_var));
    }
#line 1985 "./build/y.tab.c"
    break;

  case 75: /* Var: IDENT '[' INT_LIT ']'  */
#line 413 "./compiler.y"
                            { 
        printf("create array: %d\n", arr_length); 
        j_intlit((yyvsp[-1].i_var));
        j_create1dArr(tempType);
        arr_length = 0; 
        pushFunParm(tempType, (yyvsp[-3].s_var), VAR_FLAG_ARRAY);
        
        j_storeArr((yyvsp[-3].s_var));
    }
#line 1999 "./build/y.tab.c"
    break;

  case 76: /* $@11: %empty  */
#line 422 "./compiler.y"
                            { 
        printf ("INT_LIT %d\n", (yyvsp[-1].i_var));
        j_intlit((yyvsp[-1].i_var));
    }
#line 2008 "./build/y.tab.c"
    break;

  case 77: /* $@12: %empty  */
#line 425 "./compiler.y"
                 { j_create1dArr(tempType); }
#line 2014 "./build/y.tab.c"
    break;

  case 78: /* Var: IDENT '[' INT_LIT ']' $@11 VAL_ASSIGN $@12 '{' InitArr '}'  */
#line 425 "./compiler.y"
                                                              { 
        printf("create array: %d\n", arr_length); 
        arr_length = 0; 
        pushFunParm(tempType, (yyvsp[-9].s_var), VAR_FLAG_ARRAY); 
        
        j_storeArr((yyvsp[-9].s_var));
    }
#line 2026 "./build/y.tab.c"
    break;

  case 79: /* Var: IDENT '[' INT_LIT ']' '[' INT_LIT ']'  */
#line 432 "./compiler.y"
                                            { 
        printf ("INT_LIT %d\n", (yyvsp[-4].i_var));
        j_intlit((yyvsp[-4].i_var));
        printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); 
        j_intlit((yyvsp[-1].i_var));
        PrintIdent((yyvsp[-6].s_var)); 
        j_create2dArr(tempType);
        arr_length = 0; 
        pushFunParm(tempType, (yyvsp[-6].s_var), VAR_FLAG_ARRAY); 
        
        j_storeArr((yyvsp[-6].s_var));
    }
#line 2043 "./build/y.tab.c"
    break;

  case 80: /* $@13: %empty  */
#line 444 "./compiler.y"
                                            { 
        printf ("INT_LIT %d\n", (yyvsp[-4].i_var)); 
        printf ("INT_LIT %d\n", (yyvsp[-1].i_var)); 
        PrintIdent((yyvsp[-6].s_var)); 
        printf ("INT_LIT %d\n", (yyvsp[-4].i_var)); 
    }
#line 2054 "./build/y.tab.c"
    break;

  case 81: /* Var: IDENT '[' INT_LIT ']' '[' INT_LIT ']' $@13 VAL_ASSIGN '{' InitArr '}'  */
#line 449 "./compiler.y"
                                 {
        arr_length = 0; 
        pushFunParm(tempType, (yyvsp[-11].s_var), VAR_FLAG_ARRAY); 
    }
#line 2063 "./build/y.tab.c"
    break;

  case 82: /* $@14: %empty  */
#line 458 "./compiler.y"
                  { j_init1dArr(tempType, arr_length); }
#line 2069 "./build/y.tab.c"
    break;

  case 83: /* InitArr: InitArr ',' $@14 Expression  */
#line 458 "./compiler.y"
                                                                    { arr_length ++; j_storeArrItem(); }
#line 2075 "./build/y.tab.c"
    break;

  case 84: /* $@15: %empty  */
#line 459 "./compiler.y"
      { j_init1dArr(tempType, arr_length); }
#line 2081 "./build/y.tab.c"
    break;

  case 85: /* InitArr: $@15 Expression  */
#line 459 "./compiler.y"
                                                        { arr_length ++; j_storeArrItem(); }
#line 2087 "./build/y.tab.c"
    break;

  case 87: /* $@16: %empty  */
#line 464 "./compiler.y"
            { j_loadArr((yyvsp[0].s_var)); }
#line 2093 "./build/y.tab.c"
    break;

  case 88: /* $@17: %empty  */
#line 464 "./compiler.y"
                                                   { PrintIdent((yyvsp[-2].s_var)); tempType = findType((yyvsp[-2].s_var)); }
#line 2099 "./build/y.tab.c"
    break;

  case 89: /* ArrCall: IDENT $@16 ArrayIndices $@17  */
#line 464 "./compiler.y"
                                                                                                              { j_loadArrItem(); }
#line 2105 "./build/y.tab.c"
    break;

  case 90: /* $@18: %empty  */
#line 472 "./compiler.y"
            { 
        PrintIdent((yyvsp[0].s_var)); 
        assignIdentName = (yyvsp[0].s_var); 
    }
#line 2114 "./build/y.tab.c"
    break;

  case 91: /* AssignVarStmt: IDENT $@18 AssignmentOperator  */
#line 475 "./compiler.y"
                         {
        tempType = findType((yyvsp[-2].s_var));
    }
#line 2122 "./build/y.tab.c"
    break;

  case 92: /* $@19: %empty  */
#line 478 "./compiler.y"
            { j_loadArr((yyvsp[0].s_var)); assignIdentName = (yyvsp[0].s_var); isStoringArr = 1; }
#line 2128 "./build/y.tab.c"
    break;

  case 93: /* $@20: %empty  */
#line 478 "./compiler.y"
                                                                                                  { PrintIdent((yyvsp[-2].s_var)); }
#line 2134 "./build/y.tab.c"
    break;

  case 94: /* AssignVarStmt: IDENT $@19 ArrayIndices $@20 AssignmentOperator  */
#line 478 "./compiler.y"
                                                                                                                                                { tempType = findType((yyvsp[-4].s_var)); j_storeArrItem(); }
#line 2140 "./build/y.tab.c"
    break;

  case 95: /* $@21: %empty  */
#line 483 "./compiler.y"
                       { j_load2dArrItem(); }
#line 2146 "./build/y.tab.c"
    break;

  case 98: /* AssignmentOperator: VAL_ASSIGN Expression  */
#line 490 "./compiler.y"
                            { 
        printf("EQL_ASSIGN\n");
        if ((yyvsp[0].object_val).type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && (yyvsp[0].object_val).type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && (yyvsp[0].object_val).type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        if (!isStoringArr)
        {
            j_storeIdent(assignIdentName);
        }
        else
        {
            isStoringArr = 0;
        }
    }
#line 2173 "./build/y.tab.c"
    break;

  case 99: /* AssignmentOperator: ADD_ASSIGN Expression  */
#line 512 "./compiler.y"
                            { 
        printf("ADD_ASSIGN\n");
        if ((yyvsp[0].object_val).type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && (yyvsp[0].object_val).type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && (yyvsp[0].object_val).type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_add_assign(assignIdentName);
    }
#line 2193 "./build/y.tab.c"
    break;

  case 100: /* AssignmentOperator: SUB_ASSIGN Expression  */
#line 527 "./compiler.y"
                            { 
        printf("SUB_ASSIGN\n"); 
        if ((yyvsp[0].object_val).type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && (yyvsp[0].object_val).type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && (yyvsp[0].object_val).type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_sub_assign(assignIdentName);
    }
#line 2213 "./build/y.tab.c"
    break;

  case 101: /* AssignmentOperator: MUL_ASSIGN Expression  */
#line 542 "./compiler.y"
                            { 
        printf("MUL_ASSIGN\n"); 
        if ((yyvsp[0].object_val).type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && (yyvsp[0].object_val).type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && (yyvsp[0].object_val).type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_mul_assign(assignIdentName);
    }
#line 2233 "./build/y.tab.c"
    break;

  case 102: /* AssignmentOperator: DIV_ASSIGN Expression  */
#line 557 "./compiler.y"
                            { 
        printf("DIV_ASSIGN\n"); 
        if ((yyvsp[0].object_val).type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && (yyvsp[0].object_val).type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && (yyvsp[0].object_val).type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_div_assign(assignIdentName);
    }
#line 2253 "./build/y.tab.c"
    break;

  case 103: /* AssignmentOperator: REM_ASSIGN Expression  */
#line 572 "./compiler.y"
                            { 
        printf("REM_ASSIGN\n");
        j_rem_assign(assignIdentName);
    }
#line 2262 "./build/y.tab.c"
    break;

  case 104: /* AssignmentOperator: BAN_ASSIGN Expression  */
#line 576 "./compiler.y"
                            { 
        printf("BAN_ASSIGN\n");
        j_ban_assign(assignIdentName);
    }
#line 2271 "./build/y.tab.c"
    break;

  case 105: /* AssignmentOperator: BOR_ASSIGN Expression  */
#line 580 "./compiler.y"
                            { 
        printf("BOR_ASSIGN\n");
        j_bor_assign(assignIdentName);
    }
#line 2280 "./build/y.tab.c"
    break;

  case 106: /* AssignmentOperator: BXO_ASSIGN Expression  */
#line 584 "./compiler.y"
                            { 
        printf("BXO_ASSIGN\n");
        j_bxo_assign(assignIdentName);
    }
#line 2289 "./build/y.tab.c"
    break;

  case 107: /* AssignmentOperator: SHR_ASSIGN Expression  */
#line 588 "./compiler.y"
                            { 
        printf("SHR_ASSIGN\n");
        j_shr_assign(assignIdentName);
    }
#line 2298 "./build/y.tab.c"
    break;

  case 108: /* AssignmentOperator: SHL_ASSIGN Expression  */
#line 592 "./compiler.y"
                            { 
        printf("SHL_ASSIGN\n");
        j_shl_assign(assignIdentName);
    }
#line 2307 "./build/y.tab.c"
    break;

  case 109: /* AssignmentOperator: INC_ASSIGN  */
#line 596 "./compiler.y"
                 { 
        printf("INC_ASSIGN\n"); 
        j_inc_assign(assignIdentName);
    }
#line 2316 "./build/y.tab.c"
    break;

  case 110: /* AssignmentOperator: DEC_ASSIGN  */
#line 600 "./compiler.y"
                 { 
        printf("DEC_ASSIGN\n"); 
        j_dec_assign(assignIdentName);
    }
#line 2325 "./build/y.tab.c"
    break;

  case 111: /* $@22: %empty  */
#line 608 "./compiler.y"
                            { j_ifbegin(); }
#line 2331 "./build/y.tab.c"
    break;

  case 112: /* $@23: %empty  */
#line 608 "./compiler.y"
                                                              { printf("IF\n"); pushScope(); }
#line 2337 "./build/y.tab.c"
    break;

  case 113: /* $@24: %empty  */
#line 608 "./compiler.y"
                                                                                                            { j_ifend(); }
#line 2343 "./build/y.tab.c"
    break;

  case 114: /* $@25: %empty  */
#line 608 "./compiler.y"
                                                                                                                           { dumpScope(); }
#line 2349 "./build/y.tab.c"
    break;

  case 116: /* $@26: %empty  */
#line 609 "./compiler.y"
                            { j_ifbegin(); }
#line 2355 "./build/y.tab.c"
    break;

  case 117: /* $@27: %empty  */
#line 609 "./compiler.y"
                                                          { printf("IF\n"); }
#line 2361 "./build/y.tab.c"
    break;

  case 118: /* $@28: %empty  */
#line 609 "./compiler.y"
                                                                                   { j_ifend(); }
#line 2367 "./build/y.tab.c"
    break;

  case 120: /* $@29: %empty  */
#line 613 "./compiler.y"
               { j_elsebegin(); }
#line 2373 "./build/y.tab.c"
    break;

  case 121: /* $@30: %empty  */
#line 613 "./compiler.y"
                                  { printf("ELSE\n"); pushScope(); }
#line 2379 "./build/y.tab.c"
    break;

  case 122: /* $@31: %empty  */
#line 613 "./compiler.y"
                                                                                  { j_elseend(); }
#line 2385 "./build/y.tab.c"
    break;

  case 123: /* ELSEStmt: ELSE '{' $@29 $@30 StmtList '}' $@31  */
#line 613 "./compiler.y"
                                                                                                   { dumpScope(); }
#line 2391 "./build/y.tab.c"
    break;

  case 124: /* ELSEStmt: %empty  */
#line 614 "./compiler.y"
      { j_elsebegin(); j_elseend(); }
#line 2397 "./build/y.tab.c"
    break;

  case 125: /* $@32: %empty  */
#line 629 "./compiler.y"
            { printf("WHILE\n"); whileOrFor = 0; }
#line 2403 "./build/y.tab.c"
    break;

  case 126: /* $@33: %empty  */
#line 629 "./compiler.y"
                                                   { j_whilebegin(); }
#line 2409 "./build/y.tab.c"
    break;

  case 127: /* $@34: %empty  */
#line 629 "./compiler.y"
                                                                                          { j_whilebodybegin(); }
#line 2415 "./build/y.tab.c"
    break;

  case 128: /* $@35: %empty  */
#line 629 "./compiler.y"
                                                                                                                      { pushScope(); }
#line 2421 "./build/y.tab.c"
    break;

  case 129: /* $@36: %empty  */
#line 629 "./compiler.y"
                                                                                                                                                    { j_whileend(); }
#line 2427 "./build/y.tab.c"
    break;

  case 130: /* WhileStmt: WHILE $@32 $@33 '(' Expression ')' $@34 '{' $@35 StmtList '}' $@36  */
#line 629 "./compiler.y"
                                                                                                                                                                      { dumpScope(); }
#line 2433 "./build/y.tab.c"
    break;

  case 131: /* $@37: %empty  */
#line 634 "./compiler.y"
          { printf("FOR\n"); whileOrFor = 1; }
#line 2439 "./build/y.tab.c"
    break;

  case 132: /* $@38: %empty  */
#line 634 "./compiler.y"
                                               { j_forbegin(); }
#line 2445 "./build/y.tab.c"
    break;

  case 133: /* $@39: %empty  */
#line 634 "./compiler.y"
                                                                 { pushScope(); }
#line 2451 "./build/y.tab.c"
    break;

  case 134: /* $@40: %empty  */
#line 634 "./compiler.y"
                                                                                                    { j_forbodybegin(); }
#line 2457 "./build/y.tab.c"
    break;

  case 135: /* $@41: %empty  */
#line 634 "./compiler.y"
                                                                                                                                       { j_forend(); }
#line 2463 "./build/y.tab.c"
    break;

  case 136: /* ForStmt: FOR $@37 $@38 $@39 '(' ForInside ')' $@40 '{' StmtList $@41 '}'  */
#line 634 "./compiler.y"
                                                                                                                                                           { dumpScope(); }
#line 2469 "./build/y.tab.c"
    break;

  case 138: /* ForInside: DeclareVarStmt ':' IDENT  */
#line 640 "./compiler.y"
                               { PrintIdent((yyvsp[0].s_var));  if (tempType == OBJECT_TYPE_AUTO) {
                                                          
                                                          findObjectByName(tempName)->type = findObjectByName((yyvsp[0].s_var))->type; } }
#line 2477 "./build/y.tab.c"
    break;

  case 142: /* $@42: %empty  */
#line 669 "./compiler.y"
      { j_forcondbegin(); }
#line 2483 "./build/y.tab.c"
    break;

  case 143: /* ForCondition: $@42 Expression  */
#line 669 "./compiler.y"
                                       { j_forcondend(); }
#line 2489 "./build/y.tab.c"
    break;

  case 145: /* $@43: %empty  */
#line 674 "./compiler.y"
      { j_forupdatebegin(); }
#line 2495 "./build/y.tab.c"
    break;

  case 146: /* ForUpdate: $@43 AssignVarStmt  */
#line 674 "./compiler.y"
                                            { j_forupdateend(); }
#line 2501 "./build/y.tab.c"
    break;

  case 148: /* $@44: %empty  */
#line 680 "./compiler.y"
                          { PrintIdent((yyvsp[-2].s_var)); }
#line 2507 "./build/y.tab.c"
    break;

  case 149: /* $@45: %empty  */
#line 680 "./compiler.y"
                                                     { returnType = checkFunction((yyvsp[-3].s_var)); }
#line 2513 "./build/y.tab.c"
    break;

  case 150: /* FuncCall: IDENT '(' ParamList $@44 $@45 ')'  */
#line 680 "./compiler.y"
                                                                                                    { j_callFunc((yyvsp[-5].s_var)); }
#line 2519 "./build/y.tab.c"
    break;


#line 2523 "./build/y.tab.c"

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

#line 691 "./compiler.y"

/* C code section */
