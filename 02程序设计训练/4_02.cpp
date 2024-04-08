#include <iostream>
using namespace std;

int dfs(int apples, int N, int last)
{
    if (N == 0 && apples == 0) return 1;
    if (N < 0) return 0;
    if (apples < last) return 0;

    int rst = 0;
    for (int i = last; i <= apples; i++)
    {
        rst += dfs(apples - i, N - 1, i);
    }

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, M, N;
    cin >> t;
    while (t--)
    {
        cin >> M >> N;
        cout << dfs(M, N, 0) << endl;
    }
    
    return 0;
}