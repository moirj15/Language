#ifndef JSTRING_H
#define JSTRING_H

#include "utils.h"

struct JString {
	char 	*str;
	u64 	size;

	/**
	 * Constructor
	 */
	JString(void);

	/**
	 * Constructor
	 *
	 * @param cStr: The string.
	 */
	JString(char *cStr);

	/**
	 * Constructor
	 *
	 * @param cStr: The string.
	 * @param s: The length of the string, including null terminator.
	 */
	JString(const char *cStr, u64 s);

	/**
	 * Destructor.
	 */
	~JString(void);
};

/**
 * Gets the length of the string with the null terminator.
 *
 * @param str: The string whose length will be found.
 * @return: The length of the string with the null terminator.
 */
inline u64 strlen(char *str) {
	u64 ret = 0;
	while (str) {
		str++;
		ret++;
	}
	return ret + 1;
}

/**
 * Copys the contents of the source string into the destination string, also
 * allocates space for the destination string.
 *
 * @param dest: The destination of the copy.
 * @param src: The src string.
 * @return: The length of the string that was coppied.
 */
inline u64 strCpy(char *dest, const char *src) {
	u64 len = strlen(src);
	dest = new char[len];
	u64 i = 0;
	while (i < len) {
		dest[i] = src[i];
		i++;
	}
	return len;
}

/**
 * Determines if the two given strings are the same.
 *
 * @param a: The firs string.
 * @param b: The second string.
 * @return: true if the two strings have the same length and same contents,
 * false otherwise.
 */
inline bool strCmp(const JString &a, const JString &b) {
	if (a.size != b.size) {
		return false;
	}
	for (u64 i = 0; i < a.size; i++) {
		if (a.str[i] != b.str[i]) {
			return false;
		}
	}
	return true;
}
#endif
