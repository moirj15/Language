#ifndef LEXER_H
#define LEXER_H

#include "utils.h"
#include "errorLog.h"

/**
 * The token types that will be produced during lexical analysis
 */

enum TokenType {
	COMMA,					// ,
	ASSIGNMENT,				// =
	SUM_ASSIGNMENT,			// +=
	SUB_ASSIGNMENT,			// -=
	MULT_ASSIGNMENT,		// *=
	DIV_ASSIGNMENT,			// /=
	REM_ASSIGNMENT,			// %=
	SHIFT_LEFT_ASSIGNMENT,	// <<=
	SHIFT_RIGHT_ASSIGNMENT,	// >>=
	AND_ASSIGNMENT,			// &=
	XOR_ASSIGNMENT,			// ^=
	OR_ASSIGNMENT,			// |=
	TERNARY_CONDITIONAL,	// ?=
	LOG_OR,					// ||
	LOG_AND,				// &&
	BIT_OR,					// |
	BIT_XOR,				// ^
	BIT_AND,				// &
	EQUAL_TO,				// ==
	NOT_EQUAL_TO,			// !=
	GREATER_THAN,			// >
	GREATER_THAN_EQL,		// >=
	LESS_THAN,				// <
	LESS_THAN_EQL,			// <=
	LEFT_SHIFT,				// <<
	RIGHT_SHIFT,			// >>
	ADDITION,				// +
	SUBTRACTION,			// -
	MULTIPLICATION,			// *
	DIVISION,				// /
	REMAINDER,				// %
	SIZEOF,					// sizeof()
	ADDRESS_OF,				// &var
	DEREFERENCE,			// *var
	TYPE_CAST,				// (type)
	LOG_NOT,				// !
	BIT_NOT,				// ~
	PREFIX_INC,				// ++var
	PREFIX_DEC,				// --var
	MEMBER_ACCESS,			// struct.member
	ARRAY_SUBSCRIPT,		// arr[]
	FUNCTION_CALL,			// name()
	METHOD_CALL,			// struct.name()
	POSTFIX_INC,			// var++
	POSTFIX_DEX,			// var--
}

enum ReservedWord {
	BOOL,
	CHAR,
	SHORT,
	INT,
	LONG,
	LONG_LONG,
	UNSIGNED,
	VOID,
	FOR,
	WHILE,
	STRUCT,
	WITH,
	METHOD,
	INIT,
	FUNC,
	DO,
	IF,
	ELSE,
	DELETE,
	NEW,

}

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
private:
	void createNum(void);
	void createName(void);
	void createReservedWord(string word);


};

#endif









