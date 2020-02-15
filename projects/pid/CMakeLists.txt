cmake_minimum_required(VERSION 2.6)
project(pid)

add_executable(pid main.cpp)

install(TARGETS pid RUNTIME DESTINATION bin)
