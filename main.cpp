#include <iostream>
#include <string>
#include "core/tokens/number_matcher.h"

int main() {
  std::string test_nums{"23.96.73"};
  std::string filename{"./numbers.yaml"};
  calculator::tokens::NumberMatcher parser =
      calculator::tokens::NumberMatcher::LoadFromConfig(filename);
  for (const char &c : test_nums) {
    if (!parser.TryStep(c)) {
      std::cout << parser.GetToken() << std::endl;
      parser.Reset();
      if (!parser.TryStep(c))
        return -1;
    }
  }

  if (!parser.IsEmpty())
    std::cout << parser.GetToken() << std::endl;
  return 0;
}