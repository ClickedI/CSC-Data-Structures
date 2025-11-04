cmake_minimum_required(VERSION 3.10)
project(ComputerProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(program
    main.cpp
    computer.cpp
        Lap_Top.cpp
        "../CH9HW Hash Map/newCxxTest.h"
)