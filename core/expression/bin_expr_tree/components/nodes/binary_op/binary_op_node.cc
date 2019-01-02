#include "core/expression/bin_expr_tree/components/nodes/binary_op/binary_op_node.h"
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"
#include "core/expression/bin_expr_tree/components/type.h"

namespace calc {
namespace expr {

BinaryOpNode::BinaryOpNode(const calc::expr::Precedence &pred,
                           double (*bin_op)(double, double))
                           : Node(Type::BINARY_OP, pred),
                             bin_op(bin_op) {};

double BinaryOpNode::GetValue() const {
  if (left && right)
    return (*bin_op)(left->GetValue(), right->GetValue());

  // TODO: Throw exception
  return 0;
}

}
}
