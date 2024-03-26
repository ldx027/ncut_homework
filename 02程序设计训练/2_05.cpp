#include <iostream>
#include <string>
using namespace std;

bool check(string a, string b)
{
    auto it1 = a.begin(), it2 = b.begin();
    
    while (it1 != a.end())
    {
        while (*it1 != *it2 && it2 != b.end()) *it2++;
        if (it2 == b.end()) return false;
        it1++, it2++;
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
        string a, b;
        cin >> a >> b;

        cout << (check(a, b) ? "Yes" : "No") << endl;
    }

    return 0;
}