cmake_minimum_required(VERSION 2.6)
project(sort_template)

add_executable(sort_template main.cpp)

install(TARGETS sort_template RUNTIME DESTINATION bin)
