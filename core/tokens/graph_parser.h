#ifndef CALCULATOR_CORE_TOKENS_GRAPH_PARSER_H
#define CALCULATOR_CORE_TOKENS_GRAPH_PARSER_H
#include "core/tokens/graph_matcher.h"
#include "core/tokens/parser.h"
#include "third_party/fsm/fsm.h"

namespace calc {
namespace tokens {

class GraphParser : public TokenParser {
 private:
  fsm::Graph<size_t, char> *num_graph_;
  fsm::Graph<size_t, char> *sym_graph_;
  GraphMatcher matcher;
  void BindGraph(const char &c);
 public:
  GraphParser(const std::string &num_config,
              const std::string &sym_config);
  ~GraphParser();
  std::vector<std::string> parse(const std::string &raw_expr) final;
};

}
}

#endif  // CALCULATOR_CORE_TOKENS_GRAPH_PARSER_H
