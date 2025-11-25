cmake_minimum_required(VERSION 3.28)
project(CH11_EXAM_RBT)

set(CMAKE_CXX_STANDARD 11)

# A list of all your project's source files
set(PROJECT_SOURCES
        Random.h
        Red_Black_Tree.h
        RBNode.h
        BTNode.h
        BST_With_Rotate.h
        Binary_Search_Tree.h
        Binary_Tree.h
        BSTtest1.txt
        Bad_Structure.h
        BSTtest2.txt
        BSTtest3.txt
        test.txt
        testRight.txt
        words.txt
        pre_order_traversal.h
)

# --- Main Executable ---
add_executable(CH11_EXAM_RBT main.cpp ${PROJECT_SOURCES})

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