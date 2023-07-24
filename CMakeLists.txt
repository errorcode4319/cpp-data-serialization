project(cpp-data-serialization)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

file(GLOB_RECURSE sources src/*.cpp src/*.hpp)

add_executable(sample ${sources})
target_include_directories(
    sample PRIVATE 
    submodules/zpp_bits
)