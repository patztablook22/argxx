cmake_minimum_required(VERSION 3.17)
project(
  argxx VERSION 0.0
  DESCRIPTION "An objective solution to keyword argumnets in C++"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
