#ifndef PARSER_H
#define PARSER_H

#include "utils.h"
#include "ast.h"
#include "scanner.h"

class Parser {
    vector<Token>   tokens;
    uint32_t        pos;

	
public:
    Parser(vector<Token> tok);
    ~Parser(void);

    AST *parse(void);

private:
    IntegerAst *parseInt(void);
	
	/**
	 * Converts the arithmetic expression to postfix notation.
	 *
	 * @param end: The point where the arithmetic expression ends.
	 * @return: List containing the postfix expression.
	 */
	vector<Token> *toPostFix(uint32_t end);

};


#endif
