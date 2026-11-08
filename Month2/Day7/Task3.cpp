#include <iostream>
using namespace std;

int main()
{
    int arr[] = {12, 455, 23, 899, 1, 56, 32, 41, 22, 100};
    int n = 10;

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (isSwap == false)
        {
            break;
        }
    }

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}