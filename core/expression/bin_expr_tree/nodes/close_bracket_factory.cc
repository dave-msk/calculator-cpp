#include <string>
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"

namespace calc {
namespace expr {

Node* CreateCloseBracketNode(const std::string &token) {
  if (token != ")") return nullptr;
  return new Node(Type::CLOSE_BRACKET, Precedence::ONE);
}

}
}