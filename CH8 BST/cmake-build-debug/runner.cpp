/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_newCxxTest_init = false;
#include "..\newCxxTest.h"

static newCxxTest suite_newCxxTest;

static CxxTest::List Tests_newCxxTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_newCxxTest( "C:/Users/apees/Documents/Data Structures/CS211/CH8 BST/newCxxTest.h", 11, "newCxxTest", suite_newCxxTest, Tests_newCxxTest );

static class TestDescription_suite_newCxxTest_testCountBigLimits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCountBigLimits() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 14, "testCountBigLimits" ) {}
 void runTest() { suite_newCxxTest.testCountBigLimits(); }
} testDescription_suite_newCxxTest_testCountBigLimits;

static class TestDescription_suite_newCxxTest_testAnyOverLimit : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testAnyOverLimit() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 35, "testAnyOverLimit" ) {}
 void runTest() { suite_newCxxTest.testAnyOverLimit(); }
} testDescription_suite_newCxxTest_testAnyOverLimit;

static class TestDescription_suite_newCxxTest_testIncreaseLimit : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testIncreaseLimit() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 56, "testIncreaseLimit" ) {}
 void runTest() { suite_newCxxTest.testIncreaseLimit(); }
} testDescription_suite_newCxxTest_testIncreaseLimit;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
