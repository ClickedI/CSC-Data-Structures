#include "Infix_Evaluator.h"
#include <sstream>
#include <cctype>
using std::stack;
using std::string;
using std::istringstream;
using std::isdigit;
const std::string Infix_Evaluator::OPERATORS = "+-*/()";
const int Infix_Evaluator::PRECEDENCE[] = {1, 1, 2, 2, -1, -1};

/** Evaluates a infix expression.
@param expression The expression to be evaluated
@return The value of the expression
@throws Syntax_Error if a syntax error is detected
*/


int Infix_Evaluator::eval(const std::string& expression) {
    while (!operand_stack.empty())
        operand_stack.pop();
    while (!operator_stack.empty())
        operator_stack.pop();

    istringstream tokens(expression);
    string next_char;
    while (tokens >> next_char) {
        // Process each character in the token while handling whitespace
        for (size_t i = 0; i < next_char.length(); ) {
            if (isdigit(next_char[i])) {
                // Extract the full number
                string num_str;
                while (i < next_char.length() && isdigit(next_char[i])) {
                    num_str += next_char[i];
                    i++;
                }
                operand_stack.push(std::stoi(num_str));
                //checks operator
            } else if (is_operator(next_char[i])) {
                process_operator(next_char[i]);
                i++;
            } else if (!isspace(next_char[i])) {
                throw Syntax_Error("Unexpected Character Encountered");
            } else {
                i++;
            }
        }
    }
    while (!operator_stack.empty()) {
        char op = operator_stack.top();
        operator_stack.pop();
        if (op == '(') {
            throw Syntax_Error("Unmatched open parenthesis");
        }
        operand_stack.push(eval_op(op));
    }
    if (operand_stack.empty()) {
        throw Syntax_Error("Empty or invalid expression");
    }
return operand_stack.top();
}

void Infix_Evaluator::process_operator(char op) {
    if (operator_stack.empty() || (op == '(')) {
        if (op == ')')
            throw Syntax_Error("Unmatched close parenthesis");
        operator_stack.push(op);
    } else {
        if (precedence(op) > precedence(operator_stack.top())) {
            operator_stack.push(op);
        } else {
            while (!operator_stack.empty()
                   && (operator_stack.top() != '(')
                   && (precedence(op) <= precedence(operator_stack.top()))) {
                char first_op = operator_stack.top();
                operator_stack.pop();
                operand_stack.push(eval_op(first_op));
            }
            if (op == ')') {
                if (!operator_stack.empty()
                    && (operator_stack.top() == '(')) {
                    operator_stack.pop();
                } else {
                    throw Syntax_Error("Unmatched close parentheses");
                }
            } else {
                operator_stack.push(op);
            }
        }
    }
}
/** Evaluates the current operator.
This function pops the two operands off the operand
stack and applies the operator.
@param op A character representing the operator
@throws Syntax_Error if top is attempted on an empty stack
*/
int Infix_Evaluator::eval_op(char op) {
    if (operand_stack.empty())
        throw Syntax_Error("Stack is empty");
    int rhs = operand_stack.top();
    operand_stack.pop();
    if (operand_stack.empty())
        throw Syntax_Error("Stack is empty");
    int lhs = operand_stack.top();
    operand_stack.pop();
    int result = 0;
    switch(op) {
        case '+' : result = lhs + rhs;
            break;
        case '-' : result = lhs - rhs;
            break;
        case '*' : result = lhs * rhs;
            break;
        case '/' : result = lhs / rhs;
            break;
    }
    return result;
}

