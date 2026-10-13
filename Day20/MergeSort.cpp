
#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int st, int mid, int end)
{
    vector<int> temp(end - st + 1);

    int i = st;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right half
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    // Copy only the merged elements back
    for (int idx = 0; idx < k; idx++)
    {
        arr[st + idx] = temp[idx];
    }
}

void mergeSort(int arr[], int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        // for left half
        mergeSort(arr, st, mid);

        // for right half
        mergeSort(arr, mid + 1, end);

        merge(arr, st, mid, end);
    }
}

int main()
{
    int arr[] = {40, 10, 30, 20, 50, 1, 5, 3};
    int n = (sizeof(arr) / sizeof(int));

    mergeSort(arr, 0, n - 1);

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}
