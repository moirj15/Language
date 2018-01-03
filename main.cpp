#include "utils.h"
#include "errorLog.h"
#include "scanner.h"

int main(int argc, char **argv) {
	FILE *source = openFile("test.jay", "r");

	closeFile(source);
	return EXIT_SUCCESS;
}
