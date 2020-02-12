cmake_minimum_required(VERSION 2.6)
project(result_of_test)

add_executable(result_of_test main.cpp)

install(TARGETS result_of_test RUNTIME DESTINATION bin)
