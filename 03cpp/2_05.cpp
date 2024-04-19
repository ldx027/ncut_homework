#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point
{
friend const double operator-(const Point &a, const Point &b);
private:
    double x, y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {};
};

const double operator-(const Point &a, const Point &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    Point a(0, 0), b(3, 4);

    cout << setiosflags(ios::fixed) << setprecision(2) << a - b << endl;

    return 0;
}