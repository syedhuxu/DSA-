#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int printSmallestAndLargest(int arr[], int sz)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < sz; i++)
    {
        smallest = min(arr[i], smallest);
        largest = max(arr[i], largest);
    }

    cout << "Smallest: " << smallest << endl;
    cout << "largest: " << largest;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int sz = sizeof(arr) / sizeof(int);

    printSmallestAndLargest(arr, sz);

    return 0;
}