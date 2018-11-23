#ifndef CALCULATOR_CORE_TOKENS_GRAPH_PARSER_H_
#define CALCULATOR_CORE_TOKENS_GRAPH_PARSER_H_
#include <string>
#include <unordered_set>
#include <vector>
#include "graph_matcher.h"
#include "core/tokens/tokenizer.h"
#include "third_party/fsm/fsm.h"

namespace calc {
namespace tokens {

class GraphTokenizer : public Tokenizer {
 private:
  fsm::Graph<size_t, char> *num_graph_;
  fsm::Graph<size_t, char> *sym_graph_;
  GraphMatcher matcher;
  void BindGraph(const char &c);
 public:
  GraphTokenizer(fsm::Graph<size_t, char> *num_graph_,
                 fsm::Graph<size_t, char> *sym_graph);
  ~GraphTokenizer();
  std::vector<std::string> Tokenize(const std::string &raw_expr) final;
};

}
}

#endif  // CALCULATOR_CORE_TOKENS_GRAPH_PARSER_H_
