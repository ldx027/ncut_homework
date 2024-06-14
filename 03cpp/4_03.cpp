#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point
{
friend double distance(Point, Point);
private:
    double x, y;

public:
    Point(double _x, double _y) : x(_x), y(_y){};
};

double distance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

class Circle
{
private:
    Point center;
    double r;

public:
    Circle(Point p, double _r) : center(p), r(_r) {};

    bool onEdge(Point p)
    {
        return distance(p, center) == r;
    }
};

int main()
{
    Circle Circle(Point(1, 2), 5);
    cout << Circle.onEdge(Point(6, 2));

    return 0;
}