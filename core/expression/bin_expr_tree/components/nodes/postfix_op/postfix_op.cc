#include <string>
#include <unordered_set>
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/nodes/postfix_op/postfix_op.h"
#include "core/expression/bin_expr_tree/components/nodes/postfix_op/postfix_op_node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

std::unordered_set<std::string> PostfixOp::tokens;
std::unordered_map<std::string, PostfixOp*> PostfixOp::map;

bool PostfixOp::HasToken(const std::string &token) {
  return map.find(token) != map.end();
}

const PostfixOp* PostfixOp::Get(const std::string &token) {
  auto it = map.find(token);
  if (it == map.end()) return nullptr;
  return it->second;
}

const std::unordered_set<std::string>& PostfixOp::GetTokens() {
  return tokens;
}

PostfixOp::PostfixOp(const std::string &token,
                     const Precedence &precedence,
                     const UnaryFunction &func)
                     : token(token), pred(precedence), func(func) {
  map[token] = this;
  tokens.insert(token);
}

}
}
