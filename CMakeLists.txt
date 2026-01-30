cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(cn/C++/algm)

add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp leetcode/editor/cn/headers.h
        interview/odd_printer.cpp)

add_executable(contest contest.cpp leetcode/editor/cn/headers.h)
add_executable(376-wiggle-subsequence leetcode/editor/cn/376-wiggle-subsequence.cpp)
add_executable(2320-count-number-of-ways-to-place-houses leetcode/editor/cn/2320-count-number-of-ways-to-place-houses.cpp)
add_executable(2140-solving-questions-with-brainpower leetcode/editor/cn/2140-solving-questions-with-brainpower.cpp)
add_executable(2321-maximum-score-of-spliced-array leetcode/editor/cn/2321-maximum-score-of-spliced-array.cpp)
add_executable(1143-longest-common-subsequence leetcode/editor/cn/1143-longest-common-subsequence.cpp)
add_executable(583-delete-operation-for-two-strings leetcode/editor/cn/583-delete-operation-for-two-strings.cpp)
add_executable(647-palindromic-substrings leetcode/editor/cn/647-palindromic-substrings.cpp)
add_executable(516-longest-palindromic-subsequence leetcode/editor/cn/516-longest-palindromic-subsequence.cpp)
add_executable(2266-count-number-of-texts leetcode/editor/cn/2266-count-number-of-texts.cpp)
add_executable(2305-fair-distribution-of-cookies leetcode/editor/cn/2305-fair-distribution-of-cookies.cpp)
add_executable(203-remove-linked-list-elements leetcode/editor/cn/203-remove-linked-list-elements.cpp)
add_executable(707-design-linked-list leetcode/editor/cn/707-design-linked-list.cpp)
add_executable(sort sort/main.cc sort/sort.h)
add_executable(bubble_sort sort/bubble_sort.cc
        sort/select_sort.cc
        sort/insert_sort.cc
        sort/merge_sort.cc)
add_executable(even_printer interview/even_printer.cc)
