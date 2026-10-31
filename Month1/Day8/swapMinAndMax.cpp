#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void swapMinMax(int arr[], int size)
{
    int min = INT_MAX;
    int max = INT_MIN;

    int smallestIdx;
    int largestIdx;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            smallestIdx = i;
        }

        if (arr[i] > max)
        {
            max = arr[i];
            largestIdx = i;
        }
    }

    swap(arr[smallestIdx], arr[largestIdx]);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(int);

    swapMinMax(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}