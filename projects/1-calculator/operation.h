#ifndef OPERATION_H_
#define OPERATION_H_


enum class Op_type {add, subtract, multiply, divide, nil};


namespace Operation
{
    void operate(double num1, Op_type op_type, double num2);
    Op_type map_to_op(char op_char);
};


#endif // OPERATION_H_
