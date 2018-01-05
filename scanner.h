#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>
#include "utils.h"
namespace Lex {
 

enum TOKEN_IDENTIFER {
	INTEGER_LITERAL,	// (1..9)(1..9)*
    HEXADECIMAL_LITERAL,// 0x(0..9)*
    OCTAL_LITERAL,		// 0(0..7)*
    FLOAT_LITERAL,		// (0..9).(0..9)*		
	END_OF_FILE,
};

/**
 * Simple struct containing an identifier and data.
 */
struct Token {
	std::string data;
	uint32		identifier;

  	/**
	 * Constructor.
	 */
	Token(void);

	/**
	 * Constructor.
	 *
	 * @param d: The data that will be held by the token.
	 * @param i: The token identifier.
	 */
	Token(std::string d, uint32 i);

  	/**
 	 * Destructor.
 	 */
	~Token(void);
	
    /**
     * Prints the Token to stdout. 
     */
	void printToken(void);
};

/**
 * Class for scanning a file and producing tokens.
 */
class Scanner {
	FILE 				*currFile;
    std::vector<char> 	fileContent;
    std::vector<Token> 	tokens;
	uint64				pos;
public:

    /**
     * Constructor.
     */
	Scanner(void);

    /**
     * Destructor.
     */
	~Scanner(void);

    /**
     * Load a new file for scanning.
     *
     * @param newFile: The file that will be loaded.
     */
    void changeFile(FILE *newFile);

	/**
     * Tokenize the contents of the currently loaded file.
     */
    void tokenize(void);

    inline std::vector<Token> getTokens(void) {return tokens;}
private:

    /**
     * Skips upto the first non-whitespace character. 
     */
    void skipWhiteSpace(void);

    /**
     * Scans for an identifier in the currently loaded file.
     */
	bool scanForIdentifier(void);

    /**
     * Scans for an integer literal in the currently loaded file.
     */
    bool scanForIntLit(void);
    bool scanForHexLit(void);
    bool scanForOctalLit(void);
    bool scanForFloatLit(void);
};

}; // end namespace
#endif
