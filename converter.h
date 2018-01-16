#ifndef CONVERTER_H
#define CONVERTER_H

#include "utils.h"
#include "ast.h"
#include "vm.h"

// Do a pre-order traversal to get postfix order

namespace Converter {

void AstToByteCode(Parser::Ast *tree, std::vector<uint64> &code);

} // end namespace
#endif
