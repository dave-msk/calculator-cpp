#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_NODE_H_

#include <memory>
#include "core/expression/expression.h"
#include "core/expression/bin_expr_tree/components/order.h"
#include "core/expression/bin_expr_tree/components/precedence.h"
#include "core/expression/bin_expr_tree/components/type.h"

namespace calc {
namespace expr {

//class Node : public Expression {
// public:
//  const Type type;
//  const Order order;
//
//  explicit Node(const Type &type, const Precedence &pred);
//  ~Node() override;
//
//  void clear();
//  virtual double GetValue() const override;
//
//  friend class BinaryTreeParser;
//
// protected:
//  Node *parent = nullptr;
//  Node *left = nullptr;
//  Node *right = nullptr;
//};

class Node : public Expression {
 public:
  const Type type;
  const Order order;

  explicit Node(const Type &type, const Precedence &pred);
  virtual ~Node() override;

  void clear();
  virtual double GetValue() const override;

  friend class BinaryTreeParser;

 protected:
  std::weak_ptr<Node> parent;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;

};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_NODE_H_
