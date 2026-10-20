
#include <iostream>
using namespace std;

int fun(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * fun(n - 2);
}

int main()
{
    cout << fun(6);
    return 0;
}
