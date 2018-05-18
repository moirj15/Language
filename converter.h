#ifndef CONVERTER_H
#define CONVERTER_H

#include "utils.h"
#include "ast.h"
#include "vm.h"

// Do a pre-order traversal to get postfix order

void AstToByteCode(Ast *tree, std::vector<u64> &code);
#endif
