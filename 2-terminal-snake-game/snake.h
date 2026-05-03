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

// Used to find whether head is safe or collided
enum class Head_state
{
    SAFE, WALL_COLLISION, BODY_COLLISION, FOOD_COLLISION,
};


class Snake
{
public:
    Snake(const Region game_region);
    
    void read_input(const Input_type &ip);
    Head_state move(const Point &food_pos);
    void draw(const Terminal &term) const;

private:
    Region m_region {};            // game region where the snake moves

    std::vector<Point> m_body {};    // body of the snake, head at first, tail at end
    Move_direction m_direction {};   // direction in which snake is moving

    Move_direction ip_to_move(const Input_type &ip);

    // collision checking helpers
    bool head_collides_with_body(const Point &new_head);
    bool head_collides_with_wall(const Point &new_head);
};


#endif // SNAKE_H_
