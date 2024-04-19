#include <iostream>
#include <iomanip>
using namespace std;

class Cft
{
private:
    double length, width, height;
    double v;

public:
    Cft(){ length = width = height = v = 0; }
    Cft(double _len, double _wth, double _hit) : length(_len), width(_wth), height(_hit) { v = length * width * height; }

    double getV() { return v; }
};

int main()
{
    Cft a1(10.2, 3.1, 5.6);
    Cft a2(11.21, 9.22, 13.5);
    Cft a3(5.1, 3.4, 6.5);

    cout << setiosflags(ios::fixed) << setprecision(3) << a1.getV() << " " << a2.getV() << " " << a3.getV() << endl;

    return 0;
}