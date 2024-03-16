#include <iostream>
#include <string>
using namespace std;

string mul(string str, int n)
{
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = (str[i] - '0') * n + '0';
    }
    if (str[0] > '9')
        str = '0' + str;
    for (int i = str.size() - 1; i > 0; i--)
    {
        if (str[i] > '9')
        {
            str[i - 1] += (str[i] - '0') / 10;
            str[i] = (str[i] - '0') % 10 + '0';
        }
    }

    return str;
}

// this is a test

bool cyclic(string str)
{
    int N = str.size();
    string cycle = str + str + str;
    for (int i = 1; i <= N; i++)
    {
        if (cycle.find(mul(str, i)) == string::npos)
        {
            cout << str << " " << i << " " << mul(str, i) << endl;
            return false;
        }
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

    string str;
    while (N--)
    {
        cin >> str;
        if (cyclic(str))
        {
            cout << str << " is cyclic" << endl;
        }
        else
        {
            cout << str << " is not cyclic" << endl;
        }
    }

    return 0;
}