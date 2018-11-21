#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_NUMBER_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_NUMBER_NODE_H_
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/type.h"

namespace calc {
namespace expr {

class NumberNode : public Node {
 public:
  explicit NumberNode(const double &value);

  double GetValue() const final;

 private:
  const double value;
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_NUMBER_NODE_H_
