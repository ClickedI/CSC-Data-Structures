cmake_minimum_required(VERSION 3.28)
project("CH9EXAMOpen")

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_SOURCES
        const_iterator.h
        drinks.txt
        hash.h
        Hash_Table_Chain.h
        iterator.h
        Person.cpp
        Person.h
        persons.csv

)

add_executable(CH9EXAMOpen Test_Person.cpp ${PROJECT_SOURCES})

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