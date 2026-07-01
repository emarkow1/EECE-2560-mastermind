cmake_minimum_required(VERSION 3.15)
project(Mastermind CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(mastermind
    src/main.cpp
    src/code.cpp
)

target_include_directories(mastermind PRIVATE src)
