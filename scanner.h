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
	EOF,
}

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
};

/**
 * Class for scanning a file and producing tokens.
 */
class Scanner {
	FILE 				*currFile;
    std::vector<char> 	fileContents;
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
     * Load a new file into the character array.
     */
    void changeFile(File *newFile);
    void tokenize(void);
private:
    void skipWhiteSpace(void);
	bool scanForName(void);
    bool scanForIntLit(void);
    bool scanForHexLit(void);
    bool scanForOctalLit(void);
    bool scanForFloatLit(void);
};

}; // end namespace
#endif
