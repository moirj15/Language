#ifndef PARSER_H
#define PARSER_H

#include "utils.h"
#include "scanner.h"
#include "ast.h"

class Parser {
	std::vector<Lex::Token> 	tokens;
	Ast							*AST;
	uint64						currTok;
public:
	Parser(std::vector<Lex::Token> toks);
	~Parser(void);
	
	Ast *parse(void);
private:
	void parseExpression(void);
};

#endif
