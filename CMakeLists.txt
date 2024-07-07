cmake_minimum_required(VERSION 3.10)
project(Chunk_Codec)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find OpenCV
find_package( OpenCV REQUIRED)

# Inlucde OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(video_info src/video_info.cpp)
add_executable(scene_change src/scene_change.cpp)
add_executable(chunk_video src/chunk_video.cpp)

target_link_libraries(video_info ${OpenCV_LIBS})
target_link_libraries(scene_change ${OpenCV_LIBS})
target_link_libraries(chunk_video ${OpenCV_LIBS})

