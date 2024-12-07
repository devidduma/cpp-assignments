cmake_minimum_required(VERSION 3.3)
project(test_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_1 Time)
set(SOURCE_FILES_1 Time.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_1 Product)
set(SOURCE_FILES_1 Product.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})