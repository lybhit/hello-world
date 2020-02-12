cmake_minimum_required(VERSION 2.6)
project(bind_compose)

add_compile_options(-std=c++11)
add_executable(bind_compose main.cpp)

install(TARGETS bind_compose RUNTIME DESTINATION bin)
