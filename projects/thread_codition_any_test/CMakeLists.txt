cmake_minimum_required(VERSION 2.6)
project(thread_codition_any_test)

set(BOOST_COMPONENTS date_time chrono filesystem iostreams program_options regex system thread unit_test_framework)

find_package(Boost REQUIRED COMPONENTS ${BOOST_COMPONENTS})

add_executable(thread_codition_any_test main.cpp)
target_link_libraries(thread_codition_any_test ${Boost_LIBRARIES})

install(TARGETS thread_codition_any_test RUNTIME DESTINATION bin)
