#include "core/expression/bin_expr_tree/nodes/number_node.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"

namespace calc {
namespace expr {

NumberNode::NumberNode(const double &value)
    : Node(Type::NUMBER, Precedence::MAX),
      value(value) {}

double NumberNode::GetValue() const {
  return value;
}

}
}
