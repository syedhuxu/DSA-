
#include <iostream>
using namespace std;

void fun(int n)
{
    if (n <= 1)
    {
        cout << "Done ";
        return;
    }

    cout << n << " ";
    fun(n - 2); // 5 3 Done
}

int main()
{
    fun(5);
    return 0;
}
