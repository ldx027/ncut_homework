#include <iostream>
using namespace std;

#define Time 5

int main()
{
    int a, x, sum = 0;
    cin >> a;
    for (int i = 0; i < Time; i++)
    {
        cin >> x;
        if (x < a) sum += a;
    }
    cout << sum << endl;

    return 0;
}