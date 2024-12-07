cmake_minimum_required(VERSION 3.3)
project(test_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_1 MrMonk)
set(SOURCE_FILES_1 MrMonk.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_1 sortingSearchingCombination)
set(SOURCE_FILES_1 sortingSearchingCombination.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_1 ArrayManipulation)
set(SOURCE_FILES_1 ArrayManipulation.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})