#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_NODE_H_
#include "core/expression/expression.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"
#include "core/expression/bin_expr_tree/nodes/type.h"

namespace calc {
namespace expr {

class Node : public Expression {
 public:
  const Type type;
  const Precedence &precedence;

  explicit Node(const Type &type, const Precedence &precedence);
  ~Node() override;

  void clear();
  virtual double GetValue() const override;

  friend class BinaryTreeParser;

 protected:
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_NODE_H_
