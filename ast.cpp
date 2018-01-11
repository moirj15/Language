#include "ast.h"


BinExpAst::BinExpAst(ExpressionAst *l, ExpressionAst *r, char op) 
		: left(l), right(r), operation(op) {

}

BinExpAst::~BinExpAst(void) {

}

void BinExpAst::deleteTree(ExpressionAst *tree) {
	auto *del = dynamic_cast<BinExpAst *>(tree); 
	if (left) {
		deleteTree((ExpressionAst *)del->left);
	}
	if (right) {
		deleteTree((ExpressionAst *)del->right);
	}
	delete(tree);
}

void BinExpAst::printTree(void) {
	printf("%c\n", operation);
	left->printTree();
	right->printTree();
}
	

IntegerAst::IntegerAst(int32 d) : data(d) {

}

IntegerAst::~IntegerAst(void) {

}
	
void IntegerAst::printTree(void) {
	printf("%d", data);
}












