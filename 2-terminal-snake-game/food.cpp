#include "food.h"
#include "util.h"


void Food::generate_food()
{
    // generate x pos of food below the x boundary
    m_food_pos.x = Util::generate_int(0, m_boundaries.x);
    m_food_pos.y = Util::generate_int(0, m_boundaries.y);
}
