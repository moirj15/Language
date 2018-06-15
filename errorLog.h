#ifndef ERROR_LOG_H
#define ERROR_LOG_H

#include "utils.h"

class ErrorLog {
    std::vector<std::string> errors;
public:
	bool errorFound;
	/**
     * Constructor.
     */
    ErrorLog(void);

    /**
     * Destructor.
     */
	~ErrorLog(void);

    /**
     * Report an error to the error log.
     *
     * @param err: The error that will be reported.
     */
    void reportError(const char *err);

    /**
     * Print the errors to stdout.
     */
    void printErrors(void);

};

#endif
