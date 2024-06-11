#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define WJCL_LINKED_LIST_IMPLEMENTATION
#include "main.h"
#define WJCL_HASH_MAP_IMPLEMENTATION
//#include "value_operation.h"

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)

#define iload(var) code("iload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lload(var) code("lload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fload(var) code("fload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dload(var) code("dload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define aload(var) code("aload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)

#define istore(var) code("istore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lstore(var) code("lstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fstore(var) code("fstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dstore(var) code("dstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define astore(var) code("astore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)

#define ldz(val) code("ldc %d", getBool(val))
#define ldb(val) code("ldc %d", getByte(val))
#define ldc(val) code("ldc %d", getChar(val))
#define lds(val) code("ldc %d", getShort(val))
#define ldi(val) code("ldc %d", getInt(val))
#define ldl(val) code("ldc_w %" PRId64, getLong(val))
#define ldf(val) code("ldc %.6f", getFloat(val))
#define ldd(val) code("ldc_w %lf", getDouble(val))
#define ldt(val) code("ldc \"%s\"", getString(val))

const char* objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_BYTE] = "byte",
    [OBJECT_TYPE_CHAR] = "char",
    [OBJECT_TYPE_SHORT] = "short",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_LONG] = "long",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_DOUBLE] = "double",
    [OBJECT_TYPE_STR] = "string",
    [OBJECT_TYPE_FUNCTION] = "function",
};
const char* objectJavaTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "V",
    [OBJECT_TYPE_VOID] = "V",
    [OBJECT_TYPE_BOOL] = "Z",
    [OBJECT_TYPE_BYTE] = "B",
    [OBJECT_TYPE_CHAR] = "C",
    [OBJECT_TYPE_SHORT] = "S",
    [OBJECT_TYPE_INT] = "I",
    [OBJECT_TYPE_LONG] = "J",
    [OBJECT_TYPE_FLOAT] = "F",
    [OBJECT_TYPE_DOUBLE] = "D",
    [OBJECT_TYPE_STR] = "Ljava/lang/String;",
};





char* yyInputFileName;
bool compileError;

int indent = 0;
int scopeLevel = -1;
int funcLineNo = 0;
int variableAddress = 0;
ObjectType variableIdentType;

int addrGlobal = 0;




FILE *thefile;

int boolcnt = 0;
int gtrcnt = 0;
int lescnt = 0;
int geqcnt = 0;
int leqcnt = 0;
int lancnt = 0;
int lorcnt = 0;
int neqcnt = 0;
int eqlcnt = 0;

int ifcnt = 0;
int elsecnt = 0;

int whilecnt = 0;

int forcnt = 0;
int currentfor = 0;

int funcnt = 0;

int last_addr = 0;
int hasReturn = 0;

// TODO

// Function to create a new symbol table entry
SymbolTable* createSymbolTable(char *name, int addr, int lineno, char *func_sig, int scopelvl) {
    SymbolTable* symbol = (SymbolTable*)malloc(sizeof(SymbolTable));
    if (symbol == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    symbol->name = name; // Allocate memory for the name and copy the string
    symbol->addr = addr;
    symbol->lineno = lineno;
    symbol->func_sig = func_sig; // Allocate memory for the function signature and copy the string
    symbol->scopelvl = scopelvl;
    return symbol;
}

// Function to create a new object entry
Object* createObject(ObjectType type, uint64_t value, SymbolTable* symbol) {
    Object* object = (Object*)malloc(sizeof(Object));
    if (object == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    object->type = type;
    object->value = value;
    object->symbol = symbol;
    object->next = NULL;
    return object;
}


//SymbolTable* symbolTableStack = NULL;
Object* symbolTableStack = NULL;
Object* coutStack = NULL;


// Function to push a symbol table onto the stack
// void push(Object** stack, char *name, ObjectType type, int addr, int lineno, char *func_sig, int scopelvl) {
//     SymbolTable* newSymbol = createSymbolTable(name, type, addr, lineno, func_sig, scopelvl);
//     newSymbol->next = *stack;
//     *stack = newSymbol;
// }

// Function to push a symbol table onto the stack
void push(Object** stack, Object* obj) {
    obj->next = *stack;
    *stack = obj;
}

// void push(Object *obj) {
//     obj->next = symbolTableStack;
//     symbolTableStack = obj;
// }

void pushCoutStack(Object *obj) {
    obj->next = coutStack;
    coutStack = obj;
}

// Function to pop a symbol table from the stack
// SymbolTable* pop(SymbolTable** stack) {
//     if (*stack == NULL) {
//         return NULL;
//     }
//     SymbolTable* poppedSymbol = *stack;
//     *stack = (*stack)->next;
//     poppedSymbol->next = NULL;
//     return poppedSymbol;
// }
// Object* pop() {
//     if (symbolTableStack == NULL) {
//         return NULL;
//     }
//     Object* poppedObj = symbolTableStack;
//     symbolTableStack = symbolTableStack->next;
//     poppedObj->next = NULL;
//     return poppedObj;
// }
// Function to pop a symbol table from the stack
Object* pop(Object** stack) {
    if (*stack == NULL) {
        return NULL;
    }
    Object* poppedObj = *stack;
    *stack = (*stack)->next;
    poppedObj->next = NULL;
    return poppedObj;
}

Object* popCoutStack() {
    if (coutStack == NULL) {
        return NULL;
    }
    Object* poppedObj = coutStack;
    coutStack = coutStack->next;
    poppedObj->next = NULL;
    return poppedObj;
}

// Function to peek at the top symbol table in the stack
// SymbolTable* peek(SymbolTable* stack) {
//     if (stack == NULL) {
//         return NULL;
//     }
//     return stack;
// }

// Function to peek at the top symbol table in the stack
Object* peek(Object* stack) {
    if (stack == NULL) {
        return NULL;
    }
    return stack;
}
// Object* peek() {
//     return symbolTableStack;
// }

Object* findObjectByName(char* name) {
    Object* current = symbolTableStack;
    while (current != NULL) {
        if (current->symbol != NULL)
        {
            if (strcmp(current->symbol->name, name) == 0) {
                return current; // Found the symbol
            }
        }
        current = current->next;
    }
    return NULL; // Symbol not found
}

Object* findObjectByType(ObjectType type) {
    Object* current = symbolTableStack;
    while (current != NULL) {
        if (current->type == type) {
            return current; // Found the object
        }
        current = current->next;
    }
    return NULL; // Symbol not found
}

Object* findFuncByName(char* name) {
    Object* current = symbolTableStack;
    while (current != NULL) {
        if (current->symbol != NULL)
        {
            if (strcmp(current->symbol->name, name) == 0 && current->type == OBJECT_TYPE_FUNCTION) {
                return current; // Found the symbol
            }
        }
        current = current->next;
    }
    return NULL; // funct not found
}


// Function to free the memory allocated for a symbol table entry
void freeSymbol(SymbolTable* symbol) {
    if (symbol == NULL) {
        return;
    }
    free(symbol->name); // Free the memory allocated for the name
    free(symbol->func_sig); // Free the memory allocated for the function signature
    free(symbol); // Free the memory allocated for the symbol table
}


void pushScope() {
    scopeLevel++;
    printf("> Create symbol table (scope level %d)\n", scopeLevel);
}

// void dumpScope() {
//     printf("\n> Dump symbol table (scope level: %d)\n", scopeLevel);
//     printf("%-10s%-20s%-10s%-10s%-10s%-10s\n", "Index", "Name","Type", "Addr", "Lineno", "Func_sig");

    
//     int index = 0, level = 0, nextLevel = 0;
//     do
//     {
//         SymbolTable* symbol = pop(&symbolTableStack);
//         if (symbol == NULL)
//         {
//             break;
//         }
//         printf("%-10d%-20s%-10s%-10d%-10d%-10s\n", index, symbol->name, objectTypeName[symbol->type], symbol->addr, symbol->lineno, symbol->func_sig);
//         level = symbol->scopelvl;
//         SymbolTable* nextSymbol = peek(symbolTableStack);
//         if (nextSymbol == NULL)
//         {
//             break;
//         }
//         nextLevel = nextSymbol->scopelvl;
//         index++;
//     } while ( level == nextLevel );

//     scopeLevel--;
// }

void dumpScope() {
    printf("\n> Dump symbol table (scope level: %d)\n", scopeLevel);
    printf("%-10s%-20s%-10s%-10s%-10s%-10s\n", "Index", "Name","Type", "Addr", "Lineno", "Func_sig");

    Object* obj = peek(symbolTableStack);
    if (obj == NULL)
    {
        return;
    }
    
    int index = 0, level = obj->symbol->scopelvl;
    Object *dumpStack = NULL;
    while (level == scopeLevel)
    {
        Object* obj = pop(&symbolTableStack);
        push(&dumpStack, obj);
        Object* nextObj = peek(symbolTableStack);
        if (nextObj == NULL)
        {
            break;
        }
        level = nextObj->symbol->scopelvl;
    }

    Object *topObj;
    while((topObj = pop(&dumpStack)) != NULL) // pop all cout params
    {
        printf("%-10d%-20s%-10s%-10d%-10d%-10s\n", index, topObj->symbol->name, objectTypeName[topObj->type], topObj->symbol->addr, topObj->symbol->lineno, topObj->symbol->func_sig);
        //last_addr = topObj->symbol->addr;
        free(topObj);
        index++;
    }

    scopeLevel--;
}

Object* createVariable(ObjectType variableType, char* variableName, int variableFlag) {
    return NULL;
}

// void pushFunParm(ObjectType variableType, char* variableName, int variableFlag) {
//     printf("> Insert `%s` (addr: %d) to scope level %d\n", variableName, addrGlobal, scopeLevel);
//     push(&symbolTableStack, variableName, variableType, addrGlobal, yylineno, "hi", scopeLevel);
// }

void pushFunParm(ObjectType variableType, char* variableName, int variableFlag) {
    SymbolTable *newSymbol;
    if (scopeLevel == 0)
    {
        printf("> Insert `%s` (addr: %d) to scope level %d\n", variableName, -1, scopeLevel);
        newSymbol = createSymbolTable(variableName, -1, yylineno, "-", scopeLevel);
    }
    else 
    {
        printf("> Insert `%s` (addr: %d) to scope level %d\n", variableName, addrGlobal, scopeLevel);
        newSymbol = createSymbolTable(variableName, addrGlobal, yylineno, "-", scopeLevel);
        addrGlobal++;
    }

    Object *newObject = createObject(variableType, 1, newSymbol);
    push(&symbolTableStack, newObject);
}

// void createFunction(ObjectType variableType, char* funcName) {
//     // TODO
//     printf("func: %s\n", funcName);
//     printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, addrGlobal, scopeLevel);
//     push(&symbolTableStack, funcName, OBJECT_TYPE_FUNCTION, addrGlobal, yylineno, "hi", scopeLevel);
//     addrGlobal++;
//     pushScope();
// }

void createFunction(ObjectType variableType, char* funcName) {
    // TODO
    printf("func: %s\n", funcName);
    SymbolTable *newSymbol;
    last_addr = addrGlobal;
    if (scopeLevel == 0)
    {
        printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, -1, scopeLevel);
        newSymbol = createSymbolTable(funcName, -1, yylineno, "(", scopeLevel);
    }
    else 
    {
        printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, addrGlobal, scopeLevel);
        newSymbol = createSymbolTable(funcName, addrGlobal, yylineno, "(", scopeLevel);
        addrGlobal++;
    }
    Object *newObject = createObject(OBJECT_TYPE_FUNCTION, 1, newSymbol);
    push(&symbolTableStack, newObject);
    pushScope();
}

void debugPrintInst(char instc, Object* a, Object* b, Object* out) {
}






void j_add(Object* a, Object* b, Object* out) {
    // if (out->type == OBJECT_TYPE_INT)
    // {
    //     fprintf(thefile, "\tiadd\n");
    // }
    // else if (out->type == OBJECT_TYPE_FLOAT)
    // {
    //     fprintf(thefile, "\tfadd\n");
    // }
    if (a->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tiadd\n");
        if (out->type != a->type)
        {
            fprintf(thefile, "\ti2f\n");
        }
    }
    else if (a->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfadd\n");
        if (out->type != a->type)
        {
            fprintf(thefile, "\tf2i\n");
        }
    }
    else if (a->type == OBJECT_TYPE_BOOL)
    {
        fprintf(thefile, "\tiadd\n");
        if (out->type != a->type)
        {
            fprintf(thefile, "\tf2i\n");
        }
    }
}

void j_sub(Object* a, Object* b, Object* out) {
    if (out->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tisub\n");
    }
    else if (out->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfsub\n");
    }
}

void j_mul(Object* a, Object* b, Object* out) {
    if (out->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\timul\n");
    }
    else if (out->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfmul\n");
    }
}

void j_div(Object* a, Object* b, Object* out) {
    if (out->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tidiv\n");
    }
    else if (out->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfdiv\n");
    }
}

void j_rem() {
    fprintf(thefile, "\tirem\n");
}

void j_neg(Object* a, Object* out) {
    if (out->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tineg\n");
    }
    else if (out->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfneg\n");
    }
}

void j_gtr(Object* a, Object* b, Object* out) {
    if (a->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tif_icmpgt L_gtr%d\n", gtrcnt);
        fprintf(thefile, "\ticonst_0\n");
        fprintf(thefile, "\tgoto L_after_gtr%d\n", gtrcnt);
        fprintf(thefile, "L_gtr%d:\n", gtrcnt);
        fprintf(thefile, "\ticonst_1\n");
        fprintf(thefile, "L_after_gtr%d:\n", gtrcnt);
    }
    else if (a->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfcmpl\n");
        fprintf(thefile, "\tifgt L_gtr%d\n", gtrcnt);
        fprintf(thefile, "\ticonst_0\n");
        fprintf(thefile, "\tgoto L_after_gtr%d\n", gtrcnt);
        fprintf(thefile, "L_gtr%d:\n", gtrcnt);
        fprintf(thefile, "\ticonst_1\n");
        fprintf(thefile, "L_after_gtr%d:\n", gtrcnt);
    }
    gtrcnt++;
}

void j_les(Object* a, Object* b, Object* out) {
    if (a->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tif_icmplt L_les%d\n", lescnt);
        fprintf(thefile, "\ticonst_0\n");
        fprintf(thefile, "\tgoto L_after_les%d\n", lescnt);
        fprintf(thefile, "L_les%d:\n", lescnt);
        fprintf(thefile, "\ticonst_1\n");
        fprintf(thefile, "L_after_les%d:\n", lescnt);
    }
    else if (a->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfcmpl\n");
        fprintf(thefile, "\tiflt L_les%d\n", lescnt);
        fprintf(thefile, "\ticonst_0\n");
        fprintf(thefile, "\tgoto L_after_les%d\n", lescnt);
        fprintf(thefile, "L_les%d:\n", lescnt);
        fprintf(thefile, "\ticonst_1\n");
        fprintf(thefile, "L_after_les%d:\n", lescnt);
    }
    lescnt++;
}

void j_geq(Object* a, Object* b, Object* out) {
    if (a->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tif_icmpge L_geq%d\n", geqcnt);
        fprintf(thefile, "\ticonst_0\n");
        fprintf(thefile, "\tgoto L_after_geq%d\n", geqcnt);
        fprintf(thefile, "L_geq%d:\n", geqcnt);
        fprintf(thefile, "\ticonst_1\n");
        fprintf(thefile, "L_after_geq%d:\n", geqcnt);
    }
    else if (a->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfcmpl\n");
        fprintf(thefile, "\tifge L_geq%d\n", geqcnt);
        fprintf(thefile, "\ticonst_0\n");
        fprintf(thefile, "\tgoto L_after_geq%d\n", geqcnt);
        fprintf(thefile, "L_geq%d:\n", gtrcnt);
        fprintf(thefile, "\ticonst_1\n");
        fprintf(thefile, "L_after_geq%d:\n", geqcnt);
    }
    geqcnt++;
}

void j_leq(Object* a, Object* b, Object* out) {
    if (a->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tif_icmple L_leq%d\n", leqcnt);
        fprintf(thefile, "\ticonst_0\n");
        fprintf(thefile, "\tgoto L_after_leq%d\n", leqcnt);
        fprintf(thefile, "L_leq%d:\n", leqcnt);
        fprintf(thefile, "\ticonst_1\n");
        fprintf(thefile, "L_after_leq%d:\n", leqcnt);
    }
    else if (a->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfcmpl\n");
        fprintf(thefile, "\tifle L_leq%d\n", leqcnt);
        fprintf(thefile, "\ticonst_0\n");
        fprintf(thefile, "\tgoto L_after_leq%d\n", leqcnt);
        fprintf(thefile, "L_leq%d:\n", leqcnt);
        fprintf(thefile, "\ticonst_1\n");
        fprintf(thefile, "L_after_leq%d:\n", leqcnt);
    }
    leqcnt++;
}

void j_not(Object* a, Object* out) {
    fprintf(thefile, "\ticonst_1\n");
    fprintf(thefile, "\tixor\n");
    
}

void j_ban(Object* a, Object* b, Object* out) {
    fprintf(thefile, "\tiand\n");
    
}

void j_bor(Object* a, Object* b, Object* out) {
    fprintf(thefile, "\tior\n");
    
}

void j_bxo(Object* a, Object* b, Object* out) {
    fprintf(thefile, "\tixor\n");
    
}

void j_bnt(Object* a, Object* out) {
    fprintf(thefile, "\ticonst_m1\n");
    fprintf(thefile, "\tixor\n");
    
}

void j_shr(Object* a, Object* b, Object* out) {
    fprintf(thefile, "\tiushr\n");
    
}


void j_lan(Object* a, Object* b, Object* out) {
    fprintf(thefile, "\tiand\n");
    fprintf(thefile, "\tifne L_lan%d\n", lancnt);
    fprintf(thefile, "\ticonst_0\n");
    fprintf(thefile, "\tgoto L_after_lan%d\n", lancnt);
    fprintf(thefile, "L_lan%d:\n", lancnt);
    fprintf(thefile, "\ticonst_1\n");
    fprintf(thefile, "L_after_lan%d:\n", lancnt);
    lancnt++;
}

void j_lor(Object* a, Object* b, Object* out) {
    fprintf(thefile, "\tior\n");
    fprintf(thefile, "\tifne L_lor%d\n", lorcnt);
    fprintf(thefile, "\ticonst_0\n");
    fprintf(thefile, "\tgoto L_after_lor%d\n", lorcnt);
    fprintf(thefile, "L_lor%d:\n", lorcnt);
    fprintf(thefile, "\ticonst_1\n");
    fprintf(thefile, "L_after_lor%d:\n", lorcnt);
    lorcnt++;
}

void j_neq(Object* a, Object* b, Object* out) {
    fprintf(thefile, "\tif_icmpne L_neq%d\n", neqcnt);
    fprintf(thefile, "\ticonst_0\n");
    fprintf(thefile, "\tgoto L_after_neq%d\n", neqcnt);
    fprintf(thefile, "L_neq%d:\n", neqcnt);
    fprintf(thefile, "\ticonst_1\n");
    fprintf(thefile, "L_after_neq%d:\n", neqcnt);
    neqcnt++;
}

void j_eql(Object* a, Object* b, Object* out) {
    fprintf(thefile, "\tif_icmpeq L_eql%d\n", eqlcnt);
    fprintf(thefile, "\ticonst_0\n");
    fprintf(thefile, "\tgoto L_after_eql%d\n", eqlcnt);
    fprintf(thefile, "L_eql%d:\n", eqlcnt);
    fprintf(thefile, "\ticonst_1\n");
    fprintf(thefile, "L_after_eql%d:\n", eqlcnt);
    eqlcnt++;
}




void j_strlit(char* strlit) {
    fprintf(thefile, "\tldc \"%s\";\n", strlit);
}

void j_intlit(int intlit) {
    fprintf(thefile, "\tldc %d\n", intlit);
}

void j_floatlit(float floatlit) {
    fprintf(thefile, "\tldc %f\n", floatlit);
}

void j_boollit(bool boollit) {
    fprintf(thefile, "\ticonst_%d\n", boollit ? 1 : 0);
}




void j_storeIdent(char* idname) {
    Object* found = findObjectByName(idname);
    //printf("%d\n", found->symbol->addr);
    if (found != NULL)
    {
        if (found->type == OBJECT_TYPE_INT)
        { 
            fprintf(thefile, "\tistore %d\n", found->symbol->addr - last_addr);
        }
        else if (found->type == OBJECT_TYPE_FLOAT)
        { 
            fprintf(thefile, "\tfstore %d\n", found->symbol->addr - last_addr);
        }
        else if (found->type == OBJECT_TYPE_STR)
        { 
            fprintf(thefile, "\tastore %d\n", found->symbol->addr - last_addr);
        }
        else if (found->type == OBJECT_TYPE_BOOL)
        { 
            fprintf(thefile, "\tistore %d\n", found->symbol->addr - last_addr);
        }
    }

}

void j_loadIdent(char* idname) {
    Object* found = findObjectByName(idname);
    if (found != NULL)
    {
        if (found->type == OBJECT_TYPE_INT)
        { 
            fprintf(thefile, "\tiload %d\n", found->symbol->addr - last_addr);
        }
        else if (found->type == OBJECT_TYPE_FLOAT)
        { 
            fprintf(thefile, "\tfload %d\n", found->symbol->addr - last_addr);
        }
        else if (found->type == OBJECT_TYPE_STR)
        { 
            fprintf(thefile, "\taload %d\n", found->symbol->addr - last_addr);
        }
        else if (found->type == OBJECT_TYPE_BOOL)
        {
            fprintf(thefile, "\tiload %d\n", found->symbol->addr - last_addr);
        }
    }

}

void j_add_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    Object* found = findObjectByName(idname);
    if (found != NULL)
    {
        if (found->type == OBJECT_TYPE_INT)
        { 
            fprintf(thefile, "\tiadd\n");
        }
        else if (found->type == OBJECT_TYPE_FLOAT)
        { 
            fprintf(thefile, "\tfadd\n");
        }
    }
    j_storeIdent(idname);
}

void j_sub_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    Object* found = findObjectByName(idname);
    if (found != NULL)
    {
        if (found->type == OBJECT_TYPE_INT)
        { 
            fprintf(thefile, "\tisub\n");
        }
        else if (found->type == OBJECT_TYPE_FLOAT)
        { 
            fprintf(thefile, "\tfsub\n");
        }
    }
    j_storeIdent(idname);
}

void j_mul_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    Object* found = findObjectByName(idname);
    if (found != NULL)
    {
        if (found->type == OBJECT_TYPE_INT)
        { 
            fprintf(thefile, "\timul\n");
        }
        else if (found->type == OBJECT_TYPE_FLOAT)
        { 
            fprintf(thefile, "\tfmul\n");
        }
    }
    j_storeIdent(idname);
}

void j_div_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    Object* found = findObjectByName(idname);
    if (found != NULL)
    {
        if (found->type == OBJECT_TYPE_INT)
        { 
            fprintf(thefile, "\tidiv\n");
        }
        else if (found->type == OBJECT_TYPE_FLOAT)
        { 
            fprintf(thefile, "\tfdiv\n");
        }
    }
    j_storeIdent(idname);
}

void j_rem_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    fprintf(thefile, "\tirem\n");
    j_storeIdent(idname);
}

void j_ban_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    Object* found = findObjectByName(idname);
    fprintf(thefile, "\tiand\n");
    j_storeIdent(idname);
}

void j_bor_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    Object* found = findObjectByName(idname);
    fprintf(thefile, "\tior\n");
    j_storeIdent(idname);
}

void j_bxo_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    Object* found = findObjectByName(idname);
    fprintf(thefile, "\tixor\n");
    j_storeIdent(idname);
}

void j_shr_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    Object* found = findObjectByName(idname);
    fprintf(thefile, "\tiushr\n");
    j_storeIdent(idname);
}

void j_shl_assign(char* idname) {
    j_loadIdent(idname);
    fprintf(thefile, "\tswap\n");
    Object* found = findObjectByName(idname);
    fprintf(thefile, "\tishl\n");
    j_storeIdent(idname);
}

void j_inc_assign(char* idname) {
    j_loadIdent(idname);
    Object* found = findObjectByName(idname);
    if (found != NULL)
    {
        if (found->type == OBJECT_TYPE_INT)
        { 
            fprintf(thefile, "\tldc 1\n");
            fprintf(thefile, "\tiadd\n");
        }
        else if (found->type == OBJECT_TYPE_FLOAT)
        { 
            fprintf(thefile, "\tldc 1.0\n");
            fprintf(thefile, "\tfadd\n");
        }
    }
    j_storeIdent(idname);
}

void j_dec_assign(char* idname) {
    j_loadIdent(idname);
    Object* found = findObjectByName(idname);
    if (found != NULL)
    {
        if (found->type == OBJECT_TYPE_INT)
        { 
            fprintf(thefile, "\tldc 1\n");
            fprintf(thefile, "\tisub\n");
        }
        else if (found->type == OBJECT_TYPE_FLOAT)
        { 
            fprintf(thefile, "\tldc 1.0\n");
            fprintf(thefile, "\tfsub\n");
        }
    }
    j_storeIdent(idname);
}




void j_f2i() {
    fprintf(thefile, "\tf2i\n");
}

void j_i2f() {
    fprintf(thefile, "\ti2f\n");
}




void j_ifbegin() {
    fprintf(thefile, "\tifeq L_after_if%d\n", ifcnt);
}

void j_ifend() {
    fprintf(thefile, "\tgoto L_after_else%d\n", elsecnt);
    fprintf(thefile, "L_after_if%d:\n", ifcnt);
    ifcnt++;
}

void j_elsebegin() {
    fprintf(thefile, "L_before_else%d:\n", elsecnt);
}

void j_elseend() {
    fprintf(thefile, "L_after_else%d:\n", elsecnt);
    elsecnt++;
}


void j_whilebegin() {
    fprintf(thefile, "L_while_start%d:\n", whilecnt);
}

void j_whilebodybegin() {
    fprintf(thefile, "\tifeq L_after_while%d\n", whilecnt);
}

void j_whileend() {
    fprintf(thefile, "\tgoto L_while_start%d\n", whilecnt);
    fprintf(thefile, "L_after_while%d:\n", whilecnt);
    whilecnt++;
}

void j_breakWhile() {
    fprintf(thefile, "\tgoto L_after_while%d\n", whilecnt);
}


void j_forbegin() {
    forcnt++;
    currentfor = forcnt;
    fprintf(thefile, "L_for_start%d:\n", forcnt);
}

void j_forinitbegin() {
    fprintf(thefile, "L_for_init_start%d:\n", forcnt);
}

void j_forcondbegin() {
    fprintf(thefile, "L_for_cond_start%d:\n", forcnt);
}

void j_forcondend() {
    fprintf(thefile, "\tifeq L_after_for%d\n", forcnt);
    fprintf(thefile, "\tgoto L_for_body_start%d\n", forcnt);
}

void j_forupdatebegin() {
    fprintf(thefile, "L_for_update_start%d:\n", forcnt);
}

void j_forupdateend() {
    fprintf(thefile, "\tgoto L_for_cond_start%d\n", forcnt);
}

void j_forbodybegin() {
    fprintf(thefile, "L_for_body_start%d:\n", forcnt);
}

void j_forend() {
    fprintf(thefile, "\tgoto L_for_update_start%d\n", currentfor);
    fprintf(thefile, "L_after_for%d:\n", currentfor);
    currentfor--;
}

void j_breakFor() {
    fprintf(thefile, "\tgoto L_after_for%d\n", forcnt);
}


void j_createfunction(char* funcName) {
    Object* found = findFuncByName(funcName);
    char *sig = found->symbol->func_sig;
    if (strcmp(funcName, "main") == 0)
    {
        fprintf(thefile, ".method public static main([Ljava/lang/String;)V\n");
        fprintf(thefile, ".limit stack 100\n");
        fprintf(thefile, ".limit locals 100\n");
    }
    else
    {
        fprintf(thefile, ".method public static %s%s\n", funcName, sig);
        fprintf(thefile, ".limit stack 100\n");
        fprintf(thefile, ".limit locals 100\n");
    }
    //if (sig[strlen(sig) - 1] == 'B')
    //{
    //    fprintf(thefile, ".method public static %s([Ljava/lang/String;)V\n", funcName);
    //    fprintf(thefile, ".limit stack 100\n");
    //    fprintf(thefile, ".limit locals 100\n");
    //}
    
}

void j_endfunction() {
    if (hasReturn == 0)
    {
        fprintf(thefile, "\treturn\n");
    }
    hasReturn = 0;
    //fprintf(thefile, "L_end_function%d:\n", funcnt);
    fprintf(thefile, ".end method\n");
    funcnt++;
}

void j_return(char* funcName) {
    ObjectType funcReturnType = checkFunction(funcName);
    if (funcReturnType == OBJECT_TYPE_INT)
    {
        if (strcmp(funcName, "main") == 0)
        {
            fprintf(thefile, "\treturn\n");
        }
        else
        {
            fprintf(thefile, "\tireturn\n");
        }
    }
    else if (funcReturnType == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tfreturn\n");
    }
    else if (funcReturnType == OBJECT_TYPE_BOOL)
    {
        fprintf(thefile, "\tireturn\n");
    }
    else if (funcReturnType == OBJECT_TYPE_CHAR)
    {
        fprintf(thefile, "\tareturn\n");
    }
    else if (funcReturnType == OBJECT_TYPE_VOID)
    {
        fprintf(thefile, "\treturn\n");
    }
    else if (funcReturnType == OBJECT_TYPE_STR)
    {
        fprintf(thefile, "\tareturn\n");
    }
    
    //fprintf(thefile, "\tgoto L_end_function%d\n", funcnt);
    hasReturn = 1;
}

void j_callFunc(char* funcName) {
    Object* found = findFuncByName(funcName);
    char *sig = found->symbol->func_sig;
    fprintf(thefile, "\tinvokestatic Main/%s%s\n", funcName, sig);
}


void j_create1dArr(ObjectType numType) {
    if (numType == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tnewarray int\n");
    }
    else if (numType == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tnewarray float\n");
    }
    

}

void j_init1dArr(ObjectType numType, int numIndex) {

    fprintf(thefile, "\tdup\n");
    fprintf(thefile, "\tldc %d\n", numIndex);
}

void j_storeArrItem() {
    fprintf(thefile, "\tiastore\n");
}

void j_storeArr(char* arrName) {
    Object* found = findObjectByName(arrName);
    if (found != NULL)
    {
        fprintf(thefile, "\tastore %d\n", found->symbol->addr - last_addr);
    }
}

void j_loadArr(char* arrName) {
    Object* found = findObjectByName(arrName);
    if (found != NULL)
    {
        fprintf(thefile, "\taload %d\n", found->symbol->addr - last_addr);
    }
}

void j_loadArrItem() {
    fprintf(thefile, "\tiaload\n");
}

void j_create2dArr(ObjectType numType) {
    if (numType == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tmultianewarray [[I 2\n");
    }
    else if (numType == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tmultianewarray [[F 2\n");
    }
    

}

void j_load2dArr(char* arrName) {
    Object* found = findObjectByName(arrName);
    if (found != NULL)
    {
        fprintf(thefile, "\taload %d\n", found->symbol->addr - last_addr);
    }
}

void j_load2dArrItem() {
    fprintf(thefile, "\taaload\n");
}

bool objectExpression(char op, Object* dest, Object* val, Object* out) {
    if (op == '+') {
        printf("ADD\n");
        //out->value = dest->value + val->value;
        return true; // success
    }
    if (op == '-') {
        printf("SUB\n");
        //out->value = dest->value + val->value;
        return true; // success
    }
    // switch (op) {
    //     case '+':
    //         if (a->type == INT_TYPE && b->type == INT_TYPE) {
    //             printf("ADD\n");
    //             out->type = INT_TYPE;
    //             //out->value = dest->value + val->value;
    //             return true;
    //         }
    //         break;
    //     case '-':
    //         if (a->type == INT_TYPE && b->type == INT_TYPE) {
    //             printf("SUB\n");
    //             out->type = INT_TYPE;
    //             //out->value = dest->value + val->value;
    //             return true;
    //         }
    //         break;
    //     case '*':
    //         if (a->type == INT_TYPE && b->type == INT_TYPE) {
    //             printf("MUL\n");
    //             out->type = INT_TYPE;
    //             //out->value.intVal = a->value.intVal * b->value.intVal;
    //             return true;
    //         }
    //         break;
    //     case '/':
    //         if (a->type == INT_TYPE && b->type == INT_TYPE) {
    //             if (b->value.intVal == 0) {
    //                 fprintf(stderr, "Division by zero error\n");
    //                 return false;
    //             }
    //             printf("DIV\n");
    //             out->type = INT_TYPE;
    //             //out->value.intVal = a->value.intVal / b->value.intVal;
    //             return true;
    //         }
    //         break;
    //     case '%':
    //         if (a->type == INT_TYPE && b->type == INT_TYPE) {
    //             printf("REM\n");
    //             out->type = INT_TYPE;
    //             //out->value.intVal = a->value.intVal % b->value.intVal;
    //             return true;
    //         }
    //         break;
    //     case '>':
    //         if (a->type == INT_TYPE && b->type == INT_TYPE) {
    //             printf("GTR\n");
    //             out->type = BOOL_TYPE;
    //             //out->value.boolVal = a->value.intVal > b->value.intVal;
    //             return true;
    //         }
    //         break;
    //     case '<':
    //         if (a->type == INT_TYPE && b->type == INT_TYPE) {
    //             printf("LES\n");
    //             out->type = BOOL_TYPE;
    //             // out->value.boolVal = a->value.intVal < b->value.intVal;
    //             return true;
    //         }
    //         break;
    //     case 'g': // Represent '>=', use 'g' for 'greater than or equal to'
    //         if (a->type == INT_TYPE && b->type == INT_TYPE) {
    //             printf("GEQ\n");
    //             out->type = BOOL_TYPE;
    //             // out->value.boolVal = a->value.intVal >= b->value.intVal;
    //             return true;
    //         }
    //         break;
    //     case 'l': // Represent '<=', use 'l' for 'less than or equal to'
    //         if (a->type == INT_TYPE && b->type == INT_TYPE) {
    //             printf("LEQ\n");
    //             out->type = BOOL_TYPE;
    //             // out->value.boolVal = a->value.intVal <= b->value.intVal;
    //             return true;
    //         }
    //         break;
    //     case '=': // Represent '=='
    //         if (a->type == b->type) {
    //             if (a->type == INT_TYPE) {
    //                 out->type = BOOL_TYPE;
    //                 //out->value.boolVal = a->value.intVal == b->value.intVal;
    //                 return true;
    //             } else if (a->type == BOOL_TYPE) {
    //                 out->type = BOOL_TYPE;
    //                 //out->value.boolVal = a->value.boolVal == b->value.boolVal;
    //                 return true;
    //             }
    //             // Add cases for other types as needed
    //         }
    //         break;
    //     case '!': // Represent '!='
    //         if (a->type == b->type) {
    //             if (a->type == INT_TYPE) {
        //             out->type = BOOL_TYPE;
        //             //out->value.boolVal = a->value.intVal != b->value.intVal;
        //             return true;
        //         } else if (a->type == BOOL_TYPE) {
        //             out->type = BOOL_TYPE;
        //             //out->value.boolVal = a->value.boolVal != b->value.boolVal;
        //             return true;
        //         }
        //         // Add cases for other types as needed
        //     }
        //     break;
        // case '&': // Represent '&&'
        //     if (a->type == BOOL_TYPE && b->type == BOOL_TYPE) {
        //         out->type = BOOL_TYPE;
        //         //out->value.boolVal = a->value.boolVal && b->value.boolVal;
        //         return true;
        //     }
        //     break;
        // case '|': // Represent '||'
        //     if (a->type == BOOL_TYPE && b->type == BOOL_TYPE) {
        //         out->type = BOOL_TYPE;
        //         //out->value.boolVal = a->value.boolVal || b->value.boolVal;
        //         return true;
        //     }
        //     break;
        // default:
        //     fprintf(stderr, "Unknown binary operation '%c'\n", op);
        //     return false;
    return false;
}



bool objectExpBinary(char op, Object* a, Object* b, Object* out) {
    return false;
    //return false;
}

bool objectExpBoolean(char op, Object* a, Object* b, Object* out) {
    return true;
    //return false;
}

bool objectExpAssign(char op, Object* dest, Object* val, Object* out) {
    return true;
    //return false;
}

bool objectValueAssign(Object* dest, Object* val, Object* out) {
    return true;
    //return false;
}

bool objectNotBinaryExpression(Object* dest, Object* out) {
    return true;
    //return false;
}

bool objectNegExpression(Object* dest, Object* out) {
    return true;
    //return false;
}
bool objectNotExpression(Object* dest, Object* out) {
    return true;
    //return false;
}

bool objectIncAssign(Object* a, Object* out) {
    return true;
    //return false;
}

bool objectDecAssign(Object* a, Object* out) {
    return true;
    //return false;
}

bool objectCast(ObjectType variableType, Object* dest, Object* out) {
    printf("Cast to %s\n", objectTypeName[variableType]);
    if (variableType == OBJECT_TYPE_INT) {
        //printf("SUB\n");
        //out->value = dest->value + val->value;
        return true; // success
    }
    return true;
    //return false;
}

bool objCast(ObjectType variableType) {
    printf("Cast to %s\n", objectTypeName[variableType]);
    if (variableType == OBJECT_TYPE_INT) {
        fprintf(thefile, "\tf2i\n");
        return true; // success
    }
    else if (variableType == OBJECT_TYPE_FLOAT) {
        fprintf(thefile, "\ti2f\n");
        return true; // success
    }
    return true;
    //return false;
}

Object* findVariable(char* variableName) {
    Object* variable = NULL;
    return variable;
}

void pushFunInParm(Object* variable) {
    Object *newObject = (Object*)malloc(sizeof(Object));
    newObject->type = variable->type;
    newObject->symbol = variable->symbol;
    push(&coutStack, newObject);

    //fprintf(thefile, " %s\n\n", objectTypeName[newObject->type]);
    if (variable->type == OBJECT_TYPE_STR)
    {
        if (strcmp(variable->symbol->name, "endl") == 0)
        {
            fprintf(thefile, "\tinvokevirtual java/io/PrintStream/println()V\n");
        }
        else
        {
            // fprintf(thefile, "\tldc \"%s\";\n", topObj->symbol->name);
            fprintf(thefile, "\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");  
        }
    }
    else if (variable->type == OBJECT_TYPE_INT)
    {
        fprintf(thefile, "\tinvokevirtual java/io/PrintStream/print(I)V\n"); 
    }
    else if (variable->type == OBJECT_TYPE_FLOAT)
    {
        fprintf(thefile, "\tinvokevirtual java/io/PrintStream/print(F)V\n"); 
    }
    else if (variable->type == OBJECT_TYPE_BOOL)
    {
        fprintf(thefile, "\tifeq L_false_string%d\n", boolcnt);
        fprintf(thefile, "\tldc \"true\"\n");
        fprintf(thefile, "\tgoto L_end_string%d\n", boolcnt);
        fprintf(thefile, "L_false_string%d:\n", boolcnt);
        fprintf(thefile, "\tldc \"false\"\n");
        fprintf(thefile, "L_end_string%d:\n", boolcnt);
        fprintf(thefile, "\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n"); 
        boolcnt++;
    }
}

void stdoutPrint() {
    printf("cout");
    Object *topObj;
    Object *dumpStack = NULL;
    while((topObj = pop(&coutStack)) != NULL) // pop all cout params
    {
        push(&dumpStack, topObj);
    }
    while((topObj = pop(&dumpStack)) != NULL) // pop all cout params
    {
        printf(" %s", objectTypeName[topObj->type]);
        
        // if (topObj->type == OBJECT_TYPE_STR)
        // {
        //     if (strcmp(topObj->symbol->name, "endl") == 0)
        //     {
        //         fprintf(thefile, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
        //         fprintf(thefile, "\tldc \"\n\";\n");
        //         fprintf(thefile, "\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        //     }
        //     else
        //     {
        //         fprintf(thefile, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
        //         fprintf(thefile, "\tldc \"%s\";\n", topObj->symbol->name);
        //         fprintf(thefile, "\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");  
        //     }
        // }
        
        
        
        //free(topObj);
    }
    printf("\n");

    // fprintf(thefile, "\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
}

void j_cout() {
    fprintf(thefile, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
}

void PrintIdent(char *idname) {
    if (strcmp(idname, "endl") == 0)
    {
        printf("IDENT (name=%s, address=%d)\n", idname, -1);
    }
    else
    {
        Object* found = findObjectByName(idname);
        if (found != NULL)
        {
            printf("IDENT (name=%s, address=%d)\n", idname, found->symbol->addr);  
        }
    }
}

ObjectType findType(char *idname){
    if (strcmp(idname, "endl") == 0)
    {
        return OBJECT_TYPE_STR;
    }
    else
    {
        Object* found = findObjectByName(idname);
        if (found != NULL)
        {
            //printf("%s\n",objectTypeName[found->type]);
            return found->type; 
        }
    }
}

int findIdentAddr(char *idname){
    if (strcmp(idname, "endl") == 0)
    {
        return -1;
    }
    else
    {
        Object* found = findObjectByName(idname);
        if (found != NULL)
        {
            //printf("%s\n",objectTypeName[found->type]);
            return found->symbol->addr; 
        }
    }
}

void addFuncSignal(ObjectType type, int variableFlag){
    Object* found = findObjectByType(OBJECT_TYPE_FUNCTION);
    char a[30];
    a[0] = '\0';
    
    if (variableFlag == VAR_FLAG_FUNCTION_RETURN)
    {
        strcat(a, ")");
    }
    else if (variableFlag == VAR_FLAG_ARRAY)
    {
        strcat(a, "[");
    }
    
    if (type == OBJECT_TYPE_INT)
    {
        strcat(a, "I");
    }
    else if (type == OBJECT_TYPE_FLOAT)
    {
        strcat(a, "F");
    }
    else if (type == OBJECT_TYPE_BOOL)
    {
        strcat(a, "B");
    }
    else if (type == OBJECT_TYPE_CHAR)
    {
        strcat(a, "C");
    }
    else if (type == OBJECT_TYPE_STR)
    {
        strcat(a, "Ljava/lang/String;");
    }
    else if (type == OBJECT_TYPE_VOID)
    {
        strcat(a, "V");
    }

    if (found != NULL)
    {
        char *new_sig = malloc(strlen(found->symbol->func_sig) + strlen(a) + 1);
        strcat(new_sig, found->symbol->func_sig);
        strcat(new_sig, a);
        found->symbol->func_sig = new_sig;
        //printf("%s ", found->symbol->func_sig);
    }
}

ObjectType checkFunction(char *idname)
{
    Object* found = findFuncByName(idname);
    char *sig = found->symbol->func_sig;
    if (found != NULL)
    {
        printf("call: %s%s\n", idname, sig);  
    }
    
    // function return type by func_sig
    
    if (sig[strlen(sig) - 1] == 'I')
    {
        return OBJECT_TYPE_INT;
    }
    else if (sig[strlen(sig) - 1] == 'F')
    {
        return OBJECT_TYPE_FLOAT;
    }
    else if (sig[strlen(sig) - 1] == 'B')
    {
        return OBJECT_TYPE_BOOL;
    }
    else if (sig[strlen(sig) - 1] == 'C')
    {
        return OBJECT_TYPE_CHAR;
    }
    else if (sig[strlen(sig) - 1] == 'V')
    {
        return OBJECT_TYPE_VOID;
    }
    else if (sig[strlen(sig) - 1] == ';')
    {
        return OBJECT_TYPE_STR;
    }
    return OBJECT_TYPE_STR;
}











int main(int argc, char* argv[]) {
    char* outputFileName = NULL;
    if (argc == 3) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = fopen(outputFileName = argv[2], "w");
    } else if (argc == 2) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = stdout;
    } else {
        printf("require input file");
        exit(1);
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }
    if (!yyout) {
        printf("file `%s` doesn't exists or cannot be opened\n", outputFileName);
        exit(1);
    }

    //codeRaw(".class public Main");
    //codeRaw(".super java/lang/Object");
    
    thefile=fopen("./build/Main.j","w");
    fprintf(thefile, ".source Main.j\n");
    fprintf(thefile, ".class public Main\n");
    fprintf(thefile, ".super java/lang/Object\n");
    //fprintf(thefile, ".method public static main([Ljava/lang/String;)V\n");
    //fprintf(thefile, ".limit stack 100\n");
    //fprintf(thefile, ".limit locals 100\n");
    
    scopeLevel = -1;

    yyparse();
    
    
    // fprintf(thefile, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
    // fprintf(thefile, "\tldc \"Hello World\n\";\n");
    // fprintf(thefile, "\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
    
    
    //fprintf(thefile, "\treturn\n");
    //fprintf(thefile, ".end method\n");
    //if(ferror==1){remove("Main.j");}
    fclose(thefile);
    
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}