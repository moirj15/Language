#ifndef PARSER_H
#define PARSER_H

#include "utils.h"
#include "scanner.h"
#include "ast.h"

namespace Parser {

class Parser {
	std::vector<Lex::Token> 	tokens;
	Ast							*AST;
	Lex::Token					currTok;

public:
	Parser(std::vector<Lex::Token> toks);
	~Parser(void);
	
	Ast *parse(void);
private:
	void parseExpression(void);
	void nextToken(void);
};


}
#endif
