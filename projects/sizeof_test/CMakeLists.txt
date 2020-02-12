cmake_minimum_required(VERSION 2.6)
project(sizeof_test)

add_executable(sizeof_test main.cpp)

install(TARGETS sizeof_test RUNTIME DESTINATION bin)
