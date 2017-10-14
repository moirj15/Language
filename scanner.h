#ifndef LEXER_H
#define LEXER_H

#include "utils.h"
#include "errorLog.h"

/**
 * The token types that will be produced during lexical analysis
 */
enum TOKEN_TYPE {
	ADDITION_BINARY,		// A + B
	SUBTRACTION_BINARY,		// A - B
	DIVISION_BINARY,		// A / B
	MULTIPLICATION_BINARY,	// A * B
	LEFT_SHIFT_BINARY,		// A << B
	RIGHT_SHIFT_BINARY,		// A >> B
	LOG_OR_BINARY,			// A | B
	LOG_AND_BINARY,			// A $ B
	LOG_XOR_BINARY,			// A ^ B
	LOG_INVERT,				// ~A
	LESS_THAN,				// A < B
	LESS_THAN_EQL,			// A <= B
	GREATER_THAN,			// A > B
	GREATER_THAN_EQL,		// A >= B
	EQUAL_TO,				// A == B
	NOT,					// !A
	ASSIGNMENT,				// A = B
	UNARY_ADDITION,			// A += B
	UNARY_DIVISION,			// A /= B
	UNARY_SUBTRACTION,		// A -= B
	NEGATION,				// -A
	UNARY_MULTIPLICATION,	// A *= B
	UNARY_LOG_OR,			// A |= B
	UNARY_LOG_AND,			// A &= B
	UNARY_LOG_XOR,			// A ^= B
	INCREMENT,				// A++
	DECREMENT,				// A--
	NAME,					// name of something, can be type, function, etc.
	WHITE_SPACE,

	NUMBER_OF_TOKENS
};

/**
 * Container for the tokens.
 */
struct Token {
	uint32_t 	type;	// The type of token
	string 		data;	// The data

	Token(uint32_t t, string d);
	~Token();
};

class Scanner {

	FILE *m_source;
	ErrorLog &m_el
	vector<Token> m_tokens;
public:
	Scanner(FILE *source, ErrorLog &el);
	~Scanner(void);
};

#endif
