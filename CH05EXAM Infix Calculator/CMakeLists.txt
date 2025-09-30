cmake_minimum_required(VERSION 3.23)
project(InfixEval)

set(CMAKE_CXX_STANDARD 11)

# Replace this path with the actual location on your Mac
set(CXXTEST_INCLUDE_DIR "/Users/erickropi/cxxtest-4.4")
set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE "/Users/erickropi/cxxtest-4.4/bin/cxxtestgen")

include_directories(${CXXTEST_INCLUDE_DIR})

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    enable_testing()

    CXXTEST_ADD_TEST(unittest
            runner.cpp  # THIS IS GENERATED
            ${CMAKE_CURRENT_SOURCE_DIR}/newCxxTest.h  # YOUR TEST DESCRIPTION FILE
    )

    # Link the implementation to the test
    target_sources(unittest PRIVATE
            Infix_Evaluator.cpp
    )

endif()

# Main executable (separate from tests)
add_executable(InfixEval
        main.cpp
        Infix_Evaluator.cpp
)