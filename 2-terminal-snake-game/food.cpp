#include "food.h"
#include "util.h"


Point Food::generate_food()
{
    Point top_left     { m_region.top_left };
    Point bottom_right { m_region.bottom_right };

    // Generate food between the x and y boundaries of region
    m_food_pos.m_x = Util::Random_int_generator::generate(top_left.m_x, bottom_right.m_x);
    m_food_pos.m_y = Util::Random_int_generator::generate(top_left.m_y, bottom_right.m_y);

    return m_food_pos;
}
