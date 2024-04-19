#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
public:
    static double price;
    static int num;
    static double discount;
    static double avg;
    static double profit;

public:
    static void cal(double _discount)
    {
        discount = _discount;
        avg = price - price * discount / 1e2;
        profit = avg * num;
    }
};

double Employee::price = 30;
int Employee::num = 100;
double Employee::discount;
double Employee::avg;
double Employee::profit;

int main()
{
    double discount;
    cin >> discount;

    Employee::cal(discount);

    cout << setiosflags(ios::fixed) << setprecision(2) <<Employee::profit << " " << Employee::avg << endl;

    return 0;
}