cmake_minimum_required(VERSION 2.6)
project(optional_test)

add_executable(optional_test main.cpp)

install(TARGETS optional_test RUNTIME DESTINATION bin)
