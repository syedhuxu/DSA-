#include <iostream>
using namespace std;

int main()
{

    int arr[] = {7, 32, 12, 432, 324, 521, 1};
    int n = 7;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << endl;

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}