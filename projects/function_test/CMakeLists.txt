cmake_minimum_required(VERSION 2.6)
project(function_test)

add_executable(function_test main.cpp)

install(TARGETS function_test RUNTIME DESTINATION bin)
