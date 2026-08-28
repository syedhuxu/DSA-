#include <iostream>
using namespace std;

int main()

// Sum of all no's from 1 to N divisible by 3
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            sum += i;
        }
    }

    cout << "Sum of all no's form 1 to " << n << " divisible by 3 is: " << sum;
    return 0;
}