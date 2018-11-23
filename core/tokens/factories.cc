#include <fstream>
#include <unordered_map>
#include "core/tokens/factories.h"
#include "core/tokens/fsm_graph/graph_tokenizer.h"
#include "third_party/fsm/fsm.h"
#include "yaml-cpp/yaml.h"

namespace calc {
namespace tokens {

static fsm::Graph<size_t, char>* CreateNumberGraph(const std::string &filename);
static fsm::Graph<size_t, char>* CreateSymbolGraph(const std::string &filename);
static fsm::Graph<size_t, char>* CreateSymbolGraph(
    const std::unordered_set<std::string> &tokens);

Tokenizer* CreateGraphTokenizer(const std::string &num_config,
                                const std::string &sym_config) {
  auto num_graph = CreateNumberGraph(num_config);
  auto sym_graph = CreateSymbolGraph(sym_config);
  return new GraphTokenizer(num_graph, sym_graph);
}

Tokenizer* CreateGraphTokenizer(const std::string &num_config,
                                const std::unordered_set<std::string> &tokens) {
  auto num_graph = CreateNumberGraph(num_config);
  auto sym_graph = CreateSymbolGraph(tokens);
  return new GraphTokenizer(num_graph, sym_graph);
}

std::vector<std::string> GraphTokenizer::Tokenize(const std::string &raw_expr) {
  std::vector<std::string> tokens;

  // Parse char by char
  for (const char &c : raw_expr) {
    if (matcher.IsBoundToGraph()) {
      if (matcher.TryStep(c)) continue;
      tokens.push_back(matcher.GetToken());
      matcher.Reset();
      matcher.UnbindGraph();
    }
    BindGraph(c);
    if (!matcher.TryStep(c)) {
      std::stringstream ss;
      ss << "Invalid head character: " << c;
      throw InvalidHeadCharacterException(ss.str());
    }
  }

  if (!matcher.IsEmpty()) {
    tokens.push_back(matcher.GetToken());
    matcher.Reset();
    matcher.UnbindGraph();
  }

  return tokens;
}



fsm::Graph<size_t, char>* CreateNumberGraph(const std::string &filename) {
  YAML::Node config = YAML::LoadFile(filename);
  std::unordered_map<std::string, size_t> map;

  // Construct root edges
  const YAML::Node &root_node = config["root"];
  map["root"] = 0;
  auto graph = new fsm::Graph<size_t, char>(0);
  for (auto it = root_node.begin(); it != root_node.end(); ++it) {
    const std::string &target = it->first.as<std::string>();
    const size_t id = map[target] = map.size();
    const std::string &ops = it->second.as<std::string>();
    for (const char &c : ops) graph->AddEdge(c, 0, id);
  }

  // Construct state edges
  const YAML::Node &states = config["states"];
  for (auto s_it = states.begin(); s_it != states.end(); ++s_it) {
    const std::string &src = s_it->first.as<std::string>();
    if (map.find(src) == map.end()) map[src] = map.size();
    const size_t s_id = map[src];

    const YAML::Node &s_node = s_it->second;
    if (s_node["terminal"].as<bool>()) graph->SetTerminal(s_id);

    const YAML::Node &txns = s_node["transitions"];
    for (auto it = txns.begin(); it != txns.end(); ++it) {
      const std::string &target = it->first.as<std::string>();
      if (map.find(target) == map.end()) map[target] = map.size();
      const size_t t_id = map[target];

      const std::string &ops = it->second.as<std::string>();
      for (const char &c : ops) graph->AddEdge(c, s_id, t_id);
    }
  }
  graph->Finalize();
  return graph;
}

fsm::Graph<size_t, char>* CreateSymbolGraph(const std::string &filename) {
  std::unordered_set<std::string> tokens{};
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line)) tokens.insert(line);
  return CreateSymbolGraph(tokens);
}

fsm::Graph<size_t, char>* CreateSymbolGraph(
    const std::unordered_set<std::string> &tokens) {
  auto *graph = new fsm::Graph<size_t, char>(0);
  size_t next_id = 1;

  for (const std::string &token : tokens) {
    for (const char &c : token) {
      if (!graph->HasStep(c)) graph->AddEdge(c, next_id++);
      graph->Step(c);
    }
    graph->SetTerminal();
    graph->Reset();
  }

  const char ws = ' ';
  if (!graph->HasStep(ws)) {
    graph->AddEdge(ws, next_id);
    graph->SetTerminal(next_id);
    graph->Reset();
  }
  graph->Finalize();
  return graph;
}


}
}
