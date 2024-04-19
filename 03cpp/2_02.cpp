#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Stu
{
public:
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

    for (int i = 0; i < 5; i++)
    {
        cin >> id >> score;
        arr[i].set(id, score);
    }

    double sum = 0;
    double avg;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i].getScore();
    }

    avg = sum / 5.0;
    cout << setiosflags(ios::fixed) << setprecision(2) << avg << endl;

    for (int i = 0; i < 5; i += 2)
    {
        cout << arr[i].getId() << " ";
        cout << setiosflags(ios::fixed) << setprecision(2) << arr[i].getScore() << endl;
    }

    return 0;
}