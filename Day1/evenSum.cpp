#include <iostream>
using namespace std;

int main()
{
    // Sum of all even no's from  1 to N

    int n;
    cout << "Enter a number:";
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
    }

    cout << "Sum of all even no's form 1 to " << n << " is: " << sum;
    return 0;
}