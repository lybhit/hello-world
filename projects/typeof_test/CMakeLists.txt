cmake_minimum_required(VERSION 2.6)
project(typeof_test)

add_executable(typeof_test main.cpp)

install(TARGETS typeof_test RUNTIME DESTINATION bin)
