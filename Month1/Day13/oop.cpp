#include <iostream>
#include <string>
using namespace std;

class Teacher
{
private:
    double salary;

public:
    Teacher()
    {
        cout << "Hello i'm a constructor" << endl;
    }

public:
    string name;
    string dept;
    string subject;

    Teacher(string n, string d, string sub, double sal)
    {
        name = n;
        dept = d;
        subject = sub;
        salary = sal;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    Teacher t1("huxu", "computer science", "c++", 10);
    t1.getInfo();
    return 0;
}