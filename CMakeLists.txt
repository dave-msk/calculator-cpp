cmake_minimum_required(VERSION 3.12)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})
find_package(yaml-cpp REQUIRED)

add_executable(calculator main.cc core/tokens/matcher.h core/tokens/exceptions.h core/tokens/graph_matcher.h core/tokens/graph_matcher.cc core/tokens/tokenizer.h core/tokens/graph_tokenizer.h core/tokens/graph_tokenizer.cc core/expression/bin_expr_tree/nodes/node.cc core/expression/bin_expr_tree/nodes/node.h core/expression/bin_expr_tree/nodes/type.h core/expression/bin_expr_tree/nodes/number_node.cc core/expression/bin_expr_tree/nodes/number_node.h core/expression/expression.h core/expression/bin_expr_tree/nodes/precedence.cc core/expression/bin_expr_tree/nodes/precedence.h core/expression/bin_expr_tree/nodes/binary_op_node.cc core/expression/bin_expr_tree/nodes/binary_op_node.h core/expression/bin_expr_tree/nodes/prefix_op_node.cc core/expression/bin_expr_tree/nodes/prefix_op_node.h core/expression/bin_expr_tree/nodes/postfix_op_node.cc core/expression/bin_expr_tree/nodes/postfix_op_node.h core/expression/bin_expr_tree/nodes/function_node.cc core/expression/bin_expr_tree/nodes/function_node.h core/expression/parser.h core/expression/bin_expr_tree/binary_tree_parser.cc core/expression/bin_expr_tree/binary_tree_parser.h)
target_link_libraries(calculator yaml-cpp)
