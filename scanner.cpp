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
Scanner::Scanner(FILE *sf, ErrorLog *el) : m_sourceFile(sf), m_el(el) {
	if (fseek(m_sourceFile, 0, SEEK_SET) < 0)
		quit("Failed to seek file");
	while (!feof(m_sourceFile)) {
		char ch = fgetc(m_sourceFile);
		m_source.push_back(ch);
	}
	m_pos = 0;
}

/**
 * Destructor
 */
Scanner::~Scanner(void) {
	closeFile(m_sourceFile);
}

vector<Token> Scanner::scan(void) {
	while (m_pos < m_source.size()) {
		char ch = m_source[m_pos];
		if (isdigit(ch)) {
			isInteger();
		}
		m_pos++;
	}

	return m_tokens;
}

/**
 * Attempts to create a integer token from the current positon in the source.
 */
bool Scanner::isInteger(void) {
	int curr = m_pos;
	string num;
	while (isdigit(m_source[curr])) {
		//TODO: this isn't grabbing all the digits for the integer
		num.push_back(m_source[curr]);
		printf("num %s\n", num.c_str());
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
		m_tokens.push_back(Token(ADDITION_BINARY, "+"));
	else if (isDash(curr))
		m_tokens.push_back(Token(SUBTRACTION_BINARY, "-"));
	else if (isStar(curr))
		m_tokens.push_back(Token(MULTIPLICATION_BINARY, "*"));
	else if (isForSlash(curr))
		m_tokens.push_back(Token(DIVISION_BINARY, "/"));
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
		m_tokens.push_back(Token(LOG_AND_BINARY, "&"));
	else if (isVerBar(curr))
		m_tokens.push_back(Token(LOG_OR_BINARY, "|"));
	else if (isTilda(curr))
		m_tokens.push_back(Token(LOG_INVERT, "~"));
	else if (isCarrot(curr))
		m_tokens.push_back(Token(LOG_XOR_BINARY, "^"));
	else if (isLeftAngle(curr) && isLeftAngle(la)) {
		m_tokens.push_back(Token(LEFT_SHIFT_BINARY, "<<"));
		m_pos++;
	}
	else if(isRightAngle(curr) && isRightAngle(la)) {
		m_tokens.push_back(Token(RIGHT_SHIFT_BINARY, ">>"));
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
		m_tokens.push_back(Token(BOOL_AND, "&&"));
	else if (isVerBar(curr) && isVerBar(la)) 
		m_tokens.push_back(Token(BOOL_OR, "||"));
	else 
		return false;
	
	m_pos += 2;
	return true;
}

/**
 * Attempts to create a comparison token from the current position.
 */
bool Scanner::isCompOp(void) {
	char curr = m_source[m_pos];
	char la = m_source[m_pos + 1];
	if (isLeftAngle(curr) && isEqual(la)) {
		m_tokens.push_back(Token(LESS_THAN_EQL, "<="));
		m_pos++;
	}
	else if (isRightAngle(curr) && isEqual(la)) {
		m_tokens.push_back(Token(GREATER_THAN_EQL, ">="));
		m_pos++;
	}
	else if (isLeftAngle(curr))
		m_tokens.push_back(Token(LESS_THAN, "<"));
	else if (isRightAngle(curr))
		m_tokens.push_back(Token(GREATER_THAN, ">"));
	else 
		return false;
	
	m_pos++;
	return true;
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










