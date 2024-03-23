#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> heap;

    int N, x;
    cin >> N;

    while (N--)
    {
        cin >> x;
        heap.push(x);
    }

    int rst = 0;
    while (heap.size() > 1)
    {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        rst += a + b;
        // cout << a + b << endl;
        heap.push(a + b);
    }

    cout << rst << endl;

    return 0;
}