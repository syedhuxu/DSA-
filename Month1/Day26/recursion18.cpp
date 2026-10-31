#include <iostream>
using namespace std;

int fun(int n)
{
    if (n <= 0)
        return 1;

    return n * fun(n - 2);
}

int main()
{
    cout << fun(7);
    return 0;
}