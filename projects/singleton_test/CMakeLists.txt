cmake_minimum_required(VERSION 2.6)
project(singleton_test)

add_executable(singleton_test main.cpp)

install(TARGETS singleton_test RUNTIME DESTINATION bin)
