#include <iostream>
using namespace std;

int nFactorial(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int result = nFactorial(5);
    cout << result;
    return 0;
}