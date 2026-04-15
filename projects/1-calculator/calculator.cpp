#include "calculator.h"
#include "operation.h"
#include "input.h"

#include <iostream>


void Calculator::start()
{
    double  num1 {};
    double  num2 {};
    Op_type op_type {};
    double res {};

    while (Input::read_input(num1, op_type, num2) != -1) {
        try {
            res = Operation::operate(num1, op_type, num2);
        }
        catch (Operation::division_by_zero &err) {
            std::cerr << "Division by zero is not allowed\n";
            continue;
        }

        std::cout << "Result: " << res << '\n';
    }
}
