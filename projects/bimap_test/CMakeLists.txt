cmake_minimum_required(VERSION 2.6)
project(bimap_test)

add_executable(bimap_test main.cpp)

install(TARGETS bimap_test RUNTIME DESTINATION bin)
