#ifndef PARSER_H
#define PARSER_H

#include "utils.h"
#include "ast.h"
#include "scanner.h"

class Parser {
    vector<Token>   tokens;
    uint32_t        pos;

    IntegerAst *parseInt(void);
public:
    Parser(vector<Token> tok);
    ~Parser(void);

    AST *parse(void);
};


#endif