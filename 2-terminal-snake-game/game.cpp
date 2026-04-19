#include "game.h"
#include "terminal.h"

#include <unistd.h>


void Game::start()
{
    set_terminal();

    int i { 0 };
    while (true) {
        m_term.clear_screen();
        Point pos { 10, i };
        m_term.print("0", pos);
        i++;
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
