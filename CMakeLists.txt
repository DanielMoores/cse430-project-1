cmake_minimum_required(VERSION 3.3)
project(cse430_project_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp QElement.h Node.h)
add_executable(cse430_project_1 ${SOURCE_FILES})