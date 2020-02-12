cmake_minimum_required(VERSION 2.8.3)
project( image_show )

find_package(OpenCV)

add_executable(image_show image_show.cpp)
target_link_libraries(image_show ${OpenCV_LIBS})
