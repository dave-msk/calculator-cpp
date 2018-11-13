#ifndef CALCULATOR_CORE_TOKENS_EXCEPTIONS_H
#define CALCULATOR_CORE_TOKENS_EXCEPTIONS_H
#include <exception>
#include <string>

namespace calculator {

namespace tokens {

struct Exception : std::exception {
 private:
  std::string message_;
 public:
  explicit Exception(const std::string &message)
      : message_(message) {};

  const char *what() const noexcept override {
    return message_.c_str();
  }
};

struct InvalidTokenException : Exception {
  using Exception::Exception;
};

struct NoCharMatchException : Exception {
  using Exception::Exception;
};

}
}

#endif  // CALCULATOR_CORE_TOKENS_EXCEPTIONS_H
