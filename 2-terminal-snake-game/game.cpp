#include "game.h"
#include "terminal.h"
#include "food.h"

#include <unistd.h>
#include <iostream>


void Game::start()
{
    set_terminal();
    Point term_dimensions { m_term.get_term_dimensions() };
    Food food{term_dimensions};

    while (true) {
        m_term.clear_screen();

        Point food_pos { food.generate_food() };
        m_term.print("0", food_pos);

        sleep(1);
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
