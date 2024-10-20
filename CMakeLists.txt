cmake_minimum_required(VERSION 3.5.0)
project(tracer VERSION 0.1.0 LANGUAGES C CXX)


find_package( OpenCV REQUIRED )


include_directories("/usr/local/include/opencv4")
link_directories("/usr/local/lib")


add_executable(tracer main.cpp Point.cpp Direction.cpp)
target_link_libraries(tracer opencv_photo opencv_imgcodecs opencv_core)

