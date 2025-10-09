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
CxxTest::StaticSuiteDescription suiteDescription_newCxxTest( "C:/Users/apees/Documents/Data Structures/CSC-Data-Structures/CH8 BST/newCxxTest.h", 14, "newCxxTest", suite_newCxxTest, Tests_newCxxTest );

static class TestDescription_suite_newCxxTest_testChargeDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testChargeDefaultConstructor() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 17, "testChargeDefaultConstructor" ) {}
 void runTest() { suite_newCxxTest.testChargeDefaultConstructor(); }
} testDescription_suite_newCxxTest_testChargeDefaultConstructor;

static class TestDescription_suite_newCxxTest_testChargeGetBusiness : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testChargeGetBusiness() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 23, "testChargeGetBusiness" ) {}
 void runTest() { suite_newCxxTest.testChargeGetBusiness(); }
} testDescription_suite_newCxxTest_testChargeGetBusiness;

static class TestDescription_suite_newCxxTest_testContactDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testContactDefaultConstructor() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 28, "testContactDefaultConstructor" ) {}
 void runTest() { suite_newCxxTest.testContactDefaultConstructor(); }
} testDescription_suite_newCxxTest_testContactDefaultConstructor;

static class TestDescription_suite_newCxxTest_testContactGetters : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testContactGetters() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 35, "testContactGetters" ) {}
 void runTest() { suite_newCxxTest.testContactGetters(); }
} testDescription_suite_newCxxTest_testContactGetters;

static class TestDescription_suite_newCxxTest_testContactSetters : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testContactSetters() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 42, "testContactSetters" ) {}
 void runTest() { suite_newCxxTest.testContactSetters(); }
} testDescription_suite_newCxxTest_testContactSetters;

static class TestDescription_suite_newCxxTest_testContactOutputStream : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testContactOutputStream() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 52, "testContactOutputStream" ) {}
 void runTest() { suite_newCxxTest.testContactOutputStream(); }
} testDescription_suite_newCxxTest_testContactOutputStream;

static class TestDescription_suite_newCxxTest_testCustomerDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCustomerDefaultConstructor() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 62, "testCustomerDefaultConstructor" ) {}
 void runTest() { suite_newCxxTest.testCustomerDefaultConstructor(); }
} testDescription_suite_newCxxTest_testCustomerDefaultConstructor;

static class TestDescription_suite_newCxxTest_testCustomerGetCardNumber : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCustomerGetCardNumber() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 68, "testCustomerGetCardNumber" ) {}
 void runTest() { suite_newCxxTest.testCustomerGetCardNumber(); }
} testDescription_suite_newCxxTest_testCustomerGetCardNumber;

static class TestDescription_suite_newCxxTest_testCustomerSetCardNumber : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCustomerSetCardNumber() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 75, "testCustomerSetCardNumber" ) {}
 void runTest() { suite_newCxxTest.testCustomerSetCardNumber(); }
} testDescription_suite_newCxxTest_testCustomerSetCardNumber;

static class TestDescription_suite_newCxxTest_testCustomerGetContact : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCustomerGetContact() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 81, "testCustomerGetContact" ) {}
 void runTest() { suite_newCxxTest.testCustomerGetContact(); }
} testDescription_suite_newCxxTest_testCustomerGetContact;

static class TestDescription_suite_newCxxTest_testCustomerSetContact : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCustomerSetContact() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 89, "testCustomerSetContact" ) {}
 void runTest() { suite_newCxxTest.testCustomerSetContact(); }
} testDescription_suite_newCxxTest_testCustomerSetContact;

static class TestDescription_suite_newCxxTest_testCustomerSetCharges : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCustomerSetCharges() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 97, "testCustomerSetCharges" ) {}
 void runTest() { suite_newCxxTest.testCustomerSetCharges(); }
} testDescription_suite_newCxxTest_testCustomerSetCharges;

static class TestDescription_suite_newCxxTest_testCustomerPushBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCustomerPushBack() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 105, "testCustomerPushBack" ) {}
 void runTest() { suite_newCxxTest.testCustomerPushBack(); }
} testDescription_suite_newCxxTest_testCustomerPushBack;

static class TestDescription_suite_newCxxTest_testCustomerOutputStream : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCustomerOutputStream() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 113, "testCustomerOutputStream" ) {}
 void runTest() { suite_newCxxTest.testCustomerOutputStream(); }
} testDescription_suite_newCxxTest_testCustomerOutputStream;

static class TestDescription_suite_newCxxTest_testListOfCharge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testListOfCharge() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 123, "testListOfCharge" ) {}
 void runTest() { suite_newCxxTest.testListOfCharge(); }
} testDescription_suite_newCxxTest_testListOfCharge;

static class TestDescription_suite_newCxxTest_testBinarySearchTreeErase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinarySearchTreeErase() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 131, "testBinarySearchTreeErase" ) {}
 void runTest() { suite_newCxxTest.testBinarySearchTreeErase(); }
} testDescription_suite_newCxxTest_testBinarySearchTreeErase;

static class TestDescription_suite_newCxxTest_testBinarySearchTreeEraseNotFound : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinarySearchTreeEraseNotFound() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 147, "testBinarySearchTreeEraseNotFound" ) {}
 void runTest() { suite_newCxxTest.testBinarySearchTreeEraseNotFound(); }
} testDescription_suite_newCxxTest_testBinarySearchTreeEraseNotFound;

static class TestDescription_suite_newCxxTest_testBinarySearchTreeEraseLeftOnly : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinarySearchTreeEraseLeftOnly() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 156, "testBinarySearchTreeEraseLeftOnly" ) {}
 void runTest() { suite_newCxxTest.testBinarySearchTreeEraseLeftOnly(); }
} testDescription_suite_newCxxTest_testBinarySearchTreeEraseLeftOnly;

static class TestDescription_suite_newCxxTest_testBinarySearchTreeEraseRightOnly : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinarySearchTreeEraseRightOnly() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 175, "testBinarySearchTreeEraseRightOnly" ) {}
 void runTest() { suite_newCxxTest.testBinarySearchTreeEraseRightOnly(); }
} testDescription_suite_newCxxTest_testBinarySearchTreeEraseRightOnly;

static class TestDescription_suite_newCxxTest_testBinarySearchTreeEraseTwoChildren : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinarySearchTreeEraseTwoChildren() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 194, "testBinarySearchTreeEraseTwoChildren" ) {}
 void runTest() { suite_newCxxTest.testBinarySearchTreeEraseTwoChildren(); }
} testDescription_suite_newCxxTest_testBinarySearchTreeEraseTwoChildren;

static class TestDescription_suite_newCxxTest_testBinarySearchTreeInsertLeft : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinarySearchTreeInsertLeft() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 216, "testBinarySearchTreeInsertLeft" ) {}
 void runTest() { suite_newCxxTest.testBinarySearchTreeInsertLeft(); }
} testDescription_suite_newCxxTest_testBinarySearchTreeInsertLeft;

static class TestDescription_suite_newCxxTest_testBinarySearchTreeInsertDuplicate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinarySearchTreeInsertDuplicate() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 234, "testBinarySearchTreeInsertDuplicate" ) {}
 void runTest() { suite_newCxxTest.testBinarySearchTreeInsertDuplicate(); }
} testDescription_suite_newCxxTest_testBinarySearchTreeInsertDuplicate;

static class TestDescription_suite_newCxxTest_testCountBigLimitsEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCountBigLimitsEmpty() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 244, "testCountBigLimitsEmpty" ) {}
 void runTest() { suite_newCxxTest.testCountBigLimitsEmpty(); }
} testDescription_suite_newCxxTest_testCountBigLimitsEmpty;

static class TestDescription_suite_newCxxTest_testCountBigLimitsOne : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCountBigLimitsOne() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 249, "testCountBigLimitsOne" ) {}
 void runTest() { suite_newCxxTest.testCountBigLimitsOne(); }
} testDescription_suite_newCxxTest_testCountBigLimitsOne;

static class TestDescription_suite_newCxxTest_testCountBigLimitsMultiple : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testCountBigLimitsMultiple() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 260, "testCountBigLimitsMultiple" ) {}
 void runTest() { suite_newCxxTest.testCountBigLimitsMultiple(); }
} testDescription_suite_newCxxTest_testCountBigLimitsMultiple;

static class TestDescription_suite_newCxxTest_testAnyOverLimitEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testAnyOverLimitEmpty() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 280, "testAnyOverLimitEmpty" ) {}
 void runTest() { suite_newCxxTest.testAnyOverLimitEmpty(); }
} testDescription_suite_newCxxTest_testAnyOverLimitEmpty;

static class TestDescription_suite_newCxxTest_testAnyOverLimitFalse : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testAnyOverLimitFalse() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 285, "testAnyOverLimitFalse" ) {}
 void runTest() { suite_newCxxTest.testAnyOverLimitFalse(); }
} testDescription_suite_newCxxTest_testAnyOverLimitFalse;

static class TestDescription_suite_newCxxTest_testAnyOverLimitTrue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testAnyOverLimitTrue() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 297, "testAnyOverLimitTrue" ) {}
 void runTest() { suite_newCxxTest.testAnyOverLimitTrue(); }
} testDescription_suite_newCxxTest_testAnyOverLimitTrue;

static class TestDescription_suite_newCxxTest_testAnyOverLimitMultipleCustomers : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testAnyOverLimitMultipleCustomers() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 309, "testAnyOverLimitMultipleCustomers" ) {}
 void runTest() { suite_newCxxTest.testAnyOverLimitMultipleCustomers(); }
} testDescription_suite_newCxxTest_testAnyOverLimitMultipleCustomers;

static class TestDescription_suite_newCxxTest_testIncreaseLimitNotFound : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testIncreaseLimitNotFound() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 334, "testIncreaseLimitNotFound" ) {}
 void runTest() { suite_newCxxTest.testIncreaseLimitNotFound(); }
} testDescription_suite_newCxxTest_testIncreaseLimitNotFound;

static class TestDescription_suite_newCxxTest_testIncreaseLimitFound : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testIncreaseLimitFound() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 345, "testIncreaseLimitFound" ) {}
 void runTest() { suite_newCxxTest.testIncreaseLimitFound(); }
} testDescription_suite_newCxxTest_testIncreaseLimitFound;

static class TestDescription_suite_newCxxTest_testIncreaseLimitMultipleTimes : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testIncreaseLimitMultipleTimes() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 363, "testIncreaseLimitMultipleTimes" ) {}
 void runTest() { suite_newCxxTest.testIncreaseLimitMultipleTimes(); }
} testDescription_suite_newCxxTest_testIncreaseLimitMultipleTimes;

static class TestDescription_suite_newCxxTest_testBinaryTreeToStringEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinaryTreeToStringEmpty() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 381, "testBinaryTreeToStringEmpty" ) {}
 void runTest() { suite_newCxxTest.testBinaryTreeToStringEmpty(); }
} testDescription_suite_newCxxTest_testBinaryTreeToStringEmpty;

static class TestDescription_suite_newCxxTest_testBinaryTreeToStringWithData : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinaryTreeToStringWithData() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 387, "testBinaryTreeToStringWithData" ) {}
 void runTest() { suite_newCxxTest.testBinaryTreeToStringWithData(); }
} testDescription_suite_newCxxTest_testBinaryTreeToStringWithData;

static class TestDescription_suite_newCxxTest_testBinaryTreeToStringMultiple : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinaryTreeToStringMultiple() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 398, "testBinaryTreeToStringMultiple" ) {}
 void runTest() { suite_newCxxTest.testBinaryTreeToStringMultiple(); }
} testDescription_suite_newCxxTest_testBinaryTreeToStringMultiple;

static class TestDescription_suite_newCxxTest_testBinaryTreeIsNull : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinaryTreeIsNull() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 417, "testBinaryTreeIsNull" ) {}
 void runTest() { suite_newCxxTest.testBinaryTreeIsNull(); }
} testDescription_suite_newCxxTest_testBinaryTreeIsNull;

static class TestDescription_suite_newCxxTest_testBinaryTreeOutputOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBinaryTreeOutputOperator() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 429, "testBinaryTreeOutputOperator" ) {}
 void runTest() { suite_newCxxTest.testBinaryTreeOutputOperator(); }
} testDescription_suite_newCxxTest_testBinaryTreeOutputOperator;

static class TestDescription_suite_newCxxTest_testBTNodeToString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBTNodeToString() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 442, "testBTNodeToString" ) {}
 void runTest() { suite_newCxxTest.testBTNodeToString(); }
} testDescription_suite_newCxxTest_testBTNodeToString;

static class TestDescription_suite_newCxxTest_testBTNodeOutputOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_testBTNodeOutputOperator() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 452, "testBTNodeOutputOperator" ) {}
 void runTest() { suite_newCxxTest.testBTNodeOutputOperator(); }
} testDescription_suite_newCxxTest_testBTNodeOutputOperator;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
