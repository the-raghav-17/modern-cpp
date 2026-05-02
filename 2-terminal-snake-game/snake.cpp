#include "snake.h"
#include "terminal.h"


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


void Snake::draw(const Terminal term)
{
    for (auto body_part : m_body) {
        term.print("0", body_part);
    }
}
