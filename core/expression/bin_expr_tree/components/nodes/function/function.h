#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_FUNCTION_FUNCTION_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_FUNCTION_FUNCTION_H_
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "core/expression/bin_expr_tree/components/nodes/node.h"

namespace calc {
namespace expr {

class Function {
 public:
  using UnaryFunction = double (*)(double);
  const UnaryFunction func;

 private:
  static std::unordered_set<std::string> tokens;
  static std::unordered_map<std::string, Function*> map;

  explicit Function(const std::string &token, UnaryFunction func);

 public:
  static const Function SIN;
  static const Function COS;
  static const Function TAN;
  static const Function SINH;
  static const Function COSH;
  static const Function TANH;
  static const Function LOG;

  static bool HasToken(const std::string &token);
  static const Function* Get(const std::string &token);
  static const std::unordered_set<std::string>& GetTokens();
};

}
}


#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_NODES_FUNCTION_FUNCTION_H_
