#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"
#include "core/expression/bin_expr_tree/components/nodes/prefix_op/prefix_op_node.h"
#include "core/expression/bin_expr_tree/components/type.h"

namespace calc {
namespace expr {

PrefixOpNode::PrefixOpNode(const Precedence &precedence,
                           double (*pfx_op)(double))
                           : Node(Type::PREFIX_OP, precedence),
                             pfx_op(pfx_op) {};

double PrefixOpNode::GetValue() const {
  if (right)
    return (*pfx_op)(right->GetValue());

  // TODO: Throw exception
  return 0;
}

}
}