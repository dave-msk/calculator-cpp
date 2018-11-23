#include "core/expression/bin_expr_tree/nodes/binary_op/binary_op.h"
#include "core/expression/bin_expr_tree/nodes/binary_op/binary_op_node.h"
#include "core/expression/bin_expr_tree/nodes/factories.h"
#include "core/expression/bin_expr_tree/nodes/node.h"

namespace calc {
namespace expr {

Node* CreateBinaryOpNode(const std::string &token) {
  const BinaryOp *op = BinaryOp::Get(token);
  if (op == nullptr) return nullptr;
  return new BinaryOpNode(op->precedence, op->bin_func);
}

}
}