#include <limits>
#include "core/expression/bin_expr_tree/components/precedence.h"

namespace calc {
namespace expr {

const Precedence& Precedence::ONE() {
  static auto *ONE = new Precedence(static_cast<unsigned char>(1), false);
  return *ONE;
}

const Precedence& Precedence::TWO(){
 static auto *TWO = new Precedence(static_cast<unsigned char>(2), true);
 return *TWO;
}

const Precedence& Precedence::THREE() {
  static auto THREE = new Precedence(static_cast<unsigned char>(3), true);
  return *THREE;
}

const Precedence& Precedence::FOUR() {
  static auto FOUR = new Precedence(static_cast<unsigned char>(4), false);
  return *FOUR;
}

const Precedence& Precedence::FIVE() {
  static auto FIVE = new Precedence(static_cast<unsigned char>(5), false);
  return *FIVE;
}

const Precedence& Precedence::SIX() {
  static auto SIX = new Precedence(static_cast<unsigned char>(6), true);
  return *SIX;
}

const Precedence& Precedence::MAX() {
  static auto MAX = new Precedence(
      std::numeric_limits<unsigned char>::max(), true);
  return *MAX;
}

Precedence::Precedence(unsigned char value, bool left_associate)
    : value(value), left_associate(left_associate) {};

bool operator<(const Precedence &l, const Precedence &r) {
  return l.value < r.value;
}

bool operator>(const Precedence &l, const Precedence &r) {
  return l.value > r.value;
}

bool operator<=(const Precedence &l, const Precedence &r) {
  return l < r || l == r;
}

bool operator>=(const Precedence &l, const Precedence &r) {
  return l > r || l == r;
}

bool operator==(const Precedence &l, const Precedence &r) {
  return l.value == r.value && l.left_associate == r.left_associate;
}

bool operator!=(const Precedence &l, const Precedence &r) {
  return !(l == r);
}

}
}