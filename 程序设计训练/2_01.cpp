#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;

char change(char c)
{
    switch (c)
    {
        case 'A':
        case 'B':
        case 'C': return '2';
        case 'D':
        case 'E':
        case 'F': return '3';
        case 'G':
        case 'H':
        case 'I': return '4';
        case 'J':
        case 'K':
        case 'L': return '5';
        case 'M':
        case 'N':
        case 'O': return '6';
        case 'P':
        case 'R':
        case 'S': return '7';
        case 'T':
        case 'U':
        case 'V': return '8';
        case 'W':
        case 'X':
        case 'Y': return '9';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string str;
    map<string, int> mp;

    while (N--)
    {
        cin >> str;
        for (auto it = str.begin(); it != str.end(); it++)
        {
            if (*it == '-')
                str.erase(it--);
            if (*it >= 'A' && *it <= 'Z') *it = change(*it);
        }
        mp[str]++;
    }

    bool flg = false;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > 1) cout << it->first.substr(0, 3) << "-" << it->first.substr(3) << " " << it->second << endl, flg = true;
    }

    if (!flg) cout << "No duplicates." << endl;

    return 0;
}