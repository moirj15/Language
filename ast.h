#ifndef AST_H
#define AST_H

#include "utils.h"
#include "scanner.h"

struct Ast {
	virtual ~Ast(void) {}

	virtual void printTree(void) {}
};

struct ExpressionAst : public Ast {
	virtual ~ExpressionAst(void) {}

	virtual void printTree(void) {}
};

struct BinExpAst : public ExpressionAst {
	ExpressionAst 	*left;
	ExpressionAst	*right;
	char		operation;

	BinExpAst(ExpressionAst *l, ExpressionAst *r, char op);
	~BinExpAst(void);

	void deleteTree(ExpressionAst *tree); 
	void printTree(void);
};

struct IntegerAst : public ExpressionAst {
	int32 data;
	IntegerAst(int32 d);
	~IntegerAst(void);
	void printTree(void);
};
















#endif
