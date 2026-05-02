#ifndef SNAKE_H_
#define SNAKE_H_


#include "point.h"
#include "region.h"

#include <vector>


enum class Move_direction
{
    UP, DOWN, LEFT, RIGHT,
};


class Snake
{
public:
    Snake(const Region game_region);

private:
    Region m_region {};            // game region where the snake moves

    std::vector<Point> body {};    // body of the snake, head at first, tail at end
    Move_direction direction {};   // direction in which snake is moving
};


#endif // SNAKE_H_
