cmake_minimum_required(VERSION 2.6)
project(uuid_test)

add_executable(uuid_test main.cpp)

install(TARGETS uuid_test RUNTIME DESTINATION bin)
