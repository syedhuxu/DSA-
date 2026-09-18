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
    cout << *(ptr) << endl;

    // using ** for the original value .... ptr2 -> ptr -> a -> 10;
    cout << **(ptr2) << endl;

    //    NULL pointer (if we create a pointer and don't give it the address of some variable or else
    //     it will take some garbage value in it . To prevent this we use NULL value)
    int *ptr3 = NULL;

    return 0;
}