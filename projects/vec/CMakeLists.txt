cmake_minimum_required(VERSION 2.6)
project(vec)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 14)
add_executable(vec main.cpp)

install(TARGETS vec RUNTIME DESTINATION bin)
