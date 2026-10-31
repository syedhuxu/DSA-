
#include <iostream>
using namespace std;

void fun(int n)
{
    if (n <= 0)
    {
        return;
    }

    cout << n << " ";
    fun(n - 2);
    cout << n << " ";
}

int main()
{
    fun(5); // 5 3 1 1 3 5
    return 0;
}
