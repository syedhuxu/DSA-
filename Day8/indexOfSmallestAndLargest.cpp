#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void indexOfSmallestAndLargest(int arr[], int sz)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    int smallestIdx;
    int largestIdx;

    for (int i = 0; i < sz; i++)
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

    cout << "Index of smallest: " << smallestIdx << endl;
    cout << "Index of largest: " << largestIdx << endl;
    ;
}

int main()
{
    int arr[] = {12, 45, 86, 15, 0, 770, 56, 4};
    int sz = sizeof(arr) / sizeof(int);

    indexOfSmallestAndLargest(arr, sz);

    return 0;
}