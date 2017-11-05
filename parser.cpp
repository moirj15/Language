#include <stack>
#include "parser.h"

Parser::Parser(vector<Token> tok) : tokens(tok) {
    pos = 0;
}

Parser::~Parser(void) {

}

IntegerAst *Parser::parseInt(void) {
	uint32_t end = pos;
	while (tokens[end].type != SEMI_COLON) {
		// TODO: add error checking. 
		end++;
	}
	vector<Token> *postFix = toPostFix(end);


	delete(postFix);
}

vector<Token> *Parser::toPostFix(uint32_t end) {
	vector<Token> *result = new vector<Token>();
	stack<Token> stk;
	while (pos < end) {
		Token op = tokens[pos];
		if (op.type == NUMBER) {
			result->push_back(tokens[pos]);
		}
		else if (op.type <= TILDA) {
			while (stk.size() >= 0) {
				if (stk.empty()) {
					stk.push(tokens[pos]);
					break;
				}
				Token popped = stk.top();
				stk.pop();
				if (op.type == LEFT_PAREN) {
					stk.push(tokens[pos]);
					break;
				}
				else if (isEqualOrLess(op.type, popped.type)) {
					stk.push(popped);
					stk.push(op);
					break;
				}
				else {
					result->push_back(popped);
				}
				pos++;
			}
		}
		else if (op.type == LEFT_PAREN) {
			stk.push(op);
		}
		else if (op.type == RIGHT_PAREN) {
			while (!stk.empty()) {
				Token popped = stk.top();
				stk.pop();
				if (popped.type == LEFT_PAREN) {
					break;
				}
				result->push_back(popped);
			}
		}
		pos++;
	}

	while (!stk.empty()) {
		Token popped = stk.top();
		stk.pop();
		result->push_back(popped);
	}

	return result;
}









