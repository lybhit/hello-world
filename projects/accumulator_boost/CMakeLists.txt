cmake_minimum_required(VERSION 2.6)
project(accumulator_boost)

add_executable(accumulator_boost main.cpp)

install(TARGETS accumulator_boost RUNTIME DESTINATION bin)
