#include "snake.h"
#include "terminal.h"

#include <cassert>


Snake::Snake(const Region game_region):
    m_region { game_region },            // region where snake moves
    m_direction { Move_direction::UP }   // default move direction
{
    // TODO: Set current position of snake to the center

    Point top_left { m_region.top_left };
    Point bottom_right { m_region.bottom_right };

    int region_center_x { (bottom_right.m_x - top_left.m_x) / 2 };
    int region_center_y { (bottom_right.m_y - top_left.m_y) / 2 };

    // Snake will initially have 3 points as its body.
    // head will be at center with subsequent 2 parts below it
    m_body.push_back({region_center_x, region_center_y});
    m_body.push_back({region_center_x, region_center_y + 1});
    m_body.push_back({region_center_x, region_center_y + 2});
}


void Snake::draw(const Terminal &term) const
{
    for (auto body_part : m_body) {
        term.print("0", body_part);
    }
}


void Snake::read_input(const Input_type &ip)
{
    if (ip != Input_type::PAUSE && ip != Input_type::QUIT
            && ip != Input_type::INVALID) {
        m_direction = ip_to_move(ip);
    }
    move();
}


void Snake::move()
{
    int x { m_body.at(0).m_x };
    int y { m_body.at(0).m_y };

    switch (m_direction) {
        case Move_direction::UP:
            y -= 1;
            break;

        case Move_direction::DOWN:
            y += 1;
            break;

        case Move_direction::LEFT:
            x -= 1;
            break;

        case Move_direction::RIGHT:
            x += 1;
            break;
    }

    Point new_head { x, y };
    m_body.front() = new_head;

    for (size_t i = 1; i < m_body.size(); i++) {
        m_body.at(i) = m_body.at(i - 1);
    }
}


Move_direction Snake::ip_to_move(const Input_type &ip)
{
    assert(ip != Input_type::INVALID 
            && ip != Input_type::QUIT
            && ip != Input_type::PAUSE);

    switch (ip) {
        case Input_type::UP_ARROW:
            return Move_direction::UP;

        case Input_type::DOWN_ARROW:
            return Move_direction::DOWN;

        case Input_type::LEFT_ARROW:
            return Move_direction::LEFT;

        case Input_type::RIGHT_ARROW:
            return Move_direction::RIGHT;
    }
}
