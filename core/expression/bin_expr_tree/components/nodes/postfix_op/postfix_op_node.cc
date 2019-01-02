#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/nodes/postfix_op/postfix_op_node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"
#include "core/expression/bin_expr_tree/components/type.h"

namespace calc {
namespace expr {

PostfixOpNode::PostfixOpNode(const calc::expr::Precedence &pred,
                             double (*post_op)(double))
                             : Node(Type::POSTFIX_OP, pred),
                               post_op(post_op) {};

double PostfixOpNode::GetValue() const {
  if (left)
    return (*post_op)(left->GetValue());

  // TODO: Throw exception
  return 0;
}

}
}