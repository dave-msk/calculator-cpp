#include <cctype>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "graph_matcher.h"
#include "third_party/fsm/fsm.h"


namespace calc {
namespace tokens {

static std::unique_ptr<fsm::Graph<size_t, char>>
    CreateNumberGraph(const std::string &filename);
static std::unique_ptr<fsm::Graph<size_t, char>>
    CreateSymbolGraph(const std::unordered_set<std::string> &tokens);
static std::unique_ptr<fsm::Graph<size_t, char>>
    CreateSymbolGraph(const std::string &filename);


struct GraphMatcher::Impl {

  explicit Impl(std::unique_ptr<fsm::Graph<size_t, char>> num_graph,
                std::unique_ptr<fsm::Graph<size_t, char>> sym_graph)
      : active_graph_(),
        num_graph_(std::move(num_graph)),
        sym_graph_(std::move(sym_graph)) {};

  std::shared_ptr<fsm::Graph<size_t, char>> active_graph_;
  std::shared_ptr<fsm::Graph<size_t, char>> num_graph_;
  std::shared_ptr<fsm::Graph<size_t, char>> sym_graph_;
};

GraphMatcher::GraphMatcher(const std::string &num_config,
                           const std::unordered_set<std::string> &tokens)
    : impl_(std::make_unique<Impl>(CreateNumberGraph(num_config),
                                   CreateSymbolGraph(tokens))) {};

GraphMatcher::GraphMatcher(const std::string &num_config,
                           const std::string &sym_config)
    : impl_(std::make_unique<Impl>(CreateNumberGraph(num_config),
                                   CreateSymbolGraph(sym_config))) {};


GraphMatcher::~GraphMatcher() = default;

bool GraphMatcher::TryStep(const char &c) {
//  ValidateGraph();
  // Select active graph if not set.
  if (!impl_->active_graph_) {
    if (c == '.' or std::isdigit(c))
      impl_->active_graph_ = impl_->num_graph_;
    else
      impl_->active_graph_ = impl_->sym_graph_;
  }
  if (!impl_->active_graph_->HasStep(c)) return false;
  impl_->active_graph_->Step(c);
  return true;
}


//void GraphMatcher::ValidateGraph() const {
//  if (graph_ == nullptr)
//    throw GraphNotFoundException("Graph not found. Set graph by \"BindGraph\" "
//                                 "before use.");
//  if (!graph_->IsFinalized())
//    throw GraphNotFinalizedException("Graph must be finalized before use.");
//}

//void GraphMatcher::BindGraph(fsm::Graph<size_t, char> *graph) {
//  graph_ = graph;
//}
//
//void GraphMatcher::UnbindGraph() {
//  graph_ = nullptr;
//}

//bool GraphMatcher::IsBoundToGraph() const {
//  return graph_ != nullptr;
//}

bool GraphMatcher::IsEmpty() const {
//  ValidateGraph();
  if (impl_->active_graph_) return impl_->active_graph_->IsAtRoot();
  return true;
}

void GraphMatcher::Reset() {
//  ValidateGraph();
  if (impl_->active_graph_) {
    impl_->active_graph_->Reset();
    impl_->active_graph_.reset();
  }
//  return graph_->Reset();
}

std::string GraphMatcher::GetToken() const {
//  ValidateGraph();
  if (!impl_->active_graph_) return "";
  std::vector<char> trace = impl_->active_graph_->GetOpTrace();
  std::string s{trace.begin(), trace.end()};
  if (impl_->active_graph_->IsAtTerminal()) return s;

  std::stringstream ss;
  ss << "Invalid token: " << s;
  throw InvalidTokenException(ss.str());
}


std::unique_ptr<fsm::Graph<size_t, char>>
    CreateNumberGraph(const std::string &filename) {
  YAML::Node config = YAML::LoadFile(filename);
  std::unordered_map<std::string, size_t> map;

  // Construct root edges
  const YAML::Node &root_node = config["root"];
  map["root"] = 0;
  auto graph = std::make_unique<fsm::Graph<size_t, char>>(0);
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

std::unique_ptr<fsm::Graph<size_t, char>>
    CreateSymbolGraph(const std::unordered_set<std::string> &tokens) {
  auto graph = std::make_unique<fsm::Graph<size_t, char>>(0);
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

std::unique_ptr<fsm::Graph<size_t, char>>
    CreateSymbolGraph(const std::string &filename) {
  std::unordered_set<std::string> tokens{};
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line)) tokens.insert(line);
  return CreateSymbolGraph(tokens);
}


}  // namespace tokens
}  // namespace calc