#ifndef UTILS_H
#define UTILS_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <stack>

#define local 	static

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float	 f32;
typedef double	 f64;

#define db()	printf("hit\n");

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

