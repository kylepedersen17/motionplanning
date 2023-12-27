cmake_minimum_required(VERSION 3.10)

project(motion_planning)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(motion_planning src/main.cpp src/map.cpp src/astar.cpp)
