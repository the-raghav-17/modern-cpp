#ifndef POINT_H_
#define POINT_H_


class Point
{
public:
    int m_x;
    int m_y;

    bool operator==(const Point &point) const
    {
        return (m_x == point.m_x && m_y == point.m_y);
    }
};


#endif // POINT_H_
