#include <iostream>
using namespace std;

void sumAndProduct(int arr[], int sz)
{
    int sum = 0;
    int product = 1;

    for (int i = 0; i < sz; i++)
    {
        sum += arr[i];
        product *= arr[i];
    }

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;
}

int main() // sum and product of an array
{
    int arr[] = {
        5,
        4,
        3,
        2,
        1,
    };
    int sz = sizeof(arr) / sizeof(int);

    sumAndProduct(arr, sz);

    return 0;
}