/* Definition section */
%{
    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;
    ObjectType tempType = OBJECT_TYPE_INT;
    ObjectType returnType = OBJECT_TYPE_INT;
    Object* tempObject = NULL;
    char *tempName = NULL;
    int arr_length = 0;
%}

/* Variable or self-defined structure */
%union {
    ObjectType var_type;

    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val; /* compiler_common.h */
}

/* Token without return */
%token COUT
%token SHR SHL BAN BOR BNT BXO ADD SUB MUL DIV REM NOT GTR LES GEQ LEQ EQL NEQ LAN LOR
%token VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN INC_ASSIGN DEC_ASSIGN
%token IF ELSE FOR WHILE RETURN BREAK CONTINUE


/* Token with return, which need to sepcify type */
%token <var_type> VARIABLE_T
%token <s_var> IDENT
// TODO
%token <s_var> STR_LIT
%token <b_var> BOOL_LIT
%token <i_var> INT_LIT
%token <f_var> FLOAT_LIT


/* Nonterminal with return, which need to sepcify type */
%type <object_val> Expression /* Expression return type <object_val> */


/* TODO: precedence */
%nonassoc IFELSE // Define a new precedence level for if-else
%right VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN
%left LOR
%left LAN
%left BOR
%left BXO
%left BAN
%left BNT
%left EQL NEQ
%left GTR LES GEQ LEQ
%left SHR SHL
%left ADD SUB
%left MUL DIV REM
%right NOT INC_ASSIGN DEC_ASSIGN
%nonassoc UMINUS
%right CALL
%nonassoc CAST // Define a new precedence level for cast

/* Yacc will start at this nonterminal */
%start Program

%%
/* Grammar section */

Program
    : { pushScope(); } GlobalStmtList { dumpScope(); }
    | /* Empty file */
;

GlobalStmtList 
    : GlobalStmtList GlobalStmt
    | GlobalStmt
;

GlobalStmt
    : DefineVariableStmt
    | FunctionDefStmt
;

/* int x = 5 */
DefineVariableStmt
    : VARIABLE_T IDENT VAL_ASSIGN Expression ';'
;

/* TODO */
Expression
    /*: Expression ADD Expression { if(objectExpression('+', &$<object_val>1, &$<object_val>3, &$$)) YYABORT; }*/
    /*| Expression SUB Expression { if(objectExpression('-', &$<object_val>1, &$<object_val>3, &$$)) YYABORT; }*/
    : Expression ADD Expression { printf("ADD\n"); }
    | Expression SUB Expression { printf("SUB\n"); }
    | Expression MUL Expression { printf("MUL\n"); }
    | Expression DIV Expression { printf("DIV\n"); }
    | Expression REM Expression { printf("REM\n"); $$.type = OBJECT_TYPE_INT; }
    | SUB Expression %prec UMINUS { printf("NEG\n"); $$.type = OBJECT_TYPE_INT; }
    | Expression GTR Expression { printf("GTR\n"); $$.type = OBJECT_TYPE_BOOL; }
    | Expression LES Expression { printf("LES\n"); $$.type = OBJECT_TYPE_BOOL; }
    | Expression GEQ Expression { printf("GEQ\n"); $$.type = OBJECT_TYPE_BOOL; }
    | Expression LEQ Expression { printf("LEQ\n"); $$.type = OBJECT_TYPE_BOOL; }
    | Expression EQL Expression { printf("EQL\n"); $$.type = OBJECT_TYPE_BOOL; }
    | Expression NEQ Expression { printf("NEQ\n"); $$.type = OBJECT_TYPE_BOOL; }
    | Expression LAN Expression { printf("LAN\n"); $$.type = OBJECT_TYPE_BOOL; }
    | Expression LOR Expression { printf("LOR\n"); $$.type = OBJECT_TYPE_BOOL; }
    | NOT Expression { printf("NOT\n"); $$.type = OBJECT_TYPE_BOOL; }
    | Expression BAN Expression { printf("BAN\n"); $$.type = OBJECT_TYPE_INT; }
    | Expression BOR Expression { printf("BOR\n"); $$.type = OBJECT_TYPE_INT; }
    | Expression BXO Expression { printf("BXO\n"); $$.type = OBJECT_TYPE_INT; }
    | BNT Expression { printf("BNT\n"); $$.type = OBJECT_TYPE_INT; }
    | Expression SHR Expression { printf("SHR\n"); $$.type = OBJECT_TYPE_BOOL; }
    | STR_LIT { printf ("STR_LIT \"%s\"\n", $<s_var>1); $$.type = OBJECT_TYPE_STR; }
    | FLOAT_LIT { printf ("FLOAT_LIT %f\n", $<f_var>1); $$.type = OBJECT_TYPE_FLOAT; }
    | BOOL_LIT { printf("BOOL_LIT %s\n", $<b_var>1 ? "TRUE" : "FALSE"); $$.type = OBJECT_TYPE_BOOL; }
    | INT_LIT { printf ("INT_LIT %d\n", $<i_var>1); $$.type = OBJECT_TYPE_INT; }
    | IDENT { PrintIdent($<s_var>1); $$.type = findType($<s_var>1); }
    | '(' Expression ')' { $$ = $<object_val>2; }
    /*| '(' VARIABLE_T ')' { tempType = $<var_type>1;  printf("Cast to %s\n", objectTypeName[$<var_type>1]); }*/
    | '(' VARIABLE_T ')' Expression %prec CAST { objCast($<var_type>2); }
    | FuncCall %prec CALL { $$.type = returnType; }
    | ArrCall %prec CALL { $$.type = tempType; }
;




/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT '(' { createFunction($<var_type>1, $<s_var>2); } FunctionParameterStmtList { addFuncSignal($<var_type>1, VAR_FLAG_FUNCTION_RETURN); } ')' '{' {} StmtList '}' { dumpScope(); }
;
FunctionParameterStmtList 
    : FunctionParameterStmtList ',' FunctionParameterStmt
    | FunctionParameterStmt
    | /* Empty function parameter */
;
FunctionParameterStmt
    : VARIABLE_T IDENT { pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT); addFuncSignal($<var_type>1, VAR_FLAG_DEFAULT); }
    | VARIABLE_T IDENT '[' ']' { pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_ARRAY); addFuncSignal($<var_type>1, VAR_FLAG_ARRAY); } /* string argv[] */
;



/* TODO */



/* Scope */
StmtList 
    : StmtList Stmt
    | Stmt
;

Stmt
    : ';'
    | COUT CoutParmListStmt ';' { stdoutPrint(); } /* cout << "Hello World" << endl; */
    | RETURN Expression ';' { printf("RETURN\n"); }
    | DeclareVarStmt ';' /* int a = 5; or int a[5] = {} */
    /*| DeclareVarWithoutAssignStmt ';' {  } */
    | AssignVarStmt ';'
    | IfStmt
    | WhileStmt
    | ForStmt
    | FuncCall ';'
    | BREAK { printf ("BREAK\n"); }
    | CONTINUE { printf ("CONTINUE\n"); }
    | RETURN { printf ("RETURN\n"); }
;

CoutParmListStmt
    : CoutParmListStmt SHL Expression { pushFunInParm(&$<object_val>3); } /* push expression */
    | SHL Expression { pushFunInParm(&$<object_val>2); }
;


/*
int a;
int a,b;
int a = 5;
int a = 5, b = 5...;
int a , b, c = 5 ;
*/

DeclareVarStmt
    : VARIABLE_T { tempType = $<var_type>1; } VarList
;

VarList
    : Var
    | VarList ',' Var
;

Var
    : IDENT { pushFunParm(tempType, $<s_var>1, VAR_FLAG_DEFAULT); tempName = $<s_var>1; }
    | IDENT VAL_ASSIGN Expression { if (tempType == OBJECT_TYPE_AUTO) tempType = $<object_val>3.type; pushFunParm(tempType, $<s_var>1, VAR_FLAG_DEFAULT); }
    | IDENT '[' INT_LIT ']' { printf("create array: %d\n", arr_length); arr_length = 0; pushFunParm(tempType, $<s_var>1, VAR_FLAG_ARRAY); } 
    | IDENT '[' INT_LIT ']' { printf ("INT_LIT %d\n", $<i_var>3); } VAL_ASSIGN '{' InitArr '}' { printf("create array: %d\n", arr_length) ; arr_length = 0 ; pushFunParm(tempType, $<s_var>1, VAR_FLAG_ARRAY); }
    | IDENT '[' INT_LIT ']' '[' INT_LIT ']' { printf ("INT_LIT %d\n", $<i_var>3); printf ("INT_LIT %d\n", $<i_var>6); PrintIdent($<s_var>1); }{ arr_length = 0; pushFunParm(tempType, $<s_var>1, VAR_FLAG_ARRAY); } 
    | IDENT '[' INT_LIT ']' '[' INT_LIT ']' { printf ("INT_LIT %d\n", $<i_var>3); printf ("INT_LIT %d\n", $<i_var>6); PrintIdent($<s_var>1); } { printf ("INT_LIT %d\n", $<i_var>3); } VAL_ASSIGN '{' InitArr '}' { arr_length = 0 ; pushFunParm(tempType, $<s_var>1, VAR_FLAG_ARRAY); }
;



InitArr
    : InitArr ',' Expression { arr_length ++; }
    | Expression { arr_length ++; }
    |
;

ArrCall
    : IDENT '[' Expression ']' { PrintIdent($<s_var>1); tempType = findType($<s_var>1); }
    | IDENT '[' Expression ']' '[' Expression ']' { PrintIdent($<s_var>1); tempType = findType($<s_var>1); }
;


AssignVarStmt
    : IDENT { PrintIdent($<s_var>1); } AssignmentOperator
    | IDENT '[' Expression ']' { PrintIdent($<s_var>1); } AssignmentOperator /* array */
    | IDENT '[' Expression ']' '[' Expression ']' { PrintIdent($<s_var>1); } AssignmentOperator
;


AssignmentOperator
    : VAL_ASSIGN Expression { printf("EQL_ASSIGN\n"); }
    | ADD_ASSIGN Expression { printf("ADD_ASSIGN\n"); }
    | SUB_ASSIGN Expression { printf("SUB_ASSIGN\n"); }
    | MUL_ASSIGN Expression { printf("MUL_ASSIGN\n"); }
    | DIV_ASSIGN Expression { printf("DIV_ASSIGN\n"); }
    | REM_ASSIGN Expression { printf("REM_ASSIGN\n"); }
    | BAN_ASSIGN Expression { printf("BAN_ASSIGN\n"); }
    | BOR_ASSIGN Expression { printf("BOR_ASSIGN\n"); }
    | BXO_ASSIGN Expression { printf("BXO_ASSIGN\n"); }
    | SHR_ASSIGN Expression { printf("SHR_ASSIGN\n"); }
    | SHL_ASSIGN Expression { printf("SHL_ASSIGN\n"); }
    | INC_ASSIGN { printf("INC_ASSIGN\n"); } /* i++ */
    | DEC_ASSIGN { printf("DEC_ASSIGN\n"); } /* i++ */
;



IfStmt
    : IF '(' Expression ')' '{' %prec IFELSE { printf("IF\n"); pushScope(); } StmtList '}' { dumpScope(); } ELSEStmt
    | IF '(' Expression ')'  %prec IFELSE { printf("IF\n"); } StmtList ELSEStmt
;

ELSEStmt
    : ELSE '{' { printf("ELSE\n"); pushScope(); } StmtList '}' { dumpScope(); }
    |
/*
ElseIfStmtList
    : ElseIfStmt
    | ElseIfStmtList ElseIfStmt
;

ElseIfStmt
    : ELSE IF '(' Expression ')' '{' { printf("ELSE IF\n"); pushScope(); } StmtList '}'
    | 
;
*/


WhileStmt
    : WHILE { printf("WHILE\n"); } '(' Expression ')' '{' { pushScope(); } StmtList '}' { dumpScope(); }
;


ForStmt
    : FOR { printf("FOR\n"); }  { pushScope(); } '(' ForInside ')' '{' StmtList '}' { dumpScope(); }
;


ForInside
    : ForInit ';' ForCondition ';' ForUpdate
    | DeclareVarStmt ':' IDENT { PrintIdent($<s_var>3);  if (tempType == OBJECT_TYPE_AUTO) {
                                                          
                                                          findObjectByName(tempName)->type = findObjectByName($<s_var>3)->type; } }
;


ForInit
    : DeclareVarStmt
    | AssignVarStmt
    | /* Empty initialization */
;

/*
DeclareVarStmtFor
    : VARIABLE_T { tempType = $<var_type>1; } VarListFor
;

VarListFor
    : VarFor
    | VarListFor ',' VarFor
;

VarFor
    : IDENT VAL_ASSIGN Expression { if (tempType == OBJECT_TYPE_AUTO) tempType = $<object_val>3.type; pushFunParm(tempType, $<s_var>1, VAR_FLAG_DEFAULT); }
;
*/


ForCondition
    : Expression
    | /* Empty condition */
;

ForUpdate
    : AssignVarStmt
    | /* Empty update */
;


FuncCall
    : IDENT '(' ParamList { PrintIdent($<s_var>1); } { returnType = checkFunction($<s_var>1); } ')'
;

ParamList
    : Expression
    | ParamList ',' Expression
;
 
    

    
%%
/* C code section */