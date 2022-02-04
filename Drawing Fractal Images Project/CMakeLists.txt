cmake_minimum_required(VERSION 3.2)
set (CMAKE_CXX_STANDARD 11)
project(fractalDrawingBitMaps)

include_directories(include)
file(GLOB SRC_DIR src/*.cpp)

add_executable(runProject ${SRC_DIR})
