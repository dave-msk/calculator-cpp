#include <cctype>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include "core/tokens/exceptions.h"
#include "graph_tokenizer.h"
#include "graph_matcher.h"
#include "third_party/fsm/fsm.h"
#include "yaml-cpp/yaml.h"

namespace calc {
namespace tokens {

void GraphTokenizer::BindGraph(const char &c) {
  if (matcher.IsBoundToGraph()) return;
  if (c == '.' or std::isdigit(c)) matcher.BindGraph(num_graph_);
  else matcher.BindGraph(sym_graph_);
}

GraphTokenizer::GraphTokenizer(fsm::Graph<size_t, char> *num_graph_,
                               fsm::Graph<size_t, char> *sym_graph)
                               : num_graph_(num_graph_), sym_graph_(sym_graph){}

GraphTokenizer::~GraphTokenizer() {
  delete num_graph_;
  delete sym_graph_;
}

}
}
