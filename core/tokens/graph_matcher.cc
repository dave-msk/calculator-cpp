#include <fstream>
#include <unordered_map>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "core/tokens/graph_matcher.h"


namespace calc {
namespace tokens {


void GraphMatcher::ValidateGraph() const {
  if (graph_ == nullptr)
    throw GraphNotFoundException("Graph not found. Set graph by \"BindGraph\" "
                                 "before use.");
  if (!graph_->IsFinalized())
    throw GraphNotFinalizedException("Graph must be finalized before use.");
}

void GraphMatcher::BindGraph(fsm::Graph<size_t, char> *graph) {
  graph_ = graph;
}

void GraphMatcher::UnbindGraph() {
  graph_ = nullptr;
}

bool GraphMatcher::IsBoundToGraph() const {
  return graph_ != nullptr;
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


}  // namespace tokens
}  // namespace calc