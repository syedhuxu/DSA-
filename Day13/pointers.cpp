#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;

    int *ptr = &a;

    cout << *ptr << endl; // 10

    ptr = &b;

    cout << *ptr << endl; // 20

    *ptr = 50;

    cout << a << endl; // 10
    cout << b << endl; // 50
    return 0;
}