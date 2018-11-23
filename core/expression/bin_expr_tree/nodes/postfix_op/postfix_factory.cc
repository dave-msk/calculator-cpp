#include <string>
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/postfix_op/postfix_op.h"
#include "core/expression/bin_expr_tree/nodes/postfix_op/postfix_op_node.h"

namespace calc {
namespace expr {

Node* CreatePostfixOpNode(const std::string &token) {
  const PostfixOp *postfix_op = PostfixOp::Get(token);
  if (postfix_op == nullptr) return nullptr;
  return new PostfixOpNode(postfix_op->precedence, postfix_op->func);
}

}
}