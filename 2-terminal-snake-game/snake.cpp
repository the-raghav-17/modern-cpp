#include "snake.h"
#include "terminal.h"

#include <cassert>


Snake::Snake(const Region game_region):
    m_region { game_region },            // region where snake moves
    m_direction { Move_direction::UP }   // default move direction
{
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
    std::string head_char { "" };
    
    switch (m_direction) {
        case Move_direction::UP:
            head_char += "V";
            break;

        case Move_direction::DOWN:
            head_char += "^";
            break;

        case Move_direction::LEFT:
            head_char += ">";
            break;

        case Move_direction::RIGHT:
            head_char += "<";
            break;
    }

    // Draw the head
    term.print(head_char, m_body.front());

    // Draw rest of the body
    for (size_t i = 1; i < m_body.size(); i++) {
        term.print("0", m_body.at(i));
    }
}


void Snake::read_input(const Input_type &ip)
{
    assert(ip != Input_type::INVALID 
            && ip != Input_type::QUIT
            && ip != Input_type::PAUSE);

    Move_direction new_dir { ip_to_move(ip) };

    // If new direction is opposite of current direction, don't change the current
    // direction as it will look weird
    if (!(new_dir == Move_direction::UP && m_direction == Move_direction::DOWN)
     && !(new_dir == Move_direction::DOWN && m_direction == Move_direction::UP)
     && !(new_dir == Move_direction::LEFT && m_direction == Move_direction::RIGHT)
     && !(new_dir == Move_direction::RIGHT && m_direction == Move_direction::LEFT)) {

        m_direction = ip_to_move(ip);
    }
}


Snake_state Snake::move(const Point &food_pos)
{
    int head_x { m_body.front().m_x };
    int head_y { m_body.front().m_y };

    switch (m_direction) {
        case Move_direction::UP:
            head_y -= 1;
            break;

        case Move_direction::DOWN:
            head_y += 1;
            break;

        case Move_direction::LEFT:
            head_x -= 1;
            break;

        case Move_direction::RIGHT:
            head_x += 1;
            break;
    }

    Point new_head { head_x, head_y };

    if (head_collides_with_body(new_head)) {
        return Snake_state::BODY_COLLISION;
    }
    if (head_collides_with_wall(new_head)) {
        return Snake_state::WALL_COLLISION;
    }

    if (food_pos == new_head) {
        m_body.push_back({0, 0}); // add a dummy point
    }

    // else update the rest of body positions
    for (size_t i = m_body.size() - 1; i > 0; i--) {
        m_body.at(i) = m_body.at(i - 1);
    }

    m_body.front() = new_head;
    if (new_head == food_pos) {
        return Snake_state::FOOD_COLLISION;
    }
    return Snake_state::NORMAL;
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


bool Snake::head_collides_with_body(const Point &new_head)
{
    for (size_t i = 1; i < m_body.size(); i++) {
        if (m_body.at(i) == new_head) {
            return true;
        }
    }

    return false;
}


bool Snake::head_collides_with_wall(const Point &new_head)
{
    // Game boundary
    int min_x { m_region.top_left.m_x };
    int max_x { m_region.bottom_right.m_x };
    int min_y { m_region.top_left.m_y };
    int max_y { m_region.bottom_right.m_y };

    int head_x { new_head.m_x };
    int head_y { new_head.m_y };

    if (head_x <= min_x || head_x >= max_x
        || head_y <= min_y || head_y >= max_y) {
        return true;
    }

    return false;
}
