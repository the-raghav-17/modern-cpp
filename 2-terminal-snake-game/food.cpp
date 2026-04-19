#include "food.h"
#include "util.h"


void Food::generate_food()
{
    // generate x pos of food below the x boundary
    m_food_pos.m_x = Util::generate_int(0, m_boundaries.m_x);
    m_food_pos.m_y = Util::generate_int(0, m_boundaries.m_y);
}
