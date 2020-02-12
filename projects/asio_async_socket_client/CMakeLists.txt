cmake_minimum_required(VERSION 2.6)
project(asio_async_socket_client)

set(BOOST_COMPONENTS date_time chrono system)
find_package(Boost REQUIRED COMPONENTS ${BOOST_COMPONENTS})

add_executable(asio_async_socket_client main.cpp)
target_link_libraries(asio_async_socket_client ${Boost_LIBRARIES})

install(TARGETS asio_async_socket_client RUNTIME DESTINATION bin)
