#include <iostream>
#include <vector>
using namespace std;

class Num
{
private:
    int sig;
    vector<int> vec;

public:
    Num() : sig(1) {}

    Num (string str)
    {
        trans(str);
    }

    void trans(string str)
};