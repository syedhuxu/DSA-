
#include <iostream>
using namespace std;

int fun(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fun(n - 2) + 1;
}

int main()
{
    cout << fun(5); // 3
    return 0;
}
