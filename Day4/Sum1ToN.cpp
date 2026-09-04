#include <iostream>
using namespace std;

int sumFunc(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int result = sumFunc(10);
    cout << result;

    return 0;
}