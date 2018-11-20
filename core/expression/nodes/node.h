#ifndef CALCULATOR_CORE_EXPRESSION_NODES_NODE_H_
#define CALCULATOR_CORE_EXPRESSION_NODES_NODE_H_
#include "type.h"

namespace calc {
namespace expr {

class Node {
 public:
  const Type type;
  const unsigned char precedence;

  explicit Node(const Type &type, const unsigned char &precedence)
      : type(type), precedence(precedence) {};
  ~Node();

  void clear();
  virtual double GetValue() const { return 0; }

 protected:
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_NODES_NODE_H_
