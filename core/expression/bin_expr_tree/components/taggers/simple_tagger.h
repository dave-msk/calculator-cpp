#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_TAGGERS_SIMPLE_TAGGER_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_TAGGERS_SIMPLE_TAGGER_H_
#include <string>
#include <unordered_map>
#include <vector>
#include "core/expression/bin_expr_tree/components/taggers/tagger.h"
#include "core/expression/bin_expr_tree/components/type.h"

namespace calc {
namespace expr {

// TODO: Make it lazy
class SimpleTagger : public Tagger {
 public:
  std::vector<Type> TagTokens(
      const std::vector<std::string> &tokens) const final;
  SimpleTagger();  // TODO: Decouple policy to file
  ~SimpleTagger() final;

 private:
  std::unordered_map<Type, std::vector<Type>, std::hash<int>> type_map;

//  explicit SimpleTagger(const std::string &policy_file);

};

}
}



#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_TAGGERS_SIMPLE_TAGGER_H_
