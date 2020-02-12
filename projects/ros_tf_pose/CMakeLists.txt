cmake_minimum_required(VERSION 2.6)
project(ros_tf_pose)

add_executable(ros_tf_pose main.cpp)

install(TARGETS ros_tf_pose RUNTIME DESTINATION bin)
