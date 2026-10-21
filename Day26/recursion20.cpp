#include <iostream>
using namespace std;

void fun(int n)
{
    if (n <= 1)
    {
        cout << n << " ";
        return;
    }

    cout << n << " ";
    fun(n / 2);
    cout << n * 2 << " ";
    fun(n / 2);
}

int main()
{
    fun(6);
    return 0;
}