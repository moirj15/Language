#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>

namespace Lex {

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

class Scanner {
	std::vector<char> file;
public:
	Scanner(void);
	Scanner(char *fileName);


private:

};

}; // end namespace
#endif
