#include "core/expression/nodes/node.h"

namespace calc {
namespace expr {

Node::~Node() {
  delete left;
  delete right;
}

void Node::clear() {
  left = nullptr;
  right = nullptr;
}

}
}