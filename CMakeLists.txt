cmake_minimum_required(VERSION 3.12)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})
find_package(yaml-cpp REQUIRED)

file(GLOB calulator_SRC
        "*.h"
        "*.cc")

#add_executable(calculator ${calculator_SRC})
add_executable(calculator main.cc
        core/tokens/matcher.h core/tokens/exceptions.h
        core/tokens/fsm_graph/graph_matcher.h
        core/tokens/fsm_graph/graph_matcher.cc
        core/tokens/tokenizer.h
        core/tokens/fsm_graph/graph_tokenizer.h
        core/tokens/fsm_graph/graph_tokenizer.cc
        core/expression/bin_expr_tree/nodes/node.cc
        core/expression/bin_expr_tree/nodes/node.h
        core/expression/bin_expr_tree/nodes/type.h
        core/expression/bin_expr_tree/nodes/number/number_node.cc
        core/expression/bin_expr_tree/nodes/number/number_node.h
        core/expression/expression.h
        core/expression/bin_expr_tree/nodes/precedence.cc
        core/expression/bin_expr_tree/nodes/precedence.h
        core/expression/bin_expr_tree/nodes/binary_op/binary_op_node.cc
        core/expression/bin_expr_tree/nodes/binary_op/binary_op_node.h
        core/expression/bin_expr_tree/nodes/prefix_op/prefix_op_node.cc
        core/expression/bin_expr_tree/nodes/prefix_op/prefix_op_node.h
        core/expression/bin_expr_tree/nodes/postfix_op/postfix_op_node.cc
        core/expression/bin_expr_tree/nodes/postfix_op/postfix_op_node.h
        core/expression/bin_expr_tree/nodes/function/function_node.cc
        core/expression/bin_expr_tree/nodes/function/function_node.h
        core/expression/parser.h
        core/expression/bin_expr_tree/binary_tree_parser.cc
        core/expression/bin_expr_tree/binary_tree_parser.h
        core/expression/bin_expr_tree/nodes/function/function.cc
        core/expression/bin_expr_tree/nodes/function/function.h
        core/expression/bin_expr_tree/nodes/binary_op/binary_op.cc
        core/expression/bin_expr_tree/nodes/binary_op/binary_op.h
        core/expression/bin_expr_tree/nodes/number/number.cc
        core/expression/bin_expr_tree/nodes/number/number.h
        core/expression/bin_expr_tree/nodes/prefix_op/prefix_op.cc
        core/expression/bin_expr_tree/nodes/prefix_op/prefix_op.h
        core/expression/bin_expr_tree/nodes/postfix_op/postfix_op.cc
        core/expression/bin_expr_tree/nodes/postfix_op/postfix_op.h
        core/expression/bin_expr_tree/nodes/factories.h
        core/expression/bin_expr_tree/nodes/binary_op/binary_op_factory.cc
        core/expression/bin_expr_tree/nodes/function/function_factory.cc
        core/expression/bin_expr_tree/nodes/number/number_factory.cc
        core/expression/bin_expr_tree/nodes/postfix_op/postfix_factory.cc
        core/expression/bin_expr_tree/nodes/prefix_op/prefix_op_factory.cc
        core/expression/bin_expr_tree/nodes/open_bracket_factory.cc
        core/expression/bin_expr_tree/nodes/close_bracket_factory.cc
        core/expression/bin_expr_tree/nodes/tagger.h
        core/expression/bin_expr_tree/nodes/simple_tagger.cc
        core/expression/bin_expr_tree/nodes/simple_tagger.h
        core/tokens/factories.h
        core/tokens/factories.cc
        core/expression/bin_expr_tree/nodes/utils.h
        core/expression/bin_expr_tree/nodes/utils.cc
        core/expression/factories.h
        core/expression/factories.cc)
target_link_libraries(calculator yaml-cpp)
