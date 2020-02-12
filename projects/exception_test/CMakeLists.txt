cmake_minimum_required(VERSION 2.6)
project(exception_test)

add_executable(exception_test main.cpp)

install(TARGETS exception_test RUNTIME DESTINATION bin)
