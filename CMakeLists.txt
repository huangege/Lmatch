cmake_minimum_required(VERSION 3.5)
project(Jam)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main.h graphs.cpp fileop.cpp common.cpp matrix.cpp bmatrix.cpp lmatch.cpp gmatch.cpp experiment.cpp)
add_executable(Jam ${SOURCE_FILES})