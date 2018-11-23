#include <string>
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/prefix_op/prefix_op.h"
#include "core/expression/bin_expr_tree/nodes/prefix_op/prefix_op_node.h"

namespace calc {
namespace expr {

Node* CreatePrefixOpNode(const std::string &token) {
  const PrefixOp *prefix_op = PrefixOp::Get(token);
  if (prefix_op == nullptr) return nullptr;
  return new PrefixOpNode(prefix_op->precedence, prefix_op->func);
}

}
}
