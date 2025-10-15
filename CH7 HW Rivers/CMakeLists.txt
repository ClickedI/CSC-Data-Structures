cmake_minimum_required(VERSION 3.28)
project("CH7_HW_Rivers")

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_SOURCES
        Rivers.cpp
        Rivers.h
)

add_executable(CH7_HW_Rivers main.cpp ${PROJECT_SOURCES})

set(CXXTEST_INCLUDE_DIR c:/cxxtest-4.4)
set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/cxxtest-4.4/bin/cxxtestgen)

find_package(CxxTest)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    CXXTEST_ADD_TEST(unittest
            runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/newCxxTest.h
            ${PROJECT_SOURCES}
    )
endif()