#include "core/expression/bin_expr_tree/nodes/factories.h"
#include "core/expression/bin_expr_tree/nodes/function/function.h"
#include "core/expression/bin_expr_tree/nodes/function/function_node.h"
#include "core/expression/bin_expr_tree/nodes/node.h"

namespace calc {
namespace expr {

Node* CreateFunctionNode(const std::string &token) {
  const Function *func = Function::Get(token);
  if (func == nullptr) return nullptr;
  return new FunctionNode(func->func);
}

}
}