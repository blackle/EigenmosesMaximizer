cmake_minimum_required(VERSION 3.7.2)
project (eigenmoses)

include_directories(src)
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(eigenmoses ${SOURCES})

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -g -O2 -larmadillo")
