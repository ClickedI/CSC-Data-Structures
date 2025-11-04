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
bool suite_newCxxTest_init = false;
#include "..\newCxxTest.h"

static newCxxTest suite_newCxxTest;

static CxxTest::List Tests_newCxxTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_newCxxTest( "C:/Users/apees/Documents/Data Structures/CSC-Data-Structures/CH9HW Hash Map/newCxxTest.h", 11, "newCxxTest", suite_newCxxTest, Tests_newCxxTest );

static class TestDescription_suite_newCxxTest_test_hash_map : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_hash_map() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 14, "test_hash_map" ) {}
 void runTest() { suite_newCxxTest.test_hash_map(); }
} testDescription_suite_newCxxTest_test_hash_map;

static class TestDescription_suite_newCxxTest_test_insert : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_insert() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 20, "test_insert" ) {}
 void runTest() { suite_newCxxTest.test_insert(); }
} testDescription_suite_newCxxTest_test_insert;

static class TestDescription_suite_newCxxTest_test_operator_brackets : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_operator_brackets() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 31, "test_operator_brackets" ) {}
 void runTest() { suite_newCxxTest.test_operator_brackets(); }
} testDescription_suite_newCxxTest_test_operator_brackets;

static class TestDescription_suite_newCxxTest_test_find : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_find() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 39, "test_find" ) {}
 void runTest() { suite_newCxxTest.test_find(); }
} testDescription_suite_newCxxTest_test_find;

static class TestDescription_suite_newCxxTest_test_erase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_erase() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 53, "test_erase" ) {}
 void runTest() { suite_newCxxTest.test_erase(); }
} testDescription_suite_newCxxTest_test_erase;

static class TestDescription_suite_newCxxTest_test_rehash : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_rehash() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 67, "test_rehash" ) {}
 void runTest() { suite_newCxxTest.test_rehash(); }
} testDescription_suite_newCxxTest_test_rehash;

static class TestDescription_suite_newCxxTest_test_begin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_begin() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 77, "test_begin" ) {}
 void runTest() { suite_newCxxTest.test_begin(); }
} testDescription_suite_newCxxTest_test_begin;

static class TestDescription_suite_newCxxTest_test_end : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_end() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 91, "test_end" ) {}
 void runTest() { suite_newCxxTest.test_end(); }
} testDescription_suite_newCxxTest_test_end;

static class TestDescription_suite_newCxxTest_test_copy_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_copy_constructor() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 100, "test_copy_constructor" ) {}
 void runTest() { suite_newCxxTest.test_copy_constructor(); }
} testDescription_suite_newCxxTest_test_copy_constructor;

static class TestDescription_suite_newCxxTest_test_operator_equals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_operator_equals() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 111, "test_operator_equals" ) {}
 void runTest() { suite_newCxxTest.test_operator_equals(); }
} testDescription_suite_newCxxTest_test_operator_equals;

static class TestDescription_suite_newCxxTest_test_to_string : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_to_string() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 120, "test_to_string" ) {}
 void runTest() { suite_newCxxTest.test_to_string(); }
} testDescription_suite_newCxxTest_test_to_string;

static class TestDescription_suite_newCxxTest_test_empty_to_string : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_empty_to_string() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 127, "test_empty_to_string" ) {}
 void runTest() { suite_newCxxTest.test_empty_to_string(); }
} testDescription_suite_newCxxTest_test_empty_to_string;

static class TestDescription_suite_newCxxTest_test_hash_Person : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_hash_Person() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 133, "test_hash_Person" ) {}
 void runTest() { suite_newCxxTest.test_hash_Person(); }
} testDescription_suite_newCxxTest_test_hash_Person;

static class TestDescription_suite_newCxxTest_test_age : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_age() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 140, "test_age" ) {}
 void runTest() { suite_newCxxTest.test_age(); }
} testDescription_suite_newCxxTest_test_age;

static class TestDescription_suite_newCxxTest_test_can_vote : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_can_vote() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 145, "test_can_vote" ) {}
 void runTest() { suite_newCxxTest.test_can_vote(); }
} testDescription_suite_newCxxTest_test_can_vote;

static class TestDescription_suite_newCxxTest_test_can_drink : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_can_drink() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 153, "test_can_drink" ) {}
 void runTest() { suite_newCxxTest.test_can_drink(); }
} testDescription_suite_newCxxTest_test_can_drink;

static class TestDescription_suite_newCxxTest_test_is_senior : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_is_senior() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 161, "test_is_senior" ) {}
 void runTest() { suite_newCxxTest.test_is_senior(); }
} testDescription_suite_newCxxTest_test_is_senior;

static class TestDescription_suite_newCxxTest_test_operator_equal_equal : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_operator_equal_equal() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 169, "test_operator_equal_equal" ) {}
 void runTest() { suite_newCxxTest.test_operator_equal_equal(); }
} testDescription_suite_newCxxTest_test_operator_equal_equal;

static class TestDescription_suite_newCxxTest_test_set_given_name : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_set_given_name() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 178, "test_set_given_name" ) {}
 void runTest() { suite_newCxxTest.test_set_given_name(); }
} testDescription_suite_newCxxTest_test_set_given_name;

static class TestDescription_suite_newCxxTest_test_get_ID : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_get_ID() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 189, "test_get_ID" ) {}
 void runTest() { suite_newCxxTest.test_get_ID(); }
} testDescription_suite_newCxxTest_test_get_ID;

static class TestDescription_suite_newCxxTest_test_person_ostream : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_person_ostream() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 194, "test_person_ostream" ) {}
 void runTest() { suite_newCxxTest.test_person_ostream(); }
} testDescription_suite_newCxxTest_test_person_ostream;

static class TestDescription_suite_newCxxTest_test_hash_string : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_hash_string() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 209, "test_hash_string" ) {}
 void runTest() { suite_newCxxTest.test_hash_string(); }
} testDescription_suite_newCxxTest_test_hash_string;

static class TestDescription_suite_newCxxTest_test_hash_int : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_hash_int() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 215, "test_hash_int" ) {}
 void runTest() { suite_newCxxTest.test_hash_int(); }
} testDescription_suite_newCxxTest_test_hash_int;

static class TestDescription_suite_newCxxTest_test_operator_star : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_operator_star() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 221, "test_operator_star" ) {}
 void runTest() { suite_newCxxTest.test_operator_star(); }
} testDescription_suite_newCxxTest_test_operator_star;

static class TestDescription_suite_newCxxTest_test_operator_plus_plus : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_operator_plus_plus() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 229, "test_operator_plus_plus" ) {}
 void runTest() { suite_newCxxTest.test_operator_plus_plus(); }
} testDescription_suite_newCxxTest_test_operator_plus_plus;

static class TestDescription_suite_newCxxTest_test_const_iterator_ops : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_const_iterator_ops() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 244, "test_const_iterator_ops" ) {}
 void runTest() { suite_newCxxTest.test_const_iterator_ops(); }
} testDescription_suite_newCxxTest_test_const_iterator_ops;

static class TestDescription_suite_newCxxTest_test_const_iterator_post_increment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_const_iterator_post_increment() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 253, "test_const_iterator_post_increment" ) {}
 void runTest() { suite_newCxxTest.test_const_iterator_post_increment(); }
} testDescription_suite_newCxxTest_test_const_iterator_post_increment;

static class TestDescription_suite_newCxxTest_test_const_iterator_dereference_end_star : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_const_iterator_dereference_end_star() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 263, "test_const_iterator_dereference_end_star" ) {}
 void runTest() { suite_newCxxTest.test_const_iterator_dereference_end_star(); }
} testDescription_suite_newCxxTest_test_const_iterator_dereference_end_star;

static class TestDescription_suite_newCxxTest_test_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_size() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 271, "test_size" ) {}
 void runTest() { suite_newCxxTest.test_size(); }
} testDescription_suite_newCxxTest_test_size;

static class TestDescription_suite_newCxxTest_test_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_newCxxTest_test_empty() : CxxTest::RealTestDescription( Tests_newCxxTest, suiteDescription_newCxxTest, 279, "test_empty" ) {}
 void runTest() { suite_newCxxTest.test_empty(); }
} testDescription_suite_newCxxTest_test_empty;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
