#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_POSTFIX_OP_POSTFIX_OP_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_POSTFIX_OP_POSTFIX_OP_H_
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

class PostfixOp {
 public:
  using UnaryFunction = double (*)(double);
  const std::string token;
  const Precedence pred;
  const UnaryFunction func;

 private:
  explicit PostfixOp(const std::string &token,
                     const Precedence &precedence,
                     const UnaryFunction &func);

  static std::unordered_set<std::string> tokens;
  static std::unordered_map<std::string, PostfixOp*> map;

 public:
  static bool HasToken(const std::string &token);
  static const PostfixOp* Get(const std::string &token);
  static const std::unordered_set<std::string>& GetTokens();

};

}
}



#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_POSTFIX_OP_POSTFIX_OP_H_
