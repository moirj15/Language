#include "parser.h"

Parser::Parser(vector<Token> tok) : tokens(tok) {
    pos = 0;
}

Parser::~Parser(void) {

}

IntegerAst *Parser::parseInt(void) {

}