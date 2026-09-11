#include <iostream>
using namespace std;

int SumArray(int arr[], int size)
{

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int productArray(int arr[], int size)
{

    int product = 1;
    for (int i = 0; i < size; i++)
    {
        product *= arr[i];
    }

    return product;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);

    int sumResult = SumArray(arr, size);
    int productResult = productArray(arr, size);

    cout << "sum of array is: " << sumResult << endl;
    cout << "product of array is: " << productResult << endl;

    return 0;
}