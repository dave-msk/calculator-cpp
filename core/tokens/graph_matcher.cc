#include <fstream>
#include <unordered_map>
#include "yaml-cpp/yaml.h"
#include "core/tokens/graph_matcher.h"


namespace calculator {
namespace tokens {


void GraphMatcher::ValidateGraph() const {
  if (graph_ == nullptr)
    throw GraphNotFoundException("Graph not found. Set graph by \"UseGraph\" "
                                 "before use.");
  if (!graph_->IsFinalized())
    throw GraphNotFinalizedException("Graph must be finalized before use.");
}

void GraphMatcher::UseGraph(fsm::Graph<size_t, char> *graph) {
  graph_ = graph;
}

bool GraphMatcher::TryStep(const char &c) {
  ValidateGraph();
  if (!graph_->HasStep(c)) return false;
  graph_->Step(c);
  return true;
}

bool GraphMatcher::IsEmpty() const {
  ValidateGraph();
  return graph_->IsAtRoot();
}

void GraphMatcher::Reset() {
  ValidateGraph();
  return graph_->Reset();
}

std::string GraphMatcher::GetToken() const {
  ValidateGraph();
  std::vector<char> trace = graph_->GetOpTrace();
  std::string s{trace.begin(), trace.end()};
  if (graph_->IsAtTerminal()) return s;

  std::stringstream ss;
  ss << "Invalid token: " << s;
  throw InvalidTokenException(ss.str());
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
  auto *graph = new fsm::Graph<size_t, char>(0);
  size_t next_id = 1;

  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line)) {
    for (const char &c : line) {
      if (!graph->HasStep(c)) graph->AddEdge(c, next_id++);
      graph->Step(c);
    }
    graph->SetTerminal();
    graph->Reset();
  }
  const char ws = ' ';
  if (!graph->HasStep(ws)) graph->AddEdge(ws, next_id);
  graph->Finalize();
  return graph;
}

}  // namespace tokens
}  // namespace calculator