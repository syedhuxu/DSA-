
#include <iostream>
using namespace std;

void fun(int n)
{
    if (n <= 0)
    {
        return;
    }

    cout << n << " ";
    fun(n - 2); // 3 1
    fun(n - 1); // 2 1
}

int main()
{
    fun(3);
    return 0;
}
