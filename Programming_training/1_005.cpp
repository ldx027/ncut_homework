#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, P;
    cin >> N >> M >> P;

    map<char, int> mp;
    char c;

    for (int i = 0; i < N * M; i++)
    {
        cin >> c;
        mp[c] += 1;
    }

    string str;
    for (int i = 0; i < P; i++)
    {
        cin >> str;
        for (auto it = str.begin(); it != str.end(); it++) mp[*it]--;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        for (int i = 0; i < (*it).second; i++)
            cout << (*it).first;
    }
}