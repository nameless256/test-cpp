cmake_minimum_required(VERSION 3.21)
project(test_cpp)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")

include_directories(
        calculator
)

file(
        GLOB_RECURSE SOURCES
        "calculator/*.cpp"
)

add_executable(test_cpp main.cpp ${SOURCES})
