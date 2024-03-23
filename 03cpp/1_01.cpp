#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double func(double a, double b)
{
    return a > b ? b : a;
}

string func(string a, string b, string c)
{
    string temp;
    return (temp = (a > b ? b : a)) < c ? temp : c;
}

int func(vector<int> &vec)
{
    return *min_element(vec.begin(), vec.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double a, b;
    string c, d, e;
    vector<int> vec(10);

    cin >> a >> b >> c >> d >> e;
    for (int i = 0; i < 10; i++) cin >> vec[i];

    cout << func(a, b) << " " << func(c, d, e) << " " << func(vec);

    return 0;
}