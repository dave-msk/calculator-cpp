#ifndef CALCULATOR_CORE_TOKENS_FSM_MATCHER_H
#define CALCULATOR_CORE_TOKENS_FSM_MATCHER_H
#include <sstream>
#include <string>
#include "core/tokens/exceptions.h"
#include "core/tokens/matcher.h"
#include "third_party/fsm/fsm.h"


namespace calculator {
namespace tokens {

class GraphMatcher : public TokenMatcher {
 private:
  fsm::Graph<size_t, char> *graph_ = nullptr;
  void ValidateGraph() const;
 public:
  void BindGraph(fsm::Graph<size_t, char> *graph);
  void UnbindGraph();
  bool IsBoundToGraph() const;
  bool TryStep(const char &c) final;
  bool IsEmpty() const final;
  void Reset() final;
  std::string GetToken() const final;
};

}  // namespace tokens
}  // namespace calculator


#endif  // CALCULATOR_CORE_TOKENS_FSM_MATCHER_H
