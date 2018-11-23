#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_TYPE_TAGGER_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_TYPE_TAGGER_H_
#include <string>
#include <vector>
#include "core/expression/bin_expr_tree/nodes/type.h"

namespace calc {
namespace expr {

class Tagger {
 public:
  virtual ~Tagger() = default;
  virtual std::vector<Type> TagTokens(
      const std::vector<std::string> &tokens) const = 0;
};

}
}


#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_NODES_TYPE_TAGGER_H_
