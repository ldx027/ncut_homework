#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<short> vec(100, 0);
    vec[0] = 1;

    while (N--)
    {
        for (auto it = vec.begin(); it != vec.end() - 1; it++)
            *it *= 2;
        for (auto it = vec.begin(); it != vec.end() - 1; it++)
            if (*it > 9)
            {
                *(it + 1) += *it / 10;
                *it %= 10;
            }
    }

    auto it = vec.rbegin();
    for (; it != vec.rend(); it++)
        if (*it != 0) break;
    for (; it != vec.rend(); it++) cout << *it;

    return 0;
}