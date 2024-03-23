#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int x;
    unordered_multiset<int> st;
    int cnt = 0;

    cin >> x;  
    while (x != -1)
    {
        if (x == 0)
        {
            cout << cnt << endl;
            cnt = 0;
            st.clear();
        }
        else
        {
            cnt += st.count(x * 2) + !(x % 2) * st.count(x / 2);
            st.insert(x);
        }
        cin >> x;
    }


    return 0;
}