#include "utils.h"
#include "errorLog.h"
#include "scanner.h"
#include "ast.h"
#include "parser.h"

void printTokens(std::vector<Lex::Token> toks) {
    for (uint64 i = 0; i < toks.size(); i++) {
        toks[i].printToken();
    }
}

int main(int argc, char **argv) {
	FILE *source = openFile("test.jay", "r");

	ErrorLog errs;
    Lex::Scanner *scanner = new Lex::Scanner(&errs);

    scanner->changeFile(source);
    scanner->tokenize();
    std::vector<Lex::Token> tokens = scanner->getTokens();

    printTokens(tokens);
	errs.printErrors();	

	Parser::Parser parser(tokens);

	Parser::Ast *ast = parser.parse();

	ast->printTree();

	delete(scanner);
    return EXIT_SUCCESS;
}
