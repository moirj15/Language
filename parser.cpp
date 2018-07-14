#include "parser.h"

namespace Parser
{

static std::vector<Lex::Token> tokens;
static Ast *ast;
static Lex::Token currToken;
static std::map<NODE_TYPE, u32> precedence;

void initParser(std::vector<Lex:::Token> &t)
{
    tokens = t;
	currToken = tokens[0];

    // specify the operator precedences
    precedence[MULT_EXP] = 40;
    precedence[DIV_EXP] = 40;
    precedence[SUB_EXP] = 20;
    precedence[ADD_EXP] = 20;
}

Ast *parse(void)
{

}


} // end namespace








