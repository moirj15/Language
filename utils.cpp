#include "utils.h"

/**
 * Exits the program with EXIT_FAILURE and displays the given messaage.
 *
 * @param message: The message to be printed before exiting
 */
void quit(const char *message) {
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

/**
 * Opens a file with the given permissions, exits on failure.
 *
 * @param src: The location of the file.
 * @param perm: The permisions to open the file with.
 * @return: The opened file.
 */
FILE *openFile(const char *src, const char *perm) {
	FILE *ret = NULL;
	ret = fopen(src, perm);
	if (!ret) {
		quit("Failed to open file");
  }
	return (ret);
}

/**
 * Safely closes the given file, will exit if a failure occurs.
 *
 * @param fp: The ponter to the file that will be closed.
 */
void closeFile(FILE *fp) {
	if (fclose(fp) < 0 ) {
		quit("Failed to close file");
	}
	fp = NULL;
}

