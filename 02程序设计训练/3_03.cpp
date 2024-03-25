#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> trans(string str)
{
    vector<int> rst(str.size());
    for (int i = str.size() - 1; i >= 0; i--) rst[i] = str[str.size() - i - 1] - '0';
    return rst;
}

vector<int> sum(vector<int> &a, vector<int> &b)
{
    vector<int> rst(max(a.size(), b.size()));
    for (int i = 0; i < min(a.size(), b.size()); i++) rst[i] = a[i] + b[i];
    vector<int> *temp = &(a.size() > b.size() ? a : b);
    for (int i = min(a.size(), b.size()); i < rst.size(); i++) rst[i] = temp->at(i);

    for (int i = 0; i < rst.size(); i++)
    {
        if (rst[i] > 9)
        {
            if (i == rst.size() - 1) rst.push_back(0);
            rst[i + 1] += rst[i] / 10;
            rst[i] %= 10;
        }
    }
    while (rst.back() == 0) rst.pop_back();
    if (rst.size() == 0) rst.push_back(0);
    
    return rst;
}

void show(vector<int> &num)
{
    for (auto it = num.rbegin(); it != num.rend(); it++) cout << *it;
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    vector<int> num1 = trans(a), num2 = trans(b);
    vector<int> rst = sum(num1, num2);
    show(rst);

    return 0;
}