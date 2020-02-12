cmake_minimum_required(VERSION 2.6)
project(property_tree_test)

add_executable(property_tree_test main.cpp)

install(TARGETS property_tree_test RUNTIME DESTINATION bin)
