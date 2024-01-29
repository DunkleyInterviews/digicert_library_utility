cmake_minimum_required(VERSION 3.27)
project(digicert_library_utility)

set(CMAKE_CXX_STANDARD 17)

add_executable(digicert_library_utility main.cpp
        OptionSelector.cpp
        Book.cpp
        Book.h)

include_directories(D:/dev/cppLibraries/boost_1_84_0)