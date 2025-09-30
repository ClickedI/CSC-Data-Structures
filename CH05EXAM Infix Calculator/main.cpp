#include <iostream>
#include "Infix_Evaluator.h"
#include "Syntax_Error.h"

using namespace std;

int main() {
    Infix_Evaluator evaluator;

    cout << "Infix Expression Evaluator Test Program" << endl;
    cout << "========================================" << endl << endl;

    // Test cases
    string test_expressions[] = {
            "3 + 4 * 2",
            "( 3 + 4 ) * 2",
            "10 - 2 * 3",
            "( 10 - 2 ) * 3",
            "8 / 2 + 3",
            "8 / ( 2 + 3 )",
            "2 + 3 * 4 - 5",
            "( ( 2 + 3 ) * 4 ) - 5",
            "100 / 10 / 2",
            "5 * ( 3 + 2 ) - 4 / 2",
            "( ( 5 + 3 ) * 2 ) / ( 4 - 2 )",
            "3+4*2",  // No spaces
            "(1+2)*(3+4)",  // No spaces with parentheses
    };

    int num_tests = sizeof(test_expressions) / sizeof(test_expressions[0]);

    for (int i = 0; i < num_tests; i++) {
        try {
            int result = evaluator.eval(test_expressions[i]);
            cout << "Expression: " << test_expressions[i] << endl;
            cout << "Result: " << result << endl << endl;
        } catch (Syntax_Error& error) {
            cout << "Expression: " << test_expressions[i] << endl;
            cout << "Error: " << error.what() << endl << endl;
        }
    }

    // Test error cases
    cout << "Testing Error Cases:" << endl;
    cout << "====================" << endl << endl;

    string error_expressions[] = {
            "( 3 + 4",           // Unmatched open parenthesis
            "3 + 4 )",           // Unmatched close parenthesis
            "5 / 0",             // Division by zero
            "3 + + 4",           // Invalid syntax (would need more operands)
            "( )",               // Empty parentheses
    };

    int num_error_tests = sizeof(error_expressions) / sizeof(error_expressions[0]);

    for (int i = 0; i < num_error_tests; i++) {
        try {
            int result = evaluator.eval(error_expressions[i]);
            cout << "Expression: " << error_expressions[i] << endl;
            cout << "Result: " << result << " (Expected error!)" << endl << endl;
        } catch (Syntax_Error& error) {
            cout << "Expression: " << error_expressions[i] << endl;
            cout << "Caught expected error: " << error.what() << endl << endl;
        } catch (...) {
            cout << "Expression: " << error_expressions[i] << endl;
            cout << "Caught unexpected error type" << endl << endl;
        }
    }

    // Interactive mode
    cout << "\nInteractive Mode (enter 'quit' to exit):" << endl;
    cout << "=========================================" << endl;

    string input;
    while (true) {
        cout << "\nEnter an infix expression: ";
        getline(cin, input);

        if (input == "quit" || input == "exit" || input == "q") {
            break;
        }

        if (input.empty()) {
            continue;
        }

        try {
            int result = evaluator.eval(input);
            cout << "Result: " << result << endl;
        } catch (Syntax_Error& error) {
            cout << "Error: " << error.what() << endl;
        } catch (...) {
            cout << "Unknown error occurred" << endl;
        }
    }

    cout << "\nGoodbye!" << endl;
    return 0;
}