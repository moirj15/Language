#include "utils.h"
#include "errorLog.h"
#include "scanner.h"
#include "ast.h"
#include "parser.h"
#include "converter.h"
#include "vm.h"

/**
 *
 */
void printTokens(std::vector<Lex::Token> toks) {
    for (u64 i = 0; i < toks.size(); i++) {
        toks[i].printToken();
    }
}

void printByteCode(std::vector<u64> code) {
	printf("size %ld\n", code.size());
    for (u64 i = 0; i < code.size(); i++) {
    	printf("code %ld\n", code[i]);
	}
}

int main(int argc, char **argv) {
    if (argc < 2) {
        quit("No source file");
    }

	FILE *source = openFile(argv[1], "r");

	ErrorLog errs;
    Lex::Scanner *scanner = new Lex::Scanner(&errs);

    scanner->changeFile(source);
    scanner->tokenize();
    std::vector<Lex::Token> tokens = scanner->getTokens();

    printTokens(tokens);
	errs.printErrors();	

	Parser parser(tokens);

	Ast *ast = parser.parse();

	ast->printTree();

	std::vector<u64> code;
	AstToByteCode(ast, code);

	printByteCode(code);

	VM::VirtualMachine vm(code);

	vm.run();

	delete(scanner);
    return EXIT_SUCCESS;
}
