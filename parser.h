#ifndef PARSER_H
#define PARSER_H

#include "utils.h"
#include "scanner.h"
#include "ast.h"

#include <map>
namespace Parser 
{

    void initParser(std::vector<Lex::Token> &t);    

    Ast *parse(void);
}



#endif
