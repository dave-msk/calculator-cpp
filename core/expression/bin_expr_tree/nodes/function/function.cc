#include <cmath>
#include <string>
#include <unordered_set>
#include "core/expression/bin_expr_tree/nodes/node.h"
#include "core/expression/bin_expr_tree/nodes/function/function.h"
#include "core/expression/bin_expr_tree/nodes/function/function_node.h"

namespace calc {
namespace expr {

const Function Function::SIN = Function(
    "sin", [](double v) { return std::sin(v); });
const Function Function::COS = Function(
    "cos", [](double v) { return std::cos(v); });
const Function Function::TAN = Function(
    "tan", [](double v) { return std::tan(v); });
const Function Function::SINH = Function(
    "sinh", [](double v) { return std::sinh(v); });
const Function Function::COSH = Function(
    "cosh", [](double v) { return std::cosh(v); });
const Function Function::TANH = Function(
    "tanh", [](double v) { return std::tanh(v); });
const Function Function::LOG = Function(
    "log", [](double v) { return std::log(v); });

bool Function::HasToken(const std::string &token) {
  return map.find(token) != map.end();
}

const Function* Function::Get(const std::string &token) {
  auto it = map.find(token);
  if (it != map.end()) return it->second;
  return nullptr;
}

const std::unordered_set<std::string>& Function::GetTokens() {
  return tokens;
}

Function::Function(const std::string &token,
                   Function::UnaryFunction func) : func(func) {
  map[token] = this;
  tokens.insert(token);
}

}
}
