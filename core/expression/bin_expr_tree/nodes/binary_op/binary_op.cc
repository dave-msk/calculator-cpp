#include <cmath>
#include <string>
#include <unordered_set>
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/binary_op/binary_op.h"
#include "core/expression/bin_expr_tree/nodes/precedence.h"

namespace calc {
namespace expr {

const BinaryOp BinaryOp::ADD = BinaryOp(
    "+", Precedence::TWO, [](auto l, auto r) { return l + r; });
const BinaryOp BinaryOp::MINUS = BinaryOp(
    "-", Precedence::TWO, [](auto l, auto r) { return l - r; });
const BinaryOp BinaryOp::MULTIPLY = BinaryOp(
    "*", Precedence::THREE, [](auto l, auto r) { return l * r; });
const BinaryOp BinaryOp::DIVIDE = BinaryOp(
    "/", Precedence::THREE, [](auto l, auto r) { return l / r; });
const BinaryOp BinaryOp::MODULO = BinaryOp(
    "%", Precedence::THREE, [](auto l, auto r) { return std::fmod(l, r); });
const BinaryOp BinaryOp::POWER = BinaryOp(
    "**", Precedence::FIVE, [](auto l, auto r) { return std::pow(l, r); });

bool BinaryOp::HasToken(const std::string &token) {
  return map.find(token) != map.end();
}

const BinaryOp* BinaryOp::Get(const std::string &token) {
  auto it = map.find(token);
  if (it != map.end()) return it->second;
  return nullptr;
}

const std::unordered_set<std::string>& BinaryOp::GetTokens() {
   return tokens;
}

BinaryOp::BinaryOp(const std::string &token,
                   const calc::expr::Precedence &precedence,
                   const BinaryOp::BinaryFunction &bin_func)
                   : token(token), precedence(precedence), bin_func(bin_func) {
  map[token] = this;
  tokens.insert(token);
};

}
}