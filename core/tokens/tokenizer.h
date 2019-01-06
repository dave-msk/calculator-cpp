#ifndef CALCULATOR_CORE_TOKENS_TOKENIZER_H_
#define CALCULATOR_CORE_TOKENS_TOKENIZER_H_

#include <memory>
#include <string>
#include <vector>
#include "core/tokens/matcher.h"

namespace calc {
namespace tokens {

class Tokenizer {
 public:
  explicit Tokenizer(std::unique_ptr<TokenMatcher> matcher);
  ~Tokenizer();
  std::vector<std::string> Tokenize(const std::string &raw_expr);
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace tokens
}  // namespace calc

#endif  // CALCULATOR_CORE_TOKENS_TOKENIZER_H_
