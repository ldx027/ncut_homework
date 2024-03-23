#include <iostream>
#include <string>
using namespace std;

char change(char a)
{
    return (a - 'A' + 21) % 26 + 'A';
}

int main()
{
    string str;

    while (1)
    {
        getline(cin, str);

        if (str == "START" || str == "END") continue;
        if (str == "ENDOFINPUT") return 0;

        for (auto it = str.begin(); it != str.end(); it++)
        {
            if (*it >= 'A' && *it <= 'Z')
            {
                *it = change(*it);
            }
        }

        cout << str << endl;
    }

    return 0;
}