#ifndef FOOD_H_
#define FOOD_H_


#include "point.h"


class Food
{
public:
    Food(const Point boundaries):
        m_boundaries { boundaries }
    {}

    void generate_food();  // generates a position for food b/w boundaries

private:
    Point m_food_pos {};
    Point m_boundaries {};
};


#endif // FOOD_H_
