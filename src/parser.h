#ifndef Parser_h
#define Parser_h

#include <stdbool.h>

#include "pkmath.h"

typedef struct {
    int32_t Cursor;
    char * String;
    uint32_t StringLength;
    bool HasResult;
    int32_t Int32Result;
}
Parser_t;

typedef struct {
    bool Success;
    char * Message;
    int32_t Int32Result;
}
ParserResult_t;

void Parser_Evaluate(char * String, ParserResult_t * Result);

#endif // Parser_h