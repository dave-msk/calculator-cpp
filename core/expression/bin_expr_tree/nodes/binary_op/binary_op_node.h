#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_BINARY_OP_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_BINARY_OP_NODE_H_
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"

namespace calc {
namespace expr {

class BinaryOpNode : public Node {
 public:
  explicit BinaryOpNode(const Precedence &precedence,
                        double (*bin_op)(double, double));
  double GetValue() const final;
 private:
  double (*bin_op)(double, double);
};

}
}


#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_BINARY_OP_NODE_H_
