cmake_minimum_required(VERSION 3.10)
project(ask)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ask main.cpp)
target_include_directories(ask PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_directories(ask PRIVATE ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(ask dabai)
