#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void func(vector<T> &vec)
{
    sort(vec.begin(), vec.end());
}

template <typename T>
void show(vector<T> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> iVec(5);
    vector<string> strVec(3);
    vector<double> dVec(8);

    for (int i = 0; i < 5; i++) cin >> iVec[i];
    for (int i = 0; i < 3; i++) cin >> strVec[i];
    for (int i = 0; i < 8; i++) cin >> dVec[i];

    func(iVec);
    func(strVec);
    func(dVec);

    show(iVec);
    show(strVec);
    show(dVec);

    return 0;
}