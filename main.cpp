#include "utils.h"
#include "errorLog.h"
#include "scanner.h"


int main(int argc, char **argv) {
	FILE *source = openFile("test.jay", "r");

	ErrorLog errs;
    Lex::Scanner *scanner = new Lex::Scanner(&errs);

    scanner->changeFile(source);
    scanner->tokenize();
    std::vector<Lex::Token> tokens = scanner->getTokens();

	tokens[0].printToken();
	errs.printErrors();	
    delete(scanner);
    return EXIT_SUCCESS;
}
