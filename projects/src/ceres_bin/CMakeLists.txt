cmake_minimum_required( VERSION 2.8)
project(helloworld)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")

#添加cmake模块以使用ceres库
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

add_executable(helloworld helloworld.cpp)
target_link_libraries(helloworld ${CERES_LIBRARIES})
