cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CSC109PROJECT)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include the CxxTest framework (update path as needed)
# if your cxxtest is not located in c:/cxxtest-4.4, change the path to match your cxxtest location.
include_directories(C:/cxxtest-4.4)
# if your cxxtest is not located in c:/cxxtest-4.4, change the path to match your cxxtest location.
set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/cxxtest-4.4/bin/cxxtestgen)

# Find CxxTest (ensure it's installed and path is correct)
find_package(CxxTest REQUIRED)

# Enable testing
enable_testing()

# Automatically include all .cpp and .h files in this directory
file(GLOB ALL_CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB ALL_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# Filter out runner.cpp, newCxxTest, and main.cpp if it might exist already (so it doesn't conflict)
list(REMOVE_ITEM ALL_CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/runner.cpp")
list(REMOVE_ITEM ALL_CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/newCxxTest.h")
list(REMOVE_ITEM ALL_CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

# Add test with CxxTest — runner.cpp will be generated
CXXTEST_ADD_TEST(unittest
    runner.cpp
    ${ALL_CPP_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/newCxxTest.h
)

# Add executable using the auto-collected files
add_executable(CSC109PROJECT
    runner.cpp
    ${ALL_CPP_FILES}
    ${ALL_HEADER_FILES}
)
# do not sumbit runner.cpp and main.cpp to Web-CAT.


