#include "operation.h"

#include <iostream>


int Operation::operate(double num1, double num2,
                          Op_type op_type, double &res)
{
    switch (op_type) {
        case Op_type::add:
            res = num1 + num2;
            return 0;

        case Op_type::subtract:
            res = num1 - num2;
            return 0;

        case Op_type::multiply:
            res = num1 * num2;
            return 0;

        case Op_type::divide:
            if (num2 == 0) {
                std::cerr << "Division by zero is invalid\n";
                return -1;
            }
            res = num1 / num2;
            return 0;
    }
}
