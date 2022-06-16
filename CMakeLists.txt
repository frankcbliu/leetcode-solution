cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(cn/C++/algm)

add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp leetcode/editor/cn/headers.h)

add_executable(2-add-two-numbers leetcode/editor/cn/2-add-two-numbers.cpp)
add_executable(15-3sum leetcode/editor/cn/15-3sum.cpp)
add_executable(70-climbing-stairs leetcode/editor/cn/70-climbing-stairs.cpp)
add_executable(51-n-queens leetcode/editor/cn/51-n-queens.cpp)