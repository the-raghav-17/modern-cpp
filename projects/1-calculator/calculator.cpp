#include "calculator.h"
#include "operation.h"

#include <iostream>


void Calculator::start()
{
    Operation operation{};
    double    res {};

    while (read_input() != -1) {
        if (operation.operate(num1, num2, op_type, res) != -1) {
            std::cout << "Result: " << res << '\n';
        }
    }
}


int Calculator::read_input()
{
    std::cout << "Enter the first number (q to quit): ";
    std::cin  >> num1;

    std::cout << "Enter the second number (q to quit): ";
    std::cin  >> num2;

    char op_char {};
    std::cout << "Select the operation (+ - * /  or  q to quit): ";
    std::cin  >> op_char;

    switch (op_char) {
        case '+': op_type = Op_type::add; break;
        case '-': op_type = Op_type::subtract; break;
        case '*': op_type = Op_type::multiply; break;
        case '/': op_type = Op_type::divide; break;
    }

    return 0;
}


void Calculator::print_details() const
{
    char op_char {};
    switch (op_type) {
        case Op_type::add: op_char = '+'; break;
        case Op_type::subtract: op_char = '-'; break;
        case Op_type::multiply: op_char = '*'; break;
        case Op_type::divide: op_char = '/'; break;
    }
    std::cout << num1 << ' ' << op_char << ' ' << num2 << '\n';
}
