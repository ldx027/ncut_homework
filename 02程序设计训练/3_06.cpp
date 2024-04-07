#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Num
{

friend Num operator>>(const Num &num, const int x);

private:
    vector<int> vec;

public:
    Num()
    {
        vec.clear();
        vec.push_back(0);
    }
    Num(string str)
    {
        vec.resize(str.size(), 0);
        for (int i = str.size() - 1; i >= 0; i--)
            vec[i] = str[str.size() - i - 1] - '0';
    }

    void change(string str)
    {
        vec.resize(str.size());
        for (int i = str.size() - 1; i >= 0; i--)
            vec[i] = str[str.size() - i - 1] - '0';
    }

    int operator[](const int idx) const
    {
        return this->vec[idx];
    }

    bool operator>=(const Num &other) const
    {
        // show();
        // other.show();

        if (this->vec.size() > other.vec.size())
            return true;
        if (this->vec.size() < other.vec.size())
            return false;

        for (int i = vec.size() - 1; i >= 0; i--)
        {
            if (vec[i] != other[i])
                return vec[i] >= other[i];
        }
        return true;
    }

    Num operator-(const Num &other)
    {
        Num rst;
        rst.vec = this->vec;

        for (unsigned i = 0; i < other.vec.size(); i++)
            rst.vec[i] -= other[i];

        for (int i = 0; i < rst.vec.size() - 1; i++)
        {
            while (rst[i] < 0)
            {
                rst.vec[i] += 10;
                rst.vec[i + 1] -= 1;
            }
        }

        while (rst.vec.back() == 0)
            rst.vec.pop_back();
        if (rst.vec.size() == 0)
            rst.vec.push_back(0);

        return rst;
    }

    Num operator/(const Num &other)
    {
        Num rst, a;
        a.vec = vec;

        if (!(a >= other))
            return rst;

        rst.vec.resize(a.vec.size() - other.vec.size() + 2, 0);

        for (int i = a.vec.size() - other.vec.size() + 1; i >= 0; i--)
        {
            // cout << "wtf" << endl;
            // cout << i << endl;
            // (other >> i).show();
            while (a >= (other >> i))
            {
                rst.vec[i]++;
                a = a - (other >> i);
                // a.show();
            }
        }

        // rst.vec[0]++;

        // for (int i = 0; i < rst.vec.size(); i++)
        // {
        //     if (rst[i] > 9)
        //     {
        //         if (i == rst.vec.size() - 1) rst.vec.push_back(0);
        //         rst.vec[i + 1] += rst[i] / 10;
        //         rst.vec[i] %= 10;
        //     }
        // }

        while (rst.vec.back() == 0)
            rst.vec.pop_back();
        if (rst.vec.size() == 0)
            rst.vec.push_back(0);

        return rst;
    }

    void show() const
    {
        for (int i = vec.size() - 1; i >= 0; i--)
            cout << vec[i];
        cout << endl;
    }
};

Num operator>>(const Num &num, const int x)
{
    Num rst;
    rst.vec.resize(num.vec.size() + x);
    for (int i = 0; i < x; i++)
        rst.vec[i] = 0;
    for (int i = 0; i < num.vec.size(); i++)
        rst.vec[i + x] = num.vec[i];

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string stra, strb;
    Num num1, num2, rst;

    while (N--)
    {
        cin >> stra >> strb;

        num1.change(stra);
        num2.change(strb);

        rst = num1 / num2;
        rst.show();
    }

    return 0;
}