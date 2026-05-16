#ifndef REGION_H_
#define REGION_H_


#include "point.h"


// A region is a rectangle that can be constructed
// using two points; the top left and the bottom right
struct Region
{
    Point top_left;
    Point bottom_right;
};


#endif // REGION_H_
