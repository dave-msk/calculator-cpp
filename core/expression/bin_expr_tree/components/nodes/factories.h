#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_FACTORIES_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_FACTORIES_H_
#include <memory>
#include <string>
#include "core/expression/bin_expr_tree/components/nodes/node.h"

namespace calc {
namespace expr {

std::shared_ptr<Node> CreateNumberNode(const std::string &token);
std::shared_ptr<Node> CreateOpenBracketNode(const std::string &token);
std::shared_ptr<Node> CreateCloseBracketNode(const std::string &token);
std::shared_ptr<Node> CreateBinaryOpNode(const std::string &token);
std::shared_ptr<Node> CreatePrefixOpNode(const std::string &token);
std::shared_ptr<Node> CreatePostfixOpNode(const std::string &token);
std::shared_ptr<Node> CreateFunctionNode(const std::string &token);

}
}
#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_FACTORIES_H_
