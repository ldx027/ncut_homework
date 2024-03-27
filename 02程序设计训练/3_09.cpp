#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

vector<int> str2num(string str)
{
    vector<int> vec(str.size());
    for (int i = 0; i < vec.size(); i++)
        vec[i] = str[str.size() - 1 - i] - '0';
    return vec;
}

vector<int> int2num(int N)
{
    vector<int> vec(log10(N) + 1);
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = N % 10;
        N /= 10;
    }

    return vec;
}

void show(vector<int> vec, string mid = "", string end = "\n")
{
    // cout << vec.size();
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
        cout << *it << mid;
    cout << end;
}

vector<int> mul(vector<int> &a, vector<int> &b)
{
    vector<int> rst(a.size() + b.size() + 3, 0);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            rst[i + j] += a[i] * b[j];
        }
    }
    // show(rst, " ");

    for (int i = 0; i < rst.size(); i++)
    {
        if (rst[i] > 9)
            rst[i + 1] += rst[i] / 10, rst[i] %= 10;
    }

    while (rst.back() == 0)
        rst.pop_back();
    if (rst.size() == 0)
        rst.push_back(0);

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> rst = int2num(1);

    for (int i = 2; i <= N; i++)
    {
        vector<int> temp = int2num(i);
        rst = mul(rst, temp);
    }
    
    show(rst);
    
    return 0;
}