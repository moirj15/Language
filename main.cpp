#include "utils.h"
#include "errorLog.h"
#include "scanner.h"
#include "ast.h"
#include "parser.h"
#include "converter.h"
#include "vm.h"

void printTokens(std::vector<Lex::Token> toks) {
    for (uint64 i = 0; i < toks.size(); i++) {
        toks[i].printToken();
    }
}

void printByteCode(std::vector<uint64> code) {
	printf("size %ld\n", code.size());
    for (uint64 i = 0; i < code.size(); i++) {
    	printf("code %ld\n", code[i]);
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

	std::vector<uint64> code;
	Converter::AstToByteCode(ast, code);

	printByteCode(code);

	VM::VM vm(code);

	vm.run();

	delete(scanner);
    return EXIT_SUCCESS;
}
