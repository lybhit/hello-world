cmake_minimum_required(VERSION 2.6)
project(dynamic_bitset_test)

add_executable(dynamic_bitset_test main.cpp)

install(TARGETS dynamic_bitset_test RUNTIME DESTINATION bin)
