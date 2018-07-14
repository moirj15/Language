#ifndef AST_H
#define AST_H

#include "utils.h"
#include "scanner.h"


enum NODE_TYPE {
    ADD_EXP,
    SUB_EXP,
    MULT_EXP,
    DIV_EXP,
    NEGATE_EXP,
    UNARY_EXP,
	INTEGER,
};

struct Ast {
	u32 		nodeType;
	Lex::Token 	token;
	virtual ~Ast(void) {}

	virtual void printTree(void) {}
};

struct ExpressionAst : public Ast {
	virtual ~ExpressionAst(void) {}

	virtual void printTree(void) = 0; 
	virtual void deleteTree(ExpressionAst *tree) = 0; 
};

struct BinExpression : public ExpressionAst {
    ExpressionAst *left;
    ExpressionAst *right;

    BinExpression();
    virtual ~BinExpression();

    virtual void printTree(void);
    virtual void deleteTree(ExpressionAst *tree);
};


struct UnaryExpression : public ExpressionAst {
    ExpressionAst *child;
    
    UnaryExpression(void);
    virtual ~UnaryExpression(void);

    virtual void printTree();
    virtual void deleteTree(ExpressionAst *tree);
};

struct IntegerAst : public ExpressionAst {
	s32 data;
	
	IntegerAst(s32 d);
	~IntegerAst(void);

	void printTree(void);
	void deleteTree(ExpressionAst *tree); 
};


#endif
