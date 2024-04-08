#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool avilable(int x, int y, int n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool solve(vector<vector<bool>> vec, int ha, int la, int hb, int lb, int n)
{
    if (!vec[ha][la] || !vec[hb][lb]) return false;

    vector<vector<bool>> vst(n, vector<bool>(n, false));
    queue<pair<int, int>> que;

    pair<int, int> cur;
    que.push({ha, la});
    vst[ha][la] = 1;

    while (!que.empty())
    {
        cur = que.front();
        que.pop();

        if (cur == make_pair(hb, lb)) return true;

        for (int i = 0; i < 4; i++)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (avilable(x, y, n) && vec[x][y] && !vst[x][y])
            {
                que.push({x, y});
                vst[x][y] = 1;
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;

    while (k--)
    {
        int n;
        char c;
        cin >> n;
        vector<vector<bool>> vec(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> c;
                vec[i][j] = (c == '.');
            }
        }

        int ha, la, hb, lb;
        cin >> ha >> la >> hb >> lb;
        cout << (solve(vec, ha, la, hb, lb, n) ? "YES" : "NO") << endl;
    }

    return 0;
}