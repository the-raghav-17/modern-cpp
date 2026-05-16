#ifndef INPUT_H_
#define INPUT_H_

#include "terminal.h"

#include <vector>


enum class Input_type
{
    UP_ARROW, DOWN_ARROW,
    LEFT_ARROW, RIGHT_ARROW,

    PAUSE, QUIT,

    INVALID,
};


class Input
{
public:
    Input(Terminal &input_term);
    Input_type read_input();

private:
    Input_type char_to_iptype(std::array<char, 3> &ch);
};


#endif // INPUT_H_
