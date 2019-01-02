#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_PREFIX_OP_PREFIX_OP_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_PREFIX_OP_PREFIX_OP_NODE_H_
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

class PrefixOpNode : public Node {
 public:
  explicit PrefixOpNode(const Precedence &precedence,
                        double (*pfx_op)(double));
  double GetValue() const final;
 private:
  double (*pfx_op)(double);
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_PREFIX_OP_PREFIX_OP_NODE_H_
