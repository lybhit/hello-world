cmake_minimum_required(VERSION 2.6)
project(thread_test)

add_executable(thread_test main.cpp)

install(TARGETS thread_test RUNTIME DESTINATION bin)
