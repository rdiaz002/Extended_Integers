cmake_minimum_required(VERSION 3.7)
project(ext_numbers_tut)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ex_num.cpp ex_num.h)
add_executable(ext_numbers_tut ${SOURCE_FILES})