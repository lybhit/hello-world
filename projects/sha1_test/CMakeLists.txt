cmake_minimum_required(VERSION 2.6)
project(sha1_test)

add_executable(sha1_test main.cpp)

install(TARGETS sha1_test RUNTIME DESTINATION bin)
