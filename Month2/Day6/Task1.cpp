#include <iostream>
using namespace std;

void insertPos(int arr[], int &n, int capacity, int idx, int elem)
{
    if (n >= capacity)
    {
        cout << "Array is full" << endl;
        return;
    }
    if (idx < 0 || idx > n)
    {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = n; i > idx; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[idx] = elem;
    n++;
    cout << elem << " inserted at position " << idx << endl;
}

void deletePos(int arr[], int &n, int idx)
{
    if (n == 0)
    {
        cout << "Array is empty" << endl;
        return;
    }
    if (idx < 0 || idx >= n)
    {
        cout << "Invalid position" << endl;
        return;
    }
    cout << arr[idx] << " deleted from position " << idx << endl;

    for (int i = idx; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

int main()
{
    int capacity = 6; // capacity is the maximum number of elements of the array can store
    int arr[6] = {1, 2, 3, 4, 5};
    int n = 5; // size is the number of elements currently in the array

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    insertPos(arr, n, capacity, 1, 10);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    deletePos(arr, n, 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}