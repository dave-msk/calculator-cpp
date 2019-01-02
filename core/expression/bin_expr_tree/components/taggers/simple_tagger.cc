#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>
#include "core/expression/bin_expr_tree/components/taggers/simple_tagger.h"
#include "core/expression/bin_expr_tree/components/type.h"
#include "core/expression/bin_expr_tree/components/nodes/binary_op/binary_op.h"
#include "core/expression/bin_expr_tree/components/nodes/function/function.h"
#include "core/expression/bin_expr_tree/components/nodes/number/number.h"
#include "core/expression/bin_expr_tree/components/nodes/postfix_op/postfix_op.h"
#include "core/expression/bin_expr_tree/components/nodes/prefix_op/prefix_op.h"
#include <exception>

namespace calc {
namespace expr {

static bool IsType(const std::string &token, const Type &type);
//static std::unordered_map<Type, std::vector<Type>, std::hash<int>> LoadPolicy(
//    const std::string &policy_file);

std::vector<Type> SimpleTagger::TagTokens(
    const std::vector<std::string> &tokens) const {
  std::vector<Type> types;
  Type prev_type = Type::NONE;
  for (const std::string &token : tokens) {
    auto it = type_map.find(prev_type);

    // TODO: Add TypeNotFoundException
    if (it == type_map.end())
      throw std::exception();

    Type curr_type = Type::NONE;
    const auto candidates = it->second;
    for (const Type &type : candidates) {
      if (IsType(token, type)) {
        curr_type = type;
        break;
      }
    }

    // TODO: Add InvalidSyntaxException
    if (curr_type == Type::NONE)
      throw std::exception();

    types.push_back(curr_type);
    prev_type = curr_type;
  }
  return types;
}

// TODO: Decouple policy to file
SimpleTagger::SimpleTagger() {
  type_map[Type::NONE] = {Type::NUMBER, Type::OPEN_BRACKET,
                          Type::PREFIX_OP, Type::FUNCTION};
  type_map[Type::NUMBER] = {Type::CLOSE_BRACKET, Type::BINARY_OP,
                            Type::POSTFIX_OP};
  type_map[Type::OPEN_BRACKET] = {Type::NUMBER, Type::OPEN_BRACKET,
                                  Type::PREFIX_OP, Type::FUNCTION};
  type_map[Type::CLOSE_BRACKET] = {Type::CLOSE_BRACKET, Type::BINARY_OP,
                                   Type::POSTFIX_OP};
  type_map[Type::BINARY_OP] = {Type::NUMBER, Type::OPEN_BRACKET,
                               Type::PREFIX_OP, Type::FUNCTION};
  type_map[Type::PREFIX_OP] = {Type::NUMBER, Type::OPEN_BRACKET,
                               Type::PREFIX_OP, Type::FUNCTION};
  type_map[Type::POSTFIX_OP] = {Type::CLOSE_BRACKET, Type::BINARY_OP,
                                Type::POSTFIX_OP};
  type_map[Type::FUNCTION] = {Type::OPEN_BRACKET};
}

SimpleTagger::~SimpleTagger() = default;


//SimpleTagger::SimpleTagger(const std::string &policy_file)
//    : type_map(LoadPolicy(policy_file)) {}


static bool IsType(const std::string &token, const Type &type) {
  switch (type) {
    case Type::OPEN_BRACKET:
      return token == "(";
    case Type::CLOSE_BRACKET:
      return token == ")";
    case Type::NUMBER:
      return Number::HasToken(token);
    case Type::BINARY_OP:
      return BinaryOp::HasToken(token);
    case Type::POSTFIX_OP:
      return PostfixOp::HasToken(token);
    case Type::PREFIX_OP:
      return PrefixOp::HasToken(token);
    case Type::FUNCTION:
      return Function::HasToken(token);
    default:
      return false;
  }
}

}
}
