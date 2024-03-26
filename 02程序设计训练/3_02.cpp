#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> vec(N, vector<int>(N + 2, 0));
    for (int i = 0; i < N; i++) for (int j = 1; j <= i + 1; j++) cin >> vec[i][j];

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            vec[i][j] += max(vec[i - 1][j], vec[i - 1][j - 1]);
        }
    }

    cout << *max_element(vec[N - 1].begin(), vec[N - 1].end());    

    return 0;
}