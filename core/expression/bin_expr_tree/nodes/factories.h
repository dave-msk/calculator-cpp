#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_FACTORIES_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_FACTORIES_H_
#include <string>
#include "core/expression/bin_expr_tree/nodes/node.h"

namespace calc {
namespace expr {

Node* CreateNumberNode(const std::string &token);
Node* CreateOpenBracketNode(const std::string &token);
Node* CreateCloseBracketNode(const std::string &token);
Node* CreateBinaryOpNode(const std::string &token);
Node* CreatePrefixOpNode(const std::string &token);
Node* CreatePostfixOpNode(const std::string &token);
Node* CreateFunctionNode(const std::string &token);

}
}
#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_FACTORIES_H_
