#include "game.h"
#include "terminal.h"


void Game::start()
{
    set_terminal();
    reset_terminal();
}


void Game::set_terminal()
{
    term.set_raw_mode();
    term.hide_cursor();
}


void Game::reset_terminal()
{
    term.restore_orig_term();
    term.unhide_cursor();
}
