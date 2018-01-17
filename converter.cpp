#include "converter.h"

namespace Converter {

void AstToByteCode(Parser::Ast *tree, std::vector<uint64> &code) {
	//printf("type %d\n", tree->nodeType);
	if (!tree) {
		return;
	}
	if (tree->nodeType == Parser::BIN_ADD) {
		Parser::BinAddAst *add = static_cast<Parser::BinAddAst *>(tree);
		AstToByteCode(add->left, code);
		AstToByteCode(add->right, code);
		// NOTE: the order in which the opCodes are pushed into the vector may
		// need to change in the future
		code.push_back(VM::ADD_INT);
		code.push_back(VM::HALT);
	}
	else if (tree->nodeType == Parser::INTEGER) {
		Parser::IntegerAst *integer = static_cast<Parser::IntegerAst *>(tree);
		code.push_back(VM::PUSH_INT);
		code.push_back(integer->data);
		return;
	}
}


} // end namespace

