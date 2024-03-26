#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> vst(7, false);
vector<vector<int>> ans;

void show(vector<int>);
void dfs(vector<int> &vec, int dig)
{
    if (dig == 6)
    {
        if (vec[0] + vec[5] == vec[2] + vec[3] && vec[5] + vec[4] == vec[1] + vec[2])
        {
            ans.push_back(vec);
        }
    }
    else
    {
        for (int i = 1; i <= 6; i++)
        {
            if (!vst[i])
            {
                vec.push_back(i);
                vst[i] = true;
                dfs(vec, dig + 1);
                vec.pop_back();
                vst[i] = false;
            }
        }
    }
}

void show(vector<int> vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++) cout << *it;
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A;
    cin >> A;

    vector<int> vec{A};
    vst[A] = true;
    dfs(vec, 1);

    for (auto it = ans.begin(); it != ans.end(); it++) show(*it);

    return 0;
}