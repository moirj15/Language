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
#define isPeriod(x)			(x == '.')

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
		m_source.push_back(fgetc(m_sourceFile));	
	}
}

/**
 * Destructor
 */
Scanner::~Scanner(void) {
	closeFile(m_sourceFile);
}

vector<Token> Scanner::scan(void) {
	while (m_pos < m_source.size()) {
		char curr = m_source[m_pos];
		if (isDash(curr)) {
			if (!isNegate())
				isArithOp();
		}
		if (isPlus(curr)) {
		//	if (!isIncrement())
		}
	}
}

/**
 * Attempts to create a integer token from the current positon in the source.
 */
bool Scanner::isInteger(void) {
	int curr = m_pos;
	string num;
	while (isdigit(m_source[curr])) {
		num.push_back(m_source[curr]);
		if (isxdigit(m_source[curr + 1]))
			return false;
	
		else if (isPeriod(m_source[curr + 1]))
			return false;
	
		curr++;
	}	
	m_tokens.push_back(Token(INTEGER, num));
	m_pos = curr;
	return true;
}

/**
 * Attempts to create an arithmetic token from the current position.
 */
bool Scanner::isArithOp(void) {
	char curr = m_source[m_pos];
	if (isPlus(curr)) 
		m_tokens.push_back(Token(ADDITION_BINARY, string(1, curr)));
	else if (isDash(curr))
		m_tokens.push_back(Token(SUBTRACTION_BINARY, string(1, curr)));
	else if (isStar(curr))
		m_tokens.push_back(Token(MULTIPLICATION_BINARY, string(1, curr)));
	else if (isForSlash(curr))
		m_tokens.push_back(Token(DIVISION_BINARY, string(1, curr)));
	else
		return false;
	m_pos++;
	return true;
}

/**
 * Attempts to create a logical token from the current position.
 */
bool Scanner::isLogOp(void) {
	char curr = m_source[m_pos];
	char la = m_source[m_pos + 1];
	if (isAndPersand(curr)) 
		m_tokens.push_back(Token(LOG_AND_BINARY, NULL));
	else if (isVerBar(curr))
		m_tokens.push_back(Token(LOG_OR_BINARY, NULL));
	else if (isTilda(curr))
		m_tokens.push_back(Token(LOG_INVERT, NULL));
	else if (isCarrot(curr))
		m_tokens.push_back(Token(LOG_XOR_BINARY, NULL));
	else if (isLeftAngle(curr) && isLeftAngle(la)) {
		m_tokens.push_back(Token(LEFT_SHIFT_BINARY, NULL));
		m_pos++;
	}
	else if(isRightAngle(curr) && isRightAngle(la)) {
		m_tokens.push_back(Token(RIGHT_SHIFT_BINARY, NULL));
		m_pos++;
	}
	else {
		return false;
	}
	m_pos++;
	return true;
		
}

/**
 * Attempts to create a boolean token from the current position.
 */
bool Scanner::isBoolOp(void) {
	char curr = m_source[m_pos];
	char la = m_source[m_pos + 1];
	if (isAndPersand(curr) && isAndPersand(la))
		m_tokens.push_back(Token(BOOL_AND, NULL));
	else if (isVerBar(curr) && isVerBar(la)) 
		m_tokens.push_back(Token(BOOL_OR, NULL));
	else 
		return false;
	
	m_pos += 2;
	return true;
}

/**
 * Attempts to create a comparison token from the current position.
 */
bool Scanner::isCompOp(void) {

}

/**
 * Attempts to create a negation token from the current position.
 */
bool Scanner::isNegate(void) {
	uint32_t prevTok = m_tokens.back().type;
	//TODO: check for all possible operations on previous token.
	bool prevIsOp = (isDash(prevTok) || isPlus(prevTok) || isForSlash(prevTok) 
					|| isStar(prevTok));
	if (prevIsOp && isdigit(m_source[m_pos + 1])) {
		m_tokens.push_back(Token(NEGATION, string(1, m_source[m_pos])));
		return true;
	}
	return false;
}










