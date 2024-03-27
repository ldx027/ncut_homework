#include <iostream>
#include <vector>
using namespace std;

vector<bool> vec(26, false);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vec[0] = 1;
    while (N--)
    {
        char a, b;
        cin >> a >> b >> b;
        a -= 'a', b -= 'a';

        vec[a] = vec[b];
    }
    char buf[100];
    gets(buf);

    vector<char> ans;
    for (int i = 0; i < 26; i++)
    {
        if (vec[i]) ans.push_back(i + 'a');
    }

    if (N == 0 || ans.size() == 0) cout << "none" << endl;
    else if (ans.size() == 1) cout << ans[0] << " only" << endl;
    else for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

    return 0;
}