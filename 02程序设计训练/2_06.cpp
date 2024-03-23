#include <iostream>
using namespace std;

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int year, wek;
    cin >> year >> wek;
    wek += 12;
    wek %= 7;

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        month[1] = 29;
    }

    for (int i = 0; i < 12; i++)
    {
        // cout << i + 1 << " " << wek << endl;
        if (wek == 5) cout << i + 1 << endl;
        wek += month[i];
        wek %= 7;
    }

    return 0;
}