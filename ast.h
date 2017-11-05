#ifndef AST_H
#define AST_H

#include "utils.h"

struct AST {
    virtual ~AST(void);
    virtual void print(void);
};


struct BinaryOpAst : public AST {
    AST *left;
    AST *right;
    char op;

    BinaryOpAst(char o, AST *l, AST *r);
    ~BinaryOpAst(void);
    void print(void);
};

struct IntegerAst : public AST {
    uint32_t value;
    IntegerAst(uint32_t n);
    ~IntegerAst(void);
    void print(void);
};

#endif
