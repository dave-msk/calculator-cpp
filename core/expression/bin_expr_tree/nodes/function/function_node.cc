#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/type.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"
#include "function_node.h"

namespace calc {
namespace expr {

FunctionNode::FunctionNode(double (*func)(double))
    : Node(Type::FUNCTION, Precedence::MAX), func(func) {};

double FunctionNode::GetValue() const {
  if (right)
    return (*func)(right->GetValue());

  // TODO: Throw exception
  return 0;
}

}
}