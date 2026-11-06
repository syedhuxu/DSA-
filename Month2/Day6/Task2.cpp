#include <iostream>
using namespace std;

void binarySearch(int arr[], int l, int h, int tar)
{
    while (l <= h)
    {
        int m = l + (h - l) / 2;

        if (arr[m] == tar)
        {
            cout << tar << " found at: " << m;
            return;
        }
        else if (arr[m] > tar)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << tar << " Is not found" << endl;
    return;
}

int main()
{
    int arr[6] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(int);
    int l = 0;
    int h = n - 1;
    int tar = 10;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    binarySearch(arr, l, h, tar);
    return 0;
}