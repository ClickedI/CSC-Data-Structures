#include "Infix_Evaluator.h"
#include <sstream>
#include <cctype>
using std::stack;
using std::string;
using std::istringstream;
using std::isdigit;
const std::string Infix_Evaluator::OPERATORS = "+-*/()";
const int Infix_Evaluator::PRECEDENCE[] = {1, 1, 2, 2, -1, -1};



int Infix_Evaluator::eval(const std::string& expression) {
    while (!operand_stack.empty())
        operand_stack.pop();
    while (!operator_stack.empty())
        operator_stack.pop();

    istringstream tokens(expression);
    string next_char;
    while (tokens >> next_char) {
        // Process each character in the token
        for (size_t i = 0; i < next_char.length(); ) {
            if (isdigit(next_char[i])) {
                // Extract the full number
                string num_str;
                while (i < next_char.length() && isdigit(next_char[i])) {
                    num_str += next_char[i];
                    i++;
                }
                operand_stack.push(std::stoi(num_str));
            } else if (is_operator(next_char[i])) {
                process_operator(next_char[i]);
                i++;
            } else if (!isspace(next_char[i])) {
                throw Syntax_Error("Unexpected Character");
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
        if (operand_stack.size() < 2) {  // ADD THIS CHECK
            throw Syntax_Error("Insufficient operands");
        }
        int rhs = operand_stack.top();
        operand_stack.pop();
        int lhs = operand_stack.top();
        operand_stack.pop();
        operand_stack.push(eval_op(op, lhs, rhs));
    }
    if (operand_stack.empty()) {  // ADD THIS CHECK
        throw Syntax_Error("Empty expression");
    }
    if (operand_stack.size() > 1) {  // ADD THIS CHECK
        throw Syntax_Error("Invalid expression");
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
                int rhs = operand_stack.top();
                operand_stack.pop();
                int lhs = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(eval_op(first_op, lhs, rhs));
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

int Infix_Evaluator::eval_op(char op, int lhs, int rhs) {
    switch(op) {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '*': return lhs * rhs;
        case '/':
            if (rhs == 0) throw Syntax_Error("Division by zero");
            return lhs / rhs;
        default: throw Syntax_Error("Unknown operator");
    }
}

