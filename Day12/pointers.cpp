#include <iostream>
using namespace std;

int main()
{
    // Pointers are special variables that store address of other variables

    int a = 10;

    int *ptr = &a;

    // Using de-reference operator ...
    cout << *&a << endl;

    cout << ptr << endl;
    cout << &a << endl;
    cout << &ptr << endl;

    // one * for normal pointer and two ** for pointer of pointer
    int **ptr2 = &ptr;
    cout << ptr2 << endl;
    cout << *ptr << endl;

    return 0;
}