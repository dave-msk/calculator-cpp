#include <string>
#include <unordered_set>
#include "core/expression/bin_expr_tree/utils.h"
#include "core/expression/bin_expr_tree/components/nodes/binary_op/binary_op.h"
#include "core/expression/bin_expr_tree/components/nodes/function/function.h"
#include "core/expression/bin_expr_tree/components/nodes/number/number.h"
#include "core/expression/bin_expr_tree/components/nodes/postfix_op/postfix_op.h"
#include "core/expression/bin_expr_tree/components/nodes/prefix_op/prefix_op.h"

namespace calc {
namespace expr {

const std::unordered_set<std::string> GetAllTokens() {
  std::unordered_set<std::string> tokens{};

  auto bin_tokens = BinaryOp::GetTokens();
  tokens.insert(bin_tokens.begin(), bin_tokens.end());
  auto func_tokens = Function::GetTokens();
  tokens.insert(func_tokens.begin(), func_tokens.end());
  auto num_tokens = Number::GetTokens();
  tokens.insert(num_tokens.begin(), num_tokens.end());
  auto post_tokens = PostfixOp::GetTokens();
  tokens.insert(post_tokens.begin(), post_tokens.end());
  auto pre_tokens = PrefixOp::GetTokens();
  tokens.insert(pre_tokens.begin(), pre_tokens.end());
  tokens.insert({"(", ")", " "});

  return tokens;
}

}
}