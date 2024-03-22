#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Operator
{
private:
    vector<int> vec;

public:

    Operator() { vec.resize(3); }

    void input(vector<int> _vec)
    {
        if (_vec.size() < 3) return;
        for (int i = 0; i < 3; i++) vec[i] = _vec[i];
    }

    int getMax() 
    {
        return *max_element(vec.begin(), vec.end());
    }

    double getAvg()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++) sum += vec[i];
        return sum / 3.0;
    }

    void sortVec()
    {
        sort(vec.begin(), vec.end());
    }

    void show()
    {
        sortVec();
        for (auto it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
        cout << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> vec(3);
    for (int i = 0; i < 3; i++) cin >> vec[i];

    Operator op;
    op.input(vec);

    cout << op.getMax() << endl;
    cout << op.getAvg() << endl;
    op.show();

    return 0;
}