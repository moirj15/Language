#include "ast.h"



IntegerAst::IntegerAst(s32 d) : data(d) {
	nodeType = INTEGER;
	// TODO: replace data with token
}

IntegerAst::~IntegerAst(void) {

}
	
void IntegerAst::printTree(void) {
	printf("%d\n", data);
}

void IntegerAst::deleteTree(ExpressionAst *tree) {
    (void)tree;
}











