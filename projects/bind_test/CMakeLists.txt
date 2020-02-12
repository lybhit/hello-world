cmake_minimum_required(VERSION 2.6)
project(bind_test)

add_executable(bind_test main.cpp)
target_link_libraries(bind_test ${Boost_LIBRARIES})
install(TARGETS bind_test RUNTIME DESTINATION bin)
