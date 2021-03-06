#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_FUNCTION_FUNCTION_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_FUNCTION_FUNCTION_NODE_H_
#include "core/expression/bin_expr_tree/components/nodes/node.h"

namespace calc {
namespace expr {

class FunctionNode : public Node {
 public:
  explicit FunctionNode(double (*)(double));
  double GetValue() const final;
 private:
  double (*func)(double);
};

}
}



#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_FUNCTION_FUNCTION_NODE_H_
