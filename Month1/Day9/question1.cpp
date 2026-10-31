#include <iostream>
#include <climits>
using namespace std;

void printSmallestAndLargest(int arr[], int size)
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

    cout << "largest elem is: " << largest << endl;
    cout << "smallest elem is: " << smallest << endl;

    cout << "idx of largest is: " << largestIdx << endl;
    cout << "idx of smallest is: " << smallestIdx;
}

int main()
{
    // find smallest and largest in an array and their indices

    int arr[] = {8, 89, 4, 32, 55, 999, 2, 0, 44, 444};
    int size = sizeof(arr) / sizeof(int);

    printSmallestAndLargest(arr, size);

    return 0;
}