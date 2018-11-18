#ifndef CALCULATOR_CORE_TOKENS_PARSER_H
#define CALCULATOR_CORE_TOKENS_PARSER_H
#include <string>
#include <vector>

namespace calculator {
namespace tokens {

class TokenParser {
 public:
  virtual std::vector<std::string> parse(const std::string &raw_expr) = 0;
};

}
}

#endif //CALCULATOR_CORE_TOKENS_PARSER_H
