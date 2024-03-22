#include <iostream>
using namespace std;

void f(int n)
{
    int sum = 0;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = i + 1, sum += arr[i];
    delete[] arr;

    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    f(n);

    return 0;
}