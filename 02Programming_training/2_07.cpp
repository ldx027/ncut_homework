#include <iostream>
#include <vector>
#include <string>
using namespace std;

string mul(string str, int n)
{
    vector<int> vec(str.size());
    for (int i = 0; i < str.size(); i++) vec[i] = (str[str.size() - i - 1] - '0') * n;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > 9)
        {
            if (i == vec.size() - 1)
            {
                vec.push_back(0);
            }
            vec[i + 1] += vec[i] / 10;
            vec[i] %= 10;
        }
    }

    string rst;
    for (int i = vec.size() - 1; i >= 0; i--) rst.push_back(vec[i] + '0');

    return rst;
}

bool cyclic(string str)
{
    string cycle = str + str + str;

    for (int i = 1; i <= str.size(); i++)
    {
        if (cycle.find(mul(str, i)) == string::npos)
        {
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


    int n;
    cin >> n;

    string str;

    // cin >> str;
    // cout << mul(str, 3) << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        cout << str << " is ";
        cout << (cyclic(str) ? "" : "not ");
        cout << "cyclic\n";
    }

    return 0;
}