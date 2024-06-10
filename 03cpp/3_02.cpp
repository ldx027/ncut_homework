#include <iostream>
#include <string>
using namespace std;

class Data
{
public:
    int year, month, day;
    Data(int y, int m, int d) : year(y), month(m), day(d) {}
};

ostream& operator<<(ostream &cout, const Data data)
{
    cout << data.year << '/' << data.month << '/' << data.day;
    return cout;
}

class Teacher
{
protected:
    string name;
    Data birth;
    char gender;

    string title;

public:
    Teacher(string _name, Data _birth, char _gender, string _title) : name(_name), birth(_birth), gender(_gender), title(_title) {}
    void display()
    {
        cout << name << " " << birth << " " << gender << " " << title;
    }
};

class Cadre
{
protected:
    string name;
    Data birth;
    char gender;

    string post;

public:
    Cadre(string _name, Data _birth, char _gender, string _post) : name(_name), birth(_birth), gender(_gender), post(_post) {}
};

class Teacher_Cadre : public Teacher, public Cadre
{
private:
    double wages;

public:
    Teacher_Cadre(string _name, Data _data, char _gender, string _title, string _post, double _wages) : Teacher(_name, _data, _gender, _title), Cadre(_name, _data, _gender, _post), wages(_wages) {}
    void show()
    {
        Teacher::display();
        cout << " " << Cadre::post << " ";
        printf("%.2lf", wages);
    }
};

int main()
{
    Data data(1967, 10, 12);
    Teacher_Cadre cls("LiHong", data, 'f', "professor", "Header", 8e3);
    cls.show();

    return 0;
}