#include <iostream>
using namespace std;

int main()
{
    // Insertion Sort Code
    int arr[] = {40, 10, 30, 20, 50};
    int n = 5;

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

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}