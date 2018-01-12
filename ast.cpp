#include "ast.h"

namespace Parser {

BinAddAst::BinAddAst(ExpressionAst *l, ExpressionAst *r, Lex::Token t) 
	: left(l), right(r) {
	nodeType = BIN_ADD;
	token = t;
}


BinAddAst::~BinAddAst(void) {

}

void BinAddAst::printTree(void) {
	printf("+\n");
	left->printTree();
	right->printTree();
}

void BinAddAst::deleteTree(ExpressionAst *tree) {
	BinAddAst *del = (BinAddAst *) tree;
	if (del->left) {
		deleteTree(del->left);
	}
	if (del->right) {
		deleteTree(del->right);
	}
	delete(tree);
}

IntegerAst::IntegerAst(int32 d) : data(d) {

}

IntegerAst::~IntegerAst(void) {

}
	
void IntegerAst::printTree(void) {
	printf("%d\n", data);
}











} // end namespace
