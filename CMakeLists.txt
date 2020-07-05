cmake_minimum_required(VERSION 3.10)
project(Dust)

include_directories(./include)

set(CMAKE_CXX_STANDARD 17)

add_executable(Dust src/main.cpp include/main.h)