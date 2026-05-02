#ifndef FOOD_H_
#define FOOD_H_


#include "point.h"
#include "region.h"


class Food
{
public:
    Food(const Region game_region):
        m_region { game_region }
    {}

    Point generate_food();  // generates and returns a position for food in the region

private:
    Point m_food_pos {};
    Region m_region {};
};


#endif // FOOD_H_
