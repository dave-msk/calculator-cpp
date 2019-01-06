#include <memory>
#include <string>
#include "core/expression/bin_expr_tree/components/nodes/factories.h"
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/nodes/number/number.h"
#include "core/expression/bin_expr_tree/components/nodes/number/number_node.h"

namespace calc {
namespace expr {

std::shared_ptr<Node> CreateNumberNode(const std::string &token) {
  try {
    double value = std::stod(token);
    return std::make_shared<NumberNode>(value);
  } catch (std::invalid_argument&) {}

  const Number *number = Number::Get(token);
  if (number == nullptr) return nullptr;
  return std::make_shared<NumberNode>(number->value);
}

}
}
