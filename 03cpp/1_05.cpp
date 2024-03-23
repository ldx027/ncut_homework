#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Circle
{
private:
    int rad;

public:
    Circle() {}
    Circle(int r) : rad(r) {}

    double getPer()
    {
        return 3.14 * 2 * rad;
    }

    double getArea()
    {
        return 3.14 * pow(rad, 2);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r;
    cin >> r;

    Circle cir(r);

    cout << setiosflags(ios::fixed) << setprecision(2) << cir.getPer() << " " << cir.getArea();
    
    return 0;
}