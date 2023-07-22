cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(cn/C++/algm)

add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp leetcode/editor/cn/headers.h)

add_executable(2-add-two-numbers leetcode/editor/cn/2-add-two-numbers.cpp)
add_executable(15-3sum leetcode/editor/cn/15-3sum.cpp)
add_executable(70-climbing-stairs leetcode/editor/cn/70-climbing-stairs.cpp)
add_executable(51-n-queens leetcode/editor/cn/51-n-queens.cpp)
add_executable(62-unique-paths leetcode/editor/cn/62-unique-paths.cpp)
add_executable(343-integer-break leetcode/editor/cn/343-integer-break.cpp)
add_executable(416-partition-equal-subset-sum leetcode/editor/cn/416-partition-equal-subset-sum.cpp)
add_executable(1046-last-stone-weight leetcode/editor/cn/1046-last-stone-weight.cpp)
add_executable(1049-last-stone-weight-ii leetcode/editor/cn/1049-last-stone-weight-ii.cpp)