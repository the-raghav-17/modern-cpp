#ifndef GAME_H_
#define GAME_H_


#include "terminal.h"

#include <chrono>


class Game
{
public:
    Game();
    ~Game();

    // Delay associated with reading input from user
    static const std::chrono::duration<double> input_delay;

    void start();
    Region get_game_region() const;

private:
    Terminal m_term {};       // terminal associated with the game
    Region m_game_region {};  // terminal region in which snake and food spawn
};


#endif // GAME_H_
