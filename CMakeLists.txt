cmake_minimum_required(VERSION 3.28)
project(FixVLCHiDPI C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-mwindows")
set(CMAKE_BUILD_RPATH_USE_ORIGIN=ON)

add_executable(FixVLCHiDPI main.c logo.rc)