#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"
#include "core/expression/bin_expr_tree/components/type.h"

namespace calc {
namespace expr {

Node::Node(const Type &type, const Precedence &pred)
    : type(type), order(pred) {}

Node::~Node() = default;

void Node::clear() {
  left.reset();
  right.reset();
}

double Node::GetValue() const {
  return 0.0;
}

}
}