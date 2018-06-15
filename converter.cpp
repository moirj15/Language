#include "converter.h"


void AstToByteCode(Ast *tree, std::vector<u64> &code) {
	//printf("type %d\n", tree->nodeType);
	if (!tree) {
		return;
	}
	if (tree->nodeType == BIN_ADD) {
		BinAddAst *add = static_cast<BinAddAst *>(tree);
		AstToByteCode(add->left, code);
		AstToByteCode(add->right, code);
		// NOTE: the order in which the opCodes are pushed into the vector may
		// need to change in the future
		code.push_back(VM::ADD_INT);
		code.push_back(VM::HALT);
	}
	else if (tree->nodeType == INTEGER) {
		IntegerAst *integer = static_cast<IntegerAst *>(tree);
		code.push_back(VM::PUSH_INT);
		code.push_back(integer->data);
		return;
	}
}


