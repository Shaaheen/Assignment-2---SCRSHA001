cmake_minimum_required(VERSION 3.3)
project(Assignment_2___SCRSHA001)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp VolImage.cpp VolImage.h)
add_executable(Assignment_2___SCRSHA001 ${SOURCE_FILES})