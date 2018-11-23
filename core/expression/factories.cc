#include "core/expression/factories.h"
#include "core/expression/parser.h"
#include "core/expression/bin_expr_tree/binary_tree_parser.h"
#include "core/expression/bin_expr_tree/nodes/tagger.h"
#include "core/expression/bin_expr_tree/nodes/simple_tagger.h"

namespace calc {
namespace expr {

Parser* CreateBinaryTreeParser() {
  calc::expr::Tagger * tagger = new SimpleTagger();

}

}
}