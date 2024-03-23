#include <iostream>
#include <string>
using namespace std;

int func()
{
    int a, b;
    char c, d;
    int e;

    cin >> a >> b >> c >> d >> e;

    int rst = 0;

    if (a > 80 && e) rst += 8000;
    if (a > 85 && b > 80) rst += 4000;
    if (a > 90) rst += 2e3;
    if (a > 85 && d == 'Y') rst += 1e3;
    if (a > 80 && c =='Y') rst += 850;

    return rst;
}

int main()
{
    int N;
    cin >> N;

    string maxN;
    int max = 0;
    int total = 0;

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        int x = func();

        total += x;
        if (x > max)
        {
            maxN = name;
            max = x;
        }
    }

    cout << maxN << endl << max << endl << total;

    return 0;
}