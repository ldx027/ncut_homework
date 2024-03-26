#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Num
{

    friend Num operator-(Num &, Num &);
    friend bool operator<(Num &, Num &);

private:
    vector<int> vec;
    int sign;

public:
    Num()
    {
        vec.resize(1, 0);
        sign = 1;
    }
    Num(string str)
    {
        vec.resize(str.size() + 1, 0);
        for (int i = 0; i < str.size(); i++)
        {
            vec[i + 1] = str[str.size() - 1 - i] - '0';
        }
        sign = 1;
    }

    int& operator[](int idx)
    {
        if (idx >= vec.size() - 1)
            return vec[0];
        return vec[idx + 1];
    }

    void show(string mid = "", string end = "\n")
    {
        // cout << vec.size();
        if (sign < 0) cout << "-";
        for (auto it = vec.rbegin(); it + 1 != vec.rend(); it++) cout << *it << mid;
        cout << end;
    }
};

bool operator<(Num &a, Num &b)
{
    // cout << a.vec.size() << " " << b.vec.size();
    if (a.sign != b.sign)
        return a.sign < 0;
    if (a.vec.size() != b.vec.size())
        if (a.sign > 0) return a.vec.size() < b.vec.size();
        else return a.vec.size() > b.vec.size();

    for (int i = a.vec.size() - 2; i >= 0; i--)
        if (a[i] != b[i])
        {
            // cout << a[i] << " " << b[i] << endl;
            if (a.sign > 0) return a[i] < b[i];
            else return a[i] > b[i];
        }
    
    return false;
};

Num operator-(Num &a, Num &b)
{
    if (a < b)
    {
        Num rst = b - a;
        rst.sign = -1;
        return rst;
    }

    Num rst;
    rst.vec.resize(max(a.vec.size(), b.vec.size() + 1), 0);
    for (int i = 0; i < max(a.vec.size(), b.vec.size() - 1); i++)
        rst[i] = a[i] - b[i];
    for (int i = 0; i < rst.vec.size() - 2; i++) while (rst[i] < 0) rst[i] += 10, rst[i + 1]--;

    while (rst.vec.size() > 1 && rst.vec.back() == 0) rst.vec.pop_back();
    if (rst.vec.size() == 1) rst.vec.push_back(0);

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;
    // cout << a << endl << b << endl;
    Num a1(a), a2(b);
    Num a3 = a1 - a2;
    a3.show();
    return 0;
}