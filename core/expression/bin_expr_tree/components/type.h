#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_TYPE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_TYPE_H_

namespace calc {
namespace expr {

enum Type {
  NONE = 0,
  NUMBER = 1,
  OPEN_BRACKET = 2,
  CLOSE_BRACKET = 3,
  BINARY_OP = 4,
  PREFIX_OP = 5,
  POSTFIX_OP = 6,
  FUNCTION = 7
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_TYPE_H_
