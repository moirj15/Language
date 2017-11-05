#ifndef LEXER_H
#define LEXER_H

#include "utils.h"
#include "errorLog.h"

/**
 * The token types that will be produced during lexical analysis
 */
enum TOKEN_TYPE {
	STAR,			// *
	FORWARD_SLASH,	// / 
	PLUS,			// + 
	DASH,			// -
	VERTICAL_BAR,	// |
	ANDPERSAND,		// &
	CARROT,			// ^
	TILDA,			// ~
	LEFT_ANGLE,		// <
	RIGHT_ANGLE,	// >
	BANG,			// !
	EQUAL_SIGN,		// =
	NAME,			// name of something, can be type, function, etc.
	WHITE_SPACE,
	HASH,			// #
	NUMBER,			// (0-9)*
	PERIOD,			// .
	SEMI_COLON,
	LEFT_PAREN,
	RIGHT_PAREN,
	NUMBER_OF_TOKENS
};

/**
 * Container for the tokens.
 */
struct Token {
	uint32_t 	type;	// The type of token
	string 		data;	// The data

	Token(uint32_t t, string d);
	~Token(void);
};

class Scanner {
	FILE 			*m_sourceFile;	// The source file
	ErrorLog 		*m_el;			// The ErrorLog that the scanner will report to
	vector<Token> 	m_tokens;		// The list of tokens.
	vector<char> 	m_source;
	int				m_pos;

	void createNum(void);
	void createName(void);
	void createReservedWord(string word);
public:
	
	/**
	 * Constructor.
	 *
	 * @param source: The source file that will be read from.
	 * @param el: The reference to the ErrorLog that will be used for error
	 * reporting.
	 */
	Scanner(FILE *sf, ErrorLog *el);
	
	/**
	 * Destructor
	 */
	~Scanner(void);

	/**
	 * Scans the source file and produces a list of tokens.
	 */
	vector<Token> scan(void);	
};

#endif









