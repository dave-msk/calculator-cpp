#include <memory>
#include <string>
#include "core/expression/bin_expr_tree/components/nodes/factories.h"
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

std::shared_ptr<Node> CreateOpenBracketNode(const std::string &token) {
  if (token != "(") return nullptr;
  return std::make_shared<Node>(Type::OPEN_BRACKET, Precedence::ONE);
}

}
}