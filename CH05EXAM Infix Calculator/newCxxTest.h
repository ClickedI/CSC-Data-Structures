#include <cxxtest/TestSuite.h>
#include "Infix_Evaluator.h"
#include "Syntax_Error.h"

class SimplifiedInfixEvaluatorTest : public CxxTest::TestSuite {
private:
    Infix_Evaluator evaluator;

public:
    // Basic Math
    void test_BasicOperations() {
        TS_ASSERT_EQUALS(evaluator.eval("2 + 3"), 5);
        TS_ASSERT_EQUALS(evaluator.eval("5 - 2"), 3);
        TS_ASSERT_EQUALS(evaluator.eval("3 * 4"), 12);
        TS_ASSERT_EQUALS(evaluator.eval("8 / 2"), 4);
    }

    // Testing Precendence
    void test_PrecedenceAndAssociativity() {
        TS_ASSERT_EQUALS(evaluator.eval("2 + 3 * 4"), 14);
        TS_ASSERT_EQUALS(evaluator.eval("2 * 3 + 4"), 10);
        TS_ASSERT_EQUALS(evaluator.eval("10 - 3 - 2"), 5);
    }

    // Testing parenthasis
    void test_Parentheses() {
        TS_ASSERT_EQUALS(evaluator.eval("( 2 + 3 ) * 4"), 20);
        TS_ASSERT_EQUALS(evaluator.eval("( ( 2 + 3 ) * 4 )"), 20);
    }

    // different formats (whitespace)
    void test_InputFormatting() {
        TS_ASSERT_EQUALS(evaluator.eval("2+3"), 5);
        TS_ASSERT_EQUALS(evaluator.eval("2             +          3"), 5);
        TS_ASSERT_EQUALS(evaluator.eval("10 + 20"), 30);
    }

    // Error handling
    void test_ErrorHandling() {
        TS_ASSERT_THROWS(evaluator.eval("( 2 + 3"), Syntax_Error);
        TS_ASSERT_THROWS(evaluator.eval("2 + 3 )"), Syntax_Error);
        TS_ASSERT_THROWS(evaluator.eval("2 # 3"), Syntax_Error);
        TS_ASSERT_THROWS(evaluator.eval(""), Syntax_Error);
    }
};