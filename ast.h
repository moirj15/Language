#ifndef AST_H
#define AST_H

#include "utils.h"
#include "scanner.h"

namespace Parser {

enum NODE_TYPE {
	BIN_ADD,
	INTEGER,
};

struct Ast {
	uint32 		nodeType;
	Lex::Token 	token;
	virtual ~Ast(void) {}

	virtual void printTree(void) {}
};

struct ExpressionAst : public Ast {
	virtual ~ExpressionAst(void) {}

	virtual void printTree(void) {}
	virtual void deleteTree(ExpressionAst *tree) {}
};

struct BinAddAst : public ExpressionAst {
	ExpressionAst *left;
	ExpressionAst *right;

	BinAddAst(ExpressionAst *l, ExpressionAst *r, Lex::Token t);
	~BinAddAst(void);
	
	void printTree(void);
	void deleteTree(ExpressionAst *tree);
};

struct IntegerAst : public ExpressionAst {
	int32 data;
	
	IntegerAst(int32 d);
	~IntegerAst(void);

	void printTree(void);
	void deleteTree(ExpressionAst *tree) {}

};


} // end namespace
#endif
