cmake_minimum_required(VERSION 3.12)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})
find_package(yaml-cpp REQUIRED)

add_executable(calculator main.cpp core/tokens/number_matcher.cc core/tokens/symbol_matcher.h core/tokens/symbol_matcher.cc core/tokens/matcher.h core/tokens/exceptions.h core/tokens/fsm_matcher.h core/tokens/fsm_matcher.cc)
target_link_libraries(calculator yaml-cpp)
