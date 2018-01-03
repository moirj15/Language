#include "scanner.h"

namespace Lex {

Token::Token(void) {

}

/**
 * Constructor.
 *
 * @param d: The data that will be held by the token.
 * @param i: The token identifier.
 */
Token::Token(std::string d, uint32 i) : data(d), identifier(i) {

}

/**
 * Destructor.
 */
Token::~Token(void) {

}

}; // end namespace
