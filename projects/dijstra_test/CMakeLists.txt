cmake_minimum_required(VERSION 2.6)
project(dijstra_test)

add_executable(dijstra_test main.cpp)

install(TARGETS dijstra_test RUNTIME DESTINATION bin)
