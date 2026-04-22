#include "input.h"
#include "terminal.h"

#include <vector>
#include <unistd.h>


Input::Input(Terminal &term)
{
    term.set_read(m_vtime, m_vmin);
}


Input_type Input::read_input()
{
    std::vector<char> ch(3, '\0');

    int nbytes { read(STDIN_FILENO, &ch[0], ch.size()) };
    if (nbytes == -1) {
        // Timeout
        return Input_type::INVALID;
    }

    // Some key was pressed; determine it.
    Input_type ip = char_to_iptype(ch);

    // TODO: Logic for waiting
    return ip;
}


Input_type Input::char_to_iptype(std::vector<char> ch)
{
    char ch_0 = ch.at(0);
    char ch_1 = ch.at(1);
    char ch_2 = ch.at(2);

    if (ch_0 == 'p') {
        // p key
        return Input_type::PAUSE;
    }

    if (ch_0 == 'q') {
        // q key
        return Input_type::QUIT;
    }

    if (ch_0 == '\033') {
        if (ch_1 == '\0' && ch_2 == '\0') {
            // escape key
            return Input_type::QUIT;
        }

        if (ch_1 == '[') {
            if (ch_2 == 'A') {
                // Up arrow pressed
                return Input_type::UP_ARROW;
            }

            if (ch_2 == 'B') {
                // Down arrow pressed
                return Input_type::DOWN_ARROW;
            }

            if (ch_2 == 'C') {
                // Right arrow pressed
                return Input_type::RIGHT_ARROW;
            }

            if (ch_2 == 'D') {
                // Left arrow pressed
                return Input_type::LEFT_ARROW;
            }
        }
    }

    return Input_type::INVALID;
}
