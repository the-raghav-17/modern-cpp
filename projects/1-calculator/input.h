#ifndef INPUT_H_
#define INPUT_H_


#include "operation.h"


class Input
{
public:
        int read_input(double &num1, Op_type &op_type, double &num2);

private:
        int read_double(double &num) const;
        int read_operation(char &op_char) const;
        bool stream_is_empty() const;
        void ignore_line() const;
        void reset_cin() const;
};


#endif // INPUT_H_
