cmake_minimum_required(VERSION 3.28)
project(HW8BST)

set(CMAKE_CXX_STANDARD 11)

# A list of all your project's source files
set(PROJECT_SOURCES
        Contact.cpp
        Charge.cpp
        Customer.cpp
        Customers.cpp
        ListOfCharge.cpp
)

# --- Main Executable ---
add_executable(HW8BST main.cpp ${PROJECT_SOURCES})

# --- CxxTest Configuration ---
set(CXXTEST_INCLUDE_DIR c:/cxxtest-4.4)
set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/cxxtest-4.4/bin/cxxtestgen)

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    # Tell CxxTest to create a test runner using the full path to the test file
    CXXTEST_ADD_TEST(unittest
            runner.cpp # This is generated
            # Use the full path to your test header file
            ${CMAKE_CURRENT_SOURCE_DIR}/newCxxTest.h
            ${PROJECT_SOURCES}
    )
endif()