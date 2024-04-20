cmake_minimum_required(VERSION 3.18)
project(cudalice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # .so

# ##############################################################################

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(cudalice)
