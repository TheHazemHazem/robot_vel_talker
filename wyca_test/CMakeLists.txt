cmake_minimum_required(VERSION 2.8.3)
project(wyca_test)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  genmsg
  message_generation
  sound_play
)

## Declare ROS messages and services
#add_message_files(FILES Num.msg)
#add_service_files(FILES AddTwoInts.srv)
add_service_files(
  FILES
  AddTwoInts.srv
)
## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)
generate_messages(
   DEPENDENCIES
   std_msgs
 )

## Declare a catkin package
catkin_package()

## Build  listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener wyca_test_generate_messages_cpp)




