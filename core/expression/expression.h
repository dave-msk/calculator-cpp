#ifndef CALCULATOR_CORE_EXPRESSION_EXPRESSION_H_
#define CALCULATOR_CORE_EXPRESSION_EXPRESSION_H_

namespace calc {
namespace expr {

class Expression {
 public:
  virtual ~Expression() = default;
  virtual double GetValue() const = 0;
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_EXPRESSION_H_
