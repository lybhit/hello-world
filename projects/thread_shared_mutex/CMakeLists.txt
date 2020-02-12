cmake_minimum_required(VERSION 2.6)
project(thread_shared_mutex)

set(BOOST_COMPONENTS date_time chrono filesystem iostreams program_options regex system thread unit_test_framework)

find_package(Boost REQUIRED COMPONENTS ${BOOST_COMPONENTS})
add_executable(thread_shared_mutex main.cpp)
target_link_libraries(thread_shared_mutex ${Boost_LIBRARIES})

install(TARGETS thread_shared_mutex RUNTIME DESTINATION bin)
