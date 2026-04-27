#ifndef GAME_H_
#define GAME_H_


#include "terminal.h"


class Game
{
public:

    void start();

private:
    Terminal m_term{};    // holds terminal states
    void set_terminal();
    void reset_terminal();
};


#endif // GAME_H_
