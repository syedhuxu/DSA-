#include <iostream>
using namespace std;

int main()
// Binary Search
{
    int arr[] = {2, 5, 8, 11, 14, 17, 20};
    int target = 14;

    int low = 0, high = 6;
    int index = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            index = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << index;
    return 0;
}