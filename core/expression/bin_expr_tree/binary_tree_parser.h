#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_BINARY_TREE_PARSER_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_BINARY_TREE_PARSER_H_
#include "core/expression/expression.h"
#include "core/expression/parser.h"
#include "core/expression/bin_expr_tree/nodes/node.h"

namespace calc {
namespace expr {

class BinaryTreeParser : public Parser {
 public:
  Expression* Parse(const std::vector<std::string> &tokens) final;
  ~BinaryTreeParser() final;
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_BINARY_TREE_PARSER_H_
