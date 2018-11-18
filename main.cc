#include <iostream>
#include <string>
#include <vector>
#include "core/tokens/graph_parser.h"
#include "core/tokens/matcher.h"
#include "core/tokens/graph_matcher.h"

int main() {
  std::string num_config{"./numbers.yaml"};
  std::string sym_config{"./vocabulary.txt"};
  std::string test_expr{"23.96 * (5.0 - 4.78) / -3.61"};
  auto parser = calculator::tokens::GraphParser(num_config, sym_config);
  std::vector<std::string> tokens = parser.parse(test_expr);
  std::stringstream ss;
  for (size_t i = 0; i < tokens.size(); ++i) {
    if (i > 0) ss << ", ";
    ss << '"' << tokens[i] << '"';
  }
  std::cout << ss.str() << std::endl;

  return 0;
}