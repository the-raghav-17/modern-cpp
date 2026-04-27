#include "game.h"
#include "terminal.h"
#include "food.h"
#include "input.h"

#include <unistd.h>
#include <iostream>


void Game::start()
{
    set_terminal();
    Input input { m_term };

    while (true) {
        Input_type ip = input.read_input();
        std::string action { "" };

        switch (ip) {
            case Input_type::PAUSE:
                action += "Pause";
                break;

            case Input_type::QUIT:
                action += "Quit";
                break;

            case Input_type::INVALID:
                action += "Invalid";
                break;

            case Input_type::UP_ARROW:
                action += "Up arrow";
                break;

            case Input_type::DOWN_ARROW:
                action += "Down arrow";
                break;


            case Input_type::LEFT_ARROW:
                action += "Left arrow";
                break;


            case Input_type::RIGHT_ARROW:
                action += "Right arrow";
                break;

            default:
                action += "Default case ran";
                break;
        }

        std::cout << action << '\n';
    }

    reset_terminal();
}


void Game::set_terminal()
{
    m_term.set_raw_mode();
    m_term.hide_cursor();
}


void Game::reset_terminal()
{
    m_term.restore_orig_term();
    m_term.unhide_cursor();
}
