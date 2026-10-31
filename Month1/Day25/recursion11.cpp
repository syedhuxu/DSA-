
#include <iostream>
using namespace std;

void fun(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << " ";
    fun(n - 1);

    if (n % 2 == 0)
    {
        cout << n * 2 << " ";
    }
}
// 4 3 2 1 4 8

int main()
{
    fun(4);
    return 0;
}
