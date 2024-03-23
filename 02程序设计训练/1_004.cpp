#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;

bool avilable(int x, int y, int N)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> vec[i][j];

    int C = 0, S = 0;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    {
        if (vec[i][j] <= 50)
        {
            S++;
            bool flg = false;
            for (int u = 0; u < 4 && !flg; u++)
            {
                if (avilable(i + dx[u], j + dy[u], N))
                {
                    flg = vec[i + dx[u]][j + dy[u]] > 50;
                }
                else flg = true;
            }
            if (flg) C++;
        }
    }

    cout << S << " " << C;

    return 0;
}