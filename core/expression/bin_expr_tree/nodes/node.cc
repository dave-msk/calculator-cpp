#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"
#include "core/expression/bin_expr_tree/nodes/type.h"

namespace calc {
namespace expr {

Node::Node(const Type &type, const Precedence &precedence)
    : type(type), precedence(precedence) {}

Node::~Node() {
  delete left;
  delete right;
}

void Node::clear() {
  left = nullptr;
  right = nullptr;
}

double Node::GetValue() const {
  return 0.0;
}

}
}