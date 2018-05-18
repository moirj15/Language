#include "scanner.h"

namespace Lex {

// Atom identifiers
#define isLeftParen(x) 			(x == '(')
#define isRightParen(x) 		(x == ')')
#define isLeftCurlBracket(x) 	(x == '{')
#define isRightCurlBracket(x) 	(x == '}')
#define isBang(x)				(x == '!')
#define isAtSign(x)				(x == '@')
#define isHash(x)				(x == '#')
#define isDollar(x)				(x == '$')
#define isPercent(x)			(x == '%')
#define isCarrot(x)				(x == '^')
#define isAnd(x)				(x == '&')
#define isStar(x)				(x == '*')
#define isDash(x)				(x == '-')
#define isUnderScore(x)			(x == '_')
#define isEqualSign(x)			(x == '=')
#define isPlus(x)				(x == '+')
#define isLeftBracket(x)		(x == '[')
#define isRightBracket(x)	   	(x == ']')
#define isColon(x)				(x == ':')
#define isSemiColon(x)			(x == ';')
#define isSingleQuote(x)		(x == '\'')
#define isDoubleQuote(x)		(x == '"')
#define isBackSlash(x)			(x == '\\')
#define isVertBar(x)			(x == '|')
#define isComma(x)				(x == ',')
#define isPeriod(x)				(x == '.')
#define isForwardSlash(x)		(x == '/')
#define isOpenAngle(x)			(x == '<')
#define isCloseAngle(x)			(x == '>')
#define isQuestion(x)			(x == '?')


////////////////////////////////////////////////////////////////////////////////
// Token related code
////////////////////////////////////////////////////////////////////////////////
/**
 * Constructor.
 */
Token::Token(void) {

}

/**
 * Constructor.
 *
 * @param d: The data that will be held by the token.
 * @param i: The token identifier.
 */
Token::Token(std::string d, u32 i) : data(d), identifier(i) {

}

/**
 * Destructor.
 */
Token::~Token(void) {

}

/**
 * Prints the Token to stdout. 
 */
void Token::printToken(void) {
    printf("data: %s identifier: ", data.c_str());
    switch (identifier) {
        case INTEGER_LITERAL:
        	printf("INTEGER_LITERAL\n");
	        break;

        case HEXADECIMAL_LITERAL:
        	printf("HEXADECIMAL_LITERAL\n");
        	break;

        case OCTAL_LITERAL:
        	printf("OCTAL_LITERAL\n");
        	break;

        case FLOAT_LITERAL:
        	printf("FLOAT_LITERAL\n");
        	break;

    	case SEMI_COLON:
        	printf("SEMI_COLON\n");
        	break;

    	case IDENTIFIER:
        	printf("IDENTIFIER\n");
        	break;

	    case ADD_OP:
			printf("ADD_OP\n");
            break;

    	case END_OF_FILE:
        	printf("END_OF_FILE\n");
        	break;
    }
}

////////////////////////////////////////////////////////////////////////////////
// Scanner related code
////////////////////////////////////////////////////////////////////////////////

Scanner::Scanner(void) {
    currFile = NULL;
}

/**
 * Constructor.
 */
Scanner::Scanner(ErrorLog *errs) : errorLog(errs) {
    
}

Scanner::~Scanner(void) {
    closeFile(currFile);	// close file handle
}

/**
 * Load a new file for scanning.
 *
 * @param newFile: The file that will be loaded.
 */
void Scanner::changeFile(FILE *newFile) {
    currFile = newFile;
    if (!fileContent.empty()) {
        fileContent.clear();
		tokens.clear();
    }
	while (!feof(currFile)) {
        fileContent.push_back(fgetc(currFile));
    }
    fileContent.push_back(EOF);
}

/**
 * Tokenize the contents of the currently loaded file.
 */
void Scanner::tokenize(void) {
	if (!currFile) {	// make sure the current file isn't null
        quit("CurrFile is NULL");
    }
    //TODO: consider putting current char in it's on var
    while (fileContent[pos] != EOF) { 
		bool found = false;
		if (errorLog->errorFound) {
            skipToNextValidToken();
            errorLog->errorFound = false;
        }	
        if (isspace(fileContent[pos])) {
            skipWhiteSpace();
        }
        if (isalpha(fileContent[pos])) {
			scanForIdentifier();
        }
        if (isdigit(fileContent[pos])) {
			found = scanForIntLit();
            //TODO: Consider adding some sort of short circuit
            // ex: if a '.' is found in an intLiteral then jump to scanForFloat
			if (!found) {
                found = scanForHexLit();
            }
            if (!found) {
                found = scanForOctalLit();
            }
            if (!found) {
                found = scanForFloatLit();
            }
        }
        if (isSemiColon(fileContent[pos])) {
            tokens.push_back(Token(std::string(";"), SEMI_COLON));
            pos++;
        }
		if (isPlus(fileContent[pos])) {
            scanForAddOp();
        }
    }
    tokens.push_back(Token(std::string(""), END_OF_FILE));
}

/**
 * Skips upto the first non-whitespace character. 
 */
void Scanner::skipWhiteSpace(void) {
    while (isspace(fileContent[pos]) && (fileContent[pos] != EOF)) {
        pos++;
    }
}

/**
 * Skips to the next line of code in an attempt to move to the next safe Token.
 */
void Scanner::skipToNextValidToken(void) {
    while (!isSemiColon(fileContent[pos])) {
        pos++;
    }
}

/**
 * Scans for an identifier in the currently loaded file.
 */
bool Scanner::scanForIdentifier(void) {
    u64 tempPos = pos;
    std::string data;
	while (isalnum(fileContent[tempPos]) || isUnderScore(fileContent[tempPos])) {
        data.push_back(fileContent[tempPos]);
        tempPos++;
    }
    if (!isSemiColon(fileContent[tempPos]) && !isLeftParen(fileContent[tempPos])) {
        errorLog->reportError("Unexpected character in identifier");
        return false;
    }
    //TODO: check for reserved words
    tokens.push_back(Token(data, IDENTIFIER));
    pos = tempPos;
    return true;
}

/**
 * Scans for an integer literal in the currently loaded file.
 */
bool Scanner::scanForIntLit(void) {
    u64 tempPos = pos;
    std::string data;
	if (fileContent[tempPos] == '0') {
        return false;
    }
    while (isdigit(fileContent[tempPos])) {
        data.push_back(fileContent[tempPos]);
        tempPos++;
    }
    if (fileContent[tempPos] == 'x') {
        return false; // it's a hex literal
    }
    else if (isPeriod(fileContent[tempPos])) {
        return false; // it's a float
    }
    else if (isalpha(fileContent[tempPos])){
		// TODO: call error log
		errorLog->reportError("Unexpected character in Int literal");
        return false;
    }
	tokens.push_back(Token(data, INTEGER_LITERAL));
    pos = tempPos;
    return true; // it's an int literal
}

/**
 * Scans for a hexadecimal literal in the currently loaded file.
 */
bool Scanner::scanForHexLit(void) {
	u64 tempPos = pos;
    std::string data;
    data.push_back(fileContent[tempPos]);
    tempPos++;
    if (fileContent[tempPos] != 'x') {
        return false;	// Not a hex literal
    }
    data.push_back(fileContent[tempPos]);
    tempPos++;
    while (isxdigit(fileContent[tempPos])) {
        data.push_back(fileContent[tempPos]);
        tempPos++;
    }
    if (fileContent[tempPos] == '.') {
    	// TODO: call error log
		errorLog->reportError("Unexpected character in Hex literal");
        return false;
    }

    tokens.push_back(Token(data, HEXADECIMAL_LITERAL));
    pos = tempPos;
	return true;
}

/**
 * Scans for an octal literal in the currently loaded file.
 */
bool Scanner::scanForOctalLit(void) {
    u64 tempPos = pos;
    std::string data;
    char currChar = fileContent[tempPos];

    if (currChar != '0') {
        return false;	// Not an octal number.
    }
    data.push_back(currChar);
    tempPos++;
    currChar = fileContent[tempPos];
    while ((currChar <= '7') && (currChar >= '0')) {
        data.push_back(currChar);
        tempPos++;
        currChar = fileContent[tempPos];
    }
    if ((currChar > '7' || currChar == '.') && currChar != ';') {
		printf("%c\n", fileContent[tempPos]);
        return false;	// Not an octal number, must be a float
    }
    tokens.push_back(Token(data, OCTAL_LITERAL));
    pos = tempPos;
    return true;
}

/**
 * Scans for a float literal in the currently loaded file.
 */
bool Scanner::scanForFloatLit(void) {
    u64 tempPos = pos;
    std::string data;
   	while (isdigit(fileContent[tempPos])) {
        data.push_back(fileContent[tempPos]);
        tempPos++;
    }
    if (fileContent[tempPos] != '.') {
        errorLog->reportError("Unexpected character in Float literal");
        return false;	// Not a float, must be an error, call error log
    }
    data.push_back(fileContent[tempPos]);
    tempPos++;
   	while (isdigit(fileContent[tempPos])) {
        data.push_back(fileContent[tempPos]);
        tempPos++;
    }
	if (fileContent[tempPos] == 'f') {
        data.push_back(fileContent[tempPos]);
        tempPos++;
    }
    else if (isalpha(fileContent[tempPos])) {
        errorLog->reportError("Unexpected character in Float literal");
        return false;
    }
    tokens.push_back(Token(data, FLOAT_LITERAL));
    pos = tempPos;
    return true;
}


/**
 * Scans for an add op.
 */
void Scanner::scanForAddOp(void) {
    tokens.push_back(Token(std::string("+"), ADD_OP));
    pos++;
}




}; // end namespace
