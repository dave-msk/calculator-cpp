#include "core/expression/factories.h"
#include "core/expression/parser.h"
#include "core/expression/bin_expr_tree/binary_tree_parser.h"
#include "core/expression/bin_expr_tree/components/taggers/tagger.h"
#include "core/expression/bin_expr_tree/components/taggers/simple_tagger.h"

namespace calc {
namespace expr {

Parser* CreateBinaryTreeParser() {
  // TODO: Decouple tagger
  Tagger *tagger = new SimpleTagger();
  return new BinaryTreeParser(tagger);
}

}
}