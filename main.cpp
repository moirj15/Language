#include "utils.h"
#include "errorLog.h"
#include "scanner.h"

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
    delete(scanner);
    return EXIT_SUCCESS;
}
