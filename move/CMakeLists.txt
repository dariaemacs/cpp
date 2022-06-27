cmake_minimum_required(VERSION 3.16.0)

project(move)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB CPP_FILES
  src/parameters_data.cpp
  src/main.cpp
  )

add_executable(${PROJECT_NAME} ${CPP_FILES})
