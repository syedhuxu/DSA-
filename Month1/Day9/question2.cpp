#include <iostream>
using namespace std;

int linearSearch(int arr[], int sz, int trgt)
{
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == trgt)
        {
            return i;
        }
    }
    return -1;
}

int main()

// linear search algorithm
{
    int arr[] = {
        9,
        8,
        7,
        6,
        5,
        4,
    };
    int sz = sizeof(arr) / sizeof(int);
    int trgt = 0;

    int result = linearSearch(arr, sz, trgt);
    cout << result;

    return 0;
}