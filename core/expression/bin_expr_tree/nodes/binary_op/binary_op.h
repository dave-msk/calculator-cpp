#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_BINARY_OP_BINARY_OP_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_BINARY_OP_BINARY_OP_H_
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"

namespace calc {
namespace expr {

class BinaryOp {
 public:
  static const BinaryOp ADD;
  static const BinaryOp MINUS;
  static const BinaryOp MULTIPLY;
  static const BinaryOp DIVIDE;
  static const BinaryOp MODULO;
  static const BinaryOp POWER;

  static bool HasToken(const std::string &token);
  static const BinaryOp* Get(const std::string &token);
  static const std::unordered_set<std::string>& GetTokens();

  typedef double (*BinaryFunction)(double, double);
  const BinaryFunction bin_func;
  const Precedence &precedence;
  const std::string token;

 private:
  static std::unordered_set<std::string> tokens;
  static std::unordered_map<std::string, BinaryOp*> map;

  explicit BinaryOp(const std::string &token,
                    const Precedence &precedence,
                    const BinaryFunction &bin_func);
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_BINARY_OP_BINARY_OP_H_
