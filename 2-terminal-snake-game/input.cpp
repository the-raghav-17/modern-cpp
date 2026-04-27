#include "input.h"
#include "terminal.h"


#include <vector>
#include <array>
#include <unistd.h>
#include <thread>


Input::Input(Terminal &term)
{
    term.set_read(m_vtime, m_vmin);
}


// Will read input and return an object representing the pressed key
Input_type Input::read_input()
{
    std::array<char, 3> buf {};
    int nbytes = read(STDIN_FILENO, &buf[0], buf.size());
    if (nbytes == 0) {
        // read timed out
        return Input_type::INVALID;
    }

    const auto ip_type { char_to_iptype(buf) };
    return ip_type;
}


Input_type Input::char_to_iptype(std::array<char, 3> &ch)
{
    if (ch[0] == 'p') {
        // p key
        return Input_type::PAUSE;
    }

    if (ch[0] == 'q') {
        // q key
        return Input_type::QUIT;
    }

    if (ch[0] == '\033') {
        if (ch[1] == '[') {
            if (ch[2] == 'A') {
                // Up arrow pressed
                return Input_type::UP_ARROW;
            }

            if (ch[2] == 'B') {
                // Down arrow pressed
                return Input_type::DOWN_ARROW;
            }

            if (ch[2] == 'C') {
                // Right arrow pressed
                return Input_type::RIGHT_ARROW;
            }

            if (ch[2] == 'D') {
                // Left arrow pressed
                return Input_type::LEFT_ARROW;
            }
        }

        return Input_type::QUIT;
    }

    return Input_type::INVALID;
}
