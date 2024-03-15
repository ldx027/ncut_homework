#include <iostream>
#include <vector>
#include <string>
using namespace std;

void func(string &str)
{
    for (auto it = str.begin(); it != str.end(); it++)
    {
        if (*it == ' ')
        {
            str.erase(it--);
        }
        if (*it >= 'A' && *it <= 'Z') *it += 'a' - 'A';
    }
}

int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        string a, b;
        getline(cin, a);
        getline(cin, a);
        getline(cin, b);

        func(a); func(b);

        cout << (a == b ? "YES" : "NO") << endl;
    }
}