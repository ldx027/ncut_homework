#include <iostream>
#include <iomanip>
using namespace std;

#define pi 3.14

class Container
{
protected:
    double radius;

public:
    // Container() : radius(0) {}
    Container(double r) : radius(r) {}
    virtual ~Container() {}

    virtual double area() = 0;
};

class Cube : public Container
{
public:
    Cube(double r) : Container(r){};
    ~Cube(){}

    double area()
    {
        return radius * radius * 6;
    }
};

class Global : public Container
{
public:
    Global(double r) : Container(r){};
    ~Global(){}

    double area()
    {
        return  4 * pi * radius * radius;
    }
};

class Cylinder : public Container
{
private:
    double h;

public:
    Cylinder(double r, double _h) : Container(r), h(_h){};
    ~Cylinder(){}

    double area()
    {
        return radius * radius * pi * 2 + 2 * pi * radius * h;
    }
};

int main()
{
    Container *cube = new Cube(6);
    Container *global = new Global(5); 
    Container *cylinder = new Cylinder(5, 16);

    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << cube->area() << " " << global->area() << " " << cylinder->area();

    return 0;
}