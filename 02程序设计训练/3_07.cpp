#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fb;

void func()
{
    for (int i = 3; i < fb.size(); i++) fb[i] = (fb[i - 1] + fb[i - 2]) % int(1e3);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> input(N);
    for (int i = 0; i < N; i++) cin >> input[i];
    int n = *max_element(input.begin(), input.end());
    fb.resize(n + 1, 1);
    func();
    for (auto it = input.begin(); it != input.end(); it++) cout << fb[*it] << endl;

    return 0;
}