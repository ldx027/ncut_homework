#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        double a, b, c, d, e;
        cin >> str >> a >> b >> c >> d >> e;

        int n = 0;
        if (a < 4 || a > 10)
            n++;
        if (b < 3.5 || b > 5.5)
            n++;
        if (str == "male" && (c < 120 || c > 160))
            n++;
        if (str == "female" && (c < 110 || c > 150))
            n++;
        if (str == "male" && (d < 42 || d > 48))
            n++;
        if (str == "female" && (d < 36 || d > 40))
            n++;
        if (e < 100 || e > 300)
            n++;
        if (n == 0)
            cout << "normal";
        else cout << n;
        cout << endl;
    }

    return 0;
}