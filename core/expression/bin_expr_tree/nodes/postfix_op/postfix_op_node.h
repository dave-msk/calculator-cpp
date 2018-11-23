#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_POSTFIX_OP_POSTFIX_OP_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_POSTFIX_OP_POSTFIX_OP_NODE_H_
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"

namespace calc {
namespace expr {

class PostfixOpNode : public Node {
 public:
  explicit PostfixOpNode(const Precedence &precedence,
                         double (*post_op)(double));
  double GetValue() const final;
 private:
  double (*post_op)(double);
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_POSTFIX_OP_POSTFIX_OP_NODE_H_
