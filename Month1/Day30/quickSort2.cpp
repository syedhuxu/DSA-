#include <iostream>
using namespace std;

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;

    for (int j = 1; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

void qucikSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        qucikSort(arr, l, p - 1);
        qucikSort(arr, p + 1, h);
    }
}

int main()
{

    int nums[] = {50, 30, 20, 10, 55};
    int n = 5;

    qucikSort(nums, 0, n - 1);

    for (int val : nums)
    {
        cout << val << " ";
    }
    return 0;
}