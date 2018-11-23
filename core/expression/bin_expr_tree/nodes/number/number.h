#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_NUMBER_NUMBER_H
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_NUMBER_NUMBER_H
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "core/expression/bin_expr_tree/nodes/node.h"

namespace calc {
namespace expr {

class Number {
 public:
  static const Number PI;
  static const Number E;

  static bool HasToken(const std::string &token);
  static const Number* Get(const std::string &token);
  static const std::unordered_set<std::string>& GetTokens();

  const std::string token;
  const double value;

 private:
  static std::unordered_set<std::string> tokens;
  static std::unordered_map<std::string, Number*> map;

  explicit Number(const std::string &token, double value);
};

}
}



#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_NUMBER_NUMBER_H
