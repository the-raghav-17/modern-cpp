#ifndef SNAKE_H_
#define SNAKE_H_


#include "point.h"
#include "region.h"
#include "terminal.h"
#include "input.h"

#include <vector>


enum class Move_direction
{
    UP, DOWN, LEFT, RIGHT,
};


class Snake
{
public:
    Snake(const Region game_region);
    
    void read_input(const Input_type &ip);
    void draw(const Terminal &term) const;

private:
    Region m_region {};            // game region where the snake moves

    std::vector<Point> m_body {};    // body of the snake, head at first, tail at end
    Move_direction m_direction {};   // direction in which snake is moving

    void move();
    Move_direction ip_to_move(const Input_type &ip);
};


#endif // SNAKE_H_
