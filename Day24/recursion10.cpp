
#include <iostream>
using namespace std;

void fun(int n)
{
    if (n == 0)
    {
        cout << "X ";
        return;
    }

    cout << "A ";
    fun(n - 1);
    cout << "B ";
}

int main()
{
    fun(2); // A A X B B
    return 0;
}
