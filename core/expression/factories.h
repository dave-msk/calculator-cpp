#ifndef CALCULATOR_CORE_EXPRESSION_FACTORIES_H_
#define CALCULATOR_CORE_EXPRESSION_FACTORIES_H_

#include <memory>
#include "core/expression/parser.h"
#include "core/expression/bin_expr_tree/binary_tree_parser.h"

namespace calc {
namespace expr {

// TODO: Use abstract factory pattern
std::unique_ptr<Parser> CreateBinaryTreeParser();

}
}


#endif  // CALCULATOR_CORE_EXPRESSION_FACTORIES_H_
