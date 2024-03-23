#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    while (1)
    {
        int N;
        cin >> N;
        if (N == 0) return 0;

        vector<int> vec(N);
        for (int i = 0; i < N; i++) cin >> vec[i];
        for (int i = 0; i < N; i++) vec[i]--;

        while (1)
        {
            int n;
            cin >> n;
            if (n == 0) break;

            char c;
            c = getchar();
            c = getchar();
            vector<char> str(N, ' ');
            int idx = 0;
            while (c != '\n')
            {
                str[idx++] = c;
                c = getchar();
            }
            vector<char> temp(N, ' ');

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    temp[vec[j]] = str[j];
                }
                str = temp;
            }
            for (int i = 0; i < str.size(); i++)
            {
                cout << str[i];
            }
            cout << endl;
        }
    }

    return 0;
}