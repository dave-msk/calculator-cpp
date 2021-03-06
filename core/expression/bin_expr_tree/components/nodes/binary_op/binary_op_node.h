#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_BINARY_OP_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_BINARY_OP_NODE_H_
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

class BinaryOpNode : public Node {
 public:
  explicit BinaryOpNode(const Precedence &,
                        double (*)(double, double));
  double GetValue() const final;
 private:
  double (*bin_op)(double, double);
};

}
}


#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_BINARY_OP_NODE_H_
