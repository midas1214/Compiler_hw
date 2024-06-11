/* Definition section */
%{
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
%nonassoc CALL
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
    : Expression ADD Expression { 
        printf("ADD\n");
        // Generate Jasmin code for addition
        //code("iadd");
        j_add(&$<object_val>1, &$<object_val>3, &$$);
        $$.type = $<object_val>1.type;
    }
    | Expression SUB Expression { 
        printf("SUB\n");
        // Generate Jasmin code for subtraction
        //code("isub");
        j_sub(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression MUL Expression { 
        printf("MUL\n");
        // Generate Jasmin code for multiplication
        //code("imul");
        j_mul(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression DIV Expression { 
        printf("DIV\n");
        // Generate Jasmin code for division
        //code("idiv");
        j_div(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression REM Expression { 
        printf("REM\n");
        $$.type = OBJECT_TYPE_INT;
        // Generate Jasmin code for remainder
        //code("irem");
        j_rem();
    }
    | SUB Expression %prec UMINUS { 
        printf("NEG\n");
        $$.type = $<object_val>2.type;
        // Generate Jasmin code for negation
        //code("ineg");
        j_neg(&$<object_val>2, &$$);
    }
    | Expression GTR Expression { 
        printf("GTR\n");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for greater than comparison
        //code("if_icmpgt");
        j_gtr(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression LES Expression { 
        printf("LES\n");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for less than comparison
        //code("if_icmplt");
        j_les(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression GEQ Expression { 
        printf("GEQ\n");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for greater than or equal comparison
        //code("if_icmpge");
        j_geq(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression LEQ Expression { 
        printf("LEQ\n");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for less than or equal comparison
        //code("if_icmple");
        j_leq(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression EQL Expression { 
        printf("EQL\n");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for equality comparison
        //code("if_icmpeq");
        j_eql(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression NEQ Expression { 
        printf("NEQ\n");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for inequality comparison
        //code("if_icmpne");
        j_neq(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression LAN Expression { 
        printf("LAN\n");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for logical AND
        //code("iand");
        j_lan(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression LOR Expression { 
        printf("LOR\n");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for logical OR
        //code("ior");
        j_lor(&$<object_val>1, &$<object_val>3, &$$);
    }
    | NOT Expression { 
        printf("NOT\n");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for logical NOT
        //code("iconst_1");
        //code("ixor");
        j_not(&$<object_val>2, &$$);
    }
    | Expression BAN Expression { 
        printf("BAN\n");
        $$.type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise AND
        //code("iand");
        j_ban(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression BOR Expression { 
        printf("BOR\n");
        $$.type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise OR
        //code("ior");
        j_bor(&$<object_val>1, &$<object_val>3, &$$);
    }
    | Expression BXO Expression { 
        printf("BXO\n");
        $$.type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise XOR
        //code("ixor");
        j_bxo(&$<object_val>1, &$<object_val>3, &$$);
    }
    | BNT Expression { 
        printf("BNT\n");
        $$.type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise NOT
        //code("iconst_m1");
        //code("ixor");
        j_bnt(&$<object_val>2, &$$);
    }
    | Expression SHR Expression { 
        printf("SHR\n");
        $$.type = OBJECT_TYPE_INT;
        // Generate Jasmin code for bitwise shift right
        //code("ishr");
        j_shr(&$<object_val>1, &$<object_val>3, &$$);
    }
    | STR_LIT { 
        printf("STR_LIT \"%s\"\n", $<s_var>1);
        $$.type = OBJECT_TYPE_STR;
        $$.symbol = (SymbolTable*)malloc(sizeof(SymbolTable));
        $$.symbol->name = $<s_var>1;
        // Generate Jasmin code for string literal
        //code("ldc \"%s\"", $<s_var>1);
        j_strlit($<s_var>1);
    }
    | FLOAT_LIT { 
        printf("FLOAT_LIT %f\n", $<f_var>1);
        $$.type = OBJECT_TYPE_FLOAT;
        // Generate Jasmin code for float literal
        //code("ldc %f", $<f_var>1);
        j_floatlit($<f_var>1);
    }
    | BOOL_LIT { 
        printf("BOOL_LIT %s\n", $<b_var>1 ? "TRUE" : "FALSE");
        $$.type = OBJECT_TYPE_BOOL;
        // Generate Jasmin code for boolean literal
        //code("iconst_%d", $<b_var>1 ? 1 : 0);
        j_boollit($<b_var>1);
    }
    | INT_LIT { 
        printf("INT_LIT %d\n", $<i_var>1);
        $$.type = OBJECT_TYPE_INT;
        // Generate Jasmin code for integer literal
        //code("ldc %d", $<i_var>1);
        if (!(isMain && isReturning))
        {
            j_intlit($<i_var>1);
        }
        else
        {
            isMain = 0;
            isReturning = 0;
        }
    }
    | IDENT { 
        PrintIdent($<s_var>1);
        $$.type = findType($<s_var>1);
        $$.symbol = (SymbolTable*)malloc(sizeof(SymbolTable));
        $$.symbol->name = $<s_var>1;
        // Generate Jasmin code for identifier (load variable)
        //code("iload %d", findIndex($<s_var>1));
        j_loadIdent($<s_var>1);
    }
    | '(' Expression ')' { 
        $$ = $<object_val>2;
        // No need to generate code, just pass the value
    }
    | '(' VARIABLE_T ')' Expression %prec CAST { 
        objCast($<var_type>2);
        $$.type = $<var_type>2;
        //$$.type = $<var_type>2;
        // Generate Jasmin code for casting
        //code("cast");
    }
    | FuncCall %prec CALL { 
        $$.type = returnType;
        // Generate Jasmin code for function call
        //code("invokestatic %s", getFuncSig($<s_var>1));
    }
    | ArrCall %prec CALL { 
        $$.type = tempType;
        // Generate Jasmin code for array access
        //code("aload %d", findIndex($<s_var>1));
    }
;



/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT '(' { createFunction($<var_type>1, $<s_var>2); } FunctionParameterStmtList { addFuncSignal($<var_type>1, VAR_FLAG_FUNCTION_RETURN); } ')' '{' { j_createfunction($<s_var>2); nowFuncName = $<s_var>2; } StmtList '}' { dumpScope(); } { j_endfunction(); }
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
    | RETURN { isReturning = 1; if(strcmp(nowFuncName, "main") == 0) isMain = 1; } Expression ';' { printf("RETURN\n"); j_return(nowFuncName); }
    | DeclareVarStmt ';' /* int a = 5; or int a[5] = {} */
    /*| DeclareVarWithoutAssignStmt ';' {  } */
    | AssignVarStmt ';'
    | IfStmt
    | WhileStmt
    | ForStmt
    | FuncCall ';'
    | BREAK {  
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
    | CONTINUE { printf ("CONTINUE\n"); }
    | RETURN { isReturning = 1; if(strcmp(nowFuncName, "main") == 0) isMain = 1; } { printf ("RETURN\n"); j_return(nowFuncName); }
;

CoutParmListStmt
    : CoutParmListStmt SHL { j_cout(); } Expression { pushFunInParm(&$<object_val>4); } /* push expression */
    | SHL { j_cout(); } Expression { pushFunInParm(&$<object_val>3); }
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
    : IDENT { 
        pushFunParm(tempType, $<s_var>1, VAR_FLAG_DEFAULT); 
        tempName = $<s_var>1; 
    }
    | IDENT VAL_ASSIGN Expression { 
        if (tempType == OBJECT_TYPE_AUTO)
        {
            tempType = $<object_val>3.type;
        }
        pushFunParm(tempType, $<s_var>1, VAR_FLAG_DEFAULT);
        if ($<object_val>3.type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && $<object_val>3.type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && $<object_val>3.type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_storeIdent($<s_var>1);
    }
    | IDENT '[' INT_LIT ']' { 
        printf("create array: %d\n", arr_length); 
        j_intlit($<i_var>3);
        j_create1dArr(tempType);
        arr_length = 0; 
        pushFunParm(tempType, $<s_var>1, VAR_FLAG_ARRAY);
        
        j_storeArr($<s_var>1);
    } 
    | IDENT '[' INT_LIT ']' { 
        printf ("INT_LIT %d\n", $<i_var>3);
        j_intlit($<i_var>3);
    } VAL_ASSIGN { j_create1dArr(tempType); } '{' InitArr '}' { 
        printf("create array: %d\n", arr_length); 
        arr_length = 0; 
        pushFunParm(tempType, $<s_var>1, VAR_FLAG_ARRAY); 
        
        j_storeArr($<s_var>1);
    }
    | IDENT '[' INT_LIT ']' '[' INT_LIT ']' { 
        printf ("INT_LIT %d\n", $<i_var>3);
        j_intlit($<i_var>3);
        printf ("INT_LIT %d\n", $<i_var>6); 
        j_intlit($<i_var>6);
        PrintIdent($<s_var>1); 
        j_create2dArr(tempType);
        arr_length = 0; 
        pushFunParm(tempType, $<s_var>1, VAR_FLAG_ARRAY); 
        
        j_storeArr($<s_var>1);
    } 
    | IDENT '[' INT_LIT ']' '[' INT_LIT ']' { 
        printf ("INT_LIT %d\n", $<i_var>3); 
        printf ("INT_LIT %d\n", $<i_var>6); 
        PrintIdent($<s_var>1); 
        printf ("INT_LIT %d\n", $<i_var>3); 
    } VAL_ASSIGN '{' InitArr '}' {
        arr_length = 0; 
        pushFunParm(tempType, $<s_var>1, VAR_FLAG_ARRAY); 
    }
;



InitArr
    : InitArr ',' { j_init1dArr(tempType, arr_length); } Expression { arr_length ++; j_storeArrItem(); }
    | { j_init1dArr(tempType, arr_length); } Expression { arr_length ++; j_storeArrItem(); }
    |
;

ArrCall
    : IDENT { j_loadArr($<s_var>1); } ArrayIndices { PrintIdent($<s_var>1); tempType = findType($<s_var>1); } { j_loadArrItem(); }
;





AssignVarStmt
    : IDENT { 
        PrintIdent($<s_var>1); 
        assignIdentName = $<s_var>1; 
    } AssignmentOperator {
        tempType = findType($<s_var>1);
    }
    | IDENT { j_loadArr($<s_var>1); assignIdentName = $<s_var>1; isStoringArr = 1; } ArrayIndices { PrintIdent($<s_var>1); } AssignmentOperator { tempType = findType($<s_var>1); j_storeArrItem(); } /* array */
;


ArrayIndices
    : ArrayIndices '[' { j_load2dArrItem(); } Expression ']'   /* construct 2D array */
    | '[' Expression ']' /* construct 1D array */
    ;



AssignmentOperator
    : VAL_ASSIGN Expression { 
        printf("EQL_ASSIGN\n");
        if ($<object_val>2.type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && $<object_val>2.type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && $<object_val>2.type == OBJECT_TYPE_INT)
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
    | ADD_ASSIGN Expression { 
        printf("ADD_ASSIGN\n");
        if ($<object_val>2.type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && $<object_val>2.type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && $<object_val>2.type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_add_assign(assignIdentName);
    }
    | SUB_ASSIGN Expression { 
        printf("SUB_ASSIGN\n"); 
        if ($<object_val>2.type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && $<object_val>2.type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && $<object_val>2.type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_sub_assign(assignIdentName);
    }
    | MUL_ASSIGN Expression { 
        printf("MUL_ASSIGN\n"); 
        if ($<object_val>2.type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && $<object_val>2.type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && $<object_val>2.type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_mul_assign(assignIdentName);
    }
    | DIV_ASSIGN Expression { 
        printf("DIV_ASSIGN\n"); 
        if ($<object_val>2.type != tempType)
        {
            if (tempType == OBJECT_TYPE_INT && $<object_val>2.type == OBJECT_TYPE_FLOAT)
            {
                j_f2i();
            }
            else if (tempType == OBJECT_TYPE_FLOAT && $<object_val>2.type == OBJECT_TYPE_INT)
            {
                j_i2f();
            }
        }
        j_div_assign(assignIdentName);
    }
    | REM_ASSIGN Expression { 
        printf("REM_ASSIGN\n");
        j_rem_assign(assignIdentName);
    }
    | BAN_ASSIGN Expression { 
        printf("BAN_ASSIGN\n");
        j_ban_assign(assignIdentName);
    }
    | BOR_ASSIGN Expression { 
        printf("BOR_ASSIGN\n");
        j_bor_assign(assignIdentName);
    }
    | BXO_ASSIGN Expression { 
        printf("BXO_ASSIGN\n");
        j_bxo_assign(assignIdentName);
    }
    | SHR_ASSIGN Expression { 
        printf("SHR_ASSIGN\n");
        j_shr_assign(assignIdentName);
    }
    | SHL_ASSIGN Expression { 
        printf("SHL_ASSIGN\n");
        j_shl_assign(assignIdentName);
    }
    | INC_ASSIGN { 
        printf("INC_ASSIGN\n"); 
        j_inc_assign(assignIdentName);
    } // i++
    | DEC_ASSIGN { 
        printf("DEC_ASSIGN\n"); 
        j_dec_assign(assignIdentName);
    } // i--
;


IfStmt
    : IF '(' Expression ')' { j_ifbegin(); } '{' %prec IFELSE { printf("IF\n"); pushScope(); } StmtList '}' { j_ifend(); } { dumpScope(); } ELSEStmt
    | IF '(' Expression ')' { j_ifbegin(); } %prec IFELSE { printf("IF\n"); } Stmt { j_ifend(); } ELSEStmt
;

ELSEStmt
    : ELSE '{' { j_elsebegin(); } { printf("ELSE\n"); pushScope(); } StmtList '}' { j_elseend(); } { dumpScope(); }
    | { j_elsebegin(); j_elseend(); } 
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
    : WHILE { printf("WHILE\n"); whileOrFor = 0; } { j_whilebegin(); } '(' Expression ')' { j_whilebodybegin(); } '{' { pushScope(); } StmtList '}' { j_whileend(); } { dumpScope(); }
;


ForStmt
    : FOR { printf("FOR\n"); whileOrFor = 1; } { j_forbegin(); } { pushScope(); } '(' ForInside ')' { j_forbodybegin(); } '{' StmtList { j_forend(); } '}' { dumpScope(); }
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
    : { j_forcondbegin(); } Expression { j_forcondend(); }
    | /* Empty condition */
;

ForUpdate
    : { j_forupdatebegin(); } AssignVarStmt { j_forupdateend(); }
    | /* Empty update */
;


FuncCall
    : IDENT '(' ParamList { PrintIdent($<s_var>1); } { returnType = checkFunction($<s_var>1); } ')' { j_callFunc($<s_var>1); }
;

ParamList
    : Expression
    | ParamList ',' Expression
;
 
    

    
%%
/* C code section */