#include <iostream>
using namespace std;

int main()
{
    // Check if a number is prime or not

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1)
    {
        cout << "Enter a number greater than 1...";
        return 0;
    }

    bool isPrime = true;

    for (int i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime == true)
    {
        cout << n << " is a prime number\n";
    }
    else
    {
        cout << n << " is not a prime number\n";
    }

    return 0;
}