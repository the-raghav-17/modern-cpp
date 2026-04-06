#ifndef CALCULATOR_H_
#define CALCULATOR_H_


#include "operation.h"


class Calculator
{
public:
        void start();

private:
        double  num1 {};
        double  num2 {};
        Op_type op_type {};

        int read_input();
        void print_details() const;
        void display_message() const;
};


#endif // CALCULATOR_H_
