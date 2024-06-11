#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "main.h"

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)

#define toupper(_char) (_char - (char)32)

#define MAX_SCOPE 100

const char* objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_STR] = "string",
    [OBJECT_TYPE_FUNCTION] = "function",
};

char* yyInputFileName;
bool compileError;

int indent = 0;
int scopeLevel = -1;
int funcLineNo = 0;
int variableAddress = 0;
ObjectType variableIdentType;

int addrGlobal = 0;


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
        //printf("SUB\n");
        //out->value = dest->value + val->value;
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
    push(&coutStack, newObject);
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
        //free(topObj);
    }
    printf("\n");
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
    if (argc == 2) {
        yyin = fopen(yyInputFileName = argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }

    // Start parsing
    yyparse();
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}