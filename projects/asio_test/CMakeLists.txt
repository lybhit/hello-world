cmake_minimum_required(VERSION 2.6)
project(asio_test)

set(BOOST_COMPONENTS date_time chrono filesystem iostreams program_options regex system thread unit_test_framework)
find_package(Boost REQUIRED COMPONENTS ${BOOST_COMPONENTS})
add_executable(asio_test main.cpp)

target_link_libraries(asio_test ${Boost_LIBRARIES})
install(TARGETS asio_test RUNTIME DESTINATION bin)
