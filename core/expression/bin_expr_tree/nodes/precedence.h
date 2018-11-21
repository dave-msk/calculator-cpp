#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_PRECEDENCE_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_PRECEDENCE_H_

namespace calc {
namespace expr {

class Precedence {
 public:
  static const Precedence ONE;
  static const Precedence TWO;
  static const Precedence THREE;
  static const Precedence FOUR;
  static const Precedence FIVE;
  static const Precedence SIX;
  static const Precedence MAX;

  const unsigned char value;
  const bool left_associate;

  friend bool operator<(const Precedence &l, const Precedence &r);
  friend bool operator>(const Precedence &l, const Precedence &r);
  friend bool operator<=(const Precedence &l, const Precedence &r);
  friend bool operator>=(const Precedence &l, const Precedence &r);
  friend bool operator==(const Precedence &l, const Precedence &r);
  friend bool operator!=(const Precedence &l, const Precedence &r);

 private:
  explicit Precedence(unsigned char value, bool left_associate);
};

}
}


#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_PRECEDENCE_H_
