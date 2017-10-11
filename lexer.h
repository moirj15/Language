#ifndef LEXER_H
#define LEXER_H

#include "utils.h"

enum TOKEN_TYPE {

};

struct Token {
	uint32_t type;
	char 	 *data;
	uint32_t size;
};

#endif
