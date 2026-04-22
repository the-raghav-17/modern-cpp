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
    Input(Terminal &term);
    Input_type read_input();

private:
    int m_vtime { 5 };  // 5 deciseconds
    int m_vmin { 1 };   // 1 character

    Input_type char_to_iptype(std::vector<char> ch);
};


#endif // INPUT_H_
