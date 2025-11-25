/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
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
bool suite_RedBlackTreeTestSuite_init = false;
#include "..\newCxxTest.h"

static RedBlackTreeTestSuite suite_RedBlackTreeTestSuite;

static CxxTest::List Tests_RedBlackTreeTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_RedBlackTreeTestSuite( "C:/Users/apees/Documents/Data Structures/CSC-Data-Structures/CH11 EXAM RBT/newCxxTest.h", 9, "RedBlackTreeTestSuite", suite_RedBlackTreeTestSuite, Tests_RedBlackTreeTestSuite );

static class TestDescription_suite_RedBlackTreeTestSuite_testInsertUniqueWords : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testInsertUniqueWords() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 12, "testInsertUniqueWords" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testInsertUniqueWords(); }
} testDescription_suite_RedBlackTreeTestSuite_testInsertUniqueWords;

static class TestDescription_suite_RedBlackTreeTestSuite_testInsertDuplicates : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testInsertDuplicates() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 24, "testInsertDuplicates" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testInsertDuplicates(); }
} testDescription_suite_RedBlackTreeTestSuite_testInsertDuplicates;

static class TestDescription_suite_RedBlackTreeTestSuite_testFullPangramInsertion : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testFullPangramInsertion() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 30, "testFullPangramInsertion" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testFullPangramInsertion(); }
} testDescription_suite_RedBlackTreeTestSuite_testFullPangramInsertion;

static class TestDescription_suite_RedBlackTreeTestSuite_testStructureAfterInsertion : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testStructureAfterInsertion() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 44, "testStructureAfterInsertion" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testStructureAfterInsertion(); }
} testDescription_suite_RedBlackTreeTestSuite_testStructureAfterInsertion;

static class TestDescription_suite_RedBlackTreeTestSuite_testDeleteExistingWord : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testDeleteExistingWord() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 55, "testDeleteExistingWord" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testDeleteExistingWord(); }
} testDescription_suite_RedBlackTreeTestSuite_testDeleteExistingWord;

static class TestDescription_suite_RedBlackTreeTestSuite_testDeleteNonExistentWord : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testDeleteNonExistentWord() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 64, "testDeleteNonExistentWord" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testDeleteNonExistentWord(); }
} testDescription_suite_RedBlackTreeTestSuite_testDeleteNonExistentWord;

static class TestDescription_suite_RedBlackTreeTestSuite_testMultipleDeletions : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testMultipleDeletions() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 71, "testMultipleDeletions" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testMultipleDeletions(); }
} testDescription_suite_RedBlackTreeTestSuite_testMultipleDeletions;

static class TestDescription_suite_RedBlackTreeTestSuite_testDeleteAll : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testDeleteAll() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 87, "testDeleteAll" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testDeleteAll(); }
} testDescription_suite_RedBlackTreeTestSuite_testDeleteAll;

static class TestDescription_suite_RedBlackTreeTestSuite_testInsertAfterDelete : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testInsertAfterDelete() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 100, "testInsertAfterDelete" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testInsertAfterDelete(); }
} testDescription_suite_RedBlackTreeTestSuite_testInsertAfterDelete;

static class TestDescription_suite_RedBlackTreeTestSuite_testEmptyTreeOperations : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testEmptyTreeOperations() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 111, "testEmptyTreeOperations" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testEmptyTreeOperations(); }
} testDescription_suite_RedBlackTreeTestSuite_testEmptyTreeOperations;

static class TestDescription_suite_RedBlackTreeTestSuite_testStressTest : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testStressTest() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 117, "testStressTest" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testStressTest(); }
} testDescription_suite_RedBlackTreeTestSuite_testStressTest;

static class TestDescription_suite_RedBlackTreeTestSuite_testEdgeCases : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RedBlackTreeTestSuite_testEdgeCases() : CxxTest::RealTestDescription( Tests_RedBlackTreeTestSuite, suiteDescription_RedBlackTreeTestSuite, 137, "testEdgeCases" ) {}
 void runTest() { suite_RedBlackTreeTestSuite.testEdgeCases(); }
} testDescription_suite_RedBlackTreeTestSuite_testEdgeCases;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
