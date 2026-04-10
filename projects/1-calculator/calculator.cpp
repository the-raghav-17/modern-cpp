#include "calculator.h"
#include "operation.h"
#include "input.h"

#include <iostream>


void Calculator::start()
{
    double  num1 {};
    double  num2 {};
    Op_type op_type {};

    while (true) {
        if (Input::read_input(num1, op_type, num2) == -1) {
            break;
        }
        Operation::operate(num1, op_type, num2);
    }
}
