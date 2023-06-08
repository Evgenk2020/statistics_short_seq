cmake_minimum_required(VERSION 3.2)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
#SET(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_BUILD_RPATH app)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BUILD_RPATH}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_RPATH}/bin)

project(onerow LANGUAGES CXX)

add_library(stat STATIC stat.h stat.cpp)

add_executable(onerow main.cpp)
target_link_libraries(onerow stat)