#include "jString.h"


/**
 * Constructor
 */
JString::JString(void) {
	str = NULL;
	size = 0;
}

/**
 * Constructor
 *
 * @param cStr: The string.
 */
JString::JString(char *cStr) {
	size = strCpy(str, cStr);
}

/**
 * Constructor
 *
 * @param cStr: The string.
 * @param s: The length of the string, including null terminator.
 */
JString::JString(const char *cStr, u64 s) {
	str = (char *)cStr;
	size = s;
}

/**
 * Destructor.
 */
JString::~JString(void) {
	size = 0;
	if (str) {
		delete[](str);
	}
}
