You can combine the algorithms for converting between infix to postfix and for evaluating postfix to evaluate an infix expression directly. To do so you need two stacks: one to
contain operators and the other to contain operands. When an operand is encountered,
it is pushed onto the operand stack. When an operator is encountered, it is processed as
described in the infix-to-postfix algorithm. When an operator is popped off the operator
stack, it is processed as described in the postfix evaluation algorithm: The top two
operands are popped off the operand stack, the operation is performed, and the result is
pushed back onto the operand stack. Write a program to evaluate infix expressions
directly using this combined algorithm.