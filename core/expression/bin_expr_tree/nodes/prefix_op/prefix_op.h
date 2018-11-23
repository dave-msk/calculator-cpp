#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_PREFIX_OP_PREFIX_OP_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_PREFIX_OP_PREFIX_OP_H_
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"

namespace calc {
namespace expr {

class PrefixOp {
 public:
  static const PrefixOp NEGATE;
  static const PrefixOp IDENTITY;

  static bool HasToken(const std::string &token);
  static const PrefixOp* Get(const std::string &token);
  static const std::unordered_set<std::string>& GetTokens();

  typedef double (*UnaryFunction)(double);
  const std::string token;
  const Precedence &precedence;
  const UnaryFunction func;

 private:
  static std::unordered_set<std::string> tokens;
  static std::unordered_map<std::string, PrefixOp*> map;

  explicit PrefixOp(const std::string &token,
                    const Precedence &precedence,
                    const UnaryFunction &func);
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_PREFIX_OP_PREFIX_OP_H_
