cmake_minimum_required(VERSION 3.0)
project( DASHCAM )
find_package( OpenCV REQUIRED )
include_directories(/usr/local/include/opencv4)
add_subdirectory(video)
add_subdirectory(button)
add_subdirectory(main)
add_executable(otest main.cpp button.cpp video.cpp)


