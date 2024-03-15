#include <iostream>
using namespace std;

int func(int A, int B, int N)
{
    int a = 1, b = 1;
    for (int i = 2; i < N; i++)
    {
        int t = B * a + A * b;
        a = b;
        b = t % 7;
    }

    return b;
}

int main()
{
    int A, B, N;
    while (cin >> A >> B >> N)
    {
        if (A == 0 && B == 0 && N == 0) break;
        cout << func(A, B, N) << endl;
    }

    return 0;
}