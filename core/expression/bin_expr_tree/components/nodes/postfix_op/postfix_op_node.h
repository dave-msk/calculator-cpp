#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_POSTFIX_OP_POSTFIX_OP_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_POSTFIX_OP_POSTFIX_OP_NODE_H_
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

class PostfixOpNode : public Node {
 public:
  explicit PostfixOpNode(const Precedence&, double (*)(double));
  double GetValue() const final;
 private:
  double (*post_op)(double);
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_POSTFIX_OP_POSTFIX_OP_NODE_H_
