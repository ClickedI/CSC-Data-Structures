cmake_minimum_required(VERSION 3.23)
project(InfixEval)

set(CMAKE_CXX_STANDARD 11)

# Use Homebrew installation of CxxTest
set(CXXTEST_INCLUDE_DIR "/opt/homebrew/Cellar/cxxtest/4.4_3/include")
set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE "/opt/homebrew/Cellar/cxxtest/4.4_3/bin/cxxtestgen")

include_directories(${CXXTEST_INCLUDE_DIR})

find_package(CxxTest)

if(CXXTEST_FOUND)
    enable_testing()

    CXXTEST_ADD_TEST(unittest
            runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/newCxxTest.h
    )

    target_sources(unittest PRIVATE
            Infix_Evaluator.cpp
    )
endif()

add_executable(InfixEval
        main.cpp
        Infix_Evaluator.cpp
)