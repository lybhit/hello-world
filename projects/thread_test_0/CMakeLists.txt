cmake_minimum_required(VERSION 2.6)
project(thread_test_0)

find_package(Boost REQUIRED system thread)

add_executable(thread_test_0 main.cpp)
target_link_libraries(thread_test_0 ${Boost_LIBRARIES})

install(TARGETS thread_test_0 RUNTIME DESTINATION bin)
