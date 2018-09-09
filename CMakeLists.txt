cmake_minimum_required(VERSION 3.12)
project(multitasking CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
include_directories(src)

add_executable(multitasking main.cpp)
target_link_libraries(multitasking src pthread)