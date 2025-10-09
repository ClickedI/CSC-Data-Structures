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
bool suite_InfixEvaluatorTest_init = false;
#include "..\newCxxTest.h"

static InfixEvaluatorTest suite_InfixEvaluatorTest;

static CxxTest::List Tests_InfixEvaluatorTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_InfixEvaluatorTest( "C:/Users/apees/Documents/Data Structures/CSC-Data-Structures/CH05EXAM Infix Calculator/newCxxTest.h", 6, "InfixEvaluatorTest", suite_InfixEvaluatorTest, Tests_InfixEvaluatorTest );

static class TestDescription_suite_InfixEvaluatorTest_test01_Addition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test01_Addition() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 12, "test01_Addition" ) {}
 void runTest() { suite_InfixEvaluatorTest.test01_Addition(); }
} testDescription_suite_InfixEvaluatorTest_test01_Addition;

static class TestDescription_suite_InfixEvaluatorTest_test02_Subtraction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test02_Subtraction() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 20, "test02_Subtraction" ) {}
 void runTest() { suite_InfixEvaluatorTest.test02_Subtraction(); }
} testDescription_suite_InfixEvaluatorTest_test02_Subtraction;

static class TestDescription_suite_InfixEvaluatorTest_test03_Multiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test03_Multiplication() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 28, "test03_Multiplication" ) {}
 void runTest() { suite_InfixEvaluatorTest.test03_Multiplication(); }
} testDescription_suite_InfixEvaluatorTest_test03_Multiplication;

static class TestDescription_suite_InfixEvaluatorTest_test04_Division : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test04_Division() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 36, "test04_Division" ) {}
 void runTest() { suite_InfixEvaluatorTest.test04_Division(); }
} testDescription_suite_InfixEvaluatorTest_test04_Division;

static class TestDescription_suite_InfixEvaluatorTest_test05_Precedence : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test05_Precedence() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 44, "test05_Precedence" ) {}
 void runTest() { suite_InfixEvaluatorTest.test05_Precedence(); }
} testDescription_suite_InfixEvaluatorTest_test05_Precedence;

static class TestDescription_suite_InfixEvaluatorTest_test06_Parentheses : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test06_Parentheses() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 52, "test06_Parentheses" ) {}
 void runTest() { suite_InfixEvaluatorTest.test06_Parentheses(); }
} testDescription_suite_InfixEvaluatorTest_test06_Parentheses;

static class TestDescription_suite_InfixEvaluatorTest_test07_NoSpaces : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test07_NoSpaces() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 60, "test07_NoSpaces" ) {}
 void runTest() { suite_InfixEvaluatorTest.test07_NoSpaces(); }
} testDescription_suite_InfixEvaluatorTest_test07_NoSpaces;

static class TestDescription_suite_InfixEvaluatorTest_test08_MultiDigit : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test08_MultiDigit() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 68, "test08_MultiDigit" ) {}
 void runTest() { suite_InfixEvaluatorTest.test08_MultiDigit(); }
} testDescription_suite_InfixEvaluatorTest_test08_MultiDigit;

static class TestDescription_suite_InfixEvaluatorTest_test09_DivisionByZero : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test09_DivisionByZero() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 76, "test09_DivisionByZero" ) {}
 void runTest() { suite_InfixEvaluatorTest.test09_DivisionByZero(); }
} testDescription_suite_InfixEvaluatorTest_test09_DivisionByZero;

static class TestDescription_suite_InfixEvaluatorTest_test10_UnmatchedOpen : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test10_UnmatchedOpen() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 88, "test10_UnmatchedOpen" ) {}
 void runTest() { suite_InfixEvaluatorTest.test10_UnmatchedOpen(); }
} testDescription_suite_InfixEvaluatorTest_test10_UnmatchedOpen;

static class TestDescription_suite_InfixEvaluatorTest_test11_UnmatchedClose : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test11_UnmatchedClose() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 100, "test11_UnmatchedClose" ) {}
 void runTest() { suite_InfixEvaluatorTest.test11_UnmatchedClose(); }
} testDescription_suite_InfixEvaluatorTest_test11_UnmatchedClose;

static class TestDescription_suite_InfixEvaluatorTest_test12_UnexpectedChar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test12_UnexpectedChar() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 112, "test12_UnexpectedChar" ) {}
 void runTest() { suite_InfixEvaluatorTest.test12_UnexpectedChar(); }
} testDescription_suite_InfixEvaluatorTest_test12_UnexpectedChar;

static class TestDescription_suite_InfixEvaluatorTest_test13_InsufficientOperands : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test13_InsufficientOperands() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 124, "test13_InsufficientOperands" ) {}
 void runTest() { suite_InfixEvaluatorTest.test13_InsufficientOperands(); }
} testDescription_suite_InfixEvaluatorTest_test13_InsufficientOperands;

static class TestDescription_suite_InfixEvaluatorTest_test14_Empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test14_Empty() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 136, "test14_Empty" ) {}
 void runTest() { suite_InfixEvaluatorTest.test14_Empty(); }
} testDescription_suite_InfixEvaluatorTest_test14_Empty;

static class TestDescription_suite_InfixEvaluatorTest_test15_HigherPrecedence : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test15_HigherPrecedence() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 148, "test15_HigherPrecedence" ) {}
 void runTest() { suite_InfixEvaluatorTest.test15_HigherPrecedence(); }
} testDescription_suite_InfixEvaluatorTest_test15_HigherPrecedence;

static class TestDescription_suite_InfixEvaluatorTest_test16_NestedParentheses : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test16_NestedParentheses() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 156, "test16_NestedParentheses" ) {}
 void runTest() { suite_InfixEvaluatorTest.test16_NestedParentheses(); }
} testDescription_suite_InfixEvaluatorTest_test16_NestedParentheses;

static class TestDescription_suite_InfixEvaluatorTest_test17_LeftAssociativity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_InfixEvaluatorTest_test17_LeftAssociativity() : CxxTest::RealTestDescription( Tests_InfixEvaluatorTest, suiteDescription_InfixEvaluatorTest, 164, "test17_LeftAssociativity" ) {}
 void runTest() { suite_InfixEvaluatorTest.test17_LeftAssociativity(); }
} testDescription_suite_InfixEvaluatorTest_test17_LeftAssociativity;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
