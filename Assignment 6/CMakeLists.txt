cmake_minimum_required(VERSION 3.3)
project(test_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_1 wordlistStatistics)
set(SOURCE_FILES_1 wordlistStatistics.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_1 caesarCipher)
set(SOURCE_FILES_1 caesarCipher.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_1 frequencyOfWords)
set(SOURCE_FILES_1 frequencyOfWords.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1})