#include "food.h"
#include "util.h"


Point Food::generate_food()
{
    // generate x pos of food below the x boundary and same for y
    m_food_pos.m_x = Util::Random_int_generator::generate(0, m_boundaries.m_x);
    m_food_pos.m_y = Util::Random_int_generator::generate(0, m_boundaries.m_y);
    return m_food_pos;
}
