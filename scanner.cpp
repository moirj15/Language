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
#define isPercent(x)		(x == '%')
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
	while(m_pos < m_source.size()) {
		char c = m_source[m_pos];
		if (isdigit(c)) {
			createNum();
		}
		else if (isalpha(c)) {
			createName();
		}
		else if (isspace(c)) {
			m_pos++;
		}
		else if (isPlus(c)) {
			createAddOps();
		}
		else if (isDash(c)) {
			createSubOps();
		}
		else if (isStar(c)) {
			createMultOps();
		}
		else if (isForSlash(c)) {
			createDivOps();
		}
		else if (isRightAngle(c)) {
			
		}
		else if (isLeftAngle(c)) {
		
		}
		else if (isPercent(c)) {
		
		}
		else if (isAndPersand(c)) {
		
		}
		else if (isVerBar(c)) {
		
		}
	}
}


void Scanner::createNum(void) {
	uint32_t tPos = m_pos; // in case we need to roll back
	char c;
	string num;
	do {
		c = m_source[tPos];
		num.push_back(c);
		tPos++;
		//TODO: add some error checking
	} while (isdigit(c));

	m_tokens.push_back(Token(INTEGER, num));
	m_pos = tPos;
}

void Scanner::createName(void) {
	// TODO: implement
}

void Scanner::createReservedWord(string word) {
	// TODO: implement
}


void Scanner::createAddOps(void) {
	uint32_t tmp = m_pos + 1;
	char curr = m_source[tmp];
	string add;
	add.push_back(m_source[m_pos]);
	switch (curr) {
		case '+':
			add.push_back('+');
			m_tokens.push_back(Token())
			tmp++;
			break;

		case '=':
			add.push_back('=');

			break;

		default:
			break;
	}
}

void Scanner::createSubOps(void) {

}

void Scanner::createMultOps(void) {

}

void Scanner::createDivOps(void) {

}












