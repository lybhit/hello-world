cmake_minimum_required(VERSION 2.6)
project(unordered_test)

add_executable(unordered_test main.cpp)

install(TARGETS unordered_test RUNTIME DESTINATION bin)
