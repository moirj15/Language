#ifndef UTILS_H
#define UTILS_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <string>
#include <vector>

#define local static

using namespace std;

/**
 * Exits the program with EXIT_FAILURE and displays the given messaage.
 *
 * @param message: The message to be printed before exiting
 */
void quit(const char *message);

/**
 * Opens a file with the given permissions, exits on failure.
 *
 * @param src: The location of the file.
 * @param perm: The permisions to open the file with.
 * @return: The opened file.
 */
FILE *openFile(const char *src, const char *perm);

/**
 * Safely closes the given file, will exit if a failure occurs.
 *
 * @param fp: The ponter to the file that will be closed.
 */
void closeFile(FILE *fp);

#endif

