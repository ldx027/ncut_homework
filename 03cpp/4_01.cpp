#include <iostream>
#include <iomanip>
using namespace std;

#define pi 3.14

class Shape
{
public:
    virtual void printLength() = 0;
    virtual void printArea() = 0;
};

class Circle : public Shape
{
private:
    double r;

public:
    Circle() : r(0) {}
    Circle(double _r) : r(_r) {}
    ~Circle() {}

    void printLength() override 
    {
        cout << 2 * r * pi;
    }

    void printArea() override
    {
        cout << pi * r * r;
    }
};

class Square : public Shape
{
private:
    double l;

public:
    Square() : l(0){}
    Square(double _l) : l(_l){}
    ~Square(){}

    void printLength()
    {
        cout << 4 * l;
    }

    void printArea()
    {
        cout << l * l;
    }
};

class Rectangle : public Shape
{
private:
    double w, h;

public:
    Rectangle() : w(0), h(0){}
    Rectangle(double _w, double _h) : w(_w), h(_h){}
    ~Rectangle(){}

    void printLength()
    {
        cout << (w + h) * 2;
    }

    void printArea()
    {
        cout << w * h;
    }
};

void show(Shape *shape)
{
    shape->printLength();
    cout << " ";
    shape->printArea();
    cout << endl;
}

int main()
{
    Shape *cir = new Circle(4);
    Shape *sqr = new Square(5);
    Shape *rec = new Rectangle(2, 5);

    cout << setiosflags(ios::fixed) << setprecision(2);

    show(cir);
    show(sqr);
    show(rec);

    return 0;
}