#ifndef CALCULATOR_CORE_TOKENS_FSM_MATCHER_H
#define CALCULATOR_CORE_TOKENS_FSM_MATCHER_H
#include <sstream>
#include <string>
#include "core/tokens/exceptions.h"
#include "core/tokens/matcher.h"
#include "third_party/fsm/fsm.h"


namespace calculator {
namespace tokens {

template <typename K>
class FSMMatcher : public TokenMatcher {
 private:
  fsm::Graph<K, char> graph_;
 public:
  explicit FSMMatcher(fsm::Graph<K, char> &&graph)
      : graph_(std::move(graph)) {};
  bool TryStep(const char &c) final;
  bool IsEmpty() const final;
  void Reset() final;
  std::string GetToken() const final;

};

FSMMatcher<u_char> CreateNumberMatcher(const std::string &filename);
FSMMatcher<u_char> CreateSymbolMatcher(const std::string &filename);

template <typename K>
bool FSMMatcher<K>::TryStep(const char &c) {
  return graph_.TryStep(c);
}

template <typename K>
bool FSMMatcher<K>::IsEmpty() const {
  return graph_.IsAtRoot();
}

template <typename K>
void FSMMatcher<K>::Reset() {
  return graph_.Reset();
}

template <typename K>
std::string FSMMatcher<K>::GetToken() const {
  std::vector<char> trace = graph_.GetOpTrace();
  std::string s{trace.begin(), trace.end()};
  if (graph_.IsAtTerminal()) return s;

  std::stringstream ss;
  ss << "Invalid token: " << s;
  throw InvalidTokenException(ss.str());
}

}  // namespace tokens
}  // namespace calculator


#endif  // CALCULATOR_CORE_TOKENS_FSM_MATCHER_H
