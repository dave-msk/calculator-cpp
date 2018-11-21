#include <limits>
#include "precedence.h"

namespace calc {
namespace expr {

const Precedence Precedence::ONE = Precedence(1, false);
const Precedence Precedence::TWO = Precedence(2, true);
const Precedence Precedence::THREE = Precedence(3, true);
const Precedence Precedence::FOUR = Precedence(4, false);
const Precedence Precedence::FIVE = Precedence(5, false);
const Precedence Precedence::SIX = Precedence(6, true);
const Precedence Precedence::MAX = Precedence(1, true);

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