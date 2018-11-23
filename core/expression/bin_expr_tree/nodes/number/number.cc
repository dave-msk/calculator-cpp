#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <unordered_set>
#include "core/expression/bin_expr_tree/nodes/number/number.h"
#include "core/expression/bin_expr_tree/nodes/number/number_node.h"
#include "core/expression/bin_expr_tree/nodes/node.h"

namespace calc {
namespace expr {

const Number Number::PI = Number("pi", M_PI);
const Number Number::E = Number("e", M_E);

bool Number::HasToken(const std::string &token) {
  try {
    std::stod(token);
    return true;
  } catch (std::invalid_argument&) {}
  return map.find(token) != map.end();
}

const Number* Number::Get(const std::string &token) {
  auto it = map.find(token);
  if (it == map.end()) return nullptr;
  return it->second;
}

const std::unordered_set<std::string>& Number::GetTokens() {
  return tokens;
}

Number::Number(const std::string &token, double value)
    : token(token), value(value){
  map[token] = this;
  tokens.insert(token);
}

}
}