cmake_minimum_required(VERSION 2.6)
project(sql_test)

add_compile_options(-std=c++11)

#find_package(MySQL REQUIRED)
#include_directories(${MySQL_INCLUDE_DIR} )

add_executable(sql_test main.cpp)
target_link_libraries(sql_test mysqlclient)

install(TARGETS sql_test RUNTIME DESTINATION bin)
