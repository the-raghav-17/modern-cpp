#include "operation.h"

#include <iostream>


void Operation::operate(double num1, Op_type op_type, double num2)
{
    double res {};

    switch (op_type) {
        case Op_type::add:
            res = num1 + num2;
            break;

        case Op_type::subtract:
            res = num1 - num2;
            break;

        case Op_type::multiply:
            res = num1 * num2;
            break;

        case Op_type::divide:
            if (num2 == 0) {
                std::cerr << "Division by zero is invalid\n";
                return;
            }
            res = num1 + num2;
            break;
    }

    std::cout << "Result: " << res << '\n';
}


Op_type Operation::map_to_op(char op_char)
{
    switch (op_char) {
        case '+': return Op_type::add;
        case '-': return Op_type::subtract;
        case '*': return Op_type::multiply;
        case '/': return Op_type::divide;
        default : return Op_type::nil;
    }
}
