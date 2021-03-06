#ifndef CALCULATOR_CORE_TOKENS_MATCHER_H_
#define CALCULATOR_CORE_TOKENS_MATCHER_H_
#include <string>


namespace calc {

namespace tokens {

class TokenMatcher {
 public:
  virtual bool TryStep(const char &c) = 0;
  virtual bool IsEmpty() const = 0;
  virtual void Reset() = 0;
  virtual std::string GetToken() const = 0;
};

}  // namespace tokens
}  // namespace calc

#endif  // CALCULATOR_CORE_TOKENS_MATCHER_H_
