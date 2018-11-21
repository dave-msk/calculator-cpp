
#include <queue>
#include "core/expression/bin_expr_tree/binary_tree_parser.h"
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/type.h"

namespace calc {
namespace expr {

static std::queue<Node*> TokensToNodes(const std::vector<std::string> &tokens);

Expression* BinaryTreeParser::Parse(const std::vector<std::string> &tokens) {
  auto nodes = TokensToNodes(tokens);

  Node *curr_node = new Node(Type::NONE, Precedence::ONE);

  while (!nodes.empty()) {
    Node *new_node = nodes.front();
    nodes.pop();

    if (new_node->type != Type::OPEN_BRACKET) {
      // Step 4
      if (new_node->precedence.left_associate)
        while (curr_node->precedence >= new_node->precedence)
          curr_node = curr_node->parent;
      else
        while (curr_node->precedence > new_node->precedence)
          curr_node = curr_node->parent;
    }

    if (new_node->type == Type::CLOSE_BRACKET) {
      Node *parent = curr_node->parent;
      parent->right = curr_node->right;
      parent->right->parent = parent;
      curr_node->clear();
      delete curr_node;
      delete new_node;
      curr_node = parent;
      continue;
    }

    new_node->left = curr_node->right;
    new_node->left->parent = new_node;
    curr_node->right = new_node;
    curr_node->right->parent = curr_node;

    curr_node = new_node;
  }

  while (curr_node->parent && curr_node->parent->type != Type::NONE)
    curr_node = curr_node->parent;

  if (curr_node->parent) {
    curr_node->parent->clear();
    delete curr_node->parent;
    curr_node->parent = nullptr;
  }

  return curr_node;
}

}
}
