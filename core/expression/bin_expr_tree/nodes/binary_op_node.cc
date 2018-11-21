#include "core/expression/bin_expr_tree/nodes/binary_op_node.h"
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/type.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"

namespace calc {
namespace expr {

BinaryOpNode::BinaryOpNode(const calc::expr::Precedence &precedence,
                           double (*bin_op)(double, double))
                           : Node(Type::BINARY_OP, precedence),
                             bin_op(bin_op) {};

double BinaryOpNode::GetValue() const {
  if (left && right)
    return (*bin_op)(left->GetValue(), right->GetValue());

  // TODO: Throw exception
  return 0;
}

}
}
