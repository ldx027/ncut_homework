#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

void queen(vector<vector<bool>> vec, int n = 0, int cur = 0)
{
    // cout << cur << endl;
    if (n == 8)
    {
        ans.push_back(cur);
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (vec[n][i])
        {
            vector<vector<bool>> temp = vec;
            for (int j = 0; j < 8; j++)
            {
                temp[j][i] = 0;
                if (i - j + n >= 0 && i - j + n < 8)
                    temp[j][i + n - j] = 0;
                if (i + j - n >= 0 && i + j - n < 8)
                    temp[j][i + j - n] = 0;
            }
            queen(temp, n + 1, 10 * cur + i + 1);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<bool>> vec(8, vector<bool>(8, true));
    queen(vec);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << ans[n - 1] << endl;
    }
}