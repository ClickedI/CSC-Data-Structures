#include <cxxtest/TestSuite.h>
#include "Infix_Evaluator.h"
#include "Syntax_Error.h"

class InfixEvaluatorTest : public CxxTest::TestSuite {
private:
    Infix_Evaluator evaluator;

public:
    // Test 1: Basic addition
    void test01_Addition() {
        TS_ASSERT_EQUALS(evaluator.eval("2 + 3"), 5);
    }

    // Test 2: Basic subtraction
    void test02_Subtraction() {
        TS_ASSERT_EQUALS(evaluator.eval("5 - 2"), 3);
    }

    // Test 3: Basic multiplication
    void test03_Multiplication() {
        TS_ASSERT_EQUALS(evaluator.eval("3 * 4"), 12);
    }

    // Test 4: Basic division
    void test04_Division() {
        TS_ASSERT_EQUALS(evaluator.eval("8 / 2"), 4);
    }

    // Test 5: Operator precedence (multiplication before addition)
    void test05_Precedence() {
        TS_ASSERT_EQUALS(evaluator.eval("2 + 3 * 4"), 14);
    }

    // Test 6: Parentheses override precedence
    void test06_Parentheses() {
        TS_ASSERT_EQUALS(evaluator.eval("( 2 + 3 ) * 4"), 20);
    }

    // Test 7: No spaces between tokens
    void test07_NoSpaces() {
        TS_ASSERT_EQUALS(evaluator.eval("2+3"), 5);
    }

    // Test 8: Multi-digit numbers
    void test08_MultiDigit() {
        TS_ASSERT_EQUALS(evaluator.eval("10 + 20"), 30);
    }

    // Test 9: Division by zero should throw
    void test09_DivisionByZero() {
        TS_ASSERT_THROWS(evaluator.eval("5 / 0"), Syntax_Error);
    }

    // Test 10: Unmatched open parenthesis should throw
    void test10_UnmatchedOpen() {
        TS_ASSERT_THROWS(evaluator.eval("( 2 + 3"), Syntax_Error);
    }

    // Test 11: Unmatched close parenthesis should throw
    void test11_UnmatchedClose() {
        TS_ASSERT_THROWS(evaluator.eval("2 + 3 )"), Syntax_Error);
    }

    // Test 12: Unexpected character should throw
    void test12_UnexpectedChar() {
        TS_ASSERT_THROWS(evaluator.eval("2 # 3"), Syntax_Error);
    }

    // Test 13: Insufficient operands (operator at start)
    void test13_InsufficientOperands() {
        TS_ASSERT_THROWS(evaluator.eval("+ 3"), Syntax_Error);
    }

    // Test 14: Empty expression should throw
    void test14_Empty() {
        TS_ASSERT_THROWS(evaluator.eval(""), Syntax_Error);
    }

    // Test 15: Higher precedence (multiplication before addition, left to right)
    void test15_HigherPrecedence() {
        TS_ASSERT_EQUALS(evaluator.eval("2 * 3 + 4"), 10);
    }

    // Test 16: Nested parentheses
    void test16_NestedParentheses() {
        TS_ASSERT_EQUALS(evaluator.eval("( ( 2 + 3 ) * 4 )"), 20);
    }

    // Test 17: Left associativity (subtraction left to right)
    void test17_LeftAssociativity() {
        TS_ASSERT_EQUALS(evaluator.eval("10 - 3 - 2"), 5);
    }
};