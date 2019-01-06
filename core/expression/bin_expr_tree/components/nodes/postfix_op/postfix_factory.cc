#include <string>
#include "core/expression/bin_expr_tree/components/nodes/factories.h"
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/nodes/postfix_op/postfix_op.h"
#include "core/expression/bin_expr_tree/components/nodes/postfix_op/postfix_op_node.h"

namespace calc {
namespace expr {

std::shared_ptr<Node> CreatePostfixOpNode(const std::string &token) {
  const PostfixOp *postfix_op = PostfixOp::Get(token);
  if (postfix_op == nullptr) return nullptr;
  return std::make_shared<PostfixOpNode>(postfix_op->pred, postfix_op->func);
}

}
}