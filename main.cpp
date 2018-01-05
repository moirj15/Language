#include "utils.h"
#include "errorLog.h"
#include "scanner.h"


int main(int argc, char **argv) {
	FILE *source = openFile("test.jay", "r");

    Lex::Scanner *scanner = new Lex::Scanner();


    scanner->changeFile(source);
    scanner->tokenize();
    std::vector<Lex::Token> tokens = scanner->getTokens();

	tokens[0].printToken();
    delete(scanner);
    return EXIT_SUCCESS;
}
