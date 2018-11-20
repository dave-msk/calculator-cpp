#ifndef CALCULATOR_CORE_EXPRESSION_NODES_NUMBER_H_
#define CALCULATOR_CORE_EXPRESSION_NODES_NUMBER_H_
#include <limits>
#include "core/expression/nodes/node.h"
#include "core/expression/nodes/type.h"

namespace calc {
namespace expr {

class Number : public Node {
 public:
  explicit Number(const double &value)
      : Node(Type::NUMBER, std::numeric_limits<unsigned char>::max()),
        value(value) {};

  double GetValue() const final;

 private:
  const double value;
};

}
}

#endif  // CALCULATOR_CORE_EXPRESSION_NODES_NUMBER_H_
