#include <iostream>

#ifndef POINT_HPP
#define POINT_HPP

class Point
{
private:
    int m_x;
    int m_y;
public:
    Point();
    Point(const Point& point);
    Point(int x, int y);
    virtual ~Point();

    void placer(int x, int y);
    int x() const;
    int y() const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};


#endif // POINT_HPP