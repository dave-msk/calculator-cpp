#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
//#include "core/expression/bin_expr_tree/utils.h"
#include "core/tokens/factories.h"
#include "core/tokens/fsm_graph/graph_tokenizer.h"
#include "core/tokens/matcher.h"
#include "core/tokens/fsm_graph/graph_matcher.h"

int main() {
  std::string num_config{"./numbers.yaml"};
//  std::string sym_config{"./vocabulary.txt"};
  std::string test_expr{"23.96 * (5.0 - 4.78) / -3.61"};
//  std::unordered_set<std::string> all_tokens = calc::expr::GetAllTokens();
//  for (const std::string &s : all_tokens) std::cout << s << std::endl;
//  calc::tokens::Tokenizer *tokenizer =
//      calc::tokens::CreateGraphTokenizer(num_config, all_tokens);
//  std::vector<std::string> tokens = tokenizer->Tokenize(test_expr);
//  for (const std::string &s : tokens)
//    std::cout << s << std::endl;
  return 0;
}