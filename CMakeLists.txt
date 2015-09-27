cmake_minimum_required(VERSION 2.8)

include_directories(include)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_executable(samples 
  samples/main.cpp
  samples/sample_const_initialize.cpp
  samples/sample_const_typedefs.cpp
)

