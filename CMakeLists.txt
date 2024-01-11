cmake_minimum_required(VERSION 3.25)
project(HW_listas C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(HW_listas
        doubly_list.h
        forward_list.h
        main.cpp)
