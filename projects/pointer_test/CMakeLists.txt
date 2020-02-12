cmake_minimum_required(VERSION 2.6)
project(pointer_test)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 14)

add_executable(pointer_test main.cpp)

install(TARGETS pointer_test RUNTIME DESTINATION bin)
