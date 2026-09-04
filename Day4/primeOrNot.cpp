#include <iostream>
using namespace std;

bool isPrime(int n)
{
    bool prime = true;
    if (n <= 1)
    {
        cout << "Enter a number greater than 1...";
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            prime = false;
            break;
        }
    }
    if (prime == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char result = isPrime(7);
    cout << result;
    return 0;
}