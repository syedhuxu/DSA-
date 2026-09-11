#include <iostream>
using namespace std;

void reverseArray(int arr[], int sz)
{
    int end = sz - 1;
    for (int i = 0; i < end; i++)
    {
        swap(arr[i], arr[end]);
        end--;
    }
}

int main()
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