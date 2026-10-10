#include <iostream>
using namespace std;

// Insertion at a specific position ...

bool isInsertElement(int arr[], int &size, int capacity, int elem, int idx)
{
    for (int i = size; i > idx; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[idx] = elem;
    size++;
    cout << "Elem inserted successfully .. " << endl;
    return true;
}

int main()
{

    int arr[] = {10, 20, 50, 30, 40};
    int size = sizeof(arr) / sizeof(int);
    int capacity = size;
    int elem = 60;
    int idx = 2;

    isInsertElement(arr, size, capacity, elem, idx);

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}