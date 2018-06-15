#include "parser.h"


Parser::Parser(std::vector<Lex::Token> toks) : tokens(toks) {
	currTok = tokens[0];
}

Parser::~Parser(void) {

}

Ast *Parser::parse(void) {
	if (currTok.identifier == Lex::END_OF_FILE) {
		return AST;
	}

	else if (currTok.identifier == Lex::INTEGER_LITERAL) {
		parseExpression();
	}
	parse();
}

void Parser::parseExpression() {
	std::stack<Lex::Token> operands;
	std::stack<Lex::Token> operators;

	// TODO: add functionality to do multiple additions.
	operands.push(currTok);
	nextToken();
	operators.push(currTok);
	nextToken();
	operands.push(currTok);
	
	IntegerAst *right = new IntegerAst(atoi(operands.top().data.c_str()));
	operands.pop();
	IntegerAst *left = new IntegerAst(atoi(operands.top().data.c_str()));
	operands.pop();
	AST = new BinAddAst(left, right, operators.top());
	operators.pop();

	nextToken();
	nextToken();
}

void Parser::nextToken(void) {
	static u64 pos = 1;
	currTok = tokens[pos];
	pos++;
}








