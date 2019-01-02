#include <string>
#include <unordered_set>
#include "core/expression/bin_expr_tree/components/nodes/prefix_op/prefix_op.h"
#include "core/expression/bin_expr_tree/components/nodes/prefix_op/prefix_op_node.h"
#include "core/expression/bin_expr_tree/components/nodes/node.h"
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

PrefixOp::PrefixOp(const std::string &token,
                   const Precedence &precedence,
                   const UnaryFunction &func)
                   : token(token), pred(precedence), func(func) {
  map[token] = this;
  tokens.insert(token);
}

std::unordered_set<std::string> PrefixOp::tokens;
std::unordered_map<std::string, PrefixOp*> PrefixOp::map;

const PrefixOp PrefixOp::NEGATE = PrefixOp(
    "-", Precedence::FOUR, [](double v){ return -v; });
const PrefixOp PrefixOp::IDENTITY = PrefixOp(
    "+", Precedence::FOUR, [](double v){ return v; });

bool PrefixOp::HasToken(const std::string &token) {
  return map.find(token) != map.end();
}

const PrefixOp* PrefixOp::Get(const std::string &token) {
  auto it = map.find(token);
  if (it == map.end()) return nullptr;
  return it->second;
}

const std::unordered_set<std::string>& PrefixOp::GetTokens() {
  return tokens;
}

}
}