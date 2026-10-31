#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
    string name;
    int age;
    int salary;

    Teacher(string name, int age, int salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    void printInfo()
    {
        cout << "Hello I'm " << name << " My age is: " << age << " and my salary is: " << salary << endl;
    }
};

int main()
{
    Teacher t1("Scoripio", 22, 20);
    t1.printInfo();

    return 0;
}