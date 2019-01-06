#ifndef CALCULATOR_CORE_TOKENS_FSM_MATCHER_H
#define CALCULATOR_CORE_TOKENS_FSM_MATCHER_H

#include <memory>
#include <sstream>
#include <string>
#include <unordered_set>
#include "core/tokens/exceptions.h"
#include "core/tokens/matcher.h"
#include "third_party/fsm/fsm.h"


namespace calc {
namespace tokens {

class GraphMatcher : public TokenMatcher {
 public:
//  void BindGraph(fsm::Graph<size_t, char> *graph);
//  void UnbindGraph();
//  bool IsBoundToGraph() const;
  explicit GraphMatcher(const std::string &num_config,
                        const std::unordered_set<std::string> &tokens);
  explicit GraphMatcher(const std::string &num_config,
                        const std::string &sym_config);
  ~GraphMatcher();
  bool TryStep(const char &c) final;
  bool IsEmpty() const final;
  void Reset() final;
  std::string GetToken() const final;
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
//  fsm::Graph<size_t, char> *graph_ = nullptr;
//  void ValidateGraph() const;
};

}  // namespace tokens
}  // namespace calc


#endif  // CALCULATOR_CORE_TOKENS_FSM_MATCHER_H
