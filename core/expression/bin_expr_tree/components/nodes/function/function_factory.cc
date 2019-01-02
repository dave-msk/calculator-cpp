#include <memory>
#include "core/expression/bin_expr_tree/components/nodes/factories.h"
#include "core/expression/bin_expr_tree/components/nodes/function/function.h"
#include "core/expression/bin_expr_tree/components/nodes/function/function_node.h"
#include "core/expression/bin_expr_tree/components/nodes/node.h"

namespace calc {
namespace expr {

std::shared_ptr<Node> CreateFunctionNode(const std::string &token) {
  const Function *func = Function::Get(token);
  if (func == nullptr) return nullptr;
  return std::make_shared<FunctionNode>(func->func);
}

}
}