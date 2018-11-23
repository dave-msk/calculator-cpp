#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/postfix_op/postfix_op_node.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"
#include "core/expression/bin_expr_tree/nodes/type.h"

namespace calc {
namespace expr {

PostfixOpNode::PostfixOpNode(const calc::expr::Precedence &precedence,
                             double (*post_op)(double))
                             : Node(Type::POSTFIX_OP, precedence),
                               post_op(post_op) {};

double PostfixOpNode::GetValue() const {
  if (left)
    return (*post_op)(left->GetValue());

  // TODO: Throw exception
  return 0;
}

}
}