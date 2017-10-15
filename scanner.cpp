#include "scanner.h"

#define isPlus(x)			(x == '+')
#define isDash(x)			(x == '-')
#define isForSlash(x)		(x == '/')
#define isStar(x)			(x == '*')
#define isLeftAngle(x)		(x == '<')
#define isRightAngle(x)		(x == '>')
#define isVerBar(x)			(x == '|')
#define isAndPersand(x)		(x == '&')
#define isCarrot(x)			(x == '^')
#define isTilda(x)			(x == '~')
#define isEqual(x)			(x == '=')
#define isBang(x)			(x == '!')
#define isSemiColon(x)		(x == ';')


Token::Token(uint32_t t, string d) : type(t), data(d) {}

Token::~Token(void) {}

/**
 * Constructor.
 *
 * @param source: The source file that will be read from.
 * @param el: The reference to the ErrorLog that will be used for error
 * reporting.
 */
Scanner::Scanner(FILE *sf, ErrorLog &el) : m_sourceFile(sf), m_el(el) {
	if (fseek(m_sourceFile, 0, SEEK_SET) < 0)
		quit("Failed to seek file");
	while (!feof(m_sourceFile)) {
	
	}
}

/**
 * Destructor
 */
Scanner::~Scanner(void) {
	closeFile(m_sourceFile);
}



