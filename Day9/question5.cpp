#include <iostream>
#include <climits>
using namespace std;

void swapSmallestAndLargest(int arr[], int size)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    int smallestIdx;
    int largestIdx;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            smallestIdx = i;
        }
        if (arr[i] > largest)
        {
            largest = arr[i];
            largestIdx = i;
        }
    }
    swap(arr[smallestIdx], arr[largestIdx]);
}

int main() // swap minimum and maximum elems ;

{
    int arr[] = {99, 88, 77, 66, 55, 44, 33, 22, 11};
    int size = sizeof(arr) / sizeof(int);

    swapSmallestAndLargest(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}