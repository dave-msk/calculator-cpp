#ifndef CALCULATOR_CORE_EXPRESSION_PARSER_H_
#define CALCULATOR_CORE_EXPRESSION_PARSER_H_
#include <memory>
#include <string>
#include <vector>
#include "core/expression/expression.h"

namespace calc {
namespace expr {

class Parser {
 public:
  virtual ~Parser() = default;
  virtual std::shared_ptr<Expression>
  Parse(const std::vector<std::string> &tokens) = 0;
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_PARSER_H_
