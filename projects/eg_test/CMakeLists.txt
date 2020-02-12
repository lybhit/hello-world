cmake_minimum_required(VERSION 2.6)
project(eg_test)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 11)

find_package(Eigen3 REQUIRED)

add_executable(eg_test main.cpp)

install(TARGETS eg_test RUNTIME DESTINATION bin)
