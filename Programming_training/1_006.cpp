#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> vec(26, 0);
    string str;

    for (int i = 0; i < 4; i++)
    {
        getline(cin, str);
        for (auto it = str.begin(); it != str.end(); it++)
        {
            if (*it >= 'A' && *it <= 'Z')
                vec[*it - 'A']++;
        }
    }

    int height = *max_element(vec.begin(), vec.end());

    for (int i = height; i > 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            cout << (i <= vec[j] ? "*" : " ") << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << char('A' + i) << " ";
    }
}
