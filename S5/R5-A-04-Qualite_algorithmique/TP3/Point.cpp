#include "Point.hpp"

Point::Point():
    m_x (0),
    m_y (0)
{
}

Point::Point(const Point& point):
    m_x (point.m_x),
    m_y (point.m_y)
{
}

Point::Point(int x, int y):
    m_x (x),
    m_y (y)
{
}


void Point::placer(int x, int y)
{
    m_x = x;
    m_y = y;
}

int Point::x() const
{
    return m_x;
}

int Point::y() const
{
    return m_y;
}


Point::~Point()
{
}


std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "(" << point.m_x << ", " << point.m_y << ")";
    return os;
}