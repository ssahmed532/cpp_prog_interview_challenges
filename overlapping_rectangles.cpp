//
//  Problem statement:
//      Find if two Rectangles overlap
//
//  https://www.geeksforgeeks.org/find-two-rectangles-overlap/
//

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;


struct Point
{
    const int x;
    const int y;

    Point(int xLoc, int yLoc)
    : x(xLoc), y(yLoc)
    {
    }
};


class Rectangle
{
public:
    const Point location;
    const int width;
    const int height;

    Rectangle(const Point &p, int dimWidth, int dimHeight)
    : location(p), width(dimWidth), height(dimHeight)
    {
    }

    bool contains(const Point &p) const;

    std::vector<Point> getCorners() const;

    static bool isOverlap(const Rectangle &r1, const Rectangle &r2);
};


bool Rectangle::contains(const Point &p) const
{
     return
        ((p.x >= location.x) && 
        (p.x <= (location.x + width)) &&
        (p.y >= location.y) &&
        (p.y <= (location.y + height)));
}


std::vector<Point> Rectangle::getCorners() const
{
    std::vector<Point> corners;

    corners.emplace_back(location);

    Point topLeftCorner(location.x, location.y + height);
    corners.emplace_back(topLeftCorner);

    Point topRightCorner(location.x + width, location.y + height);
    corners.emplace_back(topRightCorner);

    Point bottomRightCorner(location.x + width, location.y);
    corners.emplace_back(bottomRightCorner);

    return corners;
}


bool Rectangle::isOverlap(const Rectangle &r1, const Rectangle &r2)
{
    const std::vector<Point> r2Corners = r2.getCorners();
    for (const auto &corner: r2Corners)
    {
        if (r1.contains(corner))
            return true;
    }

    // now check for the case when r1 is "inside" r2
    const std::vector<Point> r1Corners = r1.getCorners();
    for (const auto &corner: r1Corners)
    {
        if (r2.contains(corner))
            return true;
    }

    return false;
}


int main(void)
{
    {
        // these 2 rectangles overlap
        Rectangle r1(Point(1, 1), 5, 7);
        Rectangle r2(Point(3, 3), 7, 5);

        const auto overlap = Rectangle::isOverlap(r1, r2);
        std::cout << "Rectangles overlap: " << overlap << '\n';
        assert(overlap == true);

        // the symmetric case should also result in the same overlap value
        assert(Rectangle::isOverlap(r2, r1) == overlap);
    }

    {
        // these 2 rectangles do NOT overlap
        Rectangle r1(Point(1, 1), 1, 1);
        Rectangle r2(Point(3, 3), 7, 5);

        const auto overlap = Rectangle::isOverlap(r1, r2);
        std::cout << "Rectangles overlap: " << overlap << '\n';
        assert(overlap == false);

        // the symmetric case should also result in the same overlap value
        assert(Rectangle::isOverlap(r2, r1) == overlap);
    }

    {
        // r1 is completely contained INSIDE r2
        Rectangle r1(Point(5, 7), 10, 6);
        Rectangle r2(Point(1, 1), 25, 19);

        const auto overlap = Rectangle::isOverlap(r1, r2);
        std::cout << "Rectangles overlap: " << overlap << '\n';
        assert(overlap == true);

        // the symmetric case should also result in the same overlap value
        assert(Rectangle::isOverlap(r2, r1) == overlap);
    }

    {
        // r2 is completely contained INSIDE r1
        Rectangle r1(Point(1, 1), 30, 27);
        Rectangle r2(Point(11, 14), 13, 10);

        const auto overlap = Rectangle::isOverlap(r1, r2);
        std::cout << "Rectangles overlap: " << overlap << '\n';
        assert(overlap == true);

        // the symmetric case should also result in the same overlap value
        assert(Rectangle::isOverlap(r2, r1) == overlap);
    }

    {
        // these 2 rectangles do NOT overlap
        Rectangle r1(Point(3, 1), 4, 9);
        Rectangle r2(Point(20, 19), 7, 5);

        const auto overlap = Rectangle::isOverlap(r1, r2);
        std::cout << "Rectangles overlap: " << overlap << '\n';
        assert(overlap == false);

        // the symmetric case should also result in the same overlap value
        assert(Rectangle::isOverlap(r2, r1) == overlap);
    }

    {
        // these 2 rectangles do overlap: r1 is "inside" r2
        Rectangle r2(Point(20, 19), 7, 5);
        Rectangle r1(Point(20, 19), 4, 4);

        const auto overlap = Rectangle::isOverlap(r1, r2);
        std::cout << "Rectangles overlap: " << overlap << '\n';
        assert(overlap == true);

        // the symmetric case should also result in the same overlap value
        assert(Rectangle::isOverlap(r2, r1) == overlap);
    }

    {
        // these 2 rectangles do overlap: r2 is "inside" r1
        Rectangle r1(Point(14, 20), 17, 25);
        Rectangle r2(Point(14, 20), 11, 19);

        const auto overlap = Rectangle::isOverlap(r1, r2);
        std::cout << "Rectangles overlap: " << overlap << '\n';
        assert(overlap == true);

        // the symmetric case should also result in the same overlap value
        assert(Rectangle::isOverlap(r2, r1) == overlap);
    }

    return 0;
}
