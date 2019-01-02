#include <memory>
#include <string>
#include "core/expression/bin_expr_tree/binary_tree_parser.h"
#include "core/expression/bin_expr_tree/components/nodes/factories.h"
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/type.h"

namespace calc {
namespace expr {

static std::shared_ptr<Node> CreateNode(const std::string &token,
                                        const Type &type);

BinaryTreeParser::BinaryTreeParser(
    std::unique_ptr<Tagger> tagger) : tagger(std::move(tagger)) {}

BinaryTreeParser::~BinaryTreeParser() = default;

std::shared_ptr<Expression> BinaryTreeParser::Parse(
    const std::vector<std::string> &tokens) {

  const std::vector<Type> types = tagger->TagTokens(tokens);
  auto root_node = std::make_shared<Node>(Type::NONE, Precedence::ONE);
  auto curr_node = root_node;

  for (size_t i = 0; i < tokens.size(); ++i) {
    std::shared_ptr<Node> new_node = CreateNode(tokens.at(i), types.at(i));

    if (new_node->type != Type::OPEN_BRACKET) {
      // Step 4
      if (new_node->order.IsLeft())
        while (curr_node->order >= new_node->order)
          curr_node = curr_node->parent.lock();
      else
        while (curr_node->order > new_node->order)
          curr_node = curr_node->parent.lock();
    }

    if (new_node->type == Type::CLOSE_BRACKET) {
      // Step 5
      auto parent = curr_node->parent.lock();
      parent->right = curr_node->right;
      parent->right->parent = parent;
//      curr_node->clear();
      // Step 6
      curr_node = parent;
      continue;
    }

    new_node->left = curr_node->right;
    new_node->left->parent = new_node;
    curr_node->right = new_node;
    curr_node->right->parent = curr_node;

    curr_node = new_node;
  }

  while (!(curr_node->parent.expired())) {
    auto parent_node = curr_node->parent.lock();
    if (parent_node->type == Type::NONE) break;
    curr_node = std::move(parent_node);
  }
  root_node = curr_node;

  return root_node;
}

static std::shared_ptr<Node> CreateNode(const std::string &token,
                                        const Type &type) {
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
