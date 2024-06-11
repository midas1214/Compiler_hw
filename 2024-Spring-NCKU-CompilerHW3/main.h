#ifndef MAIN_H
#define MAIN_H
#include "compiler_common.h"

#define code(format, ...) \
    fprintf(yyout, "%*s" format "\n", scopeLevel << 2, "", __VA_ARGS__)
#define codeRaw(code) \
    fprintf(yyout, "%*s" code "\n", scopeLevel << 2, "")

extern FILE* yyout;
extern FILE* yyin;
extern bool compileError;
extern int scopeLevel;
int yyparse();
int yylex();
int yylex_destroy();


//FILE *thefile;


#define VAR_FLAG_DEFAULT 0
#define VAR_FLAG_ARRAY 0b00000001
#define VAR_FLAG_POINTER 0b00000010
#define VAR_FLAG_FUNCTION_RETURN 0b00000011



void pushScope();
void dumpScope();

Object* findVariable(char* variableName);
Object* createVariable(ObjectType variableType, char* variableName, int variableFlag);

// Object* findVariable(char* variableName);
// bool initVariable(ObjectType variableType, LinkedList* arraySubscripts, char* variableName);
// Object* createVariable(ObjectType variableType, LinkedList* arraySubscripts, char* variableName, Object* value);

// void functionLocalsBegin();
// void functionParmPush(ObjectType variableType, LinkedList* arraySubscripts, char* variableName);
// void functionBegin(ObjectType returnType, LinkedList* arraySubscripts, char* funcName);
// bool functionEnd(ObjectType returnType);

// bool returnObject(Object* obj);
// bool breakLoop();

// void functionArgsBegin();
// void functionArgPush(Object* obj);
// void functionCall(char* funcName, Object* out);

// bool stdoutPrint(Object* obj);




void pushFunParm(ObjectType variableType, char* variableName, int parmFlag);
void createFunction(ObjectType variableType, char* funcName);
void pushFunInParm(Object* b);

void PrintIdent(char *idname);
ObjectType findType(char *idname);
void addFuncSignal(ObjectType type, int variableFlag);
bool objCast(ObjectType variableType);
ObjectType checkFunction(char *idname);
Object* findObjectByName(char* name);

int findIdentAddr(char* name);

void stdoutPrint();
void j_cout();


void j_add(Object* a, Object* b, Object* out);
void j_sub(Object* a, Object* b, Object* out);
void j_mul(Object* a, Object* b, Object* out);
void j_div(Object* a, Object* b, Object* out);
void j_rem();
void j_neg(Object* a, Object* out);
void j_gtr(Object* a, Object* b, Object* out);
void j_les(Object* a, Object* b, Object* out);
void j_geq(Object* a, Object* b, Object* out);
void j_leq(Object* a, Object* b, Object* out);
void j_not(Object* a, Object* out);
void j_ban(Object* a, Object* b, Object* out);
void j_bor(Object* a, Object* b, Object* out);
void j_bxo(Object* a, Object* b, Object* out);
void j_bnt(Object* a, Object* out);
void j_shr(Object* a, Object* b, Object* out);
void j_lan(Object* a, Object* b, Object* out);
void j_lor(Object* a, Object* b, Object* out);
void j_neq(Object* a, Object* b, Object* out);
void j_eql(Object* a, Object* b, Object* out);


void j_strlit(char* strlit);
void j_intlit(int intlit);
void j_floatlit(float floatlit);
void j_boollit(bool boollit);


void j_storeIdent(char* idname);
void j_loadIdent(char* idname);
void j_add_assign(char* idname);
void j_sub_assign(char* idname);
void j_mul_assign(char* idname);
void j_div_assign(char* idname);
void j_rem_assign(char* idname);
void j_ban_assign(char* idname);
void j_bor_assign(char* idname);
void j_bxo_assign(char* idname);
void j_shr_assign(char* idname);
void j_shl_assign(char* idname);
void j_inc_assign(char* idname);
void j_dec_assign(char* idname);

void j_f2i();
void j_i2f();

void j_ifbegin();
void j_ifend();
void j_elsebegin();
void j_elseend();

void j_whilebegin();
void j_whilebodybegin();
void j_whileend();
void j_breakWhile();

void j_forbegin();
void j_forinitbegin();
void j_forcondbegin();
void j_forcondend();
void j_forupdatebegin();
void j_forupdateend();
void j_forbodybegin();
void j_forend();
void j_breakFor();

void j_createfunction(char* funcName);
void j_endfunction();
void j_return(char* funcName);
void j_callFunc(char* funcName);

void j_create1dArr(ObjectType numType);
void j_init1dArr(ObjectType numType, int numIndex);
void j_storeArrItem();
void j_storeArr(char* arrName);
void j_loadArr(char* arrName);
void j_loadArrItem();
void j_create2dArr(ObjectType numType);
void j_load2dArr(char* arrName);
void j_load2dArrItem();


// Expressions
bool objectExpression(char op, Object* a, Object* b, Object* out);
bool objectExpBinary(char op, Object* a, Object* b, Object* out);
bool objectExpBoolean(char op, Object* a, Object* b, Object* out);
bool objectNotBinaryExpression(Object* a, Object* out);
bool objectNotBooleanExpression(Object* a, Object* out);
bool objectNegExpression(Object* a, Object* out);
bool objectIncAssign(Object* a, Object* out);
bool objectDecAssign(Object* a, Object* out);
bool objectCast(ObjectType variableType, Object* a, Object* out);
bool objectExpAssign(char op, Object* dest, Object* val, Object* out);
bool objectValueAssign(Object* dest, Object* val, Object* out);

bool ifBegin(Object* a);
bool ifEnd();
bool ifOnlyEnd();
bool elseBegin();
bool elseEnd();

bool whileBegin();
bool whileBodyBegin();
bool whileEnd();

bool forBegin();
bool forInitEnd();
bool forConditionEnd(Object* result);
bool forHeaderEnd();
bool foreachHeaderEnd(Object* obj);
bool forEnd();

// bool arrayCreate(Object* out);
// bool objectArrayGet(Object* arr, LinkedList* arraySubscripts, Object* out);
// LinkedList* arraySubscriptBegin(Object* index);
// bool arraySubscriptPush(LinkedList* arraySubscripts, Object* index);
// bool arraySubscriptEnd(LinkedList* arraySubscripts);

#endif