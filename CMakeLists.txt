cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(cn/C++/algm)

add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp leetcode/editor/cn/headers.h)

add_executable(contest contest.cpp leetcode/editor/cn/headers.h)
add_executable(376-wiggle-subsequence leetcode/editor/cn/376-wiggle-subsequence.cpp)
add_executable(2320-count-number-of-ways-to-place-houses leetcode/editor/cn/2320-count-number-of-ways-to-place-houses.cpp)
add_executable(2140-solving-questions-with-brainpower leetcode/editor/cn/2140-solving-questions-with-brainpower.cpp)