#ifndef CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_ORDER_H_
#define CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_ORDER_H_

#include <memory>
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

class Order {
 public:
  bool IsLeft() const;

  explicit Order(const Precedence&);
  Order(const Order&);
  Order(Order&&) noexcept;
  virtual ~Order();

  friend bool operator==(const Order&, const Order&);
  friend bool operator!=(const Order&, const Order&);
  friend bool operator<(const Order&, const Order&);
  friend bool operator<=(const Order&, const Order&);
  friend bool operator>(const Order&, const Order&);
  friend bool operator>=(const Order&, const Order&);

 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;

};

}
}


#endif  // CALCULATOR_CORE_EXPRESSION_BIN_EXPR_TREE_COMPONENTS_ORDER_H_
