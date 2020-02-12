cmake_minimum_required(VERSION 2.6)
project(asio_async_socket_server)

set(BOOST_COMPONENTS date_time chrono program_options system )
find_package(Boost REQUIRED COMPONENTS ${BOOST_COMPONENTS})

add_executable(asio_async_socket_server main.cpp)
target_link_libraries(asio_async_socket_server ${Boost_LIBRARIES})
install(TARGETS asio_async_socket_server RUNTIME DESTINATION bin)
