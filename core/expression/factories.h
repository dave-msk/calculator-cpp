#ifndef CALCULATOR_CORE_EXPRESSION_FACTORIES_H_
#define CALCULATOR_CORE_EXPRESSION_FACTORIES_H_

#include "core/expression/parser.h"
#include "core/expression/bin_expr_tree/binary_tree_parser.h"

namespace calc {
namespace expr {

Parser* CreateBinaryTreeParser();


}
}


#endif  // CALCULATOR_CORE_EXPRESSION_FACTORIES_H_
