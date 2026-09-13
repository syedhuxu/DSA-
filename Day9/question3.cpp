#include <iostream>
using namespace std;

void reverseArray(int arr[], int sz)
{
    int st = 0;
    int end = sz - 1;

    while (st < end)
    {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}

int main()

// Reverse an array ....
{

    int arr[] = {5, 4, 3, 2, 1, 0};
    int sz = sizeof(arr) / sizeof(int);

    reverseArray(arr, sz);

    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}