#include "game.h"
#include "terminal.h"
#include "food.h"
#include "input.h"
#include "snake.h"

#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>


// Input delay of 0.7 sec or 7 decisecond (for read syscall)
const std::chrono::duration<double> Game::input_delay { 0.7 };


Game::Game()
{
    m_term.set_raw_mode();
    m_term.hide_cursor();
}


Game::~Game()
{
    m_term.restore_orig_term();
    m_term.unhide_cursor();
}


void Game::start()
{
    // for now whole terminal is for gameplay
    m_game_region = m_term.get_term_dimensions();

    Input input { m_term };
    Snake snake { m_game_region };

    while (true) {
        snake.draw(m_term);
        Input_type ip { input.read_input() };
        snake.read_input(ip);
        m_term.clear_screen();
    }
}
