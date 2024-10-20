cmake_minimum_required(VERSION 3.10) # Ensure a recent version of CMake
project(MyProject VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package( OpenCV REQUIRED )

include_directories("/usr/local/include/opencv4")
link_directories("/usr/local/lib")

add_executable(MyProject main.cpp Point.cpp Direction.cpp)
target_link_libraries(MyProject opencv_photo opencv_imgcodecs opencv_core)

