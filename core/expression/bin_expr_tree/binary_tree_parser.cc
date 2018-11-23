#include <string>
#include "core/expression/bin_expr_tree/binary_tree_parser.h"
#include "core/expression/bin_expr_tree/nodes/factories.h"
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/type.h"

namespace calc {
namespace expr {

static Node* CreateNode(const std::string &token, const Type &type);

BinaryTreeParser::BinaryTreeParser(
    const calc::expr::Tagger *tagger) : tagger(tagger) {}

BinaryTreeParser::~BinaryTreeParser() {
  delete tagger;
}

Expression* BinaryTreeParser::Parse(const std::vector<std::string> &tokens) {

  const std::vector<Type> types = tagger->TagTokens(tokens);
  Node *curr_node = new Node(Type::NONE, Precedence::ONE);

  for (size_t i = 0; i < tokens.size(); ++i) {
    Node *new_node = CreateNode(tokens.at(i), types.at(i));

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

static Node* CreateNode(const std::string &token, const Type &type) {
  switch (type) {
    case Type::NUMBER:
      return CreateNumberNode(token);
    case Type::OPEN_BRACKET:
      return CreateOpenBracketNode(token);
    case Type::CLOSE_BRACKET:
      return CreateCloseBracketNode(token);
    case Type::BINARY_OP:
      return CreateBinaryOpNode(token);
    case Type::PREFIX_OP:
      return CreatePrefixOpNode(token);
    case Type::POSTFIX_OP:
      return CreatePostfixOpNode(token);
    case Type::FUNCTION:
      return CreateFunctionNode(token);
    default:
      return nullptr;
  }
}


}
}
