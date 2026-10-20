
#include <iostream>
using namespace std;

int fun(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    if (n % 2 == 0)
    {
        return n + fun(n - 1);
    }

    return fun(n - 1); // 6
}

int main()
{
    cout << fun(5);
    return 0;
}
