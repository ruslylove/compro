cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -std=c11")

add_executable(myproj main.c mylib.c)
