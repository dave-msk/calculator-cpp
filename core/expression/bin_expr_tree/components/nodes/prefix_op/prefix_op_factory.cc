#include <memory>
#include <string>
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/nodes/prefix_op/prefix_op.h"
#include "core/expression/bin_expr_tree/components/nodes/prefix_op/prefix_op_node.h"

namespace calc {
namespace expr {

std::shared_ptr<Node> CreatePrefixOpNode(const std::string &token) {
  const PrefixOp *prefix_op = PrefixOp::Get(token);
  if (prefix_op == nullptr) return nullptr;
  return std::make_shared<PrefixOpNode>(prefix_op->pred, prefix_op->func);
}

}
}
