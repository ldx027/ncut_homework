#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    int N;
    cin >> str >> N;

    bool flg;
    for (int i = 0; i < N; i++)
    {
        flg = false;
        for (int j = 0; j < str.size() - 2; j++)
        {
            if (str[j] > str[j + 1])
            {
                str.erase(str.begin() + j, str.begin() + j + 1);
                flg = true;
                break;
            }
        }
        if (!flg)
            str.pop_back();
        // cout << str << endl;
    }

    cout << str << endl;

    return 0;
}