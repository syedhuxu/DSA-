
#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 0)
    {
        return;
    }

    print(n - 1);
    cout << n << " ";
}

int main()
{
    print(4); // 1 2 3 4
    return 0;
}
