#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int x, y;
    int n = 0;
};

bool cmp(const Node &a, const Node &b)
{
    return a.n > b.n;
}

inline int byRoad(Node a, Node b)
{
    return a.x + b.x + 2;
}

inline int byJmp(Node a, Node b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;
        
        vector<Node> vec(N * M + 1);
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++)
        {
            vec[i * M + j].x = i;
            vec[i * M + j].y = j;
            cin >> vec[i * M + j].n;
        }
        sort(vec.begin(), vec.end(), cmp);

        int time = vec[0].x + 1; 
        int total = 0;

        for (int i = 0; i < vec.size() - 1 && time + 2 + vec[i].x <= K; i++)
        {
            K -= time + 1;
            total += vec[i].n;
            time = min(byRoad(vec[i], vec[i + 1]), byJmp(vec[i], vec[i + 1]));
        }

        cout << total << endl;
    }

    return 0;
}