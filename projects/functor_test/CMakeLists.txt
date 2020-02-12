cmake_minimum_required(VERSION 2.6)
project(functor_test)

add_executable(functor_test main.cpp)

install(TARGETS functor_test RUNTIME DESTINATION bin)
