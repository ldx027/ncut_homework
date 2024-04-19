#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Stu
{
private:
    string id;
    double score;

public:
    string getId() { return id; }
    double getScore() { return score; }
    void set(string _id, double _score)
    {
        id = _id, score = _score;
    }
};

int main()
{
    Stu *arr = new Stu[5];

    string id;
    double score;

    for (auto it = arr; it < arr + 5; it++)
    {
        cin >> id >> score;
        it->set(id, score);
    }

    double sum = 0;
    double avg;
    for (auto it = arr; it < arr + 5; it++)
    {
        sum += it->getScore();
    }

    avg = sum / 5.0;
    cout << setiosflags(ios::fixed) << setprecision(2) << avg << endl;

    for (auto it = arr; it < arr + 5; it += 2)
    {
        cout << it->getId() << " ";
        cout << setiosflags(ios::fixed) << setprecision(2) << it->getScore() << endl;
    }

    return 0;
}