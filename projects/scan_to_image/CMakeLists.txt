cmake_minimum_required(VERSION 2.8)
project(scan_to_image)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_BUILD_TYPE "Release")


set(OpenCV_DIR "/home/suirui/opencv/opencv-4.1.1/build")

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIR} )

add_executable(scan_to_image main.cpp)
target_link_libraries(scan_to_image ${OpenCV_LIBS})

#install(TARGETS scan_to_image RUNTIME DESTINATION bin)