cmake_minimum_required(VERSION 2.6)
project(circular_buffer_test)

add_executable(circular_buffer_test main.cpp)

install(TARGETS circular_buffer_test RUNTIME DESTINATION bin)
