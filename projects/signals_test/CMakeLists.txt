cmake_minimum_required(VERSION 2.6)
project(signals_test)

set(CMAKE_CXX_STANDARD = C++11)
add_executable(signals_test main.cpp)

install(TARGETS signals_test RUNTIME DESTINATION bin)
