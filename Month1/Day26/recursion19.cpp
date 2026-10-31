#include <iostream>
using namespace std;

int fun(int n)
{
    if (n <= 1)
        return n;

    return fun(n - 1) + fun(n - 2);
}

int main()
{
    cout << fun(5);
    return 0;
}