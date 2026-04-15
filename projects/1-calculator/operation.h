#ifndef OPERATION_H_
#define OPERATION_H_


#include <exception>
#include <stdexcept>


enum class Op_type {add, subtract, multiply, divide, nil};


namespace Operation
{
    double operate(double num1, Op_type op_type, double num2);
    Op_type map_to_op(char op_char);

    struct division_by_zero : std::runtime_error
    {
        division_by_zero():
            std::runtime_error{"Division by zero"}
        {}
    };
};


#endif // OPERATION_H_
