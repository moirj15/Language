#include "parser.h"


Parser::Parser(std::vector<Lex::Token> toks) : tokens(toks) {

}

Parser::~Parser(void) {

}

Ast *Parser::parse(void) {
	if (currTok == Lex::END_OF_FILE) {
		return AST;
	}
}

void Parser::parseExpression() {

}
