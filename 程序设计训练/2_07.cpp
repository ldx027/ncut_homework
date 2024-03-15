#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool check(int x)
{
    string str = std::to_string(x);
    str = str + str + str;

    for (int i = 1; i <= log10(x) + 1; i++)
    {
        if (str.find(std::to_string(x * i)) == string::npos) return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    while (N--)
    {
        string x;
        cin >> x;
        if (check(x.))
        {
            cout << x << " is cyclic" << endl;
        }
        else 
        {
            cout << x << " is not cyclic" << endl;
        }
    }

    return 0;
}