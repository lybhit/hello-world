cmake_minimum_required(VERSION 2.6)
project(multi_array_test)

add_executable(multi_array_test main.cpp)

install(TARGETS multi_array_test RUNTIME DESTINATION bin)
