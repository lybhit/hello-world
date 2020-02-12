cmake_minimum_required(VERSION 2.6)
project(dynamic_program)

add_executable(dynamic_program main.cpp)

install(TARGETS dynamic_program RUNTIME DESTINATION bin)
