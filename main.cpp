#include <iostream>
#include <string>
#include "core/tokens/matcher.h"
#include "core/tokens/graph_matcher.h"

int main() {
  std::string test_nums{"23.96.73"};
  std::string filename{"./numbers.yaml"};
  auto *matcher = new calculator::tokens::GraphMatcher;
  auto num_graph = calculator::tokens::CreateNumberGraph(filename);
  matcher->UseGraph(num_graph);

  for (const char &c : test_nums) {
    if (!matcher->TryStep(c)) {
      std::cout << matcher->GetToken() << std::endl;
      matcher->Reset();
      if (!matcher->TryStep(c))
        return -1;
    }
  }

  if (!matcher->IsEmpty())
    std::cout << matcher->GetToken() << std::endl;

  return 0;
}