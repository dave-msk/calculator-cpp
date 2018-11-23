#ifndef CALCULATOR_CORE_TOKENS_FACTORIES_H
#define CALCULATOR_CORE_TOKENS_FACTORIES_H

#include <string>
#include <unordered_set>
#include "core/tokens/tokenizer.h"

namespace calc {
namespace tokens {

Tokenizer* CreateGraphTokenizer(const std::string &num_config,
                                const std::string &sym_config);
Tokenizer* CreateGraphTokenizer(const std::string &num_config,
                                const std::unordered_set<std::string> &tokens);

}
}


#endif  // CALCULATOR_CORE_TOKENS_FACTORIES_H
