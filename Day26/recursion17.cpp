#include <iostream>
using namespace std;

void fun(int n)
{
    if (n <= 0)
        return;

    cout << n << " ";
    fun(n - 1);
    fun(n - 2);
    cout << n << " ";
}

int main()
{
    fun(3);
    return 0;
}