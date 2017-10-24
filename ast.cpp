#include "ast.h"

AST::~AST() {}
void AST::print(void) {}

BinaryOpAst::BinaryOpAst(char o, AST *l, AST *r) : op(o), left(l), right(r) {

}

BinaryOpAst::~BinaryOpAst(void) {
    delete(left);
    delete(right);
}

void BinaryOpAst::print(void) {

}

IntegerAst::IntegerAst(uint32_t n) : value(n) {

}

IntegerAst::~IntegerAst(void) {}

void IntegerAst::print(void) {
    printf("%d", value);
}