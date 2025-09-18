cmake_minimum_required(VERSION 3.23)
project(CDLL)

set(CMAKE_CXX_STANDARD 14)

# Replace this path with the actual location on your Mac
set(CXXTEST_GEN_SCRIPT "/Users/erickropi/cxxtest-4.4/bin/cxxtestgen")

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    CXXTEST_ADD_TEST(unittest
            runner.cpp  # THIS IS GENERATED BUT YOU NEED TO ADD IT HERE
            DNode.h  # add source files
            circular_list.h  # add source files
            circular_list_iterator.h  # add source files
            circular_list_const_iterator.h  # add source files
            ${CMAKE_CURRENT_SOURCE_DIR}/newCxxTest.h  # YOUR TEST DESCRIPTION FILE
            )

endif()

add_executable(CDLL runner.cpp circular_list.h circular_list_const_iterator.h circular_list_iterator.h DNode.h
        newCxxTest.h)
