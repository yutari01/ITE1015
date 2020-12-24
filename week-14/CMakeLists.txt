cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(ITE1015-week14)
set (CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SOURCES src/*.cc)

add_executable(main main.cc ${SOURCES})
