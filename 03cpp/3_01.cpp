#include <iostream>
#include <string>
using namespace std;

class Person
{

protected:
    string name;
    int age;
    char sex;

public:
    Person(string _name, int _age, char _sex) : name(_name), age(_age), sex(_sex) {}
    void display()
    {
        cout << name << " " << age << " " << sex;
    }
};

class Student : public Person
{

private:
    int grade;
    double score;

public:
    Student(string _name, int _age, char _sex, int _grade, double _score) : Person(_name, _age, _sex), grade(_grade), score(_score) {}
    void show()
    {
        display();
        cout << " " << grade << " " << score;
    }
    void add(double s) { score += s; }
};

int main()
{
    Student stu("Xu Li", 20, 'f', 2, 25.4);
    stu.add(2.6);
    stu.show();

    return 0;
}