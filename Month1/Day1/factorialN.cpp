#include <iostream>
using namespace std;

int main()

{
    // Factorial of N no's

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Enter a number greater than 0...";
        return 0;
    }

    long long factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    cout << "Factorial of " << n << " is " << factorial;

    return 0;
}