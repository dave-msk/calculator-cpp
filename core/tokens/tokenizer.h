#ifndef CALCULATOR_CORE_TOKENS_TOKENIZER_H_
#define CALCULATOR_CORE_TOKENS_TOKENIZER_H_
#include <string>
#include <vector>

namespace calc {
namespace tokens {

class Tokenizer {
 public:
  virtual std::vector<std::string> Tokenize(const std::string &raw_expr) = 0;
};

}  // namespace tokens
}  // namespace calc

#endif  // CALCULATOR_CORE_TOKENS_TOKENIZER_H_
