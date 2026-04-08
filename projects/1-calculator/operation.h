#ifndef OPERATION_H_
#define OPERATION_H_


enum class Op_type {add, subtract, multiply, divide};


class Operation
{
public:
    int operate(double num1, double num2, Op_type op_type, double &res);
};


#endif // OPERATION_H_
