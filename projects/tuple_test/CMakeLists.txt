cmake_minimum_required(VERSION 2.6)
project(tuple_test)

#set(CMAKE_BUILD_TYPE "Debug")
add_executable(tuple_test main.cpp)

install(TARGETS tuple_test RUNTIME DESTINATION bin)
