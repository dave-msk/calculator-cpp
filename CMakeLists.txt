cmake_minimum_required(VERSION 3.12)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})
find_package(yaml-cpp REQUIRED)

add_executable(calculator main.cc core/tokens/matcher.h core/tokens/exceptions.h core/tokens/graph_matcher.h core/tokens/graph_matcher.cc core/tokens/parser.h core/tokens/graph_parser.h core/tokens/graph_parser.cc core/expression/nodes/node.cc core/expression/nodes/node.h core/expression/nodes/type.h core/expression/nodes/number.cc core/expression/nodes/number.h)
target_link_libraries(calculator yaml-cpp)
