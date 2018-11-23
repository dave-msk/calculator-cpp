#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_POSTFIX_OP_POSTFIX_OP_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_POSTFIX_OP_POSTFIX_OP_H_
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"

namespace calc {
namespace expr {

class PostfixOp {
 public:


  static bool HasToken(const std::string &token);
  static const PostfixOp* Get(const std::string &token);
  static const std::unordered_set<std::string>& GetTokens();

  typedef double (*UnaryFunction)(double);
  const std::string token;
  const Precedence &precedence;
  const UnaryFunction func;

 private:
  static std::unordered_set<std::string> tokens;
  static std::unordered_map<std::string, PostfixOp*> map;

  explicit PostfixOp(const std::string &token,
                     const Precedence &precedence,
                     const UnaryFunction &func);

};

}
}



#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_POSTFIX_OP_POSTFIX_OP_H_
