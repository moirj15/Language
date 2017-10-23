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
#define isDollarSign(x)		(x == '&')
#define isHash(x)			(x == '#')

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
		if (isPlus(ch)) {
			m_tokens.push_back(Token(PLUS, "+"));
		}
		else if (isDash(ch)) {
			m_tokens.push_back(Token(DASH, "-"));	
		}
		else if (isForSlash(ch)) {
			m_tokens.push_back(Token(FORWARD_SLASH, "/"));	
		}
		else if (isStar(ch)) {
			m_tokens.push_back(Token(STAR, "*"));	
		}
		else if (isVerBar(ch)) {
			m_tokens.push_back(Token(VERTICAL_BAR, "|"));	
		}
		else if (isAndPersand(ch)) {
			m_tokens.push_back(Token(ANDPERSAND, "&"));	
		}
		else if (isCarrot(ch)) {
			m_tokens.push_back(Token(CARROT, "^"));	
		}
		else if (isTilda(ch)) {
			m_tokens.push_back(Token(TILDA, "~"));	
		}
		else if (isLeftAngle(ch)) {
			m_tokens.push_back(Token(LEFT_ANGLE, "<"));	
		}
		else if (isRightAngle(ch)) {
			m_tokens.push_back(Token(RIGHT_ANGLE, ">"));	
		}
		else if (isBang(ch)) {
			m_tokens.push_back(Token(BANG, "!"));	
		}
		else if (isEqual(ch)) {
			m_tokens.push_back(Token(EQUAL_SIGN, "="));	
		}
		else if (isspace(ch)) {
			
		}
		else if (isalpha(ch)) {
			createName();
		}
		else if (isdigit(ch)) {
			createNum();
		}
		else if (isHash(ch)) {
			m_tokens.push_back(Token(HASH, "#"));	
		}
		else if (isPeriod(ch)) {
			m_tokens.push_back(Token(PERIOD, "."));	
		}
		m_pos++;
	}

	return m_tokens;
}


void Scanner::createNum(void) {
	char ch = m_source[m_pos];
	string num;
	while (isdigit(ch)) {
		num.push_back(ch);
		m_pos++;
		ch = m_source[m_pos];
	}
	m_tokens.push_back(Token(NUMBER, num));
}

void Scanner::createName(void) {
	char ch = m_source[m_pos];
	string name;
	while (isalpha(ch)) {
		name.push_back(ch);
		m_pos++;
		ch = m_source[m_pos];
	}
	m_tokens.push_back(Token(NAME, name));
}
void Scanner::createReservedWord(string word) {

}






