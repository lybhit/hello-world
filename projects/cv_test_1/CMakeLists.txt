cmake_minimum_required(VERSION 2.6)
project(cv_test_1)

set(OpenCV_DIR "/home/suirui/opencv3/opencv-3.4.2/build")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIR} )

add_executable(cv_test_1 main.cpp)
target_link_libraries(cv_test_1 ${OpenCV_LIBS})

install(TARGETS cv_test_1 RUNTIME DESTINATION bin)
