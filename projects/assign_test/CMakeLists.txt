cmake_minimum_required(VERSION 2.6)
project(assign_test)

add_executable(assign_test main.cpp)

install(TARGETS assign_test RUNTIME DESTINATION bin)
