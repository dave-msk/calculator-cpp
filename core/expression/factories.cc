#include <memory>
#include "core/expression/factories.h"
#include "core/expression/parser.h"
#include "core/expression/bin_expr_tree/binary_tree_parser.h"
#include "core/expression/bin_expr_tree/components/taggers/tagger.h"
#include "core/expression/bin_expr_tree/components/taggers/simple_tagger.h"

namespace calc {
namespace expr {

std::unique_ptr<Parser> CreateBinaryTreeParser() {
  // TODO: Decouple tagger
  auto tagger = std::make_unique<SimpleTagger>();
  return std::make_unique<BinaryTreeParser>(std::move(tagger));
}

}
}