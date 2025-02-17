#ifndef COMPILER_COMMON_H
#define COMPILER_COMMON_H

#include <stdbool.h>
#include <stdint.h>

typedef enum _objectType {
    OBJECT_TYPE_UNDEFINED,
    OBJECT_TYPE_AUTO,
    OBJECT_TYPE_VOID,
    OBJECT_TYPE_CHAR,
    OBJECT_TYPE_INT,
    OBJECT_TYPE_LONG,
    OBJECT_TYPE_FLOAT,
    OBJECT_TYPE_DOUBLE,
    OBJECT_TYPE_BOOL,
    OBJECT_TYPE_STR,
    OBJECT_TYPE_FUNCTION,
} ObjectType;

/*
typedef struct _symbolData {
    char* name;
    int32_t index;
    int64_t addr;
    int32_t lineno;
    char* func_sig;
    uint8_t func_var;
} SymbolData;
*/

// Define the SymbolTable structure
typedef struct SymbolTable {
    char *name;
    int index;
    int addr;
    int lineno;
    char *func_sig;
    int scopelvl;
    //struct SymbolTable *next; // Pointer to the next SymbolTable
} SymbolTable;

/*
typedef struct _object {
    ObjectType type;
    uint64_t value;
    SymbolData* symbol;
} Object;
*/

typedef struct _object {
    ObjectType type;
    uint64_t value;
    SymbolTable* symbol;
    struct _object *next; // Pointer to the next SymbolTable
} Object;

extern int yylineno;
extern int funcLineNo;

#endif /* COMPILER_COMMON_H */