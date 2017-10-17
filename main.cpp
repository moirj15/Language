#include "utils.h"
#include "errorLog.h"
#include "scanner.h"

int main(int argc, char **argv) {
	FILE *source = openFile("test.jay", "r");
	ErrorLog *el = new ErrorLog();
	Scanner scanner(source, el);
	vector<Token> toks = scanner.scan();
	printf("tok size %ld\n", toks.size());	
	for (int i = 0; i < toks.size(); i++) {
		printf("type: %d, data %s\n", toks[i].type, toks[i].data.c_str());
	}
	return EXIT_SUCCESS;
}
