cmake_minimum_required(VERSION 2.6)
project(heap_test)

add_compile_options(-std=c++11)

add_executable(heap_test main.cpp)

install(TARGETS heap_test RUNTIME DESTINATION bin)
