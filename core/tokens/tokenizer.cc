#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "core/tokens/exceptions.h"
#include "core/tokens/matcher.h"
#include "core/tokens/tokenizer.h"

namespace calc {
namespace tokens {

struct Tokenizer::Impl {
  explicit Impl(std::unique_ptr<TokenMatcher> matcher)
      : matcher(std::move(matcher)) {};
  std::unique_ptr<TokenMatcher> matcher;
};

Tokenizer::Tokenizer(std::unique_ptr<TokenMatcher> matcher)
    : impl_(std::make_unique<Impl>(std::move(matcher))) {};

Tokenizer::~Tokenizer() = default;

std::vector<std::string> Tokenizer::Tokenize(const std::string &raw_expr) {
  std::vector<std::string> tokens;

  // Parse char by char
  for (const char &c : raw_expr) {
    if (impl_->matcher->TryStep(c)) continue;
    tokens.push_back(impl_->matcher->GetToken());
    impl_->matcher->Reset();
    if (!impl_->matcher->TryStep(c)) {
      std::stringstream ss;
      ss << "Invalid head character: " << c;
      throw InvalidHeadCharacterException(ss.str());
    }
  }

  if (!impl_->matcher->IsEmpty()) {
    tokens.push_back(impl_->matcher->GetToken());
    impl_->matcher->Reset();
  }
  return tokens;
}

}
}
