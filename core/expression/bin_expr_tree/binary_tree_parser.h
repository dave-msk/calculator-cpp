#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_BINARY_TREE_PARSER_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_BINARY_TREE_PARSER_H_

#include <memory>
#include "core/expression/bin_expr_tree/components/taggers/tagger.h"
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/expression.h"
#include "core/expression/parser.h"

namespace calc {
namespace expr {

class BinaryTreeParser : public Parser {
 public:
  std::shared_ptr<Expression> Parse(
      const std::vector<std::string> &tokens) final;

  explicit BinaryTreeParser(std::unique_ptr<Tagger> tagger);
  ~BinaryTreeParser() final;
 private:
  std::unique_ptr<Tagger> tagger;
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_BINARY_TREE_PARSER_H_
