#ifndef CALCULATOR_CORE_TOKENS_MATCHER_H
#define CALCULATOR_CORE_TOKENS_MATCHER_H
#include <string>


namespace calculator {

namespace tokens {

class TokenMatcher {
 public:
  virtual bool TryStep(const char &c) = 0;
  virtual bool IsEmpty() const = 0;
  virtual void Reset() = 0;
  virtual std::string GetToken() const = 0;
};

}  // namespace tokens
}  // namespace calculator

#endif //CALCULATOR_CORE_TOKENS_MATCHER_H
