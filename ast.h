#ifndef AST_H
#define AST_H

#include "utils.h"
#include "scanner.h"


enum NODE_TYPE {
	BIN_ADD,
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

struct BinAddAst : public ExpressionAst {
	ExpressionAst *left;
	ExpressionAst *right;

	BinAddAst(ExpressionAst *l, ExpressionAst *r, Lex::Token t);
	~BinAddAst(void);
	
	void printTree(void);
	void deleteTree(ExpressionAst *tree);
};

struct IntegerAst : public ExpressionAst {
	s32 data;
	
	IntegerAst(s32 d);
	~IntegerAst(void);

	void printTree(void);
	void deleteTree(ExpressionAst *tree); 

};


#endif
