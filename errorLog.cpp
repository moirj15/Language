#include "errorLog.h"


/**
 * Constructor.
 */
ErrorLog::ErrorLog() {
	errorFound = false;
}

/**
 * Destructor.
 */
ErrorLog::~ErrorLog() {

}

/**
 * Report an error to the error log.
 *
 * @param err: The error that will be reported.
 */
void ErrorLog::reportError(const char *err) {
    errors.push_back(std::string(err));
	errorFound = true;
}

/**
 * Print the errors to stdout.
 */
void ErrorLog::printErrors(void) {
    for (u32 i = 0; i < errors.size(); i++) {
        printf("%s\n", errors[i].c_str());
    }
}
