#include "input.h"
#include "operation.h"

#include <iostream>


int Input::read_input(double &num1, Op_type &op_type, double &num2)
{
    std::cout << "Enter the first number(or 'q' to quit): ";
    std::cin  >> num1;

    std::cout << "Enter the second number(or 'q' to quit): ";
    std::cin  >> num2;

    char op_char {};
    std::cout << "Select the operation(+ - * /) or 'q' to quit: ";
    std::cin  >> op_char;
    if ((op_type = Operation::map_to_op(op_char)) == Op_type::nil) {
        // TODO: error condition
    }

    return 0;
}
