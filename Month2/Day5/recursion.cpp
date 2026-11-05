#include <iostream>
using namespace std;

void display(int n)
{
    if (n == 0)
    {
        return;
    }

        display(n - 1);
    cout << n << " ";
}

int main()
{
    display(5);

    return 0;
}