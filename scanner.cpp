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
Token::Token(std::string d, uint32 i) : data(d), identifier(i) {

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
    }
    tokens.push_back(Token(std::string(""), EOF));
}


void Scanner::skipWhiteSpace(void) {
    while (isspace(fileContent[pos]) && (fileContent[pos] != EOF)) {
        pos++;
    }
}

bool Scanner::scanForIdentifier(void) {
    
}

bool Scanner::scanForIntLit(void) {
    uint64 tempPos = pos;
    std::string data;
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
        return false;
    }
	tokens.push_back(Token(data, INTEGER_LITERAL));
    pos = tempPos;
    return true; // it's an int literal
}

bool Scanner::scanForHexLit(void) {
    
}

bool Scanner::scanForOctalLit(void) {
    
}

bool Scanner::scanForFloatLit(void) {
    
}






}; // end namespace
