#ifndef INPUT_H_
#define INPUT_H_


#include "operation.h"


class Input
{
public:
        int read_input(double &num1, Op_type &op_type, double &num2);

private:
        int read_double(double &num);
        int read_operation(char &op_char);
        bool stream_is_empty();
        void ignore_line();
};


#endif // INPUT_H_
