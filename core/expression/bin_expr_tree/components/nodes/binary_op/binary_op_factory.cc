#include <memory>
#include "core/expression/bin_expr_tree/components/nodes/binary_op/binary_op.h"
#include "core/expression/bin_expr_tree/components/nodes/binary_op/binary_op_node.h"
#include "core/expression/bin_expr_tree/components/nodes/factories.h"
#include "core/expression/bin_expr_tree/components/nodes/node.h"

namespace calc {
namespace expr {

std::shared_ptr<Node> CreateBinaryOpNode(const std::string &token) {
  const BinaryOp *op = BinaryOp::Get(token);
  if (op == nullptr) return nullptr;
  return std::make_shared<BinaryOpNode>(op->pred, op->bin_func);
}

}
}