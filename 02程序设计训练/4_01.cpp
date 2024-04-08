#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<vector<bool>> vec;
vector<vector<bool>> vst;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool avilable(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m && vec[x][y] && !vst[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    while (cin >> m >> n)
    {
        if (n == 0 && m == 0)
            break;

        vec.clear();
        vst.clear();
        vec.resize(n, vector<bool>(m));
        vst.resize(n, vector<bool>(m, false));
        pair<int, int> pos;

        char c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c;
                if (c == '.')
                    vec[i][j] = 1;
                else if (c == '#')
                    vec[i][j] = 0;
                else if (c == '@')
                {
                    pos = {i, j};
                    vst[i][j] = 1;
                    vec[i][j] = 1;
                }
            }
        }

        queue<pair<int, int>> que;
        que.push(pos);

        int total = 0;
        while (!que.empty())
        {
            pos = que.front();
            que.pop();
            total++;

            for (int i = 0; i < 4; i++)
            {
                if (avilable(pos.first + dx[i], pos.second + dy[i], n, m))
                {
                    que.push({pos.first + dx[i], pos.second + dy[i]});
                    vst[pos.first + dx[i]][pos.second + dy[i]] = 1;
                }
            }
        }

        cout << total << endl;
    }

    return 0;
}