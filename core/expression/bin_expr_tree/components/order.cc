#include <memory>
#include "core/expression/bin_expr_tree/components/associativity.h"
#include "core/expression/bin_expr_tree/components/order.h"
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

struct Order::Impl {
  int value;
  Associativity asso;

  explicit Impl(const Precedence &pred)
  : value(static_cast<int>(pred)), asso(Associativity::LEFT){
    switch (value) {
      case static_cast<int>(Precedence::ONE):
      case static_cast<int>(Precedence::FOUR):
      case static_cast<int>(Precedence::FIVE):
        asso = Associativity::RIGHT;
    }
  }
};

bool Order::IsLeft() const {
  return impl_->asso == Associativity::LEFT;
}

Order::Order(const Precedence &pred)
    : impl_(std::move(std::make_unique<Impl>(pred))) {};

Order::Order(const Order &order)
    : impl_(std::move(std::make_unique<Impl>(*order.impl_))) {};

Order::Order(Order &&order) noexcept = default;

Order::~Order() = default;

bool operator==(const Order &l, const Order &r) {
  return l.impl_-> value == r.impl_->value;
}

bool operator!=(const Order &l, const Order &r) {
  return l.impl_-> value != r.impl_->value;
}

bool operator<(const Order &l, const Order &r) {
  return l.impl_->value < r.impl_->value;
}

bool operator<=(const Order &l, const Order &r) {
  return l.impl_->value <= r.impl_->value;
}

bool operator>(const Order &l, const Order &r) {
  return l.impl_->value > r.impl_->value;
}

bool operator>=(const Order &l, const Order &r) {
  return l.impl_->value >= r.impl_->value;
}

}
}