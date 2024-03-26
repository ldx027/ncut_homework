#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> str2num(string str)
{
    vector<int> vec(str.size());
    for (int i = 0; i < vec.size(); i++)
        vec[i] = str[str.size() - 1 - i] - '0';
    return vec;
}

void show(vector<int> vec, string mid = "", string end = "\n")
{
    // cout << vec.size();
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
        cout << *it << mid;
    cout << end;
}

bool greater(vector<int> a, int idx, vector<int> b)
{

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

    string str1, str2;
    cin >> str1 >> str2;
    vector<int> a = str2num(str1), b = str2num(str2);

    vector<int> rst = mul(a, b);
    show(rst);

    return 0;
}