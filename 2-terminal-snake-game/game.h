#ifndef GAME_H_
#define GAME_H_


#include "terminal.h"

#include <chrono>


class Game
{
public:
    void start();
    static const std::chrono::duration<double> input_delay;

private:
    Terminal m_term{};    // holds terminal states
    void set_terminal();
    void reset_terminal();
};


#endif // GAME_H_
