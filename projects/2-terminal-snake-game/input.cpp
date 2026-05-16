#include "input.h"
#include "terminal.h"
#include "game.h"

#include <chrono>
#include <vector>
#include <array>
#include <unistd.h>
#include <thread>
#include <iostream>


Input::Input(Terminal &input_term)
{
    // convert input delay from second to decisecond
    auto vtime { Game::input_delay.count() * 10 };
    int vmin { 0 };

    // Set timeout of read to vtime and min chars read to vmin
    input_term.set_read(vtime, vmin);
}


// Will read input and return an object representing the pressed key
Input_type Input::read_input()
{

    using Time_point = std::chrono::steady_clock::time_point;
    using Clock      = std::chrono::steady_clock;
    using Duration   = std::chrono::duration<double>;

    // Clear any pending data
    tcflush(STDIN_FILENO, TCIFLUSH);

    std::array<char, 3> buf {};

    Time_point start { Clock::now() };
    const ssize_t nbytes = read(STDIN_FILENO, &buf[0], buf.size());

    if (nbytes == 0) {
        // read timed out
        return Input_type::INVALID;
    }

    const auto ip_type { char_to_iptype(buf) };
    if (ip_type == Input_type::PAUSE || ip_type == Input_type::QUIT) {
        return ip_type;
    }

    Time_point end { Clock::now() };
    Duration elapsed { end - start };
    if (elapsed.count() < Game::input_delay.count()) {
        auto sleep_duration { Game::input_delay - elapsed };
        std::this_thread::sleep_for(sleep_duration);
    }

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
